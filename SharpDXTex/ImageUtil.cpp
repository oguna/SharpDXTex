#include "stdafx.h"
#include "ImageUtil.h"
#include <memory>

using namespace System::Runtime::InteropServices;
using namespace SharpDXTex;

SharpDXTex::ImageUtil::ImageUtil()
{
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::FlipRotate(SharpDXTex::Image srcImage, SharpDXTex::FlipRotateDescription flags)
{
	auto nativeSrcImage = srcImage.toNative();
	auto nativeFlags = flags.toFlags();
	auto image = gcnew SharpDXTex::ScratchImage();
	DirectX::FlipRotate(nativeSrcImage, nativeFlags, *image->_native);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateDescription flags)
{
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	auto nativeFlags = flags.toFlags();
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeMetadata = metadata.toNative();
	DirectX::FlipRotate(nativeSrcImages.get(), srcImages->Length, nativeMetadata, nativeFlags, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Resize(Image srcImage, int width, int height, FilterDescription desc) {
	auto image = gcnew ScratchImage();
	DirectX::Resize(srcImage.toNative(), width, height, desc.toFlags(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Resize(array<Image>^ srcImages, TexMetadata metadata, int width, int height, FilterDescription desc) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::Resize((DirectX::Image*)p, srcImages->Length, metadata.toNative(), width, height, desc.toFlags(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Convert(Image srcImage, SharpDX::DXGI::Format format, FilterDescription desc, float threshold) {
	auto image = gcnew ScratchImage();
	DirectX::Convert(srcImage.toNative(), (DXGI_FORMAT)format, desc.toFlags(), threshold, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Convert(array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format, FilterDescription desc, float threshold) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::Convert((DirectX::Image*)p, srcImages->Length, metadata.toNative(), (DXGI_FORMAT)format, desc.toFlags(), threshold, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::ConvertToSinglePlane(Image srcImage) {
	auto image = gcnew ScratchImage();
	DirectX::ConvertToSinglePlane(srcImage.toNative(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::ConvertToSinglePlane(array<Image>^ srcImages, TexMetadata metadata) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::ConvertToSinglePlane((DirectX::Image*)p, srcImages->Length, metadata.toNative(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::GenerateMipMaps(Image baseImage, FilterDescription filter, int levels, bool allow1D) {
	auto image = gcnew ScratchImage();
	DirectX::GenerateMipMaps(baseImage.toNative(), filter.toFlags(), levels, *image->_native, allow1D);
	return image;
}

ScratchImage^ ImageUtil::GenerateMipMaps(array<Image>^ baseImage, TexMetadata metadata, FilterDescription filter, int levels) {
	pin_ptr<Image> p = &baseImage[0];
	auto image = gcnew ScratchImage();
	DirectX::GenerateMipMaps((DirectX::Image*)p, baseImage->Length, metadata.toNative(), filter.toFlags(), levels, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::GenerateMipMaps3D(array<Image>^ baseImage, int depth, FilterDescription filter, int levels) {
	pin_ptr<Image> p = &baseImage[0];
	auto image = gcnew ScratchImage();
	DirectX::GenerateMipMaps3D((DirectX::Image*)p, depth, filter.toFlags(), levels, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::GenerateMipMaps3D(array<Image>^ baseImage, TexMetadata metadata, FilterDescription filter, int levels) {
	pin_ptr<Image> p = &baseImage[0];
	auto image = gcnew ScratchImage();
	DirectX::GenerateMipMaps3D((DirectX::Image*)p, baseImage->Length, metadata.toNative(), filter.toFlags(), levels, *image->_native);
	return image;
}


ScratchImage^ ImageUtil::PremultiplyAlpha(Image srcImage, PremultipliedAlphaDescription desc) {
	auto image = gcnew ScratchImage();
	DirectX::PremultiplyAlpha(srcImage.toNative(), desc.toFlags(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::PremultiplyAlpha(array<Image>^ srcImages, TexMetadata metadata, PremultipliedAlphaDescription desc) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::PremultiplyAlpha((DirectX::Image*)p, srcImages->Length, metadata.toNative(), desc.toFlags(), *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Compress(Image srcImage, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaRef) {
	auto image = gcnew ScratchImage();
	DirectX::Compress(srcImage.toNative(), (DXGI_FORMAT)format, comperss.toFlags(), alphaRef, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Compress(array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaRef)
{
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::Compress((DirectX::Image*)p, srcImages->Length, metadata.toNative(), (DXGI_FORMAT)format, comperss.toFlags(),alphaRef,  *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Compress(SharpDX::Direct3D11::Device^ device, Image srcImage, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaWight) {
	auto image = gcnew ScratchImage();
	auto pDevice = (ID3D11Device*)device->NativePointer.ToPointer();
	DirectX::Compress(pDevice, srcImage.toNative(), (DXGI_FORMAT)format, comperss.toFlags(), alphaWight, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Compress(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format, CompressDescription comperss, float alphaWight) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	auto pDevice = (ID3D11Device*)device->NativePointer.ToPointer();
	DirectX::Compress((DirectX::Image*)p, srcImages->Length, metadata.toNative(), (DXGI_FORMAT)format, comperss.toFlags(), alphaWight, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Decompress(Image srcImage, SharpDX::DXGI::Format format) {
	auto image = gcnew ScratchImage();
	DirectX::Decompress(srcImage.toNative(), (DXGI_FORMAT)format, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::Decompress(array<Image>^ srcImages, TexMetadata metadata, SharpDX::DXGI::Format format) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::Decompress((DirectX::Image*)p, srcImages->Length, metadata.toNative(), (DXGI_FORMAT)format, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::ComputeNormalMap(Image srcImage, ComputeNormalMapDescription flags, float amplitude, SharpDX::DXGI::Format format) {
	auto image = gcnew ScratchImage();
	DirectX::ComputeNormalMap(srcImage.toNative(), flags.getFlags(), amplitude, (DXGI_FORMAT)format, *image->_native);
	return image;
}

ScratchImage^ ImageUtil::ComputeNormalMap(array<Image>^ srcImages, TexMetadata metadata, ComputeNormalMapDescription flags, float amplitude, SharpDX::DXGI::Format format) {
	pin_ptr<Image> p = &srcImages[0];
	auto image = gcnew ScratchImage();
	DirectX::ComputeNormalMap((DirectX::Image*)p, srcImages->Length, metadata.toNative(), flags.getFlags(), amplitude, (DXGI_FORMAT)format, *image->_native);
	return image;
}

Image ImageUtil::CopyRectagle(Image srcImage, int x, int y, int w, int h, FilterDescription filter, int xOffset, int yOffset) {
	auto image = DirectX::Image();
	auto rect = DirectX::Rect(x, y, w, h);
	DirectX::CopyRectangle(srcImage.toNative(), rect, image, filter.toFlags(), xOffset, yOffset);
	return Image::Image(image);
}

float ImageUtil::ComputeMeanSquaredError(Image image1, Image image2, ComputeMeanSquaredErrorDescription flags, [System::Runtime::InteropServices::Out] array<float>^% mseV) {
	float mse;
	float pMseV[4];
	DirectX::ComputeMSE(image1.toNative(), image2.toNative(), mse, pMseV, flags.getFlags());
	mseV = gcnew array<float>(4) { pMseV[0], pMseV[1], pMseV[2], pMseV[3] };
	return mse;
}

float ImageUtil::ComputeMeanSquaredError(Image image1, Image image2, ComputeMeanSquaredErrorDescription flags) {
	float mse;
	DirectX::ComputeMSE(image1.toNative(), image2.toNative(), mse, nullptr, flags.getFlags());
	return mse;
}