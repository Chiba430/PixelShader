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

	float addu_; //�ڂ����O���[�o���ϐ�
	float addv_; //�ڂ����O���[�o���ϐ�
	float blur_x_; //�ڂ����ϐ�
	float blur_y_; //�ڂ����ϐ�
};

