//
// Created by Danny on 22/12/2020.
//

#ifndef PIGISLAND_SIMULATION_RESULT_HPP
#define PIGISLAND_SIMULATION_RESULT_HPP

#include <vector>
#include "pig.hpp"
#include "simulation.hpp"

namespace kmint {
    namespace pigisland {
        class simulation_result {
        public:
            explicit simulation_result(simulation &simulation);

            void log() const;

            factors get_factor(int index);

        private:
            std::vector<pig*> pigs;
            std::vector<factors> pig_factors;
            int survived = 0;
            float avg_time_survived = 0;
            int pig_amount = 0;
        };
    }
}

#endif //PIGISLAND_SIMULATION_RESULT_HPP
