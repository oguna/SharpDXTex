#include "stdafx.h"
#include "ImageUtil.h"
#include <memory>

using namespace System::Runtime::InteropServices;

SharpDXTex::ImageUtil::ImageUtil()
{
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromWICFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromWICFile(System::String^ file, WICFlags flags)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromWICFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::FlipRotate(SharpDXTex::Image srcImage, SharpDXTex::FlipRotateFlags flags)
{
	auto nativeSrcImage = srcImage.toNative();
	auto nativeFlags = (DWORD)flags;
	auto image = gcnew SharpDXTex::ScratchImage();
	DirectX::FlipRotate(nativeSrcImage, nativeFlags, *image->_native);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::FlipRotate(array<Image>^ srcImages, TexMetadata metadata, FlipRotateFlags flags)
{
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	auto nativeFlags = (DWORD)flags;
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeMetadata = metadata.toNative();
	DirectX::FlipRotate(nativeSrcImages.get(), srcImages->Length, nativeMetadata, nativeFlags, *image->_native);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromWICMemory(array<byte>^ source, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromWICMemory(p, source->Length, (DWORD)flags, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromWICMemory(array<byte>^ source, WICFlags flags) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromDDSMemory(p, source->Length, (DWORD)flags, nullptr, *image->_native);
	return image;
}


SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromDDSFile(System::String^ file, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromDDSFile(System::String^ file, DDSFlags flags)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromDDSMemory(array<byte>^ source, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromWICMemory(p, source->Length, (DWORD)flags, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromDDSMemory(array<byte>^ source, DDSFlags flags) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromDDSMemory(p, source->Length, (DWORD)flags, nullptr, *image->_native);
	return image;
}



SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromTGAFile(System::String^ file, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromTGAFile((LPCTSTR)nativeName.ToPointer(), &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromTGAFile(System::String^ file)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromTGAFile((LPCTSTR)nativeName.ToPointer(), nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromTGAMemory(array<byte>^ source, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromTGAMemory(p, source->Length, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ImageUtil::LoadFromTGAMemory(array<byte>^ source) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromTGAMemory(p, source->Length, nullptr, *image->_native);
	return image;
}
