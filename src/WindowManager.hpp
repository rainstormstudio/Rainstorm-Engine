#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class WindowManager {
private:
  GLFWwindow *window;
  GLint width = 800, height = 600;
  GLint bufferWidth, bufferHeight;

public:
  WindowManager();
  
  int initialize(const char* windowTitle, GLint windowWidth, GLint windowHeight);
  GLfloat getBufferWidth();
  GLfloat getBufferHeight();
  bool getShouldClose();
  void update();
  void processEvents();
  void destroy();

  ~WindowManager();
};
