#include "Vector3D.h"

Vector3D Add( const Vector3D* const vector1, const Vector3D* const vector2)
{
	return{ vector1->x + vector2->x, vector1->y + vector2->y, vector1->z + vector2->z };
}

Vector3D Substract(const Vector3D* const vector1, const Vector3D* const vector2)
{
	return{ vector1->x - vector2->x, vector1->y - vector2->y, vector1->z - vector2->z };
}

Vector3D Scale(const Vector3D* const vector1, float scale)
{
	return{ vector1->x * scale, vector1->y * scale, vector1->z * scale };
}

float DotProduct(const Vector3D * const vector1, const Vector3D * const vector2)
{
	return (vector1->x*vector2->x + vector1->y*vector2->y + vector1->z*vector2->z);
}

Vector3D CrossLH(const Vector3D * const vector1, const Vector3D * const vector2)
{
	return{ (vector2->y*vector1->z - vector1->y*vector2->z),
		(vector2->z*vector1->x - vector1->z*vector2->x),
		(vector2->x*vector1->y - vector1->x*vector2->y) };
}

Vector3D CrossRH(const Vector3D * const vector1, const Vector3D * const vector2)
{
	return{ (vector1->y*vector2->z - vector2->y*vector1->z),
		(vector1->z*vector2->x - vector2->z*vector1->x),
		(vector1->x*vector2->y - vector2->x*vector1->y) };
}

void MoveBy(const Vector3D * const by, Vector3D * const toMove)
{
	(toMove->x += by->x); 
	(toMove->y += by->y);
	(toMove->z += by->z);
}

float Lenght(const Vector3D* const vector1)
{
	return sqrt(LenghtSquare(vector1));
}

float LenghtSquare(const Vector3D* const vector1)
{
	return (vector1->x * vector1->x + vector1->y * vector1->y + vector1->z * vector1->z);
}

bool Normalize(Vector3D* const vector1)
{
	float lenght = Lenght(vector1);
	bool hasBeenNormalized;

	if (lenght == 0)
	{
		hasBeenNormalized = false;
	}
	else
	{
		hasBeenNormalized = true;
		(vector1->x /= lenght);
		(vector1->y /= lenght); 
		(vector1->z /= lenght);
	}

	return hasBeenNormalized;
}

void ScaleBy(Vector3D* const vector1, float scale)
{
	(vector1->x *= scale);
	(vector1->y *= scale);
	(vector1->z *= scale);
}


bool Equals(const Vector3D* const vector1, const Vector3D* const vector2)
{
	bool b =	fabs(vector1->x - vector2->x) <= EPSILON && 
				fabs(vector1->y - vector2->y) <= EPSILON && 
				fabs(vector1->z - vector2->z) <= EPSILON;
	return b;
}