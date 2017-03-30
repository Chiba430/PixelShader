#include "Reversi.h"


Reversi::Reversi()
{
}


Reversi::~Reversi()
{
}

void Reversi::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	reversi_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Reversi.fx"));

	r_ = 0;
}

void Reversi::Buffer(KeyboardBuffer &key_buffer)
{
	if (key_buffer.IsPressed(Keys_Enter)){
		if (r_ == 0){
			r_ = 1;
		}
		else {
			r_ = 0;
		}
	}

	reversi_->SetParameter("r", r_);
}

void Reversi::State(KeyboardState &key_state)
{

}

void Reversi::Update()
{

}

void Reversi::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Reversi::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, reversi_);
}