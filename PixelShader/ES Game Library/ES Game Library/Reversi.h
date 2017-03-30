#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Reversi : public ShaderSource
{
public:
	Reversi();
	~Reversi();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT reversi_;

	int r_;
};

