//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_REPAIR_PLACE_HPP
#define PIGISLAND_REPAIR_PLACE_HPP

#include <kmint/random.hpp>

namespace kmint {
    namespace pigisland {
        class repair_place {
        public:
            virtual int symbol() = 0;

            virtual int min_repair() = 0;

            virtual int max_repair() = 0;

            virtual int node_id() = 0;

            int getRepairAmount() {
                return random_int(min_repair(), max_repair() + 1);
            }
        };
    }
}

#endif //PIGISLAND_REPAIR_PLACE_HPP
