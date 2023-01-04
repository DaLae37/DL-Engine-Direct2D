#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainScene : public Scene
{
public :
	MainScene();
	~MainScene();

	Sprite* icon;

	void Render();
	void Update(float dTime);
};