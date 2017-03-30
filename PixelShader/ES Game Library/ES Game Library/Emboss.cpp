#include "Emboss.h"


Emboss::Emboss()
{
}


Emboss::~Emboss()
{
}

void Emboss::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	emboss_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Emboss.fx")); //エフェクト (エンボス)
}

void Emboss::State(KeyboardState & key_state)
{

}

void Emboss::Buffer(KeyboardBuffer & key_buffer)
{

}

void Emboss::Update()
{

}

void Emboss::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Emboss::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, emboss_);
}
