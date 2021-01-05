//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_REPAIR_PLACE_FACTORY_HPP
#define PIGISLAND_REPAIR_PLACE_FACTORY_HPP

#include <memory>
#include <vector>
#include "repair_place.hpp"

namespace kmint {
    namespace pigisland {
        class repair_place_factory {
        public:
            repair_place_factory();
            std::shared_ptr<repair_place> getRepairPlace();

        private:
            std::vector<std::shared_ptr<repair_place>> repair_places;
        };
    }
}

#endif //PIGISLAND_REPAIR_PLACE_FACTORY_HPP
