#include "Laplacian8.h"


Laplacian8::Laplacian8()
{
}


Laplacian8::~Laplacian8()
{
}

void Laplacian8::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	laplacian8 = GraphicsDevice.CreateEffectFromFile(_T("FX\\Laplacian8.fx"));
}

void Laplacian8::Buffer(KeyboardBuffer &key_buffer)
{

}

void Laplacian8::State(KeyboardState &key_state)
{

}

void Laplacian8::Update()
{

}

void Laplacian8::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Laplacian8::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, laplacian8);
}