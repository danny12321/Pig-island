//
// Created by Danny on 20-12-2020.
//

#include <kmint/ui.hpp>
#include "kmint/pigisland/simulation.hpp"
#include "kmint/main.hpp" // voor de main loop
#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/pig.hpp"
#include "kmint/pigisland/resources.hpp"

namespace kmint {
    namespace pigisland {

        simulation::simulation() : stage({1024, 768}), map(pigisland::map()) {
            stage.build_actor<play::background>(math::size(1024, 768),
                                                graphics::image{map.background_image()});
            stage.build_actor<play::map_actor>(math::vector2d{0.f, 0.f}, map.graph());
            auto &boat = stage.build_actor<pigisland::boat>(map.graph(),
                                                            pigisland::find_node_of_kind(map.graph(), '1'));
            auto &shark = stage.build_actor<pigisland::shark>(map.graph(),
                                                              pigisland::find_node_of_kind(map.graph(), 'K'));

            auto locs = pigisland::random_pig_locations(100);
            for (auto loc : locs) {
                stage.build_actor<pigisland::pig>(loc, boat, shark);
            }
        }

        void simulation::run(kmint::ui::window &window) {

            // main_loop stuurt alle actors aan.
            main_loop(stage, window, [&](delta_time dt, loop_controls &ctl) {
                // gebruik dt om te kijken hoeveel tijd versterken is
                // sinds de vorige keer dat deze lambda werd aangeroepen
                // loop controls is een object met eigenschappen die je kunt gebruiken om de
                // main-loop aan te sturen.

                handleEvents(ctl);
            });
        }

        void simulation::handleEvents(loop_controls &ctl) {
            ui::events::event_source event_source{};

            for (ui::events::event &e : event_source) {
                e.handle_quit([&ctl](ui::events::quit_event qe) { ctl.quit = true; });
                e.handle_key_up([&](auto ke) {
                    switch (ke.key) {
                        case ui::events::key::p:
                            ctl.pause = !ctl.pause;
                            break;
                        case ui::events::key::r:
                            ctl.render = !ctl.render;
                            break;
                        case ui::events::key::opening_bracket:
                            ctl.time_scale /= 2.0;
                            break;
                        case ui::events::key::closing_bracket:
                            ctl.time_scale *= 2.0;
                            break;
                        case ui::events::key::d:
                            ctl.debug_overlay = !ctl.debug_overlay;
                            break;
                        default:
                            break;
                    }
                });
            }
        }
    }
}