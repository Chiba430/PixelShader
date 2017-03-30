#include "Roberts.h"


Roberts::Roberts()
{
}


Roberts::~Roberts()
{
}

void Roberts::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	roberts_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Roberts.fx"));
}

void Roberts::Buffer(KeyboardBuffer &key_buffer)
{

}

void Roberts::State(KeyboardState &key_state)
{

}

void Roberts::Update()
{

}

void Roberts::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Roberts::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, roberts_);
}