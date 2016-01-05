#include "stdafx.h"
#include "ScratchImage.h"
#include <memory>

SharpDXTex::ScratchImage::ScratchImage() {
	_native = new DirectX::ScratchImage();
}

SharpDXTex::ScratchImage::~ScratchImage() {
	_native->Release();
	delete(_native);
}

void SharpDXTex::ScratchImage::Initialize(TexMetadata mdata, ComputePitchFlags flags) {
	_native->Initialize(mdata.toNative(), (DWORD)flags);
}

void SharpDXTex::ScratchImage::Initialize(TexMetadata mdata) {
	_native->Initialize(mdata.toNative());
}

void SharpDXTex::ScratchImage::Initialize1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels, ComputePitchFlags flags) {
	_native->Initialize1D((DXGI_FORMAT)fmt, length, arraySize, mipLevels, (DWORD)flags);
}

void SharpDXTex::ScratchImage::Initialize1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels) {
	_native->Initialize1D((DXGI_FORMAT)fmt, length, arraySize, mipLevels);
}

void SharpDXTex::ScratchImage::Initialize2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels, ComputePitchFlags flags) {
	_native->Initialize2D((DXGI_FORMAT)fmt, width, height, arraySize, mipLevels, (DWORD)flags);
}

void SharpDXTex::ScratchImage::Initialize2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels) {
	_native->Initialize2D((DXGI_FORMAT)fmt, width, height, arraySize, mipLevels);
}

void SharpDXTex::ScratchImage::Initialize3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels, ComputePitchFlags flags) {
	_native->Initialize3D((DXGI_FORMAT)fmt, width, height, depth, mipLevels, (DWORD)flags);
}

void SharpDXTex::ScratchImage::Initialize3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels) {
	_native->Initialize3D((DXGI_FORMAT)fmt, width, height, depth, mipLevels);
}

void SharpDXTex::ScratchImage::InitializeCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels, ComputePitchFlags flags) {
	_native->InitializeCube((DXGI_FORMAT)fmt, width, height, nCubes, mipLevels, (DWORD)flags);
}

void SharpDXTex::ScratchImage::InitializeCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels) {
	_native->InitializeCube((DXGI_FORMAT)fmt, width, height, nCubes, mipLevels);
}

void SharpDXTex::ScratchImage::InitializeFromImage(Image srcImage, bool allow2D, ComputePitchFlags flags) {
	auto nativeImage = srcImage.toNative();
	_native->InitializeFromImage(nativeImage, allow2D, (DWORD)flags);
}

void SharpDXTex::ScratchImage::InitializeFromImage(Image srcImage, bool allow2D) {
	auto nativeImage = srcImage.toNative();
	_native->InitializeFromImage(nativeImage, allow2D);
}

void SharpDXTex::ScratchImage::InitializeArrayFromImages(array<Image>^ images, bool allow1D, ComputePitchFlags flags) {
	pin_ptr<Image> p = &images[0];
	_native->InitializeArrayFromImages((DirectX::Image*)p, allow1D, (DWORD)flags);
	p = nullptr;
}

void SharpDXTex::ScratchImage::InitializeArrayFromImages(array<Image>^ images, bool allow1D) {
	pin_ptr<Image> p = &images[0];
	_native->InitializeArrayFromImages((DirectX::Image*)p, allow1D);
	p = nullptr;
}

void SharpDXTex::ScratchImage::InitializeCubeFromImages(array<Image>^ srcImage, ComputePitchFlags flags) {
	pin_ptr<Image> p = &srcImage[0];
	_native->InitializeCubeFromImages((DirectX::Image*)p, (DWORD)flags);
	p = nullptr;
}

void SharpDXTex::ScratchImage::InitializeCubeFromImages(array<Image>^ srcImage) {
	pin_ptr<Image> p = &srcImage[0];
	_native->InitializeCubeFromImages((DirectX::Image*)p, srcImage->Length);
	p = nullptr;
}

void SharpDXTex::ScratchImage::Initialize3DFromImages(array<Image>^ srcImage, int depth, ComputePitchFlags flags) {
	pin_ptr<Image> p = &srcImage[0];
	_native->Initialize3DFromImages((DirectX::Image*)p, depth, (DWORD)flags);
	p = nullptr;
}

void SharpDXTex::ScratchImage::Initialize3DFromImages(array<Image>^ srcImage, int depth) {
	pin_ptr<Image> p = &srcImage[0];
	_native->Initialize3DFromImages((DirectX::Image*)p, depth);
	p = nullptr;
}

void SharpDXTex::ScratchImage::Release() {
	_native->Release();
}

bool SharpDXTex::ScratchImage::OverrideFormat(SharpDX::DXGI::Format f) {
	return _native->OverrideFormat((DXGI_FORMAT)f);
}

SharpDXTex::TexMetadata SharpDXTex::ScratchImage::GetMetadata() {
	auto nativeMetadata = _native->GetMetadata();
	return TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::Image SharpDXTex::ScratchImage::GetImage(int mip, int item, int slice) {
	auto nativeImage = _native->GetImage(mip, item, slice);
	return Image::Image(*nativeImage);
}

array<SharpDXTex::Image>^ SharpDXTex::ScratchImage::Images::get() {
	array<Image>^ images = gcnew array<Image>(_native->GetImageCount());
	for (int i = 0; i < _native->GetImageCount(); i++) {
		images[i] = Image::Image(_native->GetImages()[i]);
	}
	return images;
}

int SharpDXTex::ScratchImage::ImageCount::get() {
	return _native->GetImageCount();
}

System::IntPtr SharpDXTex::ScratchImage::Pixels::get() {
	return (System::IntPtr)_native->GetPixels();
}

int SharpDXTex::ScratchImage::PixelsSize::get() {
	return _native->GetPixelsSize();
}

bool SharpDXTex::ScratchImage::IsAlphaAllOpaque::get() {
	return _native->IsAlphaAllOpaque();
}
