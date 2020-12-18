#include <kmint/pigisland/fde/follow_actor.hpp>
#include <kmint/pigisland/boat.hpp>
#include <kmint/pigisland/shark.hpp>
#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"

namespace kmint {
    namespace pigisland {

        pig::pig(math::vector2d location, boat &boat, shark &shark) :
                force_driven_entity(location),
                drawable_{*this, pig_image()} {

            addFlock(std::make_unique<follow_actor>(*this, boat));
            addFlock(std::make_unique<follow_actor>(*this, shark));
        }

        void pig::act(delta_time dt) {
            force_driven_entity::act(dt);
        }

    } // namespace pigisland

} // namespace kmint
