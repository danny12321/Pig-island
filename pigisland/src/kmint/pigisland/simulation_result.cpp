//
// Created by Danny on 22/12/2020.
//

#include "kmint/pigisland/simulation_result.hpp"

namespace kmint {
    namespace pigisland {
        kmint::pigisland::simulation_result::simulation_result(kmint::pigisland::simulation &simulation) {
//            auto &stage = simulation.get_stage();
//
//            for (auto it = stage.begin(); it != stage.end(); it++) {
//                auto piggie = dynamic_cast<pig *>(it.operator->());
//                if (piggie != nullptr) {
//                    if (piggie->survived()) survived++;
//                    pig_amount++;
//                    pigs.emplace_back(piggie);
//                    pig_factors.push_back(piggie->get_factors());
//                    avg_time_survived += piggie->get_time_survived();
//                }
//            }
//
//            avg_time_survived /= pig_amount;
//
//            std::sort(pigs.begin(), pigs.end(),
//                      [](const pig *p, const pig *p2) { return p->get_time_survived() > p2->get_time_survived(); });
        }

        void simulation_result::log() const {
            std::cout << "Pig amount " << pig_amount << "\n";

            std::cout << "Best pig stats: \n";
            std::cout << "Time survived: " << pigs[0]->get_time_survived() << " seconds\n";
            pigs[0]->get_factors().log();

            std::cout << "\nWorst pig stats: \n";
            std::cout << "Time survived: " << pigs[0 + pigs.size() -1]->get_time_survived() << " seconds\n";
            pigs[0 + pigs.size() -1]->get_factors().log();

            std::cout << std::endl;
        }

        factors simulation_result::get_factor(int index) {
            return pig_factors.at(index);
        }
    }
}