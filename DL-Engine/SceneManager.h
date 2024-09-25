#pragma once
#include "Scene.h"

class SceneManager
{
private :
	Scene* currentScene;
	std::unordered_map<std::string, Scene*> scenes;
public :
	explicit SceneManager();
	~SceneManager();

	void Render();
	void Update(float dTime);

	void ChangeScene(Scene* scene, std::string sceneName = "scene", bool deleteBeforeScene = false);

	void WaitThreadsEnd();

	D2D_COLOR_F GetCurrentSceneBackgroundColor();
};