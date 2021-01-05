//
// Created by Danny on 20-12-2020.
//

#include <kmint/ui.hpp>
#include <kmint/pigisland/factors.hpp>
#include "kmint/pigisland/simulation.hpp"
#include "kmint/main.hpp" // voor de main loop
#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/pigisland/simulation_result.hpp"

namespace kmint {
    namespace pigisland {

        simulation::simulation(play::stage &stage, kmint::pigisland::boat &boat, kmint::pigisland::shark &shark) : stage(stage) {
            auto locs = pigisland::random_pig_locations(100);
            for (auto loc : locs) {
                factors factor{};
                auto &pig = stage.build_actor<pigisland::pig>(loc, boat, shark, factor);
                pigs.push_back(&pig);
            }
        }

        simulation::~simulation() {
            for(auto &pig : pigs)
                stage.remove_actor(*pig);
        }



        simulation_result simulation::get_simulation_result() {
            return simulation_result{*this};
        }
    }
}