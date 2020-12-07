//
// Created by Danny on 7-12-2020.
//

#ifndef PIGISLAND_NAVIGATION_HPP
#define PIGISLAND_NAVIGATION_HPP

#include <kmint/map/map.hpp>

namespace kmint {
namespace pigisland {
    struct shortest_road {
        kmint::map::map_node *from = nullptr;
        kmint::map::map_node *current;
        float distance = INT16_MAX;
        float estimatedDistance = INT16_MAX;
    };

    class navigation {
    public:
        navigation(kmint::map::map_graph *graph, kmint::map::map_node *start, kmint::map::map_node *target);


        kmint::map::map_node *getNextNode();

        void setTarget(kmint::map::map_node *start, kmint::map::map_node *target);

    private:
        kmint::map::map_node *start;
        kmint::map::map_node *target;
        kmint::map::map_graph *graph;
        std::vector<kmint::map::map_node*> route;

        void calculateRoute();
    };
}}

#endif //PIGISLAND_NAVIGATION_HPP
