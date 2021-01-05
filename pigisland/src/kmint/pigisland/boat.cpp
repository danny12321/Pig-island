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
                                                                     drawable_{*this,
                                                                               graphics::image{boat_image()}} {
            setState(new wandering(this));
        }

        void boat::act(delta_time dt) {
            t_passed_ += dt;
            get_pigs_onboard();

            float period = 1;

            // if the boat is in rocks the period is 4 times longer
            if (this->node().node_info().kind == 'R') period *= 4;

            if (to_seconds(t_passed_) >= period) {
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

        void boat::repair(const std::shared_ptr<repair_place>& repair_place) {
            int repair_points = repair_place->getRepairAmount();
            damage -= repair_points;
            std::cout << "Repair boat " << repair_points << " points, at: " << repair_place->get_name() << ", current damage points is " << damage << "\n" << std::endl;
        }

        void boat::get_pigs_onboard() {
            for (auto it = begin_collision(); it != end_collision(); ++it) {
                auto piggie = dynamic_cast<pig *>(it.operator->());
                if (piggie != nullptr)
                    piggie->get_onboard_boat();
            }
        }

        std::shared_ptr<repair_place> boat::get_repair_place() {
            return repair_factory.getRepairPlace();
        }

    } // namespace pigisland
} // namespace kmint
