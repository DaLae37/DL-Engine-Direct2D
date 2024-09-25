#pragma once
#include "Object.h"
class Sprite : public Object
{
private :
	ID2D1Bitmap* texture;
	D2D_COLOR_F color;
	D2D_RECT_F visibleRect;

	const wchar_t* path;

	int width;
	int height;
public :
	Sprite(const wchar_t* path);
	~Sprite();

	void LoadResourceFromFiles();
	void Render();

	int getWidth();
	int getHeight();

	D2D_COLOR_F getColor();
	void setColor(D2D_COLOR_F color);

	void SetOpacity(float opacity);
	float GetOpacity();
};