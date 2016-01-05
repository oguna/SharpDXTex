#include "stdafx.h"
#include "TextureUtil.h"
#include <vector>
#include <memory>

SharpDXTex::TextureUtil::TextureUtil()
{
}


bool SharpDXTex::TextureUtil::IsSuportedTexture(SharpDX::Direct3D11::Device^ device, TexMetadata metadata)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	auto nativeMetadata = metadata.toNative();
	auto nativeDevice = (ID3D11Device*)(void*)device->NativePointer;
	return DirectX::IsSupportedTexture(nativeDevice, nativeMetadata);
}

SharpDX::Direct3D11::Resource^ SharpDXTex::TextureUtil::CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (srcImages == nullptr) {
		throw(gcnew System::ArgumentNullException("srcImages"));
	}
	auto nativeMetadata = metadata.toNative();
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	ID3D11Resource* pResource;
	auto hr = DirectX::CreateTexture(nativeDevice, nativeSrcImages.get(), srcImages->Length, nativeMetadata, &pResource);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return gcnew SharpDX::Direct3D11::Resource((System::IntPtr)(void*)pResource);
}

SharpDX::Direct3D11::ShaderResourceView^ SharpDXTex::TextureUtil::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (srcImages == nullptr) {
		throw(gcnew System::ArgumentNullException("srcImages"));
	}
	auto nativeMetadata = metadata.toNative();
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	ID3D11ShaderResourceView* nativeSRV;
	auto hr = DirectX::CreateShaderResourceView(nativeDevice, nativeSrcImages.get(), srcImages->Length, nativeMetadata, &nativeSRV);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return gcnew SharpDX::Direct3D11::ShaderResourceView((System::IntPtr)(void*)nativeSRV);
}

/*void SharpDXTex::D3D11TextureHelper::CreateTextureEx(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImages, TexMetadata^ metadata,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB,
	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv)
{
	auto pDevice = (ID3D11Device*)(void*)(device->NativePointer); 
	auto pSrcImages = std::make_unique<DirectX::Image*[]>(srcImages->Length.ToInt32);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		pSrcImages[i] = srcImages[i]->_native;
	}
	auto pMetadata = metadata->getNative();
	ID3D11Resource* ppResource;
	DirectX::CreateTextureEx(pDevice, pSrcImages[0], srcImages->Length, pMetadata, (D3D11_USAGE)usage, (unsigned int)bindFlags, (unsigned int)cpuAccessFlags, (unsigned int)miscFlags, forceSRGB, &ppResource);
}

void SharpDXTex::D3D11TextureHelper::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImage, TexMetadata^ metadata,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB,
	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv);

void SharpDXTex::D3D11TextureHelper::CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext context, SharpDX::Direct3D11::Resource resource,
	[System::Runtime::InteropServices::Out] ScratchImage^ result);*/