#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Raster : public ShaderSource
{
public:
	Raster();
	~Raster();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT raster_;

	float division_, amplitude_;
};

