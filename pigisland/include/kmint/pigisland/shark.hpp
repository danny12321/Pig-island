#ifndef KMINT_PIGISLAND_SHARK_HPP
#define KMINT_PIGISLAND_SHARK_HPP

#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"
#include "kmint/pigisland/state/context.hpp"

namespace kmint {
    namespace pigisland {

        class shark : public context {
        public:
            shark(map::map_graph &g, map::map_node &initial_node);

            // wordt elke game tick aangeroepen
            void act(delta_time dt) override;

            ui::drawable const &drawable() const override { return drawable_; }

            // als incorporeal false is, doet de actor mee aan collision detection
            bool incorporeal() const override { return false; }

            // geeft de lengte van een zijde van de collision box van deze actor terug.
            // Belangrijk voor collision detection
            scalar collision_range() const override { return 16.0; }

            // geeft aan dat de haai andere actors kan zien
            bool perceptive() const override { return true; }

            // geeft het bereik aan waarbinnen een haai
            // andere actors kan waarnemen.
            scalar perception_range() const override { return 200.f; }

            void setTint(graphics::color color) override;


            void reset();

            void rest();

            [[nodiscard]] const bool getIsDone() const {return isDone;};

        private:
            play::image_drawable drawable_;

            void eatPig();

            bool isDone = false;

            int stepsMade = 0;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_SHARK_HPP */
