#pragma once
#include "Image.h"
#include "ScratchImage.h"
#include "TexMetadata.h"

namespace SharpDXTex
{
	[System::Flags]
	public enum class DDSFlags : System::UInt32
	{
		None = 0x0,
		LegacyDWord = 0x1,
		NoLegacyExpansion = 0x2,
		NoR10B10G10A2Fixup = 0x4,
		ForceRgb = 0x8,
		No16Bpp = 0x10,
		ExpandLuminance = 0x20,
		ForceDx10Ext = 0x10000,
		ForceDx10ExtMisc2 = 0x20000
	};

	[System::Flags]
	public enum class WICFlags : System::UInt32 {
		None = 0x0,
		LegacyRgb = 0x1,
		NoX2Bias = 0x2,
		No16Bpp = 0x4,
		AllowMono = 0x8,
		AllFrames = 0x10,
		IgnoreSrgb = 0x20,
		Dither = 0x10000,
		DitherDiffusion = 0x20000,
		FilterPoint = 0x100000,
		FilterLinear = 0x200000,
		FilterCubic = 0x300000,
		FilterFant = 0x400000,
	};

	[System::Flags]
	public enum class FlipRotateFlags : System::UInt32
	{
		Rotate0 = 0x0,
		Rotate90 = 0x1,
		Rotate180 = 0x2,
		Rotate270 = 0x3,
		FlipHorizotal = 0x08,
		FlipVertical = 0x10,
	};

	public ref class ImageUtil
	{
	private:
		ImageUtil();
	public:
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags);
		
		static ScratchImage^ FlipRotate(Image srcImage, FlipRotateFlags flags);
		static ScratchImage^ FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateFlags flags);
	};
}
