//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_SEPARATION_FLOCK_HPP
#define PIGISLAND_SEPARATION_FLOCK_HPP

#include "iflock.hpp"

namespace kmint {
    namespace pigisland {
        class separation_flock : public iflock {
        public:
            explicit separation_flock(force_driven_entity& entity) : iflock(entity) {};
            [[nodiscard]] math::vector2d getSteering() const override;
        };
    }
}

#endif //PIGISLAND_SEPARATION_FLOCK_HPP
