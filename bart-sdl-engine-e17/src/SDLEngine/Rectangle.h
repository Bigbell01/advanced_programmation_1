#pragma once

#include "Vector2D.h"
#include "GameObject.h"
#include "Engine.h"

class Rectangle
	: public GameObject
{
public:
	static void SetDebug(bool tf) { debugMode = tf; }

	Rectangle();
	Rectangle(float x, float y);
	Rectangle(float x, float y, float width, float height);
	Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight);
	~Rectangle() {}

	virtual void Update();
	virtual void Draw();

	bool Contains(float x, float y) const;
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetWidth() const { return width; }
	float GetHeight() const { return height; }
	Vector2D GetPosition() const { return Vector2D(x, y); }
	void SetPosition(const Vector2D* const vect);
	void SetPosition(float x, float y);
	void SetSize(float w, float h) { width = w; height = h; }
	void MoveBy(const Vector2D* const vect);
	void MoveBy(float x, float y);
	bool CollidesWith(const Rectangle* const rect) const;

	// Deprecated, for retro compatibility only
	const Rectangle* const GetRectangle() const { return this; }

protected:
	float x, y, width, height;

private:
	static bool debugMode;

};

