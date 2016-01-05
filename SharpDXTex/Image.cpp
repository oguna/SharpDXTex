#include "Stdafx.h"
#include "Image.h"

SharpDXTex::Image::Image(const DirectX::Image& native) {
	this->Width = native.width;
	this->Height = native.height;
	this->Format = (SharpDX::DXGI::Format)native.format;
	this->RowPitch = native.rowPitch;
	this->SlicePitch = native.slicePitch;
	this->Pixels = (System::IntPtr)native.pixels;
}
