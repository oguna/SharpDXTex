#include "Stdafx.h"
#include "TexMetadata.h"

DirectX::TexMetadata SharpDXTex::TexMetadata::getNative() {
	DirectX::TexMetadata native;
	native.arraySize = this->ArraySize;
	native.height = this->Height;
	native.width = this->Width;
	native.depth = this->Depth;
	native.miscFlags = this->MiscFlags;
	native.miscFlags2 = this->MiscFlags2;
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
	this->MiscFlags = metadata.miscFlags;
	this->MiscFlags2 = metadata.miscFlags2;
	this->Format = (SharpDX::DXGI::Format)metadata.format;
	this->Dimension = (SharpDXTex::Dimension)metadata.dimension;
}