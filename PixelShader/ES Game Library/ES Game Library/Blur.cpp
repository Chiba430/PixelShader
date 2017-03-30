#include "Blur.h"


Blur::Blur()
{
}


Blur::~Blur()
{
}

void Blur::Initialize()
{

	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	blur_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Blur.fx")); //エフェクト (ぼかし)

	addu_ = 1.0f / 1280.0f; //ぼかしグローバル変数

	addv_ = 1.0f / 720.0f; //ぼかしグローバル変数

	blur_x_ = 0.0f; //ぼかし変数

	blur_y_ = 0.0f; //ぼかし変数

}

void Blur::State(KeyboardState & key_state)
{

	addu_ = 1.0f / 1280.0f * blur_x_;
	addv_ = 1.0f / 720.0f * blur_y_;


	if (key_state.IsKeyDown(Keys_Down)){
		blur_y_ -= 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Up)){
		blur_y_ += 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Right)){
		blur_x_ += 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Left)){
		blur_x_ -= 1.0f;
	}

	blur_->SetParameter("AddU", addu_);
	blur_->SetParameter("AddV", addv_);

}

void Blur::Buffer(KeyboardBuffer & key_buffer)
{

}

void Blur::Update()
{

}

void Blur::DrawBegin()
{

	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);

}

void Blur::DrawEnd()
{

	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, blur_);

}