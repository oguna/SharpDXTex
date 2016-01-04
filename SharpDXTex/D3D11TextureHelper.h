#pragma once
#include "TexMetadata.h"
#include "Image.h"
#include "ScratchImage.h"

namespace SharpDXTex
{
	public ref class D3D11TextureHelper
	{
	private:
		D3D11TextureHelper();
	public:
		static bool IsSuportedTexture(SharpDX::Direct3D11::Device^ device, TexMetadata^ metadata);

		static void CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImages, TexMetadata^ metadata,
			[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::Resource resource);

		static void CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImage, TexMetadata^ metadata,
			[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv);

		//static void CreateTextureEx(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImages, TexMetadata^ metadata,
		//	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB,
		//	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv);


		//static void CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image^>^ srcImage, TexMetadata^ metadata,
		//	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB,
		//	[System::Runtime::InteropServices::Out] SharpDX::Direct3D11::ShaderResourceView srv);

		//static void CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext context, SharpDX::Direct3D11::Resource resource, 
		//	[System::Runtime::InteropServices::Out] ScratchImage^ result);
	};
}