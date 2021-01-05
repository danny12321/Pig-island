//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_GRAANEILAND_HPP
#define PIGISLAND_GRAANEILAND_HPP

#include "repair_place.hpp"

namespace kmint {
    namespace pigisland {
        class graaneiland : public repair_place {
        public:
            int symbol() override { return 1; };

            int min_repair() override { return 30; };

            int max_repair() override { return 50; };

            int node_id() override { return 0; }

            std::string get_name() const override {
                return "Graaneiland";
            };
        };
    }
}

#endif //PIGISLAND_GRAANEILAND_HPP
