#include "stdafx.h"
#include "ScratchImage.h"

SharpDXTex::ScratchImage::ScratchImage()
{
	_native = new DirectX::ScratchImage();
}

void SharpDXTex::ScratchImage::InitializeFromImage(Image srcImage, bool allow2D, int flags)
{
	auto nativeImage = srcImage.toNative();
	_native->InitializeFromImage(nativeImage, allow2D, flags);
}

SharpDXTex::ScratchImage::~ScratchImage()
{
	_native->Release();
	delete(_native);
}
