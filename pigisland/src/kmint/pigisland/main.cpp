#include "kmint/main.hpp" // voor de main loop
#include "kmint/pigisland/simulation.hpp"
#include "kmint/ui.hpp"

using namespace kmint;

int main() {
    // een app object is nodig om
    ui::app app{};

    //  maak een venster aan
    ui::window window{app.create_window({1024, 768}, "pigisland", 1.0)};

    kmint::pigisland::simulation().run(window);
}
