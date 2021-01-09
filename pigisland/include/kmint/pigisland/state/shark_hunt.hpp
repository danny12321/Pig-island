//
// Created by Danny on 09/01/2021.
//

#ifndef PIGISLAND_SHARK_HUNT_HPP
#define PIGISLAND_SHARK_HUNT_HPP

#include "hunt.hpp"

namespace kmint {
    namespace pigisland {
        class shark_hunt : public hunt {
        public:
            shark_hunt(pigisland::context *context, play::actor &target) : hunt(context, target) {}

            void execute(delta_time dt) override;
        };
    }
}

#endif //PIGISLAND_SHARK_HUNT_HPP
