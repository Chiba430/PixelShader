#include "Laplacian4.h"


Laplacian4::Laplacian4()
{
}


Laplacian4::~Laplacian4()
{
}

void Laplacian4::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	laplacian4 = GraphicsDevice.CreateEffectFromFile(_T("FX\\Laplacian4.fx"));
}

void Laplacian4::Buffer(KeyboardBuffer &key_buffer)
{

}

void Laplacian4::State(KeyboardState &key_state)
{

}

void Laplacian4::Update()
{

}

void Laplacian4::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Laplacian4::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, laplacian4);
}