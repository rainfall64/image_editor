#include <iostream>
#include <memory.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Window 1"
#define WINDOW_FULL_SCREEN NULL
#define WINDOW_CONTEXT_SHARE NULL


void render_loop();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    glfwInit();

    // glfw version-> 4.6 (major.minor)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // makes window non resizable
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, WINDOW_FULL_SCREEN, WINDOW_CONTEXT_SHARE);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );
    
    glfwSetWindowOpacity(window, 0.80);

    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        processInput( window );

        // rendering goes here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear( GL_COLOR_BUFFER_BIT );

        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
