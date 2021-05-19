#include "Main.h"
Main::Main() {}
int main() {
        bool on = true;
        while(on){
            Game game = Game();
            on = !(game.updateGame());
        }
        return 0;
    }
