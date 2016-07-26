#pragma once

#include <DirectXTex.h>
#include "Enums.h"

namespace SharpDXTex {
	public enum class Dimension : System::UInt32
	{
		Texture1D = 2,
		Texture2D = 3,
		Texture3D = 4
	};

	[System::Flags]
	public enum class MiscFlag : System::UInt32
	{
		None = 0x0,
		TexureCube = 0x4l
	};

	[System::Flags]
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
	internal:
		DirectX::TexMetadata toNative();
		TexMetadata(const DirectX::TexMetadata& metadata);
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

		bool IsSuportedTexture(SharpDX::Direct3D11::Device^ device);
		
		static SharpDXTex::TexMetadata FromDDSMemory(array<byte>^ buffer, DDSFlags flags);
		static SharpDXTex::TexMetadata FromDDSFile(System::String^ file, DDSFlags flags);
		static SharpDXTex::TexMetadata FromTGAMemory(array<byte>^ buffer);
		static SharpDXTex::TexMetadata FromTGAFile(System::String^ file);
		static SharpDXTex::TexMetadata FromWICMemory(array<byte>^ buffer, WICFlags flags);
		static SharpDXTex::TexMetadata FromWICFile(System::String^ file, WICFlags flags);
	};
}
