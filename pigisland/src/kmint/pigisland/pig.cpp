#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"

namespace kmint {
    namespace pigisland {


        pig::pig(math::vector2d location)
                : play::free_roaming_actor{location},
                  drawable_{*this, pig_image()} {
            velocity = math::vector2d{0, 0};
        }

        void pig::act(delta_time dt) {

            coherence();
            separation();
            alignment();
            maxSpeed();

            auto newLocation = this->location() + (velocity * to_seconds(dt));
            this->location(newLocation);
        }

        void pig::coherence() {
            // we can't see any friends
            if (num_perceived_actors() <= 0) return;

            math::vector2d center{0, 0};

            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                center += i->location();
            }

            center = math::vector2d{center.x() / num_perceived_actors(), center.y() / num_perceived_actors()};

            velocity += math::vector2d{
                    (center.x() - location().x()) * coherenceFactor,
                    (center.y() - location().y()) * coherenceFactor,
            };
        }

        void pig::separation() {
            // we can't see any friends
            if (num_perceived_actors() <= 0) return;
            math::vector2d move{0, 0};

            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                move += math::vector2d{
                        location().x() - i->location().x(),
                        location().y() - i->location().y()
                };
            }

            velocity += math::vector2d{
                    move.x() * separationFactor,
                    move.y() * separationFactor,
            };
        }

        void pig::maxSpeed() {
            if (velocity.x() > maxVelocity) velocity.x(maxVelocity);
            if (velocity.y() > maxVelocity) velocity.y(maxVelocity);
            if(velocity.x() < -maxVelocity) velocity.x(-maxVelocity);
            if(velocity.y() < -maxVelocity) velocity.y(-maxVelocity);
        }

        void pig::alignment(){
//            // we can't see any friends
//            if (num_perceived_actors() <= 0) return;
//
//            math::vector2d avgDirection {0, 0};
//
//            for (auto i = begin_perceived(); i != end_perceived(); ++i) {
//                avgDirection += math::vector2d{
//                        location().x() - i->location().x(),
//                        location().y() - i->location().y()
//                };
//                    avgDX += otherBoid.dx;
//                    avgDY += otherBoid.dy;
//            }
//
//            avgDX = avgDX / numNeighbors;
//            avgDY = avgDY / numNeighbors;
//
//            boid.dx += (avgDX - boid.dx) * matchingFactor;
//            boid.dy += (avgDY - boid.dy) * matchingFactor;
        }


    } // namespace pigisland

} // namespace kmint
