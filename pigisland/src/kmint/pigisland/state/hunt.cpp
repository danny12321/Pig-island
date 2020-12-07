//
// Created by Thierry on 2-12-2020.
//

#include "kmint/pigisland/state/hunt.hpp"

namespace kmint {
namespace pigisland {
    void hunt::execute(delta_time dt) {
        auto nextNode = tomtom->getNextNode();
        if(nextNode != nullptr) {
            context->node(*nextNode);
        }
    }

    map::map_node *hunt::getClosestNode(math::vector2d position) {
        map::map_node* closestNode;
        float minDistance = INT16_MAX;

        for(auto &node : context->graph) {
            auto distance = math::distance(node.location(), position);

            if(distance < minDistance) {
                closestNode = &node;
                minDistance = distance;
            }
        }

        return closestNode;
    }
}}