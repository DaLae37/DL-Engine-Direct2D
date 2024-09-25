#pragma once
#include "Object.h"
#include "Sprite.h"

class Animation : public Object
{
private :
	int height;
	int width;
	int maxFrame;
	int currentFrame;
	int fps;

	D2D_COLOR_F color;
	float timeChecker;

	std::vector<Sprite*> spriteVector;
	std::vector<const wchar_t*> pathVector;
public :
	Animation(int fps);
	~Animation();

	void LoadResourceFromFiles();

	void Render();
	void Update(float dTime);

	void AddFrame(const wchar_t* path);

	int getWidth();
	int getHeight();
};