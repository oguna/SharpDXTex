#pragma once
#include "TexMetadata.h"
#include "ScratchImage.h"

namespace SharpDXTex
{
	public ref class ImageHelper
	{
	public:
		static void LoadFromWICFile(System::String^ file, int flags, [System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv[System::Runtime::InteropServices::Out] TexMetadata^ metadata, [System::Runtime::InteropServices::Out] ScratchImage^ image);
	};
}