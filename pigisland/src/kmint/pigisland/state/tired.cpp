//
// Created by Thierry on 2-12-2020.
//

#include "kmint/pigisland/state/tired.hpp"
#include <kmint/pigisland/shark.hpp>

namespace kmint {
    namespace pigisland {
        void tired::execute(delta_time dt) {
            auto nextNode = nav->getNextNode();
            if (nextNode != nullptr) {
                context->node(*nextNode);
            }

            if (context->node().node_id() == restingPlaceId) {
                auto shark = dynamic_cast<kmint::pigisland::shark*>(context);

                if(shark != nullptr) {
                    shark->rest();
                }
            }
        }
    }
}