#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Watercolor : public ShaderSource
{
public:
	Watercolor();
	~Watercolor();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT blur_, posterization_, glass_;

	float addu_, addv_, blur_x, blur_y;
	int bits_;

};

