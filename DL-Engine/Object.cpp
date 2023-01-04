#include "stdafx.h"
#include "Object.h"

Object::Object() {
	pos = D2D_POINT_2F{ 0, 0 };

	rotationCenter = D2D_POINT_2F{ 0, 0 };
	scalingCenter = D2D_POINT_2F{ 0, 0 };

	rotation = 0;
	scale = D2D_POINT_2F{ 1, 1 };

	mat = D2D_MATRIX_3X2_F{ 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};

	rect.top = 0;
	rect.left = 0;
	rect.right = 0;
	rect.bottom = 0;

	parent = nullptr;
}

Object::~Object() {
	for (auto& child : childList) {
		SAFE_DELETE(child);
	}
}

void Object::Render() {
	
}

void Object::Update(float dTime) {
	for (auto& child : childList) {
		child->Update(dTime);
	}
}

void Object::AddChild(Object* child) {
	childList.push_back(child);
	child->parent = this;
}

void Object::RemoveChild(Object* child) {
	childList.remove(child);
	child->parent = nullptr;
}

bool Object::IsCollisionRect(Object * object) {
	
	D2D1_RECT_F r1 = rect, r2 = object->getRect();

	r1.left += pos.x;
	r1.right += pos.x;
	r1.top += pos.y;
	r1.bottom += pos.y;

	r2.left += object->getPosX();
	r2.right += object->getPosX();
	r2.top += object->getPosY();
	r2.bottom += object->getPosY();

	return (r1.left < r2.right&&
			r1.right > r2.left &&
			r1.top < r2.bottom&&
			r1.bottom > r2.top);
}

bool Object::IsPointInRect(D2D_POINT_2F p) {
	return (p.x > rect.left + pos.x && 
			p.x < rect.right + pos.x &&
			p.y > rect.top + pos.y &&
			p.y < rect.bottom + pos.y);
}

D2D_MATRIX_3X2_F Object::getMat() {
	return mat;
}

D2D_POINT_2F Object::getPos() {
	return pos;
}

D2D1_RECT_F Object::getRect() {
	return rect;
}

float Object::getPosX() {
	return pos.x;
}

float Object::getPosY() {
	return pos.y;
}

float Object::getRotation() {
	return rotation;
}

void Object::setParent(Object* parent) {
	this->parent = parent;
}

void Object::setPos(D2D_POINT_2F pos) {
	this->pos = pos;
}

void Object::setRotation(float rotation) {
	this->rotation = rotation;
}

void Object::setRotationCenter(D2D_POINT_2F rotationCenter) {
	this->rotationCenter.x = rotationCenter.x;
	this->rotationCenter.y = rotationCenter.y;
}

void Object::setScale(D2D_POINT_2F scale) {
	this->scale.x = scale.x;
	this->scale.y = scale.y;
}

void Object::setScalingCenter(D2D_POINT_2F scaleCenter) {
	scalingCenter.x = scaleCenter.x;
	scalingCenter.y = scaleCenter.y;
}