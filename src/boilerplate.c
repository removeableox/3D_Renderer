#include "includes.h"

GLFWwindow* setupOpenGL() {
	if (!glfwInit()) {
		return NULL;
	}

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "window", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	GLenum glewInitResult = glewInit();
	if (glewInitResult != GLEW_OK) {
		printf("ERROR::GLEW_INIT_FAILED: %s\n", glewGetErrorString(glewInitResult));
		glfwDestroyWindow(window);
		glfwTerminate();
		return NULL;
	}
	
	return window;
}

void sleep(int milliseconds) {
    struct timespec req, rem;
    req.tv_sec = milliseconds / 1000;
    req.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&req, &rem);
}

void startLoop(GLFWwindow* window, void (*functionPtr)(), double fps) {
	const double frameTime = 1.0/fps;

	while (!glfwWindowShouldClose(window)) {
		double startTime = glfwGetTime();

		glClear(GL_COLOR_BUFFER_BIT);
		
		functionPtr();

		glfwSwapBuffers(window);
		glfwPollEvents();

		double elapsedTime = glfwGetTime() - startTime;
		if (elapsedTime < frameTime) {
			sleep((frameTime-elapsedTime)*1000);
		}
	}
	
}
