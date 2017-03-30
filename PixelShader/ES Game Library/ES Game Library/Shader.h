#pragma once
#include "ESGLib.h"
#include "Collect.h"

class Shader 
{
public:
	Shader();
	~Shader();

	void Initialize(const int shader_id);
	void Control(KeyboardBuffer &key_buffer);
	void Buffer(KeyboardBuffer &key_buffer);
	void State(KeyboardState &key_state);
	void Update();
	void DrawBegin();
	void DrawEnd();

	ShaderSource *type;

	int name;
	
	enum {
		_barrel = 0,
		_binarization = 1,
		_blur = 2,
		_contrast = 3,
		_copy = 4,
		_emboss = 5,
		_gamma = 6,
		_gaussian = 7,
		_glass = 8,
		_gradient = 9,
		_gray = 10,
		_laplacian4 = 11,
		_laplacian8 = 12,
		_level = 13,
		_mosaic = 14,
		_night = 15,
		_posterization = 16,
		_prewitt = 17,
		_qper = 18,
		_raster = 19,
		_reversi = 20,
		_roberts = 21,
		_sepia = 22,
		_sharpness4 = 23,
		_sharpness8 = 24,
		_sine = 25,
		_smoothing = 26,
		_sobel = 27,
		_solarization = 28,
		_watercolor = 29,
		_whitenoise = 30
	};

};



