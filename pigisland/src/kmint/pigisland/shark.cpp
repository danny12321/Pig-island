#include "kmint/pigisland/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include <iostream>
#include <kmint/pigisland/state/tired.hpp>
#include <kmint/pigisland/state/scared.hpp>
#include <kmint/pigisland/state/hunt.hpp>
#include <kmint/pigisland/state/shark_wandering.hpp>

namespace kmint {
namespace pigisland {
shark::shark(map::map_graph &g, map::map_node &initial_node) : context(g, initial_node), drawable_{*this,
                                                     graphics::image {
                                                         shark_image()}} {

    setState(new shark_wandering(this));
}

void shark::act(delta_time dt) {
  t_passed_ += dt;
  if (to_seconds(t_passed_) >= 1) {
    // Do state
    activeState->execute(dt);
    stepsMade++;
    t_passed_ = from_seconds(0);

    if(stepsMade == 100) {
        setState(new tired(this));
    }
  }
}

} // namespace pigisland
} // namespace kmint
