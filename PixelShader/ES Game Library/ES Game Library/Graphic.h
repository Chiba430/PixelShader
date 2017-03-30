#pragma once
#include "ESGLib.h"
class Graphic
{
public:
	Graphic();
	~Graphic();

	void Initialize();
	void Update(KeyboardBuffer &keybuffer);
	void Draw();

private:

	SPRITE main;
	SPRITE grass;
	SPRITE hand;
	SPRITE ice;

	enum {_main = 0,
	      _grass = 1,
	      _hand = 2,
	      _ice = 3};

	int num;


};

