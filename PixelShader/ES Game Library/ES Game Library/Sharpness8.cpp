#include "Sharpness8.h"


Sharpness8::Sharpness8()
{
}


Sharpness8::~Sharpness8()
{
}

void Sharpness8::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	sharpness8_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Sharpness8.fx"));
}

void Sharpness8::Buffer(KeyboardBuffer &key_buffer)
{

}

void Sharpness8::State(KeyboardState &key_state)
{

}

void Sharpness8::Update()
{

}

void Sharpness8::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Sharpness8::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, sharpness8_);
}