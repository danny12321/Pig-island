//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_STATE_HPP
#define PIG_ISLAND_STATE_HPP

#include "kmint/pigisland/state/context.hpp"

namespace kmint {
    namespace pigisland {
        class state {
        public:
            state(context *_context) : context(_context) {}

            virtual void execute(delta_time dt) = 0;

            virtual bool canEatPig() = 0;

            context *context;
        };
    }
}
#endif //PIG_ISLAND_STATE_HPP
