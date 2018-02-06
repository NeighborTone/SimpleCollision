#pragma once
#include <math.h>
#include"../Figure/Figure.h"

class Tentacle
{

public:
	void MoveTentacle(float x[], float y[],float tx, float ty, 
		int num_part, float v, float limit, int num_loop);

	void MoveJoint(int num_joint, float x[], float y[], float rad[], float vrad, float lrad ,float dist, POS t);
};

