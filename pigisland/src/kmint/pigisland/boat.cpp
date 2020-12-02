#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include "kmint/random.hpp"
namespace kmint {
namespace pigisland {
  boat::boat(map::map_graph& g, map::map_node& initial_node) : context(),
    play::map_bound_actor{ initial_node },
      drawable_{ *this, graphics::image{boat_image()} } {

      setState(new wandering(this));
  }


  void boat::act(delta_time dt) {
    t_passed_ += dt;
    if (to_seconds(t_passed_) >= 1) {
      // Do state
      activeState->execute();
      // pick random edge
      int next_index = random_int(0, node().num_edges());
      this->node(node()[next_index].to());
      t_passed_ = from_seconds(0);
    }
  }

} // namespace pigisland
} // namespace kmint
