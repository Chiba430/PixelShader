#include "Raster.h"


Raster::Raster()
{
}


Raster::~Raster()
{
}

void Raster::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);
	raster_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Raster.fx"));

	division_ = 1.0f;
	amplitude_ = 1.0f;
}

void Raster::Buffer(KeyboardBuffer &key_buffer)
{

}

void Raster::State(KeyboardState &key_state)
{

}

void Raster::Update()
{
	amplitude_ += 0.01;

	if (amplitude_ >= 2.0){

		amplitude_ -= 0.01;

	}
	else if (amplitude_ <= 1.0){

		amplitude_ += 0.01;

	}

	division_ -= 0.01;

	if (division_ <= -1.0){

		division_ += 0.01;

	}
	else if (division_ >= 1.0){

		division_ -= 0.01;

	}


	raster_->SetParameter("amplitude", amplitude_);

	raster_->SetParameter("division", division_);
}

void Raster::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Raster::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, raster_);
}