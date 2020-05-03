#include "Game.hpp"

Game::Game() {
    this->mIsRunning = false;
}

void Game::initialize(int initWidth, int initHeight) {

}

bool Game::isRunning() {
    return this->mIsRunning;
}

void Game::processEvent() {

}

void Game::render() {

}

void Game::update() {
    timer->update();
    timer->frameControl();
}

void Game::destroy() {

}

Game::~Game() {

}