//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_STATE_HPP
#define PIG_ISLAND_STATE_HPP

#include "kmint/pigisland/state/context.hpp"

class state {
public:
    state(context* _context) : context(_context) {}

    virtual void execute() = 0;
    context* context;
};

#endif //PIG_ISLAND_STATE_HPP
