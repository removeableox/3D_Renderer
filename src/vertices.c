#include "includes.h"

int scale = 30;

float* threeDimToTwoDim(float* vertices3d, float* vertices2d, int size) {
	float matrix[2][3] = {
		{1,0,0},
		{0,1,0},
	};

	size_t transformedSize = (size/3) * 2;
	vertices2d = realloc(vertices2d, transformedSize*sizeof(float));

	int index = 0;

	for (int i = 0; i < size; i += 3) {
		vertices2d[index] = (vertices3d[i] * matrix[0][0] + vertices3d[i+1] * matrix[0][1])/scale;
		vertices2d[index+1] = (vertices3d[i] * matrix[1][0] + vertices3d[i+1] * matrix[1][1])/scale;
		index += 2; 
	}

	//free(vertices3d);

	return vertices2d;
}

float* matrixMultiplication(float matrix[3][3], float* vertices3d, int size) {
	for (int i = 0; i < size; i += 3) {
		float temp[] = {vertices3d[i], vertices3d[i+1], vertices3d[i+2]};
		vertices3d[i] = (temp[0] * matrix[0][0] + temp[1] * matrix[0][1] + temp[2] * matrix[0][2]);
		vertices3d[i+1] = (temp[0] * matrix[1][0] + temp[1] * matrix[1][1] + temp[2] * matrix[1][2]);
		vertices3d[i+2] = (temp[0] * matrix[2][0] + temp[1] * matrix[2][1] + temp[2] * matrix[2][2]);
	}

	return vertices3d;
}

float* threeDimXRotation(float* vertices3d, float angle, int size) {
	float a = angle * M_PI / 180.0;
	float matrix[3][3] = {
		{1,0,0},
		{0,cos(a),-sin(a)},
		{0,sin(a),cos(a)}
	};

	return matrixMultiplication(matrix, vertices3d, size);
}

float* threeDimYRotation(float* vertices3d, float angle, int size) {
	float a = angle * M_PI / 180.0;
	float matrix[3][3] = {
		{cos(a),0,sin(a)},
		{0,1,0},
		{-sin(a),0,cos(a)}
	};

	return matrixMultiplication(matrix, vertices3d, size);
}

float* threeDimZRotation(float* vertices3d, float angle, int size) {
	float a = angle * M_PI / 180.0;
	float matrix[3][3] = {
		{cos(a),-sin(a),0},
		{sin(a),cos(a),0},
		{0,0,1}
	};

	return matrixMultiplication(matrix, vertices3d, size);
}

unsigned int getVertexArray(float* vertices, int size) {
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, ((size/3)*2)*sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	return VAO;
}
