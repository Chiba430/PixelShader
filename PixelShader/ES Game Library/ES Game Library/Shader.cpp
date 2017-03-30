#include "Shader.h"


Shader::Shader() : type(nullptr)
{
	
}


Shader::~Shader()
{
	delete type;
	type = nullptr;
}

void Shader::Initialize(const int shader_id)
{
	switch (shader_id)
	{
	case _barrel:
		type = new Barrel;
		break;
	case _binarization:
		type = new Binarization;
		break;
	case _blur:
		type = new Blur;
		break;
	case _contrast:
		type = new Contrast;
		break;
	case _copy:
		type = new Copy;
		break;
	case _emboss:
		type = new Emboss;
		break;
	case _gamma:
		type = new Gamma;
		break;
	case _gaussian:
		type = new Gaussian;
		break;
	case _glass:
		type = new Glass;
		break;
	case _gradient:
		type = new Gradient;
		break;
	case _gray:
		type = new Gray;
		break;
	case _laplacian4:
		type = new Laplacian4;
		break;
	case _laplacian8:
		type = new Laplacian8;
		break;
	case _level:
		type = new Level;
		break;
	case _mosaic:
		type = new Mosaic;
		break;
	case _night:
		type = new Night;
		break;
	case _posterization:
		type = new Posterization;
		break;
	case _prewitt:
		type = new Prewitt;
		break;
	case _qper:
		type = new Qper;
		break;
	case _raster:
		type = new Raster;
		break;
	case _reversi:
		type = new Reversi;
		break;
	case _roberts:
		type = new Roberts;
		break;
	case _sepia:
		type = new Sepia;
		break;
	case _sharpness4:
		type = new Sharpness4;
		break;
	case _sharpness8:
		type = new Sharpness8;
		break;
	case _sine:
		type = new Sine;
		break;
	case _smoothing:
		type = new Smoothing;
		break;
	case _sobel:
		type = new Sobel;
		break;
	case _solarization:
		type = new Solarization;
		break;
	case _watercolor:
		type = new Watercolor;
		break;
	case _whitenoise:
		type = new Whitenoise;
		break;
	}
	
	type->Initialize();

	name = shader_id;
	
}

void Shader::Control(KeyboardBuffer &key_buffer)
{
	
	

	if (key_buffer.IsPressed(Keys_A)){
		name--;
		if (name < _barrel){
			name = _whitenoise;
		}
		Initialize(name);
		
	}

	if (key_buffer.IsPressed(Keys_D)){
		name++;
		if (name > _whitenoise){
			name = _barrel;
		}
		Initialize(name);
	}
	
	
	
}

void Shader::Buffer(KeyboardBuffer &key_buffer)
{
	type->Buffer(key_buffer);
}

void Shader::State(KeyboardState &key_state)
{

	type->State(key_state);

}

void Shader::Update()
{
	type->Update();
}

void Shader::DrawBegin()
{
	type->DrawBegin();
}

void Shader::DrawEnd()
{
	type->DrawEnd();
	
}

