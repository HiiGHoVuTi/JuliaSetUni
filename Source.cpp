#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <typeinfo>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::chrono_literals;

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
class App : public olc::PixelGameEngine
{
public:
	App(std::string name)
	{
		sAppName = name;
	}

public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;
};


std::string __uni__arrow(std::string* target, std::string object, bool dir) {
	if (dir)
		* target = object + *target;
	else
		*target += object;
	return *target;
}
int __uni__arrow(int* target, int object, bool dir) { return *target += object; }
std::string __uni__arrow(std::string* target, int object, bool dir) {
	if (dir)
		* target = std::to_string(object) + *target;
	else
		*target += std::to_string(object);
	return *target;
}


float angle(0);
int width; int height;
bool App::OnUserCreate() {
	width = ScreenWidth();
	height = ScreenHeight();
	return true;
}
bool App::OnUserUpdate(float fElapsedTime) {
	float ca(cos((angle + 100)));
	float cb(sin(angle));
	(angle += 0.02);
	Clear(olc::BLACK);
	float w(5);
	//float w((float)GetMouseY()/(float)height*10.f);
	float h(((w * height) / width));
	float xmin((-1 * w / 2));
	float ymin((-1 * h / 2));
	float maxIterations(100);
	float xmax((xmin + w));
	float ymax((ymin + h));
	float dx(((xmax - xmin) / width));
	float dy(((ymax - ymin) / height));
	float x(xmin);
	for (int i = 0; i < width; i++) {
		float y(ymin);
		for (int j = 0; j < height; j++) {
			float a(x);
			float b(y);
			float n(0);
			while ((n < maxIterations)) {
				float aa((a * a));
				float bb((b * b));
				if (((aa + bb) > 4)) {
					break;
				}
				float twoab((2 * a * b));
				a = (aa - bb + ca);
				b = (twoab + cb);
				n += 1;
			}
			olc::Pixel pix;
			if ((n == maxIterations)) {
				pix = olc::Pixel(olc::BLACK);
			}
			else {
				float hu((n / maxIterations * 255) + 20);
				pix = olc::Pixel(hu*1.2, hu*.8, hu);
			}
			Draw(i, j, pix);
			(y += dy);
		}
		(x += dx);
	}
	return true;
}
int main() {
	App demo("Julia Set");
	if (demo.Construct(640, 360, 1, 1)) {
		demo.Start();
	}
	return 0;
}