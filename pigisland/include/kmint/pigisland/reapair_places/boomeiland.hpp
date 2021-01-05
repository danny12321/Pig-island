//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_BOOMEILAND_HPP
#define PIGISLAND_BOOMEILAND_HPP

#include "repair_place.hpp"

namespace kmint {
    namespace pigisland {
        class boomeiland : public repair_place {
        public:
            int symbol() override { return 3; };

            int min_repair() override { return 50; };

            int max_repair() override { return 50; };

            int node_id() override { return 526; }

            std::string get_name() const override {
                return "Boomeiland";
            };
        };
    }
}

#endif //PIGISLAND_BOOMEILAND_HPP
