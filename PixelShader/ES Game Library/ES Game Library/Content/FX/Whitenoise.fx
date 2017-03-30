//----------------------------------------------------------------------------
// File: Mosaic.fx 
// 
// The effect file for the Mosaic HLSL sample. 
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Global variables 
//----------------------------------------------------------------------------
sampler tex0 : register(s0);

float Time = 1.0;

float rand(float2 co){
	return frac(sin(dot(co.xy, float2(12.9898, 78.233))) * 43758.5453);
}

//----------------------------------------------------------------------------
// pass0 PixelShader Main Function 
//----------------------------------------------------------------------------
float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0
{
	float3 color = tex2D(tex0, UV);

	float2 pos = UV;
	pos *= sin(Time);
	float r = rand(pos);

	float3 noise = float3(r, r, r);
	float noise_intensity = 0.3;

	color = lerp(color, noise, noise_intensity);
	
	return float4(color, 1.0);
}
//----------------------------------------------------------------------------
// Techniques 
//----------------------------------------------------------------------------
technique Mosaic {
	pass P0
	{
		VertexShader = NULL;
		PixelShader = compile ps_2_0 PS_P0_Main();
	}
}