#pragma once
#include "../Figure/Figure.h"

class Collision
{
private:
	typedef POS Vec;
public:
	bool  BoxAndLine(const Box& box, const Line& line);									//‹éŒ`‚Æü•ª
	bool  BoxAndSlope(const Box& box, const Line& line);									//‹éŒ`‚Æü•ª(â“¹)
	bool  BoxAndBox(const Box& box, const Box& box2);									//‹éŒ`“¯m
	bool  LineAndLine(const Line& line, const Line& line2);								//ü•ª‚Æü•ª
	bool  CirecleAndLine(const Circle& circle, const Line& line);					//‰~‚Æü•ª
	bool  CircleAndSlope(const Circle& circle, const Line& line);					//‰~‚Æü•ª(â“¹)
	bool  CircleAndCircle(const Circle& circle, const Circle& circle2);			//‰~‚Æ‰~
	bool  CircleAndBox(const Circle& circle, const Box& box);							//‰~‚Æ‹éŒ`
	bool  CircleAndTriangle(const Circle& circle, const Triangle& tri);			//‰~‚ÆOŠpŒ`
	bool  TriangleAndLine(const Triangle& tri, const Line& line);						//OŠpŒ`‚Æü•ª
};
	

