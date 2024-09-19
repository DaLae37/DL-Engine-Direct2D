#pragma once
#include "stdafx.h"

class Object
{
protected:
	Object* parent;
	std::list<Object*> childList;

	D2D_MATRIX_3X2_F mat;
	D2D_RECT_F rect;
	D2D_POINT_2F pos;
	D2D_POINT_2F scalingCenter;
	D2D_POINT_2F scale;
	D2D_POINT_2F rotationCenter;
	float rotation;

	bool isActive;
	int z_index;
	std::string tag;

public:
	Object();
	~Object();

	virtual void Render();
	virtual void Update(float dTime);

	void AddChild(Object* child);
	void RemoveChild(Object* child);

	bool IsCollisionRect(Object* object);
	bool IsPointInRect(D2D_POINT_2F p);

	D2D_MATRIX_3X2_F getMat();
	D2D_POINT_2F getPos();
	D2D_RECT_F getRect();

	float getPosX();
	float getPosY();
	float getRotation();

	bool getIsActive();
	std::string getTag();
	int get_z_index();

	void setParent(Object* parent);
	void setPos(D2D_POINT_2F pos);
	void setScale(D2D_POINT_2F scale);
	void setScalingCenter(D2D_POINT_2F scaleCenter);
	void setRotation(float rotation);
	void setRotationCenter(D2D_POINT_2F rotationCenter);
	void setIsActive(bool isAcitve);
	void setTag(std::string tag);
	void set_z_index(int z_index);

	template<typename PX, typename PY>
	void setPos(PX posX, PY posY) {
		pos.x = posX;
		pos.y = posY;
	}

	template<typename SX, typename SY>
	void setScale(SX scaleX, SY scaleY) {
		scale.x = scaleX;
		scale.y = scaleY;
	}

	template<typename SCX, typename SCY>
	void setScalingCenter(SCX scaleCenterX, SCY scaleCenterY) {
		scalingCenter.x = scaleCenterX;
		scalingCenter.y = scaleCenterY;
	}

	template<typename RCX, typename RCY>
	void setRotationCenter(RCX rotationCenterX, RCY rotationCenterY) {
		rotationCenter.x = rotationCenterX;
		rotationCenter.y = rotationCenterY;
	}

	static bool compare_z_index(Object* a, Object* b) {
		return a->z_index < b->z_index;
	}
};