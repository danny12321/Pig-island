//
// Created by Thierry on 2-12-2020.
//

#include <kmint/pigisland/state/shark_wandering.hpp>
#include "kmint/pigisland/state/hunt.hpp"

namespace kmint {
    namespace pigisland {
        void hunt::execute(delta_time dt) {
            auto targetClosedNode = getClosestNode(target.location());

            if (tomtom->getTarget() != targetClosedNode) {
                tomtom->setTarget(&context->node(), targetClosedNode);
            }

            auto nextNode = tomtom->getNextNode();
            if (nextNode != nullptr) {
                context->node(*nextNode);
            }

            if (context->node().node_id() == targetClosedNode->node_id()) {
                target.remove();
                context->setState(new shark_wandering(context));
            }
        }

        map::map_node *hunt::getClosestNode(math::vector2d position) {
            map::map_node *closestNode;
            float minDistance = INT16_MAX;

            for (auto &node : context->graph) {
                auto distance = math::distance(node.location(), position);

                if (distance < minDistance) {
                    closestNode = &node;
                    minDistance = distance;
                }
            }

            return closestNode;
        }
    }
}