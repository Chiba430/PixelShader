#include "Gamma.h"


Gamma::Gamma()
{
}


Gamma::~Gamma()
{
}

void Gamma::Initialize()
{
	offscreen_ = GraphicsDevice.CreateRenderTarget(1280, 720, PixelFormat_RGBA8888, DepthFormat_Unknown);

	gamma_ = GraphicsDevice.CreateEffectFromFile(_T("FX\\Gamma.fx")); //エフェクト (ガンマ補正)

	g_ = 0.5; //ガンマ補正グローバル変数
}

void Gamma::State(KeyboardState & key_state)
{

}

void Gamma::Buffer(KeyboardBuffer & key_buffer)
{
	if (key_buffer.IsPressed(Keys_Down)){

		g_ -= 0.1;

	}
	else if (g_ <= 0.1){

		g_ = 0.1;

	}

	if (key_buffer.IsPressed(Keys_Up)){

		g_ += 0.1;

	}
	else if (g_ >= 4.0){

		g_ = 4.0;

	}

	gamma_->SetParameter("g", g_);
}

void Gamma::Update()
{

}

void Gamma::DrawBegin()
{
	GraphicsDevice.SetRenderTarget(offscreen_);
	GraphicsDevice.Clear(Color_Black);
}

void Gamma::DrawEnd()
{
	GraphicsDevice.RenderTargetToBackBuffer(offscreen_, gamma_);
}