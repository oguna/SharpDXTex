#pragma once

#include "TexMetadata.h"
#include "Image.h"
#include "ScratchImage.h"

namespace SharpDXTex
{
	public ref class TextureUtil
	{
	private:
		TextureUtil() {};
	public:
		static bool IsSuportedTexture(SharpDX::Direct3D11::Device^ device, TexMetadata metadata);

		static SharpDX::Direct3D11::Resource^ CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata);

		static SharpDX::Direct3D11::ShaderResourceView^ CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata);

		static SharpDX::Direct3D11::Resource^ CreateTexture(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata,
			SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB);

		static SharpDX::Direct3D11::ShaderResourceView^ CreateShaderResourceView(SharpDX::Direct3D11::Device^ device, array<Image>^ srcImages, TexMetadata metadata,
			SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB);

		static SharpDXTex::ScratchImage^ CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext^ context, SharpDX::Direct3D11::Resource^ resource);
	};
}
