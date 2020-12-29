//
// Created by Danny on 21/12/2020.
//

#ifndef PIGISLAND_FACTORS_HPP
#define PIGISLAND_FACTORS_HPP

#include <cassert>
#include <kmint/random.hpp>
#include <iostream>

namespace kmint {
    namespace pigisland {
        class factor {
        public:
            factor(float value, float min, float max) {
                assert(min < max);
                assert(value >= min);
                assert(value <= max);
                this->min = min;
                this->value = value;
                this->max = max;
            }

            factor(float min, float max) {
                assert(min < max);
                this->min = min;
                this->value = random_scalar(min, max);
                this->max = max;
            }

            factor(const factor &f) {
                this->min = f.get_min();
                this->value = f.get_value();
                this->max = f.get_max();
            }

            explicit factor(float value) {
                this->value = value;
            }

            void set_factor(float value) {
                assert(value >= min);
                assert(value <= max);

                this->value = value;
            }

            [[nodiscard]] float get_min() const { return min; }

            [[nodiscard]] float get_value() const { return value; }

            [[nodiscard]] float get_max() const { return max; }

            void log() {
                std::cout << value << " out of " << min << "/" << max << "\n";
            }

        private:
            float min;
            float value;
            float max;
        };

        class factors {
        public:
            factors(float separation, float coherence, float alignment, float shark_attraction, float boat_attraction) {
                this->separation.set_factor(separation);
                this->coherence.set_factor(coherence);
                this->alignment.set_factor(alignment);
                this->shark_attraction.set_factor(shark_attraction);
                this->boat_attraction.set_factor(boat_attraction);
            };

            factors(const factors &f) {
                separation = factor{f.separation};
                coherence = factor{f.coherence};
                alignment = factor{f.alignment};
                shark_attraction = factor{f.shark_attraction};
                boat_attraction = factor{f.boat_attraction};
            }

            factors() = default;

            [[nodiscard]] factor get_separation_factor() const { return separation; };

            [[nodiscard]] factor get_coherence_factor() const { return coherence; };

            [[nodiscard]] factor get_alignment_factor() const { return alignment; };

            [[nodiscard]] factor get_shark_attraction_factor() const { return shark_attraction; };

            [[nodiscard]] factor get_boat_attraction_factor() const { return boat_attraction; };


            void log() {
                std::cout << "Separation: ";
                separation.log();

                std::cout << "Coherence: ";
                coherence.log();

                std::cout << "Alignment: ";
                alignment.log();

                std::cout << "Shark attraction: ";
                shark_attraction.log();

                std::cout << "Boat attraction: ";
                boat_attraction.log();
            }

        private:
            factor separation{0, 1};
            factor coherence{0, 1};
            factor alignment{0, 1};
            factor shark_attraction{-1, 1};
            factor boat_attraction{-1, 1};
        };
    }
}

#endif //PIGISLAND_FACTORS_HPP
