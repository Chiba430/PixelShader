//-----------------------------------------------------------------------------

// File: Enverse.fx

//

// The effect file for the HLSL sample.

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

// Global variables

//-----------------------------------------------------------------------------

sampler tex0 : register(s0);

//-----------------------------------------------------------------------------

// pass0 PixelShader Main Function

//-----------------------------------------------------------------------------

 int r = 1;

float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0

{

	float4 color = tex2D(tex0, UV);

	if (r == 0){

		color.r = color.r;
		color.g = color.g;
		color.b = color.b;

	}
	if (r == 1){

		color.r = 1.0f - color.r;
		color.g = 1.0f - color.g;
		color.b = 1.0f - color.b;

	}


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