//
// Created by Danny on 20-12-2020.
//

#include <kmint/pigisland/state/go_to_repair_place.hpp>
#include <kmint/pigisland/reapair_places/repair_place_factory.hpp>
#include <kmint/pigisland/state/wandering.hpp>
#include <kmint/pigisland/boat.hpp>

namespace kmint {
    namespace pigisland {
        void go_to_repair_place::execute(kmint::delta_time dt) {
            auto nextNode = tomtom->getNextNode();
            if (nextNode != nullptr) {
                context->node(*nextNode);
            }

            if (context->node().node_id() == repairPlace->node_id()) {
                auto b = dynamic_cast<boat*>(context);
                if(b != nullptr)
                    b->repair(repairPlace);

                context->setState(new wandering(context));
            }
        }

        go_to_repair_place::go_to_repair_place(kmint::pigisland::context *context) : state(context) {
            auto boat = dynamic_cast<pigisland::boat *>(context);
            if(boat != nullptr) {
                repairPlace = boat->get_repair_place();
                std::cout << "Boat is going to repair at " << repairPlace->get_name() << std::endl;
                tomtom = std::make_unique<navigation>(&context->graph, &context->node(), &context->graph[repairPlace->node_id()]);
            } else {
                std::cout << "Only boats can go to the repair shop! Setting new state to wandering" << std::endl;
                context->setState(new wandering(context));
            }
        }
    }
}