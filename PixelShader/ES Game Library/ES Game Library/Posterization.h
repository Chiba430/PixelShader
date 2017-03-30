#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Posterization : public ShaderSource
{
public:
	Posterization();
	~Posterization();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void	 Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT posterization_;

	int bits_;
};

