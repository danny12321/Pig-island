//
// Created by Thierry on 2-12-2020.
//

#include <kmint/random.hpp>
#include "kmint/pigisland/state/wandering.hpp"


namespace kmint {
namespace pigisland {

    void wandering::execute(delta_time dt) {
        int next_index = random_int(0, context->node().num_edges());
        context->node(context->node()[next_index].to());
    }
}}