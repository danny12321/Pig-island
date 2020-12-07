//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_SCARED_HPP
#define PIG_ISLAND_SCARED_HPP

#include "kmint/pigisland/state/state.hpp"

namespace kmint {
namespace pigisland {

    class scared : public state {
    public:
        scared(class context *context) : state(context) {};

        void execute(delta_time dt) override;

    };
}}

#endif //PIG_ISLAND_SCARED_HPP
