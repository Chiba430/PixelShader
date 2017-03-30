#include "Qper.h"


Qper::Qper()
{
}


Qper::~Qper()
{
}

void Qper::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	qper_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Qper.fx"));
}

void Qper::Buffer(KeyboardBuffer &key_buffer)
{

}

void Qper::State(KeyboardState &key_state)
{

}

void Qper::Update()
{

}

void Qper::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Qper::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, qper_);
}