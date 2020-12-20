//
// Created by Danny on 20-12-2020.
//

#include <kmint/pigisland/reapair_places/repair_place_factory.hpp>
#include <kmint/pigisland/reapair_places/graaneiland.hpp>
#include <kmint/pigisland/reapair_places/graseiland.hpp>
#include <kmint/pigisland/reapair_places/boomeiland.hpp>

namespace kmint {
    namespace pigisland {
        std::unique_ptr<repair_place> repair_place_factory::getRepairPlace(int symbol) {
            switch (symbol) {
                case 1:
                    return std::make_unique<graaneiland>();

                case 2:
                    return std::make_unique<graseiland>();

                case 3:
                    return std::make_unique<boomeiland>();

                default:
                    return nullptr;
            }
        }
    }
}
