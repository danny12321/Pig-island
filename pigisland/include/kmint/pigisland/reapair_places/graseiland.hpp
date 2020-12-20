//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_GRASEILAND_HPP
#define PIGISLAND_GRASEILAND_HPP

#include "repair_place.hpp"

namespace kmint {
    namespace pigisland {
        class graseiland : public repair_place {
        public:
            int symbol() override { return 2; };

            int min_repair() override { return 20; };

            int max_repair() override { return 100; };

            int node_id() override { return 128; };

        };
    }
}

#endif //PIGISLAND_GRASEILAND_HPP
