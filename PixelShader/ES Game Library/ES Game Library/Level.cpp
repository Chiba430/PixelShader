#include "Level.h"


Level::Level()
{
}


Level::~Level()
{
}

void Level::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	level_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Level.fx"));

	l_ = 0.1;
}

void Level::Buffer(KeyboardBuffer &key_buffer)
{
	if (key_buffer.IsPressed(Keys_Down)){

		l_ -= 0.1;

	}
	else if (l_ <= 0.1){

		l_ = 0.1;

	}

	if (key_buffer.IsPressed(Keys_Up)){

		l_ += 0.1;

	}
	else if (l_ >= 1.0){

		l_ = 1.0;

	}

	level_->SetParameter("l", l_);
}

void Level::State(KeyboardState &key_state)
{

}

void Level::Update()
{

}

void Level::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Level::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, level_);
}