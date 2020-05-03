#include "Game.hpp"

Game::Game() {
  this->mIsRunning = false;
}

void Game::initialize(int initWidth, int initHeight) {
  mainWindow.initialize("Rainstorm", initWidth, initHeight);
  mIsRunning = true;
  timer = new Timer();
}

bool Game::isRunning() {
  return this->mIsRunning;
}

void Game::processEvent() {
  mainWindow.processEvents();
  mIsRunning = !mainWindow.getShouldClose();
}

void Game::render() {
  mainWindow.update();
}

void Game::update() {
  timer->update();
  timer->frameControl();
}

void Game::destroy() {
  mainWindow.destroy();
}

Game::~Game() {

}
