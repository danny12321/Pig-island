//
// Created by Thierry on 2-12-2020.
//

#ifndef PIG_ISLAND_TIRED_HPP
#define PIG_ISLAND_TIRED_HPP

#include <memory>
#include <kmint/pigisland/navigation.hpp>
#include "kmint/pigisland/state/state.hpp"

namespace kmint {
namespace pigisland {

    class tired : public state {
    public:
        tired(class context *context) : state(context) {
            context->setTint(graphics::colors::white);
            nav = std::make_unique<navigation>(&context->graph, &context->node(), &context->graph[restingPlaceId]);
        };

        void execute(delta_time dt) override;

    private:
        std::unique_ptr<navigation> nav;

        const int restingPlaceId = 609;
    };
}}
#endif //PIG_ISLAND_TIRED_HPP
