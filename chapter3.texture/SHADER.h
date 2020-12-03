#pragma once
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include<string>
using namespace std;
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
class Shader
{
public:
    // shader����ID
    unsigned int ID;

    /*string vertexString;
    string fragmentString;
    const char* vertexSource;
    const char* fragmentSource;*/


    // ��������ȡ��������ɫ��
    Shader(const char* vertexPath, const char* fragmentPath);
    // ʹ��/�������
    void use();
    // uniform���ߺ���
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
};