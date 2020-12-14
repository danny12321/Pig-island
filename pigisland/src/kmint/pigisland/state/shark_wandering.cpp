//
// Created by Danny on 7-12-2020.
//

#include <kmint/pigisland/state/hunt.hpp>
#include <kmint/pigisland/pig.hpp>
#include "kmint/pigisland/state/shark_wandering.hpp"

namespace kmint {
    namespace pigisland {
        void shark_wandering::execute(kmint::delta_time dt) {
            wandering::execute(dt);

            for (auto i = context->begin_perceived(); i != context->end_perceived(); ++i) {
                auto &a = *i;
                if (typeid(a).name() == typeid(kmint::pigisland::pig).name()) {
                    context->setState(new hunt(context, a));
                    break;
                }
            }
        }
    }
}