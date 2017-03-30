#pragma once
#include "ESGLib.h"
class ShaderSource
{
public:
	ShaderSource();
	~ShaderSource();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawEnd();
	virtual void DrawBegin();

	RENDERTARGET offscreen_;
	RENDERTARGET offscreen2_;

};

