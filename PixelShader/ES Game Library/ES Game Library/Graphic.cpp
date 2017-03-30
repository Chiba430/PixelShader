#include "Graphic.h"


Graphic::Graphic()
{
	
}


Graphic::~Graphic()
{
}

void Graphic::Initialize()
{

	num = _main;

	main = GraphicsDevice.CreateSpriteFromFile(_T("default.png"));
	grass = GraphicsDevice.CreateSpriteFromFile(_T("grass.png"));
	hand = GraphicsDevice.CreateSpriteFromFile(_T("hand.png"));
	ice = GraphicsDevice.CreateSpriteFromFile(_T("ice.png"));
	
	
}

void Graphic::Update(KeyboardBuffer &key_buffer)
{
	if (key_buffer.IsPressed(Keys_Space)){
		num++;
		if (num > _ice){
			num = _main;
		}
	}
}

void Graphic::Draw()
{
	switch (num)
	{
	case _main:
		SpriteBatch.Draw(*main, Vector3(0.0f, 0.0f, 0.0f));
		break;
	case _grass:
		SpriteBatch.Draw(*grass, Vector3(0.0f, 0.0f, 0.0f));
		break;
	case _hand:
		SpriteBatch.Draw(*hand, Vector3(0.0f, 0.0f, 0.0f));
		break;
	case _ice:
		SpriteBatch.Draw(*ice, Vector3(0.0f, 0.0f, 0.0f));
		break;
	default:
		SpriteBatch.Draw(*main, Vector3(0.0f, 0.0f, 0.0f));
		break;
	}
	

}