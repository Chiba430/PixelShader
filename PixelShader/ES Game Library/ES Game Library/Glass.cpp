#include "Glass.h"


Glass::Glass()
{
}


Glass::~Glass()
{
}

void Glass::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	glass_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Glass.fx"));
}

void Glass::State(KeyboardState & key_state)
{

}

void Glass::Buffer(KeyboardBuffer & key_buffer)
{

}

void Glass::Update()
{

}

void Glass::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Glass::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, glass_);
}