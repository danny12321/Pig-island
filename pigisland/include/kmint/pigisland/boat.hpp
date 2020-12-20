#ifndef KMINT_PIGISLAND_BOAT_HPP
#define KMINT_PIGISLAND_BOAT_HPP

#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"
#include "kmint/pigisland/state/context.hpp"

namespace kmint {
    namespace pigisland {

        class boat : public context {
        public:
            boat(map::map_graph &g, map::map_node &initial_node);

            // wordt elke game tick aangeroepen
            void act(delta_time dt) override;

            ui::drawable const &drawable() const override { return drawable_; }

            // als incorporeal false is, doet de actor mee aan collision detection
            bool incorporeal() const override { return false; }

            // geeft de lengte van een zijde van de collision box van deze actor terug.
            // Belangrijk voor collision detection
            scalar collision_range() const override { return 16.0; }

            void setTint(graphics::color color) override;

            void repair(int amount);

        private:
            play::image_drawable drawable_;
            int damage = 0;
            void get_pigs_onboard();
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_BOAT_HPP */
