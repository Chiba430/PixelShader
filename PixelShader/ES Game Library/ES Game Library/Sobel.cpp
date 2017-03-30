#include "Sobel.h"


Sobel::Sobel()
{
}


Sobel::~Sobel()
{
}

void Sobel::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	sobel_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Sobel.fx"));
}

void Sobel::Buffer(KeyboardBuffer &key_buffer)
{

}

void Sobel::State(KeyboardState &key_state)
{

}

void Sobel::Update()
{

}

void Sobel::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Sobel::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, sobel_);
}