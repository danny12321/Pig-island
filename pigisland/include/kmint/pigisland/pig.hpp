#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>

namespace kmint {
    namespace pigisland {

        class pig : public play::free_roaming_actor {
        public:
            pig(math::vector2d location);

            const ui::drawable &drawable() const override { return drawable_; }

            void act(delta_time dt) override;

            // geeft aan dat de haai andere actors kan zien
            bool perceptive() const override { return true; }

            // geeft het bereik aan waarbinnen een haai
            // andere actors kan waarnemen.
            scalar perception_range() const override { return 200.f; }

        private:
            math::vector2d velocity;

            play::image_drawable drawable_;

            void coherence();

            void separation();

            float coherenceFactor = 0.005;
            float separationFactor = 0.05;
            float alignmentFactor = 0.05;
            float maxVelocity = 10;

            void maxSpeed();

            void alignment();
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
