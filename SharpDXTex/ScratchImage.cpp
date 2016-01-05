#include "stdafx.h"
#include "ScratchImage.h"

SharpDXTex::ScratchImage::ScratchImage()
{
	_native = new DirectX::ScratchImage();
}

void SharpDXTex::ScratchImage::InitializeFromImage(Image^ srcImage, bool allow2D, int flags)
{
	DirectX::Image nativeImage;
	srcImage->toNative(&nativeImage);
	_native->InitializeFromImage(nativeImage, allow2D, flags);
}