#include "Graphics.h"
#include "../MyMath/MyMath.h"
#include <math.h>
void Painter::SetGraphic(const char* path)
{
	handle = LoadGraph(path);
}
void Painter::RenderGraphic(POS& p , bool f)
{
	DrawGraphF(p.x, p.y, handle,f);
}

void Painter::RenderRotaGraphic(POS& p, float angle, bool f)
{
	DrawRotaGraphF(p.x, p.y, 1, angle, handle, f);
}
void Painter::RenderRotaGraphic(float& x, float& y, float angle, bool f)
{
	DrawGraphF(x, y, handle, f);
}
void Painter::Raster_Scrool(const float &X, const float &Y, float Cycle, float Shake,float speed)
{
	const float PI = 3.14159265358979323846f;
	int Width = 0;
	int Height = 0;
	static float Correction = 0;
	GetGraphSize(handle, &Width, &Height);
	for (int i = 0; i < Height; ++i)
	{
		DrawRectGraphF(X - Width / 2.0f + (float)cos((i + Correction) / 180.0f + PI + Cycle) * Shake,
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