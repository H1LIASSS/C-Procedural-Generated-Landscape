#include <iostream>

#include "Landscape.h"

using namespace std;

const GLchar* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 460 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";


GLuint shaderProgram;
void shadersStuff()
{
   
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Link shaders
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

int main()
{   
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window;
    int width = 640, height = 640;
    window = glfwCreateWindow(width, height, "ProceduralGeneration ddgen", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    shadersStuff();

    //GLuint t[144];
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint) * 144, t);
    //for (int i = 0; i < 142; i+=3)
    //    cout << t[i] << ',' << t[i + 1] << ',' << t[i + 2] << endl;
    //cout << endl;

    //Point3 z[36];
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glGetBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Point3) * 36, z);
    //
    //for (int i = 0; i < 36; i++)
    //    cout << z[i].x << ',' << z[i].y << endl;

    Landscape lnd(10);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(lnd.getVAO());
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, lnd.getTriangles(), GL_UNSIGNED_INT, 0);
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