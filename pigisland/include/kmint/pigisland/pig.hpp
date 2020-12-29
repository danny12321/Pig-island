#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>
#include "./fde/force_driven_entity.hpp"
#include "shark.hpp"
#include "boat.hpp"
#include "factors.hpp"

namespace kmint {
    namespace pigisland {
        class pig : public force_driven_entity {
        public:
            explicit pig(math::vector2d location, boat &boat, shark &shark, factors &factors);

            [[nodiscard]] const ui::drawable &drawable() const override { return drawable_; }

            // als incorporeal false is, doet de actor mee aan collision detection
            [[nodiscard]] bool incorporeal() const override { return !active; }

            // geeft de lengte van een zijde van de collision box van deze actor terug.
            // Belangrijk voor collision detection
            [[nodiscard]] scalar collision_range() const override { return 16.0; }

            void act(delta_time dt) override;

            [[nodiscard]] bool perceptive() const override { return active; }

            // geeft het bereik aan waarbinnen een haai
            // andere actors kan waarnemen.
            [[nodiscard]] scalar perception_range() const override { return 200.f; }

            void gotEaten();

            [[nodiscard]] float get_time_survived() const { return time_survived; }

            [[nodiscard]] bool survived() const { return !dead; };

            void get_onboard_boat();

        private:
            play::image_drawable drawable_;
            float time_survived = 0;
            bool active = true;
            bool dead = false;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
