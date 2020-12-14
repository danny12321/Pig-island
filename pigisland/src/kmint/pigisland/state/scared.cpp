//
// Created by Thierry on 2-12-2020.
//

#include <kmint/pigisland/state/shark_wandering.hpp>
#include "kmint/pigisland/state/scared.hpp"

namespace kmint {
    namespace pigisland {

        void scared::execute(delta_time dt) {
            wandering::execute(dt);
            steps++;

            if (steps >= walkingDistance) {
                context->setState(new shark_wandering(context));
            }
        }
    }
}