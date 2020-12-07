//
// Created by Thierry on 2-12-2020.
//

#include "kmint/pigisland/state/tired.hpp"


namespace kmint {
namespace pigisland {
    void tired::execute(delta_time dt) {
        auto nextNode = nav->getNextNode();
        if (nextNode != nullptr) {
            context->node(*nextNode);
        }
    }
}}