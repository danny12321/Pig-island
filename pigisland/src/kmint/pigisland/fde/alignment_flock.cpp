//
// Created by Danny on 18-12-2020.
//

#include <kmint/pigisland/fde/alignment_flock.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>
#include <kmint/pigisland/pig.hpp>

namespace kmint {
    namespace pigisland {
        math::vector2d alignment_flock::getSteering() const {
            float alignmentFactor = .1;
            if (entity.num_perceived_actors() <= 0) return {0, 0};

            math::vector2d avgDirection{0, 0};
            int total = 0;

            for (auto i = entity.begin_perceived(); i != entity.end_perceived(); ++i) {
                auto piggie = dynamic_cast<pig *>(i.operator->());

                if (piggie != nullptr) {
                    total++;
                    avgDirection += math::vector2d{
                            piggie->getVelocity().x(),
                            piggie->getVelocity().y()
                    };
                }
            }

            if (total <= 0) return {0, 0};

            return {
                    ((avgDirection.x() / total) - entity.getVelocity().x()) * alignmentFactor,
                    ((avgDirection.y() / total) - entity.getVelocity().y()) * alignmentFactor
            };
        }
    }
}