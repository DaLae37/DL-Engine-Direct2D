#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const wchar_t* path) {
	texture = textureManager->LoadTextureFromFile(path);
	
	D2D_SIZE_U textureSize =  texture->GetPixelSize();
	width = textureSize.width;
	height = textureSize.height;

	rotationCenter.x = width / 2;
	rotationCenter.y = height / 2;

	scalingCenter.x = width / 2;
	scalingCenter.y = height / 2;

	visibleRect.left = 0;
	visibleRect.top = 0;
	visibleRect.right = width;
	visibleRect.bottom = height;

	rect = visibleRect;

	color = D2D_COLOR_F{ 1.0f, 1.0f, 1.0f, 1.0f };
}

Sprite::~Sprite() {
	
}

void Sprite::Render() {
	Object::Render();
	
	renderTarget->SetTransform(D2D1::Matrix3x2F::Translation(pos.x, pos.y) * D2D1::Matrix3x2F::Scale(scale.x, scale.y, scalingCenter) * D2D1::Matrix3x2F::Rotation(rotation, rotationCenter));
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

void Sprite::SetOpacity(float opacity) {
	color.a = opacity;
}

float Sprite::GetOpacity() {
	return color.a;
}