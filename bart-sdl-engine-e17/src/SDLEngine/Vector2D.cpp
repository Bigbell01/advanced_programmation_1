#include "Vector2D.h"

Vector2D Add(const Vector2D* const vector1, const Vector2D* const vector2)
{
	return{ vector1->x + vector2->x, vector1->y + vector2->y };
}

Vector2D Substract(const Vector2D* const vector1, const Vector2D* const vector2)
{
	return{ vector1->x - vector2->x, vector1->y - vector2->y };
}

Vector2D Scale(const Vector2D* const vector1, float scale)
{
	return{ (vector1->x * scale),(vector1->y * scale) };
}

void MoveBy(const Vector2D * const by, Vector2D * const toMove)
{
	(toMove->x += by->x); 
	(toMove->y += by->y);
}

float GetPolarAngleDegree(const Vector2D* const vector1)
{
	float angleDegree;

	if (vector1->x == ZERO)
	{
		if (vector1->y < ZERO)
		{
			angleDegree = THREEQUARTERCIRCLE;
		}
		else if (vector1->y > ZERO)
		{
			angleDegree = QUARTERCIRCLE;
		}
		else
		{
			angleDegree = ZERO;
		}
	}
	else if (vector1->x != ZERO)
	{
		if (vector1->y > ZERO && vector1->x > ZERO)
		{
			angleDegree = (float)(atanf(vector1->y / vector1->x) * HALFCIRCLE / PI);
		}
		else if ((vector1->y > ZERO && vector1->x < ZERO) || ((vector1->y < ZERO && vector1->x < ZERO)))
		{
			angleDegree = (float)(atanf(vector1->y / vector1->x)* HALFCIRCLE / PI) + HALFCIRCLE;
		}
		else if (vector1->y < ZERO && vector1->x > ZERO)
		{
			angleDegree = (float)(atanf(vector1->y / vector1->x)* HALFCIRCLE / PI) + 2 * HALFCIRCLE;
		}
		else if (vector1->y == ZERO)
		{
			if (vector1->x < ZERO)
			{
				angleDegree = HALFCIRCLE;
			}
			else if (vector1->x > ZERO)
			{
				angleDegree = ZERO;
			}
		}
	}

	return angleDegree;
}

float AngleBetweenDeltas(const Vector2D* const vector1, const Vector2D* const vector2)
{
	return abs(GetPolarAngleDegree(vector1) - GetPolarAngleDegree(vector2));
}

float Lenght(const Vector2D* const vector1)
{
	return sqrt(LenghtSquare(vector1));
}

float LenghtSquare(const Vector2D* const vector1)
{
	return (vector1->x * vector1->x + vector1->y * vector1->y);
}

void ScaleBy(Vector2D* const vector1, float scale)
{
	vector1->x *= scale;
	vector1->y *= scale;
}

bool Normalize(Vector2D* const vector1)
{
	float longueur = Lenght(vector1);
	bool aEteNormalise;

	if (longueur == ZERO)
	{
		aEteNormalise = false;
	}
	else
	{
		(vector1->x /= longueur); 
		(vector1->y /= longueur);
		aEteNormalise = true;
	}

	return aEteNormalise;
}

Vector2D GetVectorByAngleDegree(float angle) 
{
	return { cosf(angle* (float)PI / HALFCIRCLE), sinf(angle * (float)PI / HALFCIRCLE) };
}

bool Equals(const Vector2D* const vector1, const Vector2D* const vector2)
{
	return fabs( vector1->x - vector2->x) <= EPSILON && fabs(vector1->y - vector2->y) <= EPSILON;
}

void MoveToward(Vector2D * origin, const Vector2D * const destination, const float speed)
{
	Vector2D a = Vector2D(destination->x - origin->x, destination->y - origin->y);
	if (speed > Lenght(&a))
	{
		*origin = *destination;
		return;
	}
	Normalize(&a);
	Scale(&a, speed);
	MoveBy(&a, origin);
}
