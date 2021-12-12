#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "LoadShaders.h"

#define BUFFER_OFFSET(a) ((void*)(a))

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

using namespace std;

void init() {
    cout << "Start to call init" << endl;
    static const GLfloat vertices[NumVertices][2] = {
        { -0.90, -0.90 },
        { 0.85, -0.90 },
        { -0.90, 0.85 },
        { 0.90, -0.85 },
        { -0.90, 0.90 },
        { 0.85, 0.90 }
    };
    glCreateBuffers(NumBuffers, Buffers);
    glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);

    ShaderInfo shaders[] = {
        { GL_VERTEX_SHADER, "triangles.vert" },
        { GL_FRAGMENT_SHADER, "triangles.frag" },
        { GL_NONE, NULL }
    };

    GLuint program = LoadShaders(shaders);
    glUseProgram(program);

    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
    return;
}

void display() {
    static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    glClearBufferfv(GL_COLOR, 0, black);
    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    return;
}

int main(int argc, char *argv[])
{
    GLFWwindow* window;

    glewExperimental = true;
    if (!glfwInit()) {
        cout << "init failed" << endl;
        return -1;
    }
    else {
        cout << "init successfully" << endl;
    }
 
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(640, 480, "HelloWorld", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        cout << "glew init error" << endl;
    }
    else {
        cout << "glew init successfully" << endl;
    }

    init();

    while(!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();

    return 0;
}
