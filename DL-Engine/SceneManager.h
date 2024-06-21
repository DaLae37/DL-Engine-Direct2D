#pragma once
#include "Scene.h"

class SceneManager
{
private :
	Scene* currentScene;
public :
	SceneManager();
	~SceneManager();

	void Render();
	void Update(float dTime);

	void ChangeScene(Scene* scene);

	D2D_COLOR_F GetCurrentSceneBackgroundColor();
};