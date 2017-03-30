#include "Binarization.h"


Binarization::Binarization()
{
}


Binarization::~Binarization()
{
}

void Binarization::Initialize()
{

	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	binarization_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Binarization.fx")); //エフェクト (2値化)

}

void Binarization::State(KeyboardState & key_state)
{

}

void Binarization::Buffer(KeyboardBuffer & key_buffer)
{

}

void Binarization::Update()
{

}

void Binarization::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Binarization::DrawEnd()
{

	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, binarization_);

}