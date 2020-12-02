//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_TIRED_HPP
#define PIG_ISLAND_TIRED_HPP

#include "kmint/pigisland/state/state.hpp"

class tired : public state {
public:
    tired(class context *context) : state(context) {};

    void execute() override;

};

#endif //PIG_ISLAND_TIRED_HPP
