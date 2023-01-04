#pragma once
#include "Object.h"
class Sprite : public Object
{
private :
	ID2D1Bitmap* texture;
	D2D_COLOR_F color;
	D2D_RECT_F visibleRect;

	int width;
	int height;
public :
	Sprite(const wchar_t* path);
	~Sprite();

	void Render();

	int getWidth();
	int getHeight();
	D2D_COLOR_F getColor();

	void setColor(D2D_COLOR_F color);
};