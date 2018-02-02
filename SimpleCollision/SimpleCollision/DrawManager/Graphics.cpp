#include "Graphics.h"
#include <math.h>
void Painter::SetGraphic(const char* path)
{
	handle = LoadGraph(path);
}
void Painter::RenderGraphic(POS& p , bool f)
{
	DrawGraphF(p.x, p.y, handle,f);
}

void Painter::RenderRotaGraphic(POS& p, bool f)
{
	DrawRotaGraphF(p.x, p.y, 1, 0, handle, f);
}
void Painter::Raster_Scrool(const float &X, const float &Y, float Cycle, float Shake,int speed)
{
	const float PI = 3.14159265358979323846f;
	float Width = 0;
	float Height = 0;
	static int Correction = 0;
	GetGraphSizeF(handle, &Width, &Height);
	for (int i = 0; i < Height; ++i)
	{
		DrawRectGraphF(X - Width / 2 + (float)cos((i + Correction) / 180.0f + PI + Cycle) * Shake,
			Y - Height / 2 + i, 0, i, Width, 1, handle, true,false);
	}
	Correction += speed;
}
void Painter::Raster_ScroolLogo(const float &X, const float &Y)
{
	const float PI = 3.14159265358979323846f;
	float Width = 0;
	float Height = 0;
	GetGraphSizeF(handle, &Width, &Height);
}