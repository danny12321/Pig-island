//
// Created by Danny on 09/01/2021.
//

#include <kmint/pigisland/state/shark_hunt.hpp>
#include <kmint/pigisland/state/shark_wandering.hpp>

namespace kmint {
    namespace pigisland {
        void shark_hunt::execute(kmint::delta_time dt) {
            bool in_sight = std::any_of(context->begin_perceived(), context->end_perceived(), [this](const play::actor &a) {
                return &a == &target;
            });

            if (in_sight) {
                hunt::execute(dt);
            } else {
                context->setState(new shark_wandering(context));
            };
        }
    }
}