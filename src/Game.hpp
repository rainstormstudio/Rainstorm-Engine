#pragma once
#include "Timer.hpp"
#include "WindowManager.hpp"

class Game {
private:
  bool mIsRunning;
  Timer *timer;
  WindowManager mainWindow;

public:
  Game();

  bool isRunning();
  void initialize(int initWidth, int initHeight);
  void processEvent();
  void update();
  void render();
  void destroy();

  ~Game();
};
