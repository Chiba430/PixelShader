#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Copy : public ShaderSource
{
public:
	Copy();
	~Copy();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void	 Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT copy_;

	float c_;

};

