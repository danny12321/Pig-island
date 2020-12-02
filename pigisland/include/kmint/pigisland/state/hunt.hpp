//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_HUNT_HPP
#define PIG_ISLAND_HUNT_HPP

#include "kmint/pigisland/state/state.hpp"

class hunt : public state {
public:
    hunt(class context* context) : state(context) {};
    void execute() override;
};


#endif //PIG_ISLAND_HUNT_HPP
