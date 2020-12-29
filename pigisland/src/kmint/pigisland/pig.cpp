#include <kmint/pigisland/fde/follow_actor.hpp>
#include <kmint/pigisland/boat.hpp>
#include <kmint/pigisland/shark.hpp>
#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"

namespace kmint {
    namespace pigisland {

        pig::pig(math::vector2d location, boat &boat, shark &shark, factors &pig_factor) :
                force_driven_entity(location, pig_factor),
                drawable_{*this, pig_image()} {

            addFlock(std::make_unique<follow_actor>(*this, boat, pig_factor.get_boat_attraction_factor()));
            addFlock(std::make_unique<follow_actor>(*this, shark, pig_factor.get_shark_attraction_factor()));
        }

        void pig::act(delta_time dt) {
            if (!active) return;
            time_survived += to_seconds(dt);
            force_driven_entity::act(dt);
        }

        void pig::gotEaten() {
            active = false;
            dead = true;
            drawable_.set_tint(graphics::color::from_scalars(60, 60, 60));
        }

        void pig::get_onboard_boat() {
            active = false;
            // cannot delete actor or stop de drawing so place it outside the view
            location({-500, -500});
        }

    } // namespace pigisland

} // namespace kmint
