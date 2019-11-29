#include "hzpch.h"
#include "Hazel/Renderer/OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {

	OrthographicCamera::OrthographicCamera(float left, float right, float buttom, float top)
		:m_ProjectionMatrix(glm::ortho(left, right, buttom, top, -1.0f, +1.0f)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float buttom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, buttom, top, -1.0f, +1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 trasform = glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

		m_ViewMatrix = glm::inverse(trasform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}
