#include "Stdafx.h"
#include "TexMetadata.h"

DirectX::TexMetadata SharpDXTex::TexMetadata::toNative()
{
	DirectX::TexMetadata native;
	native.arraySize = this->ArraySize;
	native.height = this->Height;
	native.width = this->Width;
	native.depth = this->Depth;
	native.miscFlags = (uint32_t)this->MiscFlags;
	native.miscFlags2 = (uint32_t)this->MiscFlags2;
	native.format = (DXGI_FORMAT) this->Format;
	native.dimension = (DirectX::TEX_DIMENSION)this->Dimension;
	native.mipLevels = this->MipLevels;
	return native;
}

SharpDXTex::TexMetadata::TexMetadata(const DirectX::TexMetadata& metadata)
{
	this->Width = metadata.width;
	this->Height = metadata.height;
	this->Depth = metadata.depth;
	this->ArraySize = metadata.arraySize;
	this->MipLevels = metadata.mipLevels;
	this->MiscFlags = (SharpDXTex::MiscFlag)metadata.miscFlags;
	this->MiscFlags2 = (SharpDXTex::MiscFlag2)metadata.miscFlags2;
	this->Format = (SharpDX::DXGI::Format)metadata.format;
	this->Dimension = (SharpDXTex::Dimension)metadata.dimension;
}

int SharpDXTex::TexMetadata::ComputeIndex(int mip, int item, int slice)
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.ComputeIndex(mip, item, slice);
}

bool SharpDXTex::TexMetadata::IsCubemap()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsCubemap();
}

bool SharpDXTex::TexMetadata::IsPMAlpha()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsPMAlpha();
}

void SharpDXTex::TexMetadata::SetAlphaMode(AlphaMode mode)
{
	auto native = this->toNative();
	native.SetAlphaMode((DirectX::TEX_ALPHA_MODE)mode);
	this->MiscFlags2 = (SharpDXTex::MiscFlag2)native.miscFlags2;
}

bool SharpDXTex::TexMetadata::IsVolumemap()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsVolumemap();
}
