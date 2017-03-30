#include "Smoothing.h"


Smoothing::Smoothing()
{
}


Smoothing::~Smoothing()
{
}

void Smoothing::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	smoothing_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Smoothing.fx"));
}

void Smoothing::Buffer(KeyboardBuffer &key_buffer)
{

}

void Smoothing::State(KeyboardState &key_state)
{

}

void Smoothing::Update()
{

}

void Smoothing::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Smoothing::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, smoothing_);
}