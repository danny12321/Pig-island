//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_SIMULATION_HPP
#define PIGISLAND_SIMULATION_HPP

#include <kmint/ui/window.hpp>
#include <kmint/play/stage.hpp>
#include <kmint/map/map.hpp>
#include <kmint/main.hpp>
#include "boat.hpp"
#include "shark.hpp"
#include "pig.hpp"

namespace kmint {
    namespace pigisland {
        class simulation_result;

        class simulation {
        public:
            simulation(play::stage &stage, kmint::pigisland::boat &boat, kmint::pigisland::shark &shark);
            ~simulation();

            [[nodiscard]] simulation_result get_simulation_result();


        private:
            play::stage &stage;
            std::vector<pig*> pigs;
        };
    }
}

#endif //PIGISLAND_SIMULATION_HPP
