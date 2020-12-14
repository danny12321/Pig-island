//
// Created by Danny on 7-12-2020.
//

#include "kmint/pigisland/navigation.hpp"

namespace kmint {
    namespace pigisland {
        navigation::navigation(kmint::map::map_graph *graph, kmint::map::map_node *start, kmint::map::map_node *target)
                : graph(graph), start(start),
                  target(target) {
            calculateRoute();
        }

        kmint::map::map_node *kmint::pigisland::navigation::getNextNode() {
            if (route.empty()) return nullptr;

            auto node = route[route.size() - 1];
            route.erase(route.begin() + route.size() - 1);
            return node;
        }

        void kmint::pigisland::navigation::setTarget(kmint::map::map_node *start, kmint::map::map_node *target) {
            this->start = start;
            this->target = target;
            calculateRoute();
        }

        void kmint::pigisland::navigation::calculateRoute() {
            graph->untag_all();

            if (start->node_id() == target->node_id()) {
                route = {};
                return;
            }

            std::vector<shortest_road> path; // tabelletje
            std::vector<kmint::map::map_node *> queue;

            for (auto &node : *graph) {
                shortest_road a;
                a.current = &node;

                if (node.node_id() == start->node_id()) {
                    a.distance = 0;
                }

                a.estimatedDistance = std::sqrt(pow(target->location().x() - node.location().x(), 2) +
                                                pow(target->location().y() - node.location().y(), 2) * 1.0) / 28;

                path.push_back(a);
                queue.push_back(&node);
            }

            bool done = false;

            while (!done) {

                // Search node in queue with shortest distance
                kmint::map::map_node *activeNode = nullptr;
                int shortest = INT16_MAX;

                // Choose active node
                for (auto node : path) {
                    if (queue[node.current->node_id()] != nullptr &&
                        node.distance + node.estimatedDistance < shortest) {
                        activeNode = node.current;
                        shortest = node.distance + node.estimatedDistance;
                    }
                }

                activeNode->tag(graph::node_tag::visited);
                // Remove active node from queue
                queue[activeNode->node_id()] = nullptr;

                for (auto edge : *activeNode) {
                    auto *activePath = &path[activeNode->node_id()];
                    auto *toPath = &path[edge.to().node_id()];


                    if (activePath->distance + edge.weight() < toPath->distance) {
                        toPath->distance = activePath->distance + edge.weight();
                        toPath->from = activeNode;
                    }
                }

                done = true;

                auto currentShortestPath = path[target->node_id()];

                if (currentShortestPath.from == nullptr) {

                    for (auto q : queue) {
                        if (q != nullptr) {
                            done = false;
                            break;
                        }
                    }
                }
            }

            auto currentShortestPath = path[target->node_id()];
            std::vector<kmint::map::map_node *> realPath{};

            while (currentShortestPath.from != nullptr) {
                realPath.push_back(currentShortestPath.current);
                currentShortestPath.current->tag(graph::node_tag::path);
                currentShortestPath = path[currentShortestPath.from->node_id()];
            }

            route = realPath;
        }

        kmint::map::map_node *navigation::getTarget() {
            return target;
        }
    }
}