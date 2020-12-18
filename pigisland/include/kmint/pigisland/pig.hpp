#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include <tuple>
#include <vector>
#include "./fde/force_driven_entity.hpp"
#include "shark.hpp"
#include "boat.hpp"

namespace kmint {
    namespace pigisland {

    class pig : public force_driven_entity {
        public:
            explicit pig(math::vector2d location, boat &boat, shark &shark);

            [[nodiscard]] const ui::drawable &drawable() const override { return drawable_; }

            void act(delta_time dt) override;

            // geeft aan dat de haai andere actors kan zien
            [[nodiscard]] bool perceptive() const override { return true; }

            // geeft het bereik aan waarbinnen een haai
            // andere actors kan waarnemen.
            [[nodiscard]] scalar perception_range() const override { return 200.f; }

        private:
            play::image_drawable drawable_;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
