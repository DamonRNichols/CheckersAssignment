#include "CheckersGame.h"

#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "Gizmos.h"


bool CheckersGame::startup()
{
	if (Application::startup() == false)
	{
		return false;
	}

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	Gizmos::create();

	m_camera = new FlyCamera();
	Players = new PlayerManager();

	return true;
}

void CheckersGame::shutdown()
{
	Gizmos::destroy();

	Application::shutdown();
}

bool CheckersGame::update()
{
	if (Application::update() == false)
	{
		return false;
	}

	Gizmos::clear();

	float dt = (float)glfwGetTime();
	glfwSetTime(0.0f);
	m_timer += dt;

	m_camera->update(dt);

	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i <= 8; ++i)
	{
		Gizmos::addLine(vec3(0 + i, 0, 0), vec3(0 + i, 0, 8), white);
		Gizmos::addLine(vec3(0, 0, 0 + i), vec3(8, 0, 0 + i), white);
	}
	//origin lines
	Gizmos::addLine(vec3(0, 0.01f, 0), vec3(1, 0.01f, 0), vec4(1, 0, 0, 1));
	Gizmos::addLine(vec3(0, 0, 0), vec3(0, 1, 0), vec4(0, 1, 0, 1));
	Gizmos::addLine(vec3(0, 0.01f, 0), vec3(0, 0.01f, 1), vec4(0, 0, 1, 1));

	Players->Update(m_window, m_camera);

	return true;
}

void CheckersGame::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Gizmos::draw(m_camera->m_proj, m_camera->m_view);
	/*
	glUseProgram(m_programID);

	int view_proj_uniform = glGetUniformLocation(m_programID, "projection_view");
	glUniformMatrix4fv(view_proj_uniform, 1, GL_FALSE, (float*)&m_camera->m_view_proj);
	*/
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}