#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

// Defining window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{

  // Initialize GLFW
  if(!glfwInit())
  {
    std::cout << "Initialization failed.\n";
    glfwTerminate();
    return 1; // error
  }

  // Setup GLFW window properties
  // OpenGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Core profile means no backwards compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Allow forward compatibiliy
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Create glfw window
  // Params: width, heigh, title, multi monitors, shared across systems
  GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
  if(!mainWindow)
  {
    std::cout << "GLFW window creation failed.\n";
    glfwTerminate();
    return 1;
  }

  // Set buffer size information
  // After window creation, need area in the window = buffer
  // Buffer holds all the openGL data that is being drawn to
  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

  // Set context for GLEW to use (could switch between windows)
  glfwMakeContextCurrent(mainWindow);

  // Allow modern extension features (enable glew experimental)
  glewExperimental = GL_TRUE;

  // Initialize glew
  if(glewInit() != GLEW_OK)
  {
    std::cout << "GLEW initialization failed.\n";
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    return 1;
  }

  // Set up viewport size
  glViewport(0, 0, bufferWidth, bufferHeight);

  // Loop until window closed
  while(!glfwWindowShouldClose(mainWindow))
  {
    // Get & handle user input events
    glfwPollEvents();

    // clear window
    glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mainWindow);
  }

  return 0;
}