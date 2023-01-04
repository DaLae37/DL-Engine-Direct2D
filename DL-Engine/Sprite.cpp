#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const wchar_t* path) {
	texture = textureManager->LoadTextureFromFile(path);
	
	D2D_SIZE_U textureSize =  texture->GetPixelSize();
	width = textureSize.width;
	height = textureSize.height;

	visibleRect.left = 0;
	visibleRect.top = 0;
	visibleRect.right = width;
	visibleRect.bottom = height;

	rect = visibleRect;

	color = D2D_COLOR_F{ 255, 255, 255, 255 };
}

Sprite::~Sprite() {
	
}

void Sprite::Render() {
	Object::Render();
	D2D1_POINT_2F sca;
	sca.x = width / 2;
	sca.y = height / 2;
	renderTarget->SetTransform(D2D1::Matrix3x2F::Translation(pos.x, pos.y) * D2D1::Matrix3x2F::Scale(scale.x, scale.y, sca) * D2D1::Matrix3x2F::Rotation(rotation, rotationCenter));
	renderTarget->DrawBitmap(texture, &rect, color.a, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, nullptr);
}

int Sprite::getHeight() {
	return height;
}

int Sprite::getWidth() {
	return width;
}

D2D_COLOR_F Sprite::getColor() {
	return color;
}

void Sprite::setColor(D2D_COLOR_F color) {
	this->color = color;
}