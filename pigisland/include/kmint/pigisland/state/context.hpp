//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_CONTEXT_HPP
#define PIG_ISLAND_CONTEXT_HPP

class state;
class context {
public:
    context() {};
    void setState(state* newState) { activeState = newState; }

protected:
    state* activeState;
};

#endif //PIG_ISLAND_CONTEXT_HPP
