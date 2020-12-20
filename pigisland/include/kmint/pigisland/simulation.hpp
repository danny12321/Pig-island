//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_SIMULATION_HPP
#define PIGISLAND_SIMULATION_HPP

#include <kmint/ui/window.hpp>
#include <kmint/play/stage.hpp>
#include <kmint/map/map.hpp>
#include <kmint/main.hpp>

namespace kmint {
    namespace pigisland {
        class simulation {
        public:
            simulation();
            void run(kmint::ui::window &window);

        private:
            play::stage stage;
            map::map map;

            void handleEvents(loop_controls &ctl);

        };
    }
}

#endif //PIGISLAND_SIMULATION_HPP
