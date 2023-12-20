#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int width = 1920;
const int height = 1080;

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(width, height, "Delaunay", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Error creating window!";
        glfwTerminate();
        return -1;
    }

    const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (vidmode->width - width) / 2, (vidmode->height - height) / 2);

    glfwMakeContextCurrent(window);
    glfwShowWindow(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::clog << "OpenGL: " << glGetString(GL_VERSION) << "\n";

    glClearColor(0.3f, 0.5f, 0.5f, 1.0f);

    int fps = 0;
    double frameTime = glfwGetTime(), currentTime;

    while (!glfwWindowShouldClose(window)) {
        fps += 1;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        currentTime = glfwGetTime();

        if (currentTime - frameTime >= 1.0) {
            std::cout << fps << " fps\n";
            fps = 0, frameTime = currentTime;
        }
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}
