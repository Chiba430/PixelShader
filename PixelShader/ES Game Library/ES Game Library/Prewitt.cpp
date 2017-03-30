#include "Prewitt.h"


Prewitt::Prewitt()
{
}


Prewitt::~Prewitt()
{
}

void Prewitt::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	prewitt_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Prewitt.fx"));
}

void Prewitt::Buffer(KeyboardBuffer &key_buffer)
{

}

void Prewitt::State(KeyboardState &key_state)
{

}

void Prewitt::Update()
{

}

void Prewitt::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Prewitt::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, prewitt_);
}