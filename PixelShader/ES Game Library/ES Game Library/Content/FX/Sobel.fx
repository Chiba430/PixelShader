//-----------------------------------------------------------------------------

// File: Sobel.fx

//

// The effect file for the Sobel Filter HLSL sample.

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

	// pixel

	float4 p0 = tex2D(tex0, UV);

	float4 p1 = tex2D(tex0, UV + float2(-AddU, -AddV));

	float4 p2 = tex2D(tex0, UV + float2(0.0f, -AddV));

	float4 p3 = tex2D(tex0, UV + float2(+AddU, -AddV));

	float4 p4 = tex2D(tex0, UV + float2(-AddU, 0.0f));

	// float4 p5 = tex2D( tex0, UV + float2( 0.0f, 0.0f) );

	float4 p6 = tex2D(tex0, UV + float2(+AddU, 0.0f));

	float4 p7 = tex2D(tex0, UV + float2(-AddU, +AddV));

	float4 p8 = tex2D(tex0, UV + float2(0.0f, +AddV));

	float4 p9 = tex2D(tex0, UV + float2(+AddU, +AddV));

	// x-axsis

	float4 x0 = p0 * 0.0f;

	float4 x1 = p1 * -1.0f;

	float4 x2 = p2 * 0.0f;

	float4 x3 = p3 * 1.0f;

	float4 x4 = p4 * -2.0f;

	float4 x6 = p6 * 2.0f;

	float4 x7 = p7 * -1.0f;

	float4 x8 = p8 * 0.0f;

	float4 x9 = p9 * 1.0f;

	// y-axsis

	float4 y0 = p0 * 0.0f;

	float4 y1 = p1 * -1.0f;

	float4 y2 = p2 * -2.0f;

	float4 y3 = p3 * -1.0f;

	float4 y4 = p4 * 0.0f;

	float4 y6 = p6 * 0.0f;

	float4 y7 = p7 * 1.0f;

	float4 y8 = p8 * 2.0f;

	float4 y9 = p9 * 1.0f;

	// variance

	float4 cx = x0 + x1 + x2 + x3 + x4 + x6 + x7 + x8 + x9;

	float4 cy = y0 + y1 + y2 + y3 + y4 + y6 + y7 + y8 + y9;

	// pixel-color

	float4 color;

	color = sqrt(cx * cx + cy * cy);

	// color.rgb = (color.r + color.g + color.b) / 3.0f;

	color.a = 1.0f;

	return color;

}

//-----------------------------------------------------------------------------

// Techniques

//-----------------------------------------------------------------------------

technique Sobel

{

	pass P0

	{

		VertexShader = NULL;

		PixelShader = compile ps_2_0 PS_P0_Main();

	}

}