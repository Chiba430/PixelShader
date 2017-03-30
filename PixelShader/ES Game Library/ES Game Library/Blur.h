#pragma once
#include "ESGLib.h"
#include "ShaderSource.h"
class Blur : public ShaderSource
{
public:
	Blur();
	~Blur();

	virtual void Initialize();
	virtual void State(KeyboardState &key_state);
	virtual void Buffer(KeyboardBuffer &key_buffer);
	virtual void	 Update();
	virtual void DrawBegin();
	virtual void DrawEnd();

	EFFECT blur_;

	float addu_; //ぼかしグローバル変数
	float addv_; //ぼかしグローバル変数
	float blur_x_; //ぼかし変数
	float blur_y_; //ぼかし変数
};

