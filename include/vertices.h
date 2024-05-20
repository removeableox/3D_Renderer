#ifndef VERTICES_H
#define VERTICES_H

float* threeDimToTwoDim(float* vertices3d, float* vertices2d, int size);

float* threeDimXRotation(float* vertices, float angle, int size);
float* threeDimYRotation(float* vertices, float angle, int size);
float* threeDimZRotation(float* vertices, float angle, int size);

unsigned int getVertexArray(float* vertices, int size);

#endif
