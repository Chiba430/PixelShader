#include "Copy.h"


Copy::Copy()
{
}


Copy::~Copy()
{
}

void Copy::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	copy_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Copy.fx")); //エフェクト (複製描画)

	c_ = 2;
}

void Copy::State(KeyboardState & key_state)
{

}

void Copy::Buffer(KeyboardBuffer & key_buffer)
{
	if (key_buffer.IsPressed(Keys_Up)){
		c_ += 1;
	}
	if (key_buffer.IsPressed(Keys_Down)){
		c_ -= 1;
	}

	copy_->SetParameter("c", c_);

}

void Copy::Update()
{

}

void Copy::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Copy::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, copy_);
}