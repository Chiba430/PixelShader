#include "Whitenoise.h"


Whitenoise::Whitenoise()
{
}


Whitenoise::~Whitenoise()
{
}

void Whitenoise::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	whitenoise_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Whitenoise.fx"));
}

void Whitenoise::Buffer(KeyboardBuffer &key_buffer)
{

}

void Whitenoise::State(KeyboardState &key_state)
{

}

void Whitenoise::Update()
{
	whitenoise_->SetParameter("Time", Math_Random());
}

void Whitenoise::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Whitenoise::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, whitenoise_);
}