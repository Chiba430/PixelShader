//----------------------------------------------------------------------------
// File: Raster.fx 
// 
// The effect file for the Raster HLSL sample. 
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Global variables 
//----------------------------------------------------------------------------
sampler tex0 : register(s0) = sampler_state { 
	MipFilter = LINEAR; 
	MinFilter = LINEAR; 
	MagFilter = LINEAR; 
	AddressU = WRAP; 
	AddressV = WRAP; 
};

float amplitude = 1.0f; 
float division = 1.0f;

//----------------------------------------------------------------------------
// pass0 PixelShader Main Function 
//----------------------------------------------------------------------------
float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0 
{ 

	UV.x += sin(UV.y * 3.141952 * division) * 5.0f * amplitude;

	return tex2D(tex0, UV); 

}
//----------------------------------------------------------------------------
// Techniques 
//----------------------------------------------------------------------------
technique Raster 
{
	pass P0 
	{
		VertexShader = NULL; 
		PixelShader = compile ps_2_0 PS_P0_Main();	
	} 
}