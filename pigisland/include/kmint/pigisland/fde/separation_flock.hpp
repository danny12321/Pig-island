//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_SEPARATION_FLOCK_HPP
#define PIGISLAND_SEPARATION_FLOCK_HPP

#include "iforce.hpp"

namespace kmint {
    namespace pigisland {
        class separation_flock : public iforce {
        public:
            explicit separation_flock(force_driven_entity& entity, const factor &force_factor) : iforce(entity, force_factor) {};
            [[nodiscard]] math::vector2d getSteering(delta_time dt) const override;
        };
    }
}

#endif //PIGISLAND_SEPARATION_FLOCK_HPP
