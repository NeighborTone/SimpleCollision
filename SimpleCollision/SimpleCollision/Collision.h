#pragma once
#include "Figure.h"

bool CircleAndSlopeCollision(const Circle&, const Line&);			//‰~‚Æü•ª(â“¹)
bool BoxAndSlopeCollision(const Box&, const Line&);					//‹éŒ`‚Æü•ª(â“¹)
bool BoxCollision(const Box&, const Box&);							//‹éŒ`“¯m
bool CircleCollision(const Circle&, const Circle&);					//‰~‚Æ‰~
bool CircleAndBoxCollision(const Circle&, const Box&);				//‰~‚Æ‹éŒ`
bool CircleAndTriangleCollision(const Circle&, const Triangle&);	//‰~‚ÆOŠpŒ`