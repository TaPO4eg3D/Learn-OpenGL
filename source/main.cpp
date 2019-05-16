#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, 800, 600);
}

void proccesInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Our very basic shaders
const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


int main(){
    // Initialize glfw and set openGL version
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a new Window and pray for success
    GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create a window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Loading GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport for OpenGL
    glViewport(0, 0, 800, 600);

    // User can change the window, so register a callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // ==================
    // Drawing a triangle
    // ==================

    // Defining vertices
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    // Creating a buffer
    GLuint VBO;
    glGenBuffers(1, &VBO);
    // Binding
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Sending data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Generating shaders
    GLenum vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Attach the shader source code
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader); // compiling shader

    // Checking for compiling errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog){

        }
    }

    while(!glfwWindowShouldClose(window)){
        // Listen for input
        proccesInput(window);

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Manage screen updating
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate the GLFW session
    glfwTerminate();

    // Return a success finish
    return 0;
}
