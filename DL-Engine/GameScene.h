#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public :
	GameScene();
	~GameScene();

	void LoadResourceData();
	void Render();
	void Update(float dTime);
};