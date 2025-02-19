//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_WANDERING_HPP
#define PIG_ISLAND_WANDERING_HPP

#include "kmint/pigisland/state/state.hpp"

namespace kmint {
    namespace pigisland {
        class wandering : public state {
        public:
            wandering(class context *context) : state(context) {
                context->setTint(graphics::colors::green);
            };

            void execute(delta_time dt) override;

            bool canEatPig() override { return true; };
        };
    }
}

#endif //PIG_ISLAND_WANDERING_HPP
