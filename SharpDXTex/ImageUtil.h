#pragma once

#include "TexMetadata.h"
#include "Image.h"
#include "ScratchImage.h"
#include "Enums.h"

namespace SharpDXTex
{
		public enum class RotateAngle : System::UInt32
		{
			Rotate0 = 0x0,
			Rotate90 = 0x1,
			Rotate180 = 0x2,
			Rotate270 = 0x3,
			FlipHorizotal = 0x08,
			FlipVertical = 0x10,
		};

		[System::Flags]
		public enum class FlipDirection
		{
			Horizotal = 0x08,
			Vertical = 0x10,
		};

		public value struct FlipRotateDescription
		{
		public:
			RotateAngle Angle;
			FlipDirection Direction;
		internal:
			uint32_t toFlags() {
				return (uint32_t)Angle | (uint32_t)Direction;
			}
		};

		public enum class FilterMode
		{
			Point = 0x100000,
			Linear = 0x200000,
			Cubic = 0x300000,
			Box = 0x400000,
			Fant = 0x400000,
			Triangle = 0x500000,
		};

		public value struct FilterDescription
		{
		public:
			bool WrapU;
			bool WrapV;
			bool WrapW;
			bool MirrorU;
			bool MirrorV;
			bool MirrorW;
			bool SeparateAlpha;
			bool CopyRed;
			bool CopyGreen;
			bool CopyBlue;
			bool Dither;
			bool DitherDiffusion;
			FilterMode Mode;
			bool SRGBIn;
			bool SRGBOut;
			bool ForceNonWIC;
			bool ForceWIC;
		internal:
			uint32_t toFlags() {
				uint32_t wrap = WrapU * 0x1 | WrapV * 0x2 | WrapW * 0x4;
				uint32_t mirror = MirrorU * 0x10 | MirrorV * 0x20 | MirrorW * 0x40;
				uint32_t separateAlpha = SeparateAlpha * 0x100;
				uint32_t rgbCopy = CopyRed * 0x1000 | CopyGreen * 0x2000 | CopyBlue * 0x4000;
				uint32_t dither = Dither * 0x10000 | DitherDiffusion * 0x20000;
				uint32_t mode = (uint32_t)mode;
				uint32_t srgb = SRGBIn * 0x1000000 | SRGBOut * 0x2000000;
				uint32_t wic = ForceNonWIC * 0x10000000 | ForceWIC * 0x20000000;
				return wrap | mirror | separateAlpha | rgbCopy | dither | mode | srgb | wic;
			}
		};

		public value struct PremultipliedAlphaDescription
		{
		public:
			bool IgnoreSRgb;
			bool SRgbIn;
			bool SRgbOut;
		internal:
			uint32_t toFlags() {
				return 0x1 * IgnoreSRgb | 0x1000000 * SRgbIn | 0x2000000 * SRgbOut;
			}
		};

		public value struct CompressDescription
		{
		public:
			bool RgbDither;
			bool AlphaDither;
			bool Uniform;
			bool BC7Use3Subsets;
			bool SrgbIn;
			bool SrgbOut;
			bool Parallel;
		internal:
			uint32_t toFlags() {
				uint32_t dither = 0x10000 * RgbDither | 0x20000 * AlphaDither;
				uint32_t uniform = 0x40000 * Uniform;
				uint32_t mode = 0x80000 * BC7Use3Subsets;
				uint32_t srgb = 0x1000000 * SrgbIn | 0x2000000 * SrgbOut;
				uint32_t parallel = 0x10000000 * Parallel;
				return dither | uniform | mode | srgb | parallel;
			}
		};

		public enum class Channel
		{
			None = 0,
			Red = 1,
			Green = 2,
			Blue = 3,
			Alpha = 4,
			Luminance = 5
		};
		
		public value struct ComputeNormalMapDescription
		{
		public:
			Channel Channel;
			bool MirrorU;
			bool MirrorV;
			bool InvertSign;
			bool ComputeOcclusion;
		internal:
			uint32_t getFlags() {
				uint32_t mirror = MirrorU * 0x1000 | MirrorV * 0x2000;
				return (uint32_t)Channel | mirror | InvertSign * 0x4000 | ComputeOcclusion * 0x8000;
			}
		};

		public value struct ComputeMeanSquaredErrorDescription
		{
		public:
			bool Image1SRgb;
			bool Image2SRgb;
			bool IgnoreRed;
			bool IgnoreGreen;
			bool IgnoreBlue;
			bool IgnoreAlpha;
			bool Image1X2Bias;
			bool Image2X2Bias;
		internal:
			uint32_t getFlags() {
				return 0;
			}
		};

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

		static ScratchImage^ FlipRotate(Image srcImage, FlipRotateDescription desc);
		static ScratchImage^ FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateDescription desc);

		static ScratchImage^ Resize(Image srcImage, int width, int height, FilterDescription desc);
		static ScratchImage^ Resize(array<Image>^ srcImages, TexMetadata metadata, int width, int height, FilterDescription desc);

		static ScratchImage^ Convert(Image srcImage, SharpDX::DXGI::Format format, FilterDescription desc, float threshold);
		static ScratchImage^ Convert(array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format, FilterDescription desc, float threshold);

		static ScratchImage^ ConvertToSinglePlane(Image srcImage);
		static ScratchImage^ ConvertToSinglePlane(array<Image>^ srcImages, TexMetadata metadata);

		static ScratchImage^ GenerateMipMaps(Image baseImage, FilterDescription filter, int levels, bool allow1D);
		static ScratchImage^ GenerateMipMaps(array<Image>^ baseImage, TexMetadata metadata, FilterDescription filter, int levels);

		static ScratchImage^ GenerateMipMaps3D(array<Image>^ baseImage, int depth, FilterDescription filter, int levels);
		static ScratchImage^ GenerateMipMaps3D(array<Image>^ baseImage, TexMetadata metadata, FilterDescription filter, int levels);

		static ScratchImage^ PremultiplyAlpha(Image srcImage, PremultipliedAlphaDescription desc);
		static ScratchImage^ PremultiplyAlpha(array<Image>^ srcImages, TexMetadata metadata, PremultipliedAlphaDescription desc);

		static ScratchImage^ Compress(Image srcImage, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaRef);
		static ScratchImage^ Compress(array<Image>^ srcImage, TexMetadata metadata, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaRef);

		static ScratchImage^ Compress(SharpDX::Direct3D11::Device^ device, Image srcImage, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaWight);
		static ScratchImage^ Compress(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaWight);

		static ScratchImage^ Decompress(Image image, SharpDX::DXGI::Format format);
		static ScratchImage^ Decompress(array<Image>^ images, TexMetadata metadata, SharpDX::DXGI::Format format);

		static ScratchImage^ ComputeNormalMap(Image image, ComputeNormalMapDescription flags, float amplitude, SharpDX::DXGI::Format format);
		static ScratchImage^ ComputeNormalMap(array<Image>^ image, TexMetadata metadata, ComputeNormalMapDescription flags, float amplitude, SharpDX::DXGI::Format format);

		static Image CopyRectagle(Image image, int x, int y, int w, int h, FilterDescription filter, int xOffset, int yOffset);

		static float ComputeMeanSquaredError(Image image1, Image image2, ComputeMeanSquaredErrorDescription flags, [System::Runtime::InteropServices::Out] array<float>^% mseV);
		static float ComputeMeanSquaredError(Image image1, Image image2, ComputeMeanSquaredErrorDescription flags);
	};
}
