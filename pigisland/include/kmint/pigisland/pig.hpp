#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>


enum FlockingType {
    Alignment,
    Separation,
    Coherence,
    WithinBounds
};

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

            void addFlockingFactor(FlockingType type, float amount);

            void logFlock() const;

        private:
            math::vector2d velocity;

            play::image_drawable drawable_;

            math::vector2d coherence();

            math::vector2d separation();

            math::vector2d alignment();

            math::vector2d keepWithinBounds();

            float coherenceFactor = 0.8;
            float separationFactor = 1.5;
            float alignmentFactor = 0.1;
            float keepWithinBoundFactor = 1.5;
            float maxVelocity = 100;

            void maxSpeed();
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
