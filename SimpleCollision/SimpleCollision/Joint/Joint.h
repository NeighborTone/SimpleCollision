#pragma once
#include <math.h>
#include"../Figure/Figure.h"

class Tentacle
{

private:
	int num_part;
	float speed;
	float limit;
	int num_loop;
public:
	void SetTentacle(int num_part,float speed, float limit,int numloop);
	void MoveTentacle(float x[],float y[] , POS& target);
};

