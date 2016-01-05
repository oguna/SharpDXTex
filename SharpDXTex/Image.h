#pragma once
#include <DirectXTex.h>

namespace SharpDXTex
{
	public value struct Image
	{
	public:
		int Width;
		int Height;
		SharpDX::DXGI::Format Format;
		int RowPitch;
		int SlicePitch;
		System::IntPtr Pixels;
	internal:
		Image(const DirectX::Image& native);
		void toNative(DirectX::Image* native) {
			native->width = Width;
			native->height = Height;
			native->format = (DXGI_FORMAT)Format;
			native->rowPitch = RowPitch;
			native->slicePitch = SlicePitch;
			native->pixels = (uint8_t*)(void*)Pixels;
		}
		DirectX::Image toNative() {
			DirectX::Image image;
			image.width = Width;
			image.height = Height;
			image.format = (DXGI_FORMAT)Format;
			image.rowPitch = RowPitch;
			image.slicePitch = SlicePitch;
			image.pixels = (uint8_t*)(void*)Pixels;
			return image;
		}
	};
}