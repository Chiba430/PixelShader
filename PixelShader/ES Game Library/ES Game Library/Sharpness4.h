#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Sharpness4 : public ShaderSource
{
public:
	Sharpness4();
	~Sharpness4();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT sharpness4_;
};

