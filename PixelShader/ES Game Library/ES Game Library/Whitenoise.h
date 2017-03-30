#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Whitenoise : public ShaderSource
{
public:
	Whitenoise();
	~Whitenoise();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT whitenoise_;
};

