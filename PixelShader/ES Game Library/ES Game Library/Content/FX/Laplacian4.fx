//-----------------------------------------------------------------------------

// File: Blur.fx

//

// The effect file for the Basic Blur HLSL sample.

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

// Global variables

//-----------------------------------------------------------------------------

sampler tex0 : register(s0);

float AddU = 1.0f / 1280.0f;
float AddV = 1.0f / 720.0f;

//-----------------------------------------------------------------------------

// pass0 PixelShader Main Function

//-----------------------------------------------------------------------------

float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0

{

	float4 txl0 = tex2D(tex0, UV + float2(0.0f, 0.0f)) * 4;

	float4 txl1 = tex2D(tex0, UV + float2(-AddU, -AddV)) * 0;

	float4 txl2 = tex2D(tex0, UV + float2(0.0f, -AddV)) * -1;

	float4 txl3 = tex2D(tex0, UV + float2(+AddU, -AddV)) * 0;

	float4 txl4 = tex2D(tex0, UV + float2(-AddU, 0.0f)) * -1;

	float4 txl5 = tex2D(tex0, UV + float2(+AddU, 0.0f)) * -1;

	float4 txl6 = tex2D(tex0, UV + float2(-AddU, +AddV)) * 0.0;

	float4 txl7 = tex2D(tex0, UV + float2(0.0f, +AddV)) * -1;

	float4 txl8 = tex2D(tex0, UV + float2(+AddU, +AddV)) * 0;

	float4 color = txl0 + txl1 + txl2 + txl3 + txl4 + txl5 + txl6 + txl7 + txl8;

	return color;

}

//-----------------------------------------------------------------------------

// Techniques

//-----------------------------------------------------------------------------

technique Blur

{

	pass P0

	{

		VertexShader = NULL;

		PixelShader = compile ps_2_0 PS_P0_Main();

	}

}