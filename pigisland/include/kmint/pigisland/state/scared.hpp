//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_SCARED_HPP
#define PIG_ISLAND_SCARED_HPP

#include "kmint/pigisland/state/wandering.hpp"

namespace kmint {
    namespace pigisland {

        class scared : public wandering {
        public:
            scared(class context *context) : wandering(context) {
                context->setTint(graphics::colors::black);
            };

            void execute(delta_time dt) override;

        private:
            int steps = 0;
            const int walkingDistance = 10;
        };
    }
}

#endif //PIG_ISLAND_SCARED_HPP
