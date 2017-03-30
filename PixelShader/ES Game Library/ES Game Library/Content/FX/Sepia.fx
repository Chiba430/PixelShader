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
// �Z�s�A�p�[�g�P

	/*color.rgb = 0.29891f * color.r + 0.58661f * color.g + 0.11448f * color.b;

	color.r = color.r * 0.941176;

	color.g = color.g * 0.784313;

	color.b = color.b * 0.293103;*/

// �Z�s�A�p�[�g�Q
	float4 mono = float4(0.298912, 0.586611, 0.114478, 0.0);
		float4 sepia = float4(0.941176, 0.784313, 0.293103, 1.0);
		color.rgb = dot(color.rgb, mono);
	color.a = 1.0;
	color.rgb *= sepia;

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