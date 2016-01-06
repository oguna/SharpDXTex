#pragma once

#include "TexMetadata.h"
#include "Image.h"
#include "ScratchImage.h"
#include "Enums.h"

namespace SharpDXTex
{
	public ref class ImageUtil
	{
	private:
		ImageUtil();
	public:
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs);

		static ScratchImage^ FlipRotate(Image srcImage, FlipRotateFlags flags);
		static ScratchImage^ FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateFlags flags);
	};
}
