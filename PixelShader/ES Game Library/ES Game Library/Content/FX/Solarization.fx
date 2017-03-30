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

float sola = 2.0f;
float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0

{

	float4 color = tex2D(tex0, UV);

	color.rgb = sin(color.rgb * 3.141592 * sola);

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