#include "Sharpness4.h"


Sharpness4::Sharpness4()
{
}


Sharpness4::~Sharpness4()
{
}

void Sharpness4::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	sharpness4_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Sharpness4.fx"));
}

void Sharpness4::Buffer(KeyboardBuffer &key_buffer)
{

}

void Sharpness4::State(KeyboardState &key_state)
{

}

void Sharpness4::Update()
{

}

void Sharpness4::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Sharpness4::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, sharpness4_);
}