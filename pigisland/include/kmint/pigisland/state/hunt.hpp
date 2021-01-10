//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_HUNT_HPP
#define PIG_ISLAND_HUNT_HPP

#include <kmint/pigisland/navigation.hpp>
#include "kmint/pigisland/state/state.hpp"
#include <kmint/pigisland/node_algorithm.hpp>

namespace kmint {
    namespace pigisland {
        class hunt : public state {
        public:
            hunt(pigisland::context *context, play::actor &target) : state(context), target(target) {
                context->setTint(graphics::colors::red);
                auto &targetClosedNode = find_closest_node_to(context->graph, target.location());
                tomtom = std::make_unique<navigation>(&context->graph, &context->node(), &context->graph[targetClosedNode.node_id()]);
            };

            void execute(delta_time dt) override;

            bool canEatPig() override { return true; };

        protected:
            play::actor &target;

        private:
            std::unique_ptr<navigation> tomtom;
        };
    }
}

#endif //PIG_ISLAND_HUNT_HPP
