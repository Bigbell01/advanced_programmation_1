#pragma once

class Component 
{
public:
	Component();
	~Component();

	void SetDepth(int depth)
	{
		this->depth = depth;
		// R�ordonner le tableau
	}

	virtual void Start() {}
	virtual void Update() {}
	virtual void Draw();
	virtual void Stop() {}

protected:
	int depth;

};

