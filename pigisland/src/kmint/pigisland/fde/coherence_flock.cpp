#include <kmint/pigisland/fde/coherence_flock.hpp>
#include <kmint/pigisland/fde/force_driven_entity.hpp>

namespace kmint {
    namespace pigisland {
        math::vector2d coherence_flock::getSteering() const {
            float coherenceFactor = .8;
            int coherenceView = 25;

            // we can't see any friends
            if (entity.num_perceived_actors() <= 0) return {0, 0};

            math::vector2d center{0, 0};
            int total = 0;

            for (auto i = entity.begin_perceived(); i != entity.end_perceived(); ++i) {
                if (math::distance(i->location(), entity.location()) < coherenceView) {
                    total++;
                    center += i->location();
                }
            }

            center = math::vector2d{center.x() / total, center.y() / total};
            if (total <= 0) return {0, 0};
            return {
                    (center.x() - entity.location().x()) * coherenceFactor,
                    (center.y() - entity.location().y()) * coherenceFactor,
            };
        }
    }
}