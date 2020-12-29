//
// Created by Danny on 18-12-2020.
//

#ifndef PIGISLAND_FOLLOW_ACTOR_HPP
#define PIGISLAND_FOLLOW_ACTOR_HPP

#include "iflock.hpp"

namespace kmint {
    namespace pigisland {
        class follow_actor : public iflock {
        public:
            explicit follow_actor(force_driven_entity& entity, play::actor &actor, const factor &force_factor) : iflock(entity, force_factor), actor(actor) {};
            [[nodiscard]] math::vector2d getSteering() const override;

        private:
            play::actor &actor;
        };
    }
}

#endif //PIGISLAND_FOLLOW_ACTOR_HPP
