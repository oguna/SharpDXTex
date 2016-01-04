#include "Stdafx.h"
#include "Image.h"

SharpDXTex::Image::Image(DirectX::Image* native) {
	this->Width = native->width;
	this->Height = native->height;
	this->Format = native->format;
	this->RowPitch = native->rowPitch;
	this->SlicePitch = native->slicePitch;
}
