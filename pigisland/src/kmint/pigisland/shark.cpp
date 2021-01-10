#include "kmint/pigisland/shark.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include <kmint/pigisland/state/tired.hpp>
#include <kmint/pigisland/state/scared.hpp>
#include <kmint/pigisland/state/shark_wandering.hpp>
#include <kmint/pigisland/boat.hpp>
#include <kmint/pigisland/pig.hpp>
#include <kmint/pigisland/node_algorithm.hpp>

namespace kmint {
    namespace pigisland {
        shark::shark(map::map_graph &g, map::map_node &initial_node) : context(g, initial_node), drawable_{*this,
                                                                                                           graphics::image{
                                                                                                                   shark_image()}} {
            setState(new shark_wandering(this));
        }

        void shark::act(delta_time dt) {
            t_passed_ += dt;
            eatPig();

            if (to_seconds(t_passed_) >= waiting_time(node())) {
                // Do state
                getState()->execute(dt);
                stepsMade++;
                t_passed_ = from_seconds(0);

                if (stepsMade == 100) {
                    setState(new tired(this));
                } else {
                    bool boatInSight = std::any_of(begin_perceived(), end_perceived(), [this](const auto &a) {
                        return typeid(a).name() == typeid(kmint::pigisland::boat).name() &&
                               math::distance(a.location(), this->location()) <= 50;
                    });

                    if (boatInSight) {
                        setState(new scared(this));
                    }
                }
            }
        }

        void shark::setTint(graphics::color color) {
            drawable_.set_tint(color);
        }

        void shark::eatPig() {
            if (!getState()->canEatPig()) return;

            for (auto it = begin_collision(); it != end_collision(); ++it) {
                auto piggie = dynamic_cast<pig *>(it.operator->());
                if (piggie != nullptr)
                    piggie->gotEaten();
            }
        }

        void shark::reset() {
            setState(new shark_wandering(this));
            isDone = false;
        }

        void shark::rest() {
            stepsMade = 0;
            isDone = true;
        }

    } // namespace pigisland
} // namespace kmint
