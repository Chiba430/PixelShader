#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Sharpness8 : public ShaderSource
{
public:
	Sharpness8();
	~Sharpness8();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT sharpness8_;
};

