#include "Contrast.h"


Contrast::Contrast()
{
}


Contrast::~Contrast()
{
}

void Contrast::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	contrast_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Contrast.fx")); //エフェクト (コントラスト調整)

	con_ = 2.5f;
}

void Contrast::State(KeyboardState & key_state)
{
	if (key_state.IsKeyDown(Keys_Down)){

		con_ -= 0.1f;
	}


	if (key_state.IsKeyDown(Keys_Up)){
		con_ += 0.1f;
	}


	contrast_->SetParameter("contrast", con_);

}

void Contrast::Buffer(KeyboardBuffer & key_buffer)
{

}

void Contrast::Update()
{

}

void Contrast::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Contrast::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, contrast_);
}
