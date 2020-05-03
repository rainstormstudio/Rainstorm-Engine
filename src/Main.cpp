#include "Constants.hpp"
#include "Game.hpp"

int main(int argc, char *argv[]) {
  Game *game = new Game();
  game->initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

  while (game->isRunning()) {
    game->processEvent();
    game->update();
    game->render();
  }

  game->destroy();
  
  return 0;
}
