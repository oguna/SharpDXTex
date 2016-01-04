#pragma once
#include <DirectXTex.h>

namespace SharpDXTex {
	public enum class Dimension 
	{
		Texture1D = 2,
		Texture2D = 3,
		Texture3D = 4
	};

	public enum class MiscFlag
	{
		TexureCube = 0x4l
	};

	public enum class MiscFlag2
	{
		AlphaModeMask = 0x7l,
	};

	public enum class AlphaMode
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
		int MiscFlags;
		int MiscFlags2;
		SharpDX::DXGI::Format Format;
		Dimension Dimension;
	internal:
		DirectX::TexMetadata getNative();
		TexMetadata(const DirectX::TexMetadata& metadata);
	};
}