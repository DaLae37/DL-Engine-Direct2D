#pragma once
#include "Object.h"

class Scene
{
private :
	std::string sceneName;
	bool isSceneLoaded;
	std::vector<Object*> objects;
	std::vector<Object*> UIs;
	D2D_COLOR_F backgroundColor;
public :
	Scene(std::string sceneName = "scene");
	virtual ~Scene();

	virtual void LoadResourceData() = 0;
	void LoadResourceFromFiles();

	virtual void Render();
	virtual void Update(float dTime);

	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void AddUI(Object* ui);
	void RemoveUI(Object* ui);

	void setBackgroundColor(D2D_COLOR_F backgroundColor);
	D2D_COLOR_F getBackgroundColor();
};