#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Camera
{
public:
	Camera(glm::vec3 position,glm::vec3 target,glm::vec3 worldup);
	Camera(glm::vec3 position,float pitch, float yaw, glm::vec3 worldup);
	glm::mat4 GetViewMatrix();

	glm::vec3 Position;
	glm::vec3 Forward;
	glm::vec3 Right;
	glm::vec3 Up;
	glm::vec3 WorldUp;
	float Pitch;
	float Yaw;

	float speedZ = 0;

	void ProcessMouseMovement(float deltaX, float deltaY);
	void UpdateCameraPos();

private:
	void UpdateCameraVectors();
	

};

