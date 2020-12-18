#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"

namespace kmint {
    namespace pigisland {


        pig::pig(math::vector2d location)
                : play::free_roaming_actor{location},
                  drawable_{*this, pig_image()} {
            velocity = math::vector2d{random_scalar(-100, 100), random_scalar(-100, 100)};
        }

        void pig::act(delta_time dt) {
            math::vector2d acceleration{0, 0};
            acceleration += coherence();
            acceleration += separation();
            acceleration += alignment();
            acceleration += keepWithinBounds();
            velocity += acceleration;
            velocity *= maxVelocity;
            maxSpeed();
            auto newLocation = this->location() + (velocity * to_seconds(dt));
            this->location(newLocation);
        }

        math::vector2d pig::coherence() {
            // we can't see any friends
            if (num_perceived_actors() <= 0) return {0, 0};
            int coherenceView = 25;

            math::vector2d center{0, 0};
            int total = 0;

            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                if (math::distance(i->location(), this->location()) < coherenceView) {
                    total++;
                    center += i->location();
                }
            }

            center = math::vector2d{center.x() / total, center.y() / total};
            if (total <= 0) return {0, 0};
            return {
                    (center.x() - location().x()) * coherenceFactor,
                    (center.y() - location().y()) * coherenceFactor,
            };
        }

        math::vector2d pig::separation() {
            // we can't see any friends
            if (num_perceived_actors() <= 0) return {0, 0};

            math::vector2d move{0, 0};
            int separationView = 25;

            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                // get velocity instead of location
                if (math::distance(i->location(), this->location()) < separationView) {
                    move += math::vector2d{
                            location().x() - i->location().x(),
                            location().y() - i->location().y()
                    };
                }
            }

            return {
                    move.x() * separationFactor,
                    move.y() * separationFactor,
            };
        }

        void pig::maxSpeed() {
            float speed = sqrt(velocity.x() * velocity.x() + velocity.y() * velocity.y());
            if (speed > maxVelocity) {
                velocity.x((velocity.x() / speed) * maxVelocity);
                velocity.y((velocity.y() / speed) * maxVelocity);
            }
        }

        math::vector2d pig::alignment() {
//            // we can't see any friends
            if (num_perceived_actors() <= 0) return {0, 0};

            math::vector2d avgDirection{0, 0};
            int total = 0;

            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                auto piggie = dynamic_cast<pig *>(i.operator->());

                if (piggie != nullptr) {
                    total++;
                    avgDirection += math::vector2d{
                            piggie->velocity.x(),
                            piggie->velocity.y()
                    };
                }
            }

            if (total <= 0) return {0, 0};

            return {
                    ((avgDirection.x() / total) - velocity.x()) * alignmentFactor,
                    ((avgDirection.y() / total) - velocity.y()) * alignmentFactor
            };
        }

        math::vector2d pig::keepWithinBounds() {
            int width = 1024;
            int height = 768;
            int padding = 10;

            if (location().x() > width - padding) {
                return {-keepWithinBoundFactor * maxVelocity, 0};
            } else if (location().x() < 0 + padding) {
                return {keepWithinBoundFactor * maxVelocity, 0};
            }
            if (location().y() > height - padding) {
                return {0, -keepWithinBoundFactor * maxVelocity};
            } else if (location().y() < 0 + padding) {
                return {0, keepWithinBoundFactor * maxVelocity};
            }

            return {0, 0};
        }

        void pig::addFlockingFactor(FlockingType type, float amount) {
            switch (type) {
                case FlockingType::Coherence:
                    coherenceFactor += amount;
                    break;
                case FlockingType::Separation:
                    separationFactor += amount;
                    break;
                case FlockingType::Alignment:
                    alignmentFactor += amount;
                    break;
                case FlockingType::WithinBounds:
                    keepWithinBoundFactor += amount;
                    break;
            }
        }

        void pig::logFlock() const {
            std::cout << "Flocking factor: \n";
            std::cout << "  Coherence: " << coherenceFactor << "\n";
            std::cout << "  Alignment: " << alignmentFactor << "\n";
            std::cout << "  Separation: " << separationFactor << "\n";
            std::cout << "  WithinBounds: " << keepWithinBoundFactor << std::endl;
        }


    } // namespace pigisland

} // namespace kmint
