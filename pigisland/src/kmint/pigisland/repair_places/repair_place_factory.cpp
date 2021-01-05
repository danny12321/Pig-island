//
// Created by Danny on 20-12-2020.
//

#include <kmint/pigisland/reapair_places/repair_place_factory.hpp>
#include <kmint/pigisland/reapair_places/graaneiland.hpp>
#include <kmint/pigisland/reapair_places/graseiland.hpp>
#include <kmint/pigisland/reapair_places/boomeiland.hpp>
#include <iostream>

namespace kmint {
    namespace pigisland {
        std::shared_ptr<repair_place> repair_place_factory::getRepairPlace() {
            int total_avg_repair = 0;
            std::cout << "Chances to go to repair place: ";

            for (const auto &place : repair_places) {
                total_avg_repair += place->get_avg_repair();
                std::cout << place->get_avg_repair() << " " << place->get_name() << " | ";
            }

            std::cout << " out of " << total_avg_repair << " points" << std::endl;

            int key = random_int(0, total_avg_repair);
            int points = 0;

            for (const auto &place : repair_places) {
                points += place->get_avg_repair();
                if (key < points) {
                    return place;
                }
            }

            std::cout << "Could not choose a proper repair place" << std::endl;
            return repair_places[0];
        }

        repair_place_factory::repair_place_factory() {
            repair_places.push_back(std::make_shared<graaneiland>());
            repair_places.push_back(std::make_shared<graseiland>());
            repair_places.push_back(std::make_shared<boomeiland>());
        }
    }
}
