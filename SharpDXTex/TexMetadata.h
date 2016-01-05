#pragma once
#include <DirectXTex.h>

namespace SharpDXTex {
	public enum class Dimension : System::UInt32
	{
		Texture1D = 2,
		Texture2D = 3,
		Texture3D = 4
	};

	[System::FlagsAttribute]
	public enum class MiscFlag : System::UInt32
	{
		None = 0x0,
		TexureCube = 0x4l
	};

	[System::FlagsAttribute]
	public enum class MiscFlag2 : System::UInt32
	{
		None = 0x0,
		AlphaModeMask = 0x7l,
	};

	public enum class AlphaMode : System::UInt32
	{
		Unknown = 0,
		Straight = 1,
		Premultiplied = 2,
		Opaque = 3,
		Custom = 4
	};

	public value struct TexMetadata
	{
	public:
		int Width;
		int Height;
		int Depth;
		int ArraySize;
		int MipLevels;
		MiscFlag MiscFlags;
		MiscFlag2 MiscFlags2;
		SharpDX::DXGI::Format Format;
		Dimension Dimension;

		int ComputeIndex(int mip, int item, int slice);
		bool IsCubemap();
		bool IsPMAlpha();
		void SetAlphaMode(AlphaMode mode);
		bool IsVolumemap();
	internal:
		DirectX::TexMetadata toNative();
		TexMetadata(const DirectX::TexMetadata& metadata);
	};
}