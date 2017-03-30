#include "Posterization.h"


Posterization::Posterization()
{
}


Posterization::~Posterization()
{
}

void Posterization::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	posterization_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Posterization.fx"));

	bits_ = 32;
}

void Posterization::Buffer(KeyboardBuffer &key_buffer)
{

}

void Posterization::State(KeyboardState &key_state)
{
	if (key_state.IsKeyDown(Keys_Up)){
		bits_ += 1;
	}
	if (key_state.IsKeyDown(Keys_Down)){
		bits_ -= 1;
	}


	posterization_->SetParameter("bits", bits_);
}

void Posterization::Update()
{

}

void Posterization::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Posterization::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, posterization_);
}