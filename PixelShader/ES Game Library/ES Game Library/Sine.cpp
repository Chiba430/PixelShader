#include "Sine.h"


Sine::Sine()
{
}


Sine::~Sine()
{
}

void Sine::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	sine_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Sine.fx"));
	
	n_ = 1.0;
}

void Sine::Buffer(KeyboardBuffer &key_buffer)
{

}

void Sine::State(KeyboardState &key_state)
{

}

void Sine::Update()
{
	n_ += 0.01;

	if (n_ >= 5.0){
		n_ = 1.0;
	}
	sine_->SetParameter("Time", n_);
}

void Sine::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Sine::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, sine_);
}