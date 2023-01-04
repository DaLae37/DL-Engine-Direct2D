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
public :
	Animation(int fps);
	~Animation();

	void Render();
	void Update(float dTime);

	void AddFrame(const wchar_t* path);

	int getWidth();
	int getHeight();
};