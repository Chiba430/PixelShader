//----------------------------------------------------------------------------
// File: Mosaic.fx 
// 
// The effect file for the Mosaic HLSL sample. 
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Global variables 
//----------------------------------------------------------------------------
sampler tex0 : register(s0);


float grids = 100.0f;

//----------------------------------------------------------------------------
// pass0 PixelShader Main Function 
//----------------------------------------------------------------------------
float4 PS_P0_Main(float2 UV : TEXCOORD0) : COLOR0 
{ 
	
	float2 ms_uv = floor(UV * grids + 0.5f) / grids;
	
	return tex2D(tex0, ms_uv);

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