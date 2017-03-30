#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Level : public ShaderSource
{
public:
	Level();
	~Level();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void	 Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT level_;

	float l_;
};

