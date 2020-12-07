#include "kmint/pigisland/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include <iostream>

namespace kmint {
namespace pigisland {
shark::shark(map::map_graph &g, map::map_node &initial_node) : context(g, initial_node), drawable_{*this,
                                                     graphics::image {
                                                         shark_image()}} {

    setState(new wandering(this));
}

void shark::act(delta_time dt) {
  t_passed_ += dt;
  if (to_seconds(t_passed_) >= 1) {
    // Do state
    activeState->execute(dt);
    t_passed_ = from_seconds(0);
    // pick random edge

  }
  // laat ook even zien welke varkentjes hij ruikt
  for (auto i = begin_perceived(); i != end_perceived(); ++i) {
    auto const &a = *i;
    std::cout << "Smelled a pig at " << a.location().x() << ", "
              << a.location().y() << "\n";
  }
}

} // namespace pigisland
} // namespace kmint
