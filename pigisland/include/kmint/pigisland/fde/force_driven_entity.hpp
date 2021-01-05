#ifndef KMINT_PIGISLAND_FORCE_DRIVE_ENTITY_HPP
#define KMINT_PIGISLAND_FORCE_DRIVE_ENTITY_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>
#include <kmint/pigisland/fde/coherence_flock.hpp>
#include <kmint/pigisland/factors.hpp>

namespace kmint {
    namespace pigisland {

        class force_driven_entity : public play::free_roaming_actor {
        public:
            explicit force_driven_entity(math::vector2d location, factors &factors);

            void act(delta_time dt) override;

            void addFlock(std::unique_ptr<iforce> flock) {
                flocks.push_back(std::move(flock));
            }

            [[nodiscard]] math::vector2d getVelocity() const { return velocity; }

            [[nodiscard]] factors get_factors() const { return force_factors; };

        private:
            math::vector2d velocity;

            std::vector<std::unique_ptr<iforce>> flocks;

            float maxVelocity = 100;

            void setMaxVelocity();

            void addWalls();

            factors force_factors;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_FORCE_DRIVE_ENTITY_HPP */
