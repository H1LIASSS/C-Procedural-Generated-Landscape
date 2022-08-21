#include <iostream>

#include "Landscape.h"
#include "Shader.h"

using namespace std;


void projectInit()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void windowInit(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

int main()
{   
    projectInit();
    int w = 640, h = 640;
    GLFWwindow* window = glfwCreateWindow(640, 640, "ProceduralGeneration ddgen", NULL, NULL);
    windowInit(window, w, h);

    Shader shader;
    Landscape lnd(1024);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.getShaderProgram());
        glBindVertexArray(lnd.getVAO());
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, lnd.getVertecies(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


//TODO  
//
//vertex shader import
//fragment shader import
//
//
//
//
//
//
//
//
//
/////////////////////////