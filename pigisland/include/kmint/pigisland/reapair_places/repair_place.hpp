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

            int get_avg_repair() const {
                return total_repair_points_given / repairs_given;
            }

            int getRepairAmount() {
                int repair_points = random_int(min_repair(), max_repair() + 1);
                repairs_given++;
                total_repair_points_given += repair_points;
                return repair_points;
            }

            virtual std::string get_name() const = 0;

        private:
            int total_repair_points_given = 50;

            int repairs_given = 1;
        };
    }
}

#endif //PIGISLAND_REPAIR_PLACE_HPP
