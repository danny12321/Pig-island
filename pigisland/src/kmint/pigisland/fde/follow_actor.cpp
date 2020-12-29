//
// Created by Danny on 18-12-2020.
//

#include <kmint/pigisland/fde/follow_actor.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>

namespace kmint {
    namespace pigisland {
        math::vector2d follow_actor::getSteering() const {
            int followActorView = 100;

            if (math::distance(entity.location(), actor.location()) < followActorView) {
                return {
                        (actor.location().x() - entity.location().x()) * force_factor.get_value(),
                        (actor.location().y() - entity.location().y()) * force_factor.get_value(),
                };
            }

            return {0, 0};
        }
    }
}