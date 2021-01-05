//
// Created by Danny on 20-12-2020.
//

#ifndef PIGISLAND_GO_TO_REPAIR_PLACE_HPP
#define PIGISLAND_GO_TO_REPAIR_PLACE_HPP

#include <kmint/pigisland/reapair_places/repair_place.hpp>
#include <kmint/pigisland/navigation.hpp>
#include "state.hpp"

namespace kmint {
    namespace pigisland {
        class go_to_repair_place : public state {
        public:
            go_to_repair_place(class context *context);

            void execute(delta_time dt) override;

            bool canEatPig() override {return false;};

        private:
            std::shared_ptr<repair_place> repairPlace;
            std::unique_ptr<navigation> tomtom;
        };
    }
}

#endif //PIGISLAND_GO_TO_REPAIR_PLACE_HPP
