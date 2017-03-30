#include "Mosaic.h"


Mosaic::Mosaic()
{
}


Mosaic::~Mosaic()
{
}

void Mosaic::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	mosaic_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Mosaic.fx"));

	grids_ = 100.0;
}

void Mosaic::Buffer(KeyboardBuffer &key_buffer)
{

}

void Mosaic::State(KeyboardState &key_state)
{
	if (key_state.IsKeyDown(Keys_Down)){
		grids_ -= 0.3;
	}
	if (key_state.IsKeyDown(Keys_Up)){
		grids_ += 0.3;
	}

	mosaic_->SetParameter("grids", grids_);
}

void Mosaic::Update()
{

}

void Mosaic::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Mosaic::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, mosaic_);
}