#pragma once

#include "Includes.h"

struct Vector3D
{
	Vector3D()
		: x(0), y(0), z(0) {}
	Vector3D(float x, float y, float z)
		: x(x), y(y) { }

	float x, y, z;
};

Vector3D Add(const Vector3D* const vector1, const Vector3D* const vector2); 
Vector3D Substract(const Vector3D* const vector1, const Vector3D* const vector2); 
Vector3D Scale(const Vector3D* const vector1, float scale); 
float DotProduct(const Vector3D* const vector1, const Vector3D* const vector2); 
Vector3D CrossLH(const Vector3D* const vector1, const Vector3D* const vector2); 
Vector3D CrossRH(const Vector3D* const vector1, const Vector3D* const vector2); 
void MoveBy(const Vector3D* const by, Vector3D* const toMove); 
float Lenght(const Vector3D* const vector1); 
float LenghtSquare(const Vector3D* const vector1); 
bool Normalize(Vector3D* const vector1); 
void ScaleBy(Vector3D* const vector1, float scale); 
bool Equals(const Vector3D* const vector1, const Vector3D* const vector2);