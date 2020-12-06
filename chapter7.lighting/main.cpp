#include<iostream>
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "SHADER.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

//ģ������
#pragma region Model Data
GLfloat vertices[] = {
       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
       -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
       -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
       -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};
glm::vec3 cubePositions[] = {
   glm::vec3(0.0f,  0.0f,  0.0f),
   glm::vec3(2.0f,  5.0f, -15.0f),
   glm::vec3(-1.5f, -2.2f, -2.5f),
   glm::vec3(-3.8f, -2.0f, -12.3f),
   glm::vec3(2.4f, -0.4f, -3.5f),
   glm::vec3(-1.7f,  3.0f, -7.5f),
   glm::vec3(1.3f, -2.0f, -2.5f),
   glm::vec3(1.5f,  2.0f, -2.5f),
   glm::vec3(1.5f,  0.2f, -1.5f),
   glm::vec3(-1.3f,  1.0f, -1.5f)
};
#pragma endregion
//����ͷ����
#pragma region cameradeclare
//camera class
Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
#pragma endregion
//��������������
#pragma region INPUT
float LastX=400;
float LastY=300;
bool FirstMouse = true;

unsigned int indices[] = { // ע��������0��ʼ! 
    0, 1, 2, // ��һ��������
    2, 3, 0  // �ڶ���������
};


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.speedZ=0.1f;
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.speedZ=-0.1f;
    }
    else
    {
        camera.speedZ = 0;
    }



}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (FirstMouse)
    {
        LastX = xpos;
        LastY = ypos;
        FirstMouse = false;
    }

    float deltaX = xpos - LastX;
    float deltaY = ypos - LastY;
    LastX = xpos;
    LastY = ypos;

    camera.ProcessMouseMovement(deltaX, deltaY);
}
#pragma endregion

#pragma region LoadimagetoGPU
unsigned int  LoadimagetoGPU(const char* filename, GLint internelFormat,GLenum format,int textureSlot)
{
    unsigned int textureBuffer;
    glGenTextures(1, &textureBuffer);
    glActiveTexture(GL_TEXTURE0+ textureSlot);
    glBindTexture(GL_TEXTURE_2D, textureBuffer);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, internelFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("load img fail");
    }
    stbi_image_free(data);

    return textureBuffer;

}
#pragma endregion

int main()
{
 
#pragma region Open a window

    glEnable(GL_DEPTH_TEST);
    
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // openglfw window
    GLFWwindow* window = glfwCreateWindow(800, 600, "my opengl", NULL, NULL);
    if (window == NULL)
    {
        printf("open window fail");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetCursorPosCallback(window, mouse_callback);


    // init glew
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        printf("init glew failed");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);
 #pragma endregion


    Shader* testshader = new Shader("vertexSource.vert", "fragmentSource.frag");
    //���治��
   /* glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);*/

#pragma region init and load models to VAO,VBO
    // loop
    //����VAO,VBO����
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //������
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //EBO
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
#pragma endregion


    // λ������
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // ��ɫ����
    /*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);*/
    //��������
   /* glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);*/
    //����
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(3);

    //��һ��texturebuffer
    unsigned int textureBufferA;
    textureBufferA = LoadimagetoGPU("container.jpg",GL_RGB,GL_RGB,0);
    //�ڶ���textureBuffer
    unsigned int textureBufferB;
    textureBufferB = LoadimagetoGPU("awesomeface.png", GL_RGBA, GL_RGBA, 0);

    ////camera class
    //Camera camera(glm::vec3(0,0,3.0f),glm::radians(15.0f),glm::radians(180.0f),glm::vec3(0,1.0f,0));



    //glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 trans;
    glm::mat4 model;
    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view;
    // ע�⣬���ǽ�����������Ҫ�����ƶ������ķ������ƶ���
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
   /* view = camera.GetViewMatrix();*/
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    /*trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));*/
   /* trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));*/

//pragma region renderloop
    while (!glfwWindowShouldClose(window))
    {
        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(1.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        /*trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));*/
        processInput(window);
        glClearColor(0.2f, 0.4f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //activate��bind
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureBufferA);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textureBufferB);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        view = camera.GetViewMatrix();

        testshader->use();
        //ͨ��ʹ��glUniform1i����ÿ���������ķ�ʽ����OpenGLÿ����ɫ�������������ĸ�����Ԫ
        //glUniform1i(glGetUniformLocation(testshader->ID, "ourTexture"), 0);
        //glUniform1i(glGetUniformLocation(testshader->ID, "ourFace"), 1);

        //unsigned int transformLoc = glGetUniformLocation(testshader->ID, "transform");
        unsigned int modelLoc = glGetUniformLocation(testshader->ID, "model");
        unsigned int viewLoc = glGetUniformLocation(testshader->ID, "view");
        unsigned int projectionLoc = glGetUniformLocation(testshader->ID, "projection");
        //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform3f(glGetUniformLocation(testshader->ID, "objColor"), 1.0f, 0.5f, 0.3f);
        glUniform3f(glGetUniformLocation(testshader->ID, "ambientColor"), 1.0f, 1.0f, 1.0f);
        glUniform3f(glGetUniformLocation(testshader->ID, "lightPos"), 10.0f, 10.0f, 5.0f);
        glUniform3f(glGetUniformLocation(testshader->ID, "lightColor"), 1.0f, 1.0f, 1.0f);
 
        for (unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model;
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            unsigned int modelLoc = glGetUniformLocation(testshader->ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
        camera.UpdateCameraPos();
    }

    glfwTerminate();
    return 0;


}

