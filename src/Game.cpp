#include "Game.hpp"

Game::Game() {
  this->mIsRunning = false;
}

void Game::initialize(int initWidth, int initHeight) {
  mainWindow.initialize("Rainstorm", initWidth, initHeight);
}

bool Game::isRunning() {
  return this->mIsRunning;
}

void Game::processEvent() {

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
