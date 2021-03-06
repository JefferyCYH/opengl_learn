#include<iostream>
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>


float vertices[] = {
    -0.5f, -0.5f, 0.0f,//0
     0.5f, -0.5f, 0.0f,//1
     0.0f,  0.5f, 0.0f,//2
     /*0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,*/
     0.8f,  0.8f, 0.0f//3

};

unsigned int indices[] = { // 注意索引从0开始! 
    0, 1, 2, // 第一个三角形
    2, 1, 3  // 第二个三角形
};



const char* vertexShaderSource =
"#version 330 core                                      /n  "
"layout(location = 0) in vec3 aPos;                     /n  "
"void main(){                                           /n  "
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}   /n  ";

const char* fragmentShaderSource =
"#version 330 core                                /n   "
"out vec4 FragColor;                              /n   "
"void main() {                                    /n   "
"   FragColor = vec4(0.3f, 0.5f, 0.5f, 1.0f);}    /n   ";

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // openglfw window
    GLFWwindow* window = glfwCreateWindow(800, 600,"my opengl", NULL, NULL);
    if (window == NULL)
    {
        printf("open window fail");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // init glew
    glewExperimental = true;
    if (glewInit()!=GLEW_OK)
    {
        printf("init glew failed");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);

    //背面不画
   /* glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);*/


    // loop
    //创建VAO,VBO并绑定
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //传数据
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //EBO
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    
    //vertexshader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //fragmentshader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //shaderprogram
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        
        glUseProgram(shaderProgram);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }

    glfwTerminate();
    return 0;


}

