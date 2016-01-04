#include "stdafx.h"
#include "ScratchImage.h"

SharpDXTex::ScratchImage::ScratchImage()
{
	_native = new DirectX::ScratchImage();
}

void SharpDXTex::ScratchImage::InitializeFromImage(Image^ srcImage, bool allow2D, int flags)
{
	auto pImage = srcImage->_native;
	_native->InitializeFromImage(*pImage, allow2D, flags);
}