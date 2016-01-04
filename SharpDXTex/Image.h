#pragma once
#include <DirectXTex.h>

namespace SharpDXTex
{
	public ref class Image
	{
	internal:
		DirectX::Image* _native;
	public:
		int Width;
		int Height;
		DXGI_FORMAT Format;
		int RowPitch;
		int SlicePitch;
		array<byte>^ Pixels;
	internal:
		Image(DirectX::Image* native);
	};
}