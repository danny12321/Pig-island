//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_WANDERING_HPP
#define PIG_ISLAND_WANDERING_HPP

#include "kmint/pigisland/state/state.hpp"
//#include "kmint/pigisland/state/context.hpp"

class wandering : public state {
public:
    wandering(class context* context) : state(context) {};

    void execute() override;

};

#endif //PIG_ISLAND_WANDERING_HPP
