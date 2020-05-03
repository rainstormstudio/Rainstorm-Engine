#include "WindowManager.hpp"

WindowManager::WindowManager() {
  width = 800;
  height = 600;
}

int WindowManager::initialize(const char *windowTitle, GLint windowWidth, GLint windowHeight) {
  width = windowWidth;
  height = windowHeight;
  
  if (!glfwInit()) {
    std::cout << "GLFW initialization failed!" << std::endl;
    glfwTerminate();
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
  if (!window) {
    std::cout << "GLFW window creation failed!" << std::endl;
    glfwTerminate();
    return 1;
  }

  glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW initialization failed!" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  glEnable(GL_DEPTH_TEST);

  glViewport(0, 0, bufferWidth, bufferHeight);
  glfwSetWindowUserPointer(window, this);

  return 0;
}

GLfloat WindowManager::getBufferWidth() {
  return bufferWidth;
}

GLfloat WindowManager::getBufferHeight() {
  return bufferHeight;
}

bool WindowManager::getShouldClose() {
  return glfwWindowShouldClose(window);
}

void WindowManager::update() {
  glfwSwapBuffers(window);
}

void WindowManager::processEvents() {
  glfwPollEvents();
}

void WindowManager::destroy() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

WindowManager::~WindowManager() {
  destroy();
}
