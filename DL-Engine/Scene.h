#pragma once
#include "Object.h"

class Scene
{
private :
	std::list<Object*> objectList;
	std::list<Object*> uiList;
	D2D_COLOR_F backgroundColor;
public :
	Scene();
	~Scene();

	virtual void LoadResource() = 0;

	virtual void Render();
	virtual void Update(float dTime);

	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void AddUI(Object* ui);
	void RemoveUI(Object* ui);

	void setBackgroundColor(D2D_COLOR_F backgroundColor);
	D2D_COLOR_F getBackgroundColor();
};