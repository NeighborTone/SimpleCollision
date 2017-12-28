#pragma once
#define _USE_MATH_DEFINES
#include "Figure.h"

namespace MATH
{

	float Radian(const float degree);
	float Gravity(const float bym);
	bool CirecleAndLineCollision(const Circle&, const Line&);			//‰~‚Æü+++–¢À‘•
	bool LineCollision(const Line&, const Line&);						//ü•ª‚Æü•ª
	bool CircleAndSlopeCollision(const Circle&, const Line&);			//‰~‚Æü•ª(â“¹)
	bool BoxAndSlopeCollision(const Box&, const Line&);					//‹éŒ`‚Æü•ª(â“¹)
	bool BoxCollision(const Box&, const Box&);							//‹éŒ`“¯m
	bool CircleCollision(const Circle&, const Circle&);					//‰~‚Æ‰~
	bool CircleAndBoxCollision(const Circle&, const Box&);				//‰~‚Æ‹éŒ`
	bool CircleAndTriangleCollision(const Circle&, const Triangle&);	//‰~‚ÆOŠpŒ`+++–¢À‘•

}
