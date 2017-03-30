#include "Sepia.h"


Sepia::Sepia()
{
}


Sepia::~Sepia()
{
}

void Sepia::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	sepia_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Sepia.fx"));
}

void Sepia::Buffer(KeyboardBuffer &key_buffer)
{

}

void Sepia::State(KeyboardState &key_state)
{

}

void Sepia::Update()
{

}

void Sepia::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Sepia::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, sepia_);
}