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
		static ScratchImage^ LoadFromDDSFile(System::String^ file, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromDDSFile(System::String^ file, DDSFlags flags);
		static ScratchImage^ LoadFromDDSMemory(array<byte>^ source, DDSFlags flasgs, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromDDSMemory(array<byte>^ source, DDSFlags flasgs);

		static ScratchImage^ LoadFromTGAFile(System::String^ file, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromTGAFile(System::String^ file);
		static ScratchImage^ LoadFromTGAMemory(array<byte>^ source, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromTGAMemory(array<byte>^ source);

		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs);

		static ScratchImage^ FlipRotate(Image srcImage, FlipRotateFlags flags);
		static ScratchImage^ FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateFlags flags);
	};
}
