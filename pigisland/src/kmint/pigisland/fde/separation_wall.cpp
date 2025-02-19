//
// Created by Danny on 18-12-2020.
//

#include <kmint/pigisland/fde/separation_wall.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>

namespace kmint {
    namespace pigisland {
        math::vector2d separation_wall::getSteering(delta_time dt) const {
            float lookingDistance = 10 + (to_seconds(dt) * 500);
            math::vector2d steering{0, 0};


            // vertical wall check
            if (abs(point1.x() - entity.location().x()) < lookingDistance &&
                ((entity.location().y() < point1.y() && entity.location().y() > point2.y()) ||
                 (entity.location().y() > point1.y() && entity.location().y() < point2.y()))) {

                if (entity.location().x() > point1.x()) steering += {lookingDistance, 0};
                else steering += {-lookingDistance, 0};
            }

            // horizontal wall check
            if (abs(point1.y() - entity.location().y()) < lookingDistance &&
                ((entity.location().x() < point1.x() && entity.location().x() > point2.x()) ||
                 (entity.location().x() > point1.x() && entity.location().x() < point2.x()))) {

                if (entity.location().y() > point1.y()) steering += {0,lookingDistance};
                else steering += {0, -lookingDistance};
            }

            return steering * force_factor.get_value();
        }
    }
}