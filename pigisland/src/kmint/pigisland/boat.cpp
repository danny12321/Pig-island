#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include "kmint/random.hpp"

namespace kmint {
namespace pigisland {
  boat::boat(map::map_graph& g, map::map_node& initial_node) : context(g, initial_node),
      drawable_{ *this, graphics::image{boat_image()} } {

      setState(new wandering(this));
  }

  void boat::act(delta_time dt) {
    t_passed_ += dt;
    if (to_seconds(t_passed_) >= 1) {
        activeState->execute(dt);
        t_passed_ = from_seconds(0);
    }
  }

    void boat::setTint(graphics::color color) {
        drawable_.set_tint(color);
    }

} // namespace pigisland
} // namespace kmint
