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

float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0

{
	
	float4 color = tex2D(tex0, UV);

	//color.rgb = (color.r + color.g + color.b) / 3;

	color.rgb = 0.29891f * color.r + 0.58661f * color.g + 0.11448f * color.b;

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