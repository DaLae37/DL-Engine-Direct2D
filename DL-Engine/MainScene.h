#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainScene : public Scene
{
private :
	Sprite* background;

	Sprite* resetButton;
	Sprite* startButton;
	Sprite* endButton;

public :
	MainScene(std::string sceneName);
	~MainScene();

	void LoadResourceData();
	void Render();
	void Update(float dTime);
};