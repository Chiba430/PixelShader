#include "Gradient.h"


Gradient::Gradient()
{
}


Gradient::~Gradient()
{
}

void Gradient::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	gradient_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Gradient.fx"));
}

void Gradient::State(KeyboardState & key_state)
{

}

void Gradient::Buffer(KeyboardBuffer & key_buffer)
{

}

void Gradient::Update()
{

}

void Gradient::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Gradient::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, gradient_);
}

