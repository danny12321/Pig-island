#include <kmint/pigisland/state/go_to_repair_place.hpp>
#include <kmint/pigisland/pig.hpp>
#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/state/wandering.hpp"
#include "kmint/random.hpp"

namespace kmint {
    namespace pigisland {
        boat::boat(map::map_graph &g, map::map_node &initial_node) : context(g, initial_node),
                                                                     drawable_{*this, graphics::image{boat_image()}} {

            setState(new wandering(this));
        }

        void boat::act(delta_time dt) {
            t_passed_ += dt;
            get_pigs_onboard();

            if (to_seconds(t_passed_) >= 1) {
                activeState->execute(dt);

                if (damage < 100) {
                    ++damage;
                    if (damage == 100)
                        setState(new go_to_repair_place(this));
                }
                t_passed_ = from_seconds(0);
            }
        }

        void boat::setTint(graphics::color color) {
            drawable_.set_tint(color);
        }

        void boat::repair(int amount) {
            damage -= amount;
            std::cout << "repair boat " << amount << std::endl;

        }

        void boat::get_pigs_onboard() {
            for(auto it = begin_collision(); it != end_collision(); ++it) {
                auto piggie = dynamic_cast<pig *>(it.operator->());
                if(piggie != nullptr)
                    piggie->remove();
            }
        }

    } // namespace pigisland
} // namespace kmint
