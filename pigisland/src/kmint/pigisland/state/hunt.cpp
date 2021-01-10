//
// Created by Thierry on 2-12-2020.
//

#include <kmint/pigisland/state/shark_wandering.hpp>
#include <kmint/pigisland/pig.hpp>
#include "kmint/pigisland/state/hunt.hpp"

namespace kmint {
    namespace pigisland {
        void hunt::execute(delta_time dt) {
            auto piggie = dynamic_cast<pig*>(&target);
            if (piggie != nullptr && !piggie->survived()) {
                context->setState(new shark_wandering(context));
                return;
            }

            auto &targetClosedNode = find_closest_node_to(context->graph, target.location());

            if (tomtom->getTarget() != &targetClosedNode) {
                tomtom->setTarget(&context->node(), &context->graph[targetClosedNode.node_id()]);
            }

            auto nextNode = tomtom->getNextNode();
            if (nextNode != nullptr) {
                context->node(*nextNode);
            }
        }

    }
}