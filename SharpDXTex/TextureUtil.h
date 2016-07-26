#pragma once

#include "TexMetadata.h"
#include "Image.h"
#include "ScratchImage.h"

namespace SharpDXTex
{
	public ref class TextureUtil
	{
	private:
		TextureUtil() {};
	public:
		static SharpDXTex::ScratchImage^ CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext^ context, SharpDX::Direct3D11::Resource^ resource);
	};
}
