#pragma once

#include"SHADER.h"
class Material
{
public:

	Shader* shader;
	glm::vec3 diffuse;
	glm::vec3 specular;
	glm::vec3 ambient;
	float shininess;
	Material(Shader* _shader, glm::vec3 _diffuse,glm::vec3 _specular,glm::vec3 _ambient,float _shininess);
};

