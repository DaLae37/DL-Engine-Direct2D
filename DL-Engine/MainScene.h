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
	MainScene();
	~MainScene();

	void LoadResource();
	void Render();
	void Update(float dTime);
};