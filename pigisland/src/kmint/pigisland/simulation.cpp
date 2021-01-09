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
                factors factor{}; // create a random set of factors for every pig
                auto &pig = stage.build_actor<pigisland::pig>(loc, boat, shark, factor);
                pigs.push_back(&pig);
            }
        }

        void simulation::log_result() {
            std::cout << "Simulation result \n\nPig amount " << pigs.size() << "\n";

            std::sort(pigs.begin(), pigs.end(), [](const pig *pig1, const pig *pig2) { return pig1->get_time_survived() > pig2->get_time_survived();});

            std::cout << "Best pig stats: \n";
            std::cout << "Time survived: " << pigs[0]->get_time_survived() << " seconds\n";
            pigs[0]->get_factors().log();

            std::cout << "\nWorst pig stats: \n";
            std::cout << "Time survived: " << pigs[0 + pigs.size() -1]->get_time_survived() << " seconds\n";
            pigs[0 + pigs.size() -1]->get_factors().log();

            std::cout << std::endl;
        }

        simulation::~simulation() {
            for(auto &pig : pigs)
                stage.remove_actor(*pig);
        }
    }
}