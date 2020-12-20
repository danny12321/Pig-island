//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_HUNT_HPP
#define PIG_ISLAND_HUNT_HPP

#include <kmint/pigisland/navigation.hpp>
#include "kmint/pigisland/state/state.hpp"

namespace kmint {
    namespace pigisland {
        class hunt : public state {
        public:
            hunt(pigisland::context *context, play::actor &target) : state(context), target(target) {
                context->setTint(graphics::colors::red);
                auto targetLocation = getClosestNode(target.location());
                tomtom = std::make_unique<navigation>(&context->graph, &context->node(), targetLocation);
            };

            void execute(delta_time dt) override;

            bool canEatPig() override { return true; };

        private:
            play::actor &target;
            std::unique_ptr<navigation> tomtom;

            map::map_node *getClosestNode(math::vector2d position);
        };
    }
}

#endif //PIG_ISLAND_HUNT_HPP
