#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Solarization : public ShaderSource
{
public:
	Solarization();
	~Solarization();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT solarization_;

	float sola_;
};

