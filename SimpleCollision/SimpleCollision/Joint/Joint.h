#pragma once
#include "../Figure/Figure.h"
namespace Joint
{
	class Node
	{
	public:
		Circle c;
		float rad;
		Node();
	};

	class JointVector
	{
	public:
		POS pos;
		float dot_n;	//“àÏ‚Ì¬•ª
		void Dot(float dx, float dy)
		{
			dot_n = pos.x*dx + pos.y*dy;
		}
	};

	void MoveJoints(Node nodes[], int max,float vRad, float lRad, float distance, POS p);
}



