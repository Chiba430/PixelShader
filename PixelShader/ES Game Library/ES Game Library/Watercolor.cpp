#include "Watercolor.h"


Watercolor::Watercolor()
{
}


Watercolor::~Watercolor()
{
}

void Watercolor::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	offscreen2_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	addu_ = 1.0f / 1280.0f; //�ڂ����O���[�o���ϐ�

	addv_ = 1.0f / 720.0f; //�ڂ����O���[�o���ϐ�

	blur_x = 5.0f; //�ڂ����ϐ�

	blur_y = 5.0f; //�ڂ����ϐ�

	blur_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Blur.fx")); //�G�t�F�N�g (�ڂ���)

	posterization_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Posterization.fx")); //�G�t�F�N�g (�|�X�^���[�[�V����)

	bits_ = 32;

	glass_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Glass.fx")); //�G�t�F�N�g (����K���X)
}

void Watercolor::Buffer(KeyboardBuffer &key_buffer)
{

}

void Watercolor::State(KeyboardState &key_state)
{
	addu_ = 1.0f / 1280.0f * blur_x;
	addv_ = 1.0f / 720.0f * blur_y;


	if (key_state.IsKeyDown(Keys_Down)){
		blur_y -= 0.1f;
	}
	if (key_state.IsKeyDown(Keys_Up)){
		blur_y += 0.1f;
	}
	if (key_state.IsKeyDown(Keys_Right)){
		blur_x += 0.1f;
	}
	if (key_state.IsKeyDown(Keys_Left)){
		blur_x -= 0.1f;
	}

	blur_->SetParameter("AddU", addu_);
	blur_->SetParameter("AddV", addv_);

	if (key_state.IsKeyDown(Keys_LeftShift)){
		if (key_state.IsKeyDown(Keys_Up)){
			bits_ += 1;
		}
		if (key_state.IsKeyDown(Keys_Down)){
			bits_ -= 1;
		}
	}

	posterization_->SetParameter("bits", bits_);
}

void Watercolor::Update()
{

}

void Watercolor::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Watercolor::DrawEnd()
{
	GraphicsDevice.RenderTargetToRenderTarget(offscreen2_, offscreen_, posterization_);
	GraphicsDevice.RenderTargetToRenderTarget(offscreen_, offscreen2_, glass_);
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, blur_);
}