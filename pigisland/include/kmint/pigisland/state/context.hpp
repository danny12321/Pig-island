//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_CONTEXT_HPP
#define PIG_ISLAND_CONTEXT_HPP

//#include <kmint/pigisland/simulation.hpp>
#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"

namespace kmint {
    namespace pigisland {

        class state;

        class context : public play::map_bound_actor {
        public:
            context(map::map_graph &g, map::map_node &initial_node) : play::map_bound_actor{initial_node}, graph(g) {};

            void setState(state *newState) {
                activeState = newState;
            }

            virtual void setTint(graphics::color color) = 0;

            delta_time t_passed_{};
            map::map_graph &graph;
            int stepsMade = 0;

            bool isDone = false;
        protected:
            state *activeState;
        };
    }
}
#endif //PIG_ISLAND_CONTEXT_HPP
