#include "includes.h"

int main() {
	GLFWwindow* window = setupOpenGL();

	unsigned int shaderProgram = createShaderProgram();
	
	int size;
	float* vertices3d = getVerticesFromFile("./vertices.txt", &size);
	float* vertices2d = NULL;
	float* vertices;
	vertices3d = threeDimXRotation(vertices3d, -60, size);
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	void loop() {
		vertices3d = threeDimYRotation(vertices3d, 0.1, size);
		vertices = threeDimToTwoDim(vertices3d, vertices2d, size);
		
		glUseProgram(shaderProgram);
		unsigned int VAO = getVertexArray(vertices, size);
		glBindVertexArray(VAO);
		glDrawArrays(GL_POINTS, 0, size/3);
	} 

	startLoop(window, loop, 60.0);

	glDeleteProgram(shaderProgram);
	
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
