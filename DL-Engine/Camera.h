#pragma once
#include "Object.h"
class Camera : public Object
{
private :
	D2D_MATRIX_3X2_F mat;

public :
	Camera();
	~Camera();
};

