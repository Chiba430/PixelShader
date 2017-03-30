#include "Night.h"


Night::Night()
{
}


Night::~Night()
{
}

void Night::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	night_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Night.fx"));
}

void Night::Buffer(KeyboardBuffer &key_buffer)
{

}

void Night::State(KeyboardState &key_state)
{

}

void Night::Update()
{

}

void Night::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Night::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, night_);
}