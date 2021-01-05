//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_ALIGNMENT_FLOCK_HPP
#define PIGISLAND_ALIGNMENT_FLOCK_HPP

#include "iforce.hpp"

namespace kmint {
    namespace pigisland {
        class alignment_flock : public iforce {
        public:
            explicit alignment_flock(force_driven_entity& entity, const factor &force_factor) : iforce(entity, force_factor) {};
            [[nodiscard]] math::vector2d getSteering() const override;
        };
    }
}

#endif //PIGISLAND_ALIGNMENT_FLOCK_HPP
