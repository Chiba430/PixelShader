#include "Solarization.h"


Solarization::Solarization()
{
}


Solarization::~Solarization()
{
}

void Solarization::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	solarization_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Solarization.fx"));

	sola_ = 2.0f;
}

void Solarization::Buffer(KeyboardBuffer &key_buffer)
{

}

void Solarization::State(KeyboardState &key_state)
{
	if (key_state.IsKeyDown(Keys_Down)){

		sola_ -= 0.1f;

	}

	if (key_state.IsKeyDown(Keys_Up)){

		sola_ += 0.1f;

	}

	solarization_->SetParameter("sola", sola_);
}

void Solarization::Update()
{

}

void Solarization::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Solarization::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, solarization_);
}