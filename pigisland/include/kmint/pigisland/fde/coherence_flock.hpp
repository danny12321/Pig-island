//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_COHERENCE_FLOCK_HPP
#define PIGISLAND_COHERENCE_FLOCK_HPP

#include "iforce.hpp"

namespace kmint {
    namespace pigisland {
        class coherence_flock : public iforce {
        public:
            explicit coherence_flock(force_driven_entity& entity, const factor &force_factor) : iforce(entity, force_factor) {};
            [[nodiscard]] math::vector2d getSteering(delta_time dt) const override;
        };
    }
}

#endif //PIGISLAND_COHERENCE_FLOCK_HPP
