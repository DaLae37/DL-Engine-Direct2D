#include "stdafx.h"
#include "Animation.h"

Animation::Animation(int fps) {
	this->fps = fps;
	maxFrame = 0;
	currentFrame = 0;
	timeChecker = 0;

	height = 0;
	width = 0;

	color = D2D_COLOR_F{ 255, 255, 255, 255 };
}

Animation::~Animation() {
	for (auto& sprite : spriteVector) {
		SAFE_DELETE(sprite);
	}
}

void Animation::Render() {
	Object::Render();
	if (maxFrame > 0) {
		spriteVector[currentFrame]->setColor(color);
		spriteVector[currentFrame]->Render();
	}
}

void Animation::Update(float dTime) {
	timeChecker += dTime;

	if (timeChecker > 1.f / fps) {
		timeChecker = 0;
		currentFrame++;

		if (currentFrame == maxFrame) {
			currentFrame = 0;
		}
	}
}

void Animation::AddFrame(const wchar_t* path) {
	spriteVector.push_back(new Sprite(path));

	AddChild(spriteVector[maxFrame]);

	if (maxFrame == 0) {
		rect = spriteVector[maxFrame]->getRect();
		width = spriteVector[maxFrame]->getWidth();
		height = spriteVector[maxFrame]->getHeight();
	}

	maxFrame++;
}

int Animation::getWidth() {
	return width;
}

int Animation::getHeight() {
	return height;
}