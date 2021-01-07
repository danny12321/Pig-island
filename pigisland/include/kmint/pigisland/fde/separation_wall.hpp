//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_SEPARATION_WALL_HPP
#define PIGISLAND_SEPARATION_WALL_HPP

#include "iforce.hpp"

namespace kmint {
    namespace pigisland {
        class separation_wall : public iforce {
        public:
            explicit separation_wall(force_driven_entity& entity,math::vector2d point1,math::vector2d point2, const factor &force_factor) : iforce(entity, force_factor), point1(point1), point2(point2) {};
            [[nodiscard]] math::vector2d getSteering(delta_time dt) const override;

        private:
            math::vector2d point1;
            math::vector2d point2;
        };
    }
}

#endif //PIGISLAND_SEPARATION_WALL_HPP
