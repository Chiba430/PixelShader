#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Laplacian8 : public ShaderSource
{
public:
	Laplacian8();
	~Laplacian8();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void	 Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT laplacian8;
};

