//
// Created by Danny on 7-12-2020.
//

#ifndef PIGISLAND_SHARK_WANDERING_HPP
#define PIGISLAND_SHARK_WANDERING_HPP

#include "wandering.hpp"

namespace kmint {
    namespace pigisland {
        class shark_wandering : public wandering {

        public:
            shark_wandering(class context *context) : wandering(context) {}

            void execute(delta_time dt) override;

        private:

        };
    }
}
#endif //PIGISLAND_SHARK_WANDERING_HPP
