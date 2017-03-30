#include "Gray.h"


Gray::Gray()
{
}


Gray::~Gray()
{
}


void Gray::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	gray_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Grayscale.fx"));
}

void Gray::State(KeyboardState & key_state)
{

}

void Gray::Buffer(KeyboardBuffer & key_buffer)
{

}

void Gray::Update()
{

}

void Gray::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Gray::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, gray_);
}