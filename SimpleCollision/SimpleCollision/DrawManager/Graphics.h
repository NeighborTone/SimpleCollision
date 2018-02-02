#pragma once
#include "DxLib.h"
#include "../Figure/Figure.h"
#include <vector>
class Painter
{
private:
	int handle;
	std::vector<int>handles;
public:
	void SetGraphic(const char* path);
	void RenderGraphic(POS& p,bool f = true);
	void RenderRotaGraphic(POS& p, float angle = 0, bool f = true);
	void Raster_Scrool(const float &X, const float &Y,  float Cycle, float Shake,float speed);
	void Raster_ScroolLogo(const float &X, const float &Y);
};