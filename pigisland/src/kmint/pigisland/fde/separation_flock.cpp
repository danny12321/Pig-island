//
// Created by Danny on 18-12-2020.
//

#include <kmint/pigisland/fde/separation_flock.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>

namespace kmint {
    namespace pigisland {
        math::vector2d separation_flock::getSteering() const {
            float separationFactor = 1.5;
            // we can't see any friends
            if (entity.num_perceived_actors() <= 0) return {0, 0};

            math::vector2d move{0, 0};
            int separationView = 25;

            for (auto i = entity.begin_perceived(); i != entity.end_perceived(); ++i) {
                // get velocity instead of location
                if (math::distance(i->location(), entity.location()) < separationView) {
                    move += math::vector2d{
                            entity.location().x() - i->location().x(),
                            entity.location().y() - i->location().y()
                    };
                }
            }

            return {
                    move.x() * separationFactor,
                    move.y() * separationFactor,
            };
        }
    }
}