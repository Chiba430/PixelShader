#include "Gaussian.h"


Gaussian::Gaussian()
{
}


Gaussian::~Gaussian()
{
}

void Gaussian::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	gaussian_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Gaussian.fx"));
}

void Gaussian::State(KeyboardState & key_state)
{

}

void Gaussian::Buffer(KeyboardBuffer & key_buffer)
{

}

void Gaussian::Update()
{

}

void Gaussian::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Gaussian::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, gaussian_);
}