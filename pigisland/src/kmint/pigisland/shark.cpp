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
#include <kmint/pigisland/boat.hpp>

namespace kmint {
    namespace pigisland {
        shark::shark(map::map_graph &g, map::map_node &initial_node) : context(g, g[69]), drawable_{*this,
                                                                                                           graphics::image{
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

                if (stepsMade == 100) {
                    setState(new tired(this));
                }

                for (auto i = begin_perceived(); i != end_perceived(); ++i) {
                    auto &a = *i;

                    if(typeid(a).name() == typeid(kmint::pigisland::boat).name()) {
                        if(math::distance(a.location(), this->location()) <= 50) {
                            setState(new scared(this));
                        }
                    }
                }

            }
        }

        void shark::setTint(graphics::color color) {
            drawable_.set_tint(color);
        }

    } // namespace pigisland
} // namespace kmint
