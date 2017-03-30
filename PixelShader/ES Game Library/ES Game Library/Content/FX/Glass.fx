//-----------------------------------------------------------------------------

// File: Enverse.fx

//

// The effect file for the HLSL sample.

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

// Global variables

//-----------------------------------------------------------------------------

sampler tDiffusu : register(s0);

//-----------------------------------------------------------------------------

// pass0 PixelShader Main Function

//-----------------------------------------------------------------------------

float rand(float2 co){

	float a = frac(dot(co, float2(2.067390879775102, 12.451168662908249))) - 0.5;
	float s = a * (6.182785114200511 + a * a * (-38.026512460676566 + a * a * 53.392573080032137));

	float t = frac(s * 43758.5453);

	return t;

}


float2  vScreenSize = float2(1280.0f, 720.0f);


float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0

{

	float radius = 5.0;

	float x = (UV.x * vScreenSize.x) + rand(UV) * radius * 2.0 - radius;
	float y = (UV.y * vScreenSize.y) + rand(float2(UV.y, UV.x)) * radius * 2.0 - radius;

//	UV.x = x / vScreenSize.x;
//	UV.y = y / vScreenSize.y;

//	float4 color = tex2D(tDiffusu, UV);
	float4 color = tex2D(tDiffusu, float2(x, y) / vScreenSize);


	return color;

}

//-----------------------------------------------------------------------------

// Techniques

//-----------------------------------------------------------------------------

technique Inverse

{

	pass P0

	{

		VertexShader = NULL;

		PixelShader = compile ps_2_0 PS_P0_Main();

	}

}