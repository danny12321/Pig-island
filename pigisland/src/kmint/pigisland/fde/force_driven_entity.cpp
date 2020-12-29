#include <kmint/random.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>
#include <kmint/pigisland/fde/alignment_flock.hpp>
#include <kmint/pigisland/fde/separation_flock.hpp>
#include <kmint/pigisland/fde/separation_wall.hpp>

namespace kmint {
    namespace pigisland {
        force_driven_entity::force_driven_entity(math::vector2d location, factors &factors) : play::free_roaming_actor{location}, force_factors(factors) {
            velocity = math::vector2d{random_scalar(-100, 100), random_scalar(-100, 100)};

            flocks.push_back(std::make_unique<coherence_flock>(*this, force_factors.get_coherence_factor()));
            flocks.push_back(std::make_unique<alignment_flock>(*this, force_factors.get_alignment_factor()));
            flocks.push_back(std::make_unique<separation_flock>(*this, force_factors.get_separation_factor()));
            addWalls();
        }

        void force_driven_entity::act(delta_time dt) {
            math::vector2d steeringForce{0, 0};

            for (const auto &flock : flocks)
                steeringForce += flock->getSteering();

            velocity += steeringForce;
            velocity *= maxVelocity;
            setMaxVelocity();
            this->location(this->location() + (velocity * to_seconds(dt)));
            actor::act(dt);
        }

        void force_driven_entity::setMaxVelocity() {
            float speed = sqrt(velocity.x() * velocity.x() + velocity.y() * velocity.y());
            if (speed > maxVelocity) {
                velocity.x((velocity.x() / speed) * maxVelocity);
                velocity.y((velocity.y() / speed) * maxVelocity);
            }
        }

        void force_driven_entity::addWalls() {
            factor wall_force {50};

            // ADD WALLS
            float width = 1024;
            float height = 768;

            math::vector2d topLeft{0, 0};
            math::vector2d topRight{width, 0};
            math::vector2d bottomLeft{0, height};
            math::vector2d bottomRight{width, height};

            flocks.push_back(std::make_unique<separation_wall>(*this, topLeft, topRight, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, topRight, bottomRight, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, bottomRight, bottomLeft, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, bottomLeft, topLeft, wall_force));


            // top left island
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {0, 90}, math::vector2d{290,90}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {290, 0}, math::vector2d{290,90}, wall_force));

            // top right island
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {900, 0}, math::vector2d{900 ,55}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {900, 55}, math::vector2d{990,55}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {990, 55}, math::vector2d{990,130}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {990, 130}, math::vector2d{1024,130}, wall_force));

            // bottom left island
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {80, 560}, math::vector2d{200 ,560}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {200, 560}, math::vector2d{200,690}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {80, 690}, math::vector2d{200,690}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {80, 560}, math::vector2d{80,690}, wall_force));


            // bottom right island
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {810, 768}, math::vector2d{810 ,620}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {810, 620}, math::vector2d{895 ,620}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {895, 620}, math::vector2d{895 ,545}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {895, 545}, math::vector2d{930 ,545}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {930, 545}, math::vector2d{930 ,590}, wall_force));
            flocks.push_back(std::make_unique<separation_wall>(*this, math::vector2d {930, 590}, math::vector2d{1024 ,590}, wall_force));
        }
    }
}