#include "stdafx.h"
#include "D3D11TextureHelper.h"
#include <vector>
#include <memory>

SharpDXTex::D3D11TextureHelper::D3D11TextureHelper()
{
}


bool SharpDXTex::D3D11TextureHelper::IsSuportedTexture(SharpDX::Direct3D11::Device^ device, TexMetadata^ metadata)
{
	auto native_metadata = metadata->getNative();
	return DirectX::IsSupportedTexture((ID3D11Device*)(void*)(device->NativePointer), native_metadata);
}

void SharpDXTex::D3D11TextureHelper::CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImages, TexMetadata^ metadata,
	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::Resource^ resource)
{
	auto native_metadata = metadata->getNative();
	auto nativeSrcImages = std::make_unique<DirectX::Image[]>(srcImages->Length);
	for (auto i = 0; i < srcImages->Length; i++)
	{
		nativeSrcImages[i] = *srcImages[i]->_native;
	}
	ID3D11Resource* pResource;
	DirectX::CreateTexture((ID3D11Device*)(void*)(device->NativePointer), &nativeSrcImages[0], srcImages->Length, native_metadata, &pResource);
	resource = gcnew SharpDX::Direct3D11::Resource((System::IntPtr)(void*)pResource);
}

void SharpDXTex::D3D11TextureHelper::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImage, TexMetadata^ metadata,
	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv)
{
	auto pDevice = (ID3D11Device*)(void*)(device->NativePointer);

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