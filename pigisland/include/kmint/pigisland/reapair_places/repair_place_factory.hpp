//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_REPAIR_PLACE_FACTORY_HPP
#define PIGISLAND_REPAIR_PLACE_FACTORY_HPP

#include <memory>
#include "repair_place.hpp"

namespace kmint {
    namespace pigisland {
        class repair_place_factory {
        public:
            std::unique_ptr<repair_place> getRepairPlace(int symbol);
        };
    }
}

#endif //PIGISLAND_REPAIR_PLACE_FACTORY_HPP
