#include "stdafx.h"
#include "TextureUtil.h"
#include <vector>
#include <memory>

SharpDX::Direct3D11::Resource^ CreateTextureResource(ID3D11Resource* pResource) {
	ID3D11Texture1D* pTexture1D;
	auto hr1 = pResource->QueryInterface(__uuidof(ID3D11Texture1D), (void**)&pTexture1D);
	if (SUCCEEDED(hr1)) {
		return gcnew SharpDX::Direct3D11::Texture1D((System::IntPtr)pTexture1D);
	}
	ID3D11Texture2D* pTexture2D;
	auto hr2 = pResource->QueryInterface(__uuidof(ID3D11Texture2D), (void**)&pTexture2D);
	if (SUCCEEDED(hr2)) {
		return gcnew SharpDX::Direct3D11::Texture2D((System::IntPtr)pTexture2D);
	}
	ID3D11Texture3D* pTexture3D;
	auto hr3 = pResource->QueryInterface(__uuidof(ID3D11Texture3D), (void**)&pTexture3D);
	if (SUCCEEDED(hr3)) {
		return gcnew SharpDX::Direct3D11::Texture3D((System::IntPtr)pTexture3D);
	}
	if (pResource) {
		pResource->Release();
	}
	return nullptr;
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
	return CreateTextureResource(pResource);
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

SharpDX::Direct3D11::Resource^ SharpDXTex::TextureUtil::CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (srcImages == nullptr) {
		throw(gcnew System::ArgumentNullException("srcImages"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	auto nativeMetadata = metadata.toNative();
	ID3D11Resource* pResource;
	auto hr = DirectX::CreateTextureEx(nativeDevice, nativeSrcImages.get(), srcImages->Length, nativeMetadata,
		(D3D11_USAGE)usage, (uint32_t)bindFlags, (uint32_t)cpuAccessFlags, (uint32_t)miscFlags, forceSRGB, &pResource);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return CreateTextureResource(pResource);
}

SharpDX::Direct3D11::ShaderResourceView^ SharpDXTex::TextureUtil::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (srcImages == nullptr) {
		throw(gcnew System::ArgumentNullException("srcImages"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = srcImages[i].toNative();
	}
	auto nativeMetadata = metadata.toNative();
	ID3D11ShaderResourceView* nativeSRV;
	DirectX::CreateShaderResourceViewEx(nativeDevice, nativeSrcImages.get(), srcImages->Length, nativeMetadata,
		(D3D11_USAGE)usage, (uint32_t)bindFlags, (uint32_t)cpuAccessFlags, (uint32_t)miscFlags, forceSRGB, &nativeSRV);
	return gcnew SharpDX::Direct3D11::ShaderResourceView((System::IntPtr)(void*)nativeSRV);
}

SharpDXTex::ScratchImage^ SharpDXTex::TextureUtil::CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext^ context, SharpDX::Direct3D11::Resource^ resource)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (context == nullptr) {
		throw(gcnew System::ArgumentNullException("context"));
	}
	if (resource == nullptr) {
		throw(gcnew System::ArgumentNullException("resource"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)device->NativePointer;
	auto nativeContext = (ID3D11DeviceContext*)(void*)context->NativePointer;
	auto nativeResource = (ID3D11Resource*)(void*)resource->NativePointer;
	auto image = gcnew ScratchImage();
	DirectX::CaptureTexture(nativeDevice, nativeContext, nativeResource, *image->_native);
	return image;
}