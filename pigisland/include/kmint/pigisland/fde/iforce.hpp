//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_IFORCE_HPP
#define PIGISLAND_IFORCE_HPP

#include <kmint/pigisland/factors.hpp>
#include "kmint/play.hpp"

namespace kmint {
    namespace pigisland {
        class force_driven_entity;

        class iforce {
        public:
            explicit iforce(force_driven_entity &entity, const factor &force_factor) : entity(entity),
                                                                                       force_factor(force_factor) {
            }

            [[nodiscard]] virtual math::vector2d getSteering(delta_time dt) const = 0;

        protected:
            const factor force_factor;
            force_driven_entity &entity;
        };
    }
}

#endif //PIGISLAND_IFORCE_HPP
