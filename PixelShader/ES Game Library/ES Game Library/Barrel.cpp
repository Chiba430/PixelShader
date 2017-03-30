#include "Barrel.h"


Barrel::Barrel()
{
}


Barrel::~Barrel()
{
}

void Barrel::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	barrel_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Barrel.fx"));
}

void Barrel::State(KeyboardState & key_state)
{

}

void Barrel::Buffer(KeyboardBuffer & key_buffer)
{

}

void Barrel::Update()
{

}

void Barrel::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Barrel::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, barrel_);

}