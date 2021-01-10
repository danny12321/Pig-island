#include <kmint/pigisland/resources.hpp>
#include <kmint/pigisland/node_algorithm.hpp>
#include "kmint/main.hpp" // voor de main loop
#include "kmint/pigisland/simulation.hpp"
#include "kmint/ui.hpp"

using namespace kmint;

int main() {
    // een app object is nodig om
    ui::app app{};

    //  maak een venster aan
    ui::window window{app.create_window({1024, 768}, "pigisland", 1.0)};

    // maak een podium aan
    play::stage s{{1024, 768}};

    auto map = pigisland::map();
    auto &graph = map.graph();
    s.build_actor<play::background>(math::size(1024, 768), graphics::image{map.background_image()});
    s.build_actor<play::map_actor>(math::vector2d{0.f, 0.f}, map.graph());
    auto &boat = s.build_actor<pigisland::boat>(map.graph(), pigisland::find_node_of_kind(map.graph(), '1'));
    auto &shark = s.build_actor<pigisland::shark>(map.graph(), pigisland::find_node_of_kind(map.graph(), 'K'));

    bool running = true;

    ui::events::event_source event_source{};

    while (running) {
        kmint::pigisland::simulation sim{s, boat, shark};
        shark.reset();

        main_loop(s, window, [&](delta_time dt, loop_controls &ctl) {

            if(shark.getIsDone()) ctl.quit = true;

            for (ui::events::event &e : event_source) {
                e.handle_quit([&ctl, &running](ui::events::quit_event qe) {
                    ctl.quit = true;
                    running = false;
                });
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
        });

        sim.log_result();
    }
}
