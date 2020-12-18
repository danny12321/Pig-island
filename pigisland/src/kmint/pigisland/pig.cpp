#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"

namespace kmint {
    namespace pigisland {

        pig::pig(math::vector2d location) :
                force_driven_entity(location),
                drawable_{*this, pig_image()} {
        }

        void pig::act(delta_time dt) {
            force_driven_entity::act(dt);
        }

    } // namespace pigisland

} // namespace kmint
