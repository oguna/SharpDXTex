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