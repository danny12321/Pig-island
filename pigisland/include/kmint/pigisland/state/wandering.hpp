//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_WANDERING_HPP
#define PIG_ISLAND_WANDERING_HPP

#include "kmint/pigisland/state/state.hpp"
//#include "kmint/pigisland/state/context.hpp"

namespace kmint {
    namespace pigisland {
        class wandering : public state {
        public:
            wandering(class context *context) : state(context) {
                context->setTint(graphics::colors::green);
            };

            void execute(delta_time dt) override;

        };
    }
}

#endif //PIG_ISLAND_WANDERING_HPP
