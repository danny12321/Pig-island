//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_TIRED_HPP
#define PIG_ISLAND_TIRED_HPP

#include "kmint/pigisland/state/state.hpp"

namespace kmint {
namespace pigisland {

    class tired : public state {
    public:
        tired(class context *context) : state(context) {};

        void execute(delta_time dt) override;

    };
}}
#endif //PIG_ISLAND_TIRED_HPP
