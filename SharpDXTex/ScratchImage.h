#pragma once

#include <DirectXTex.h>
#include "Image.h"
#include "TexMetadata.h"
#include "DXGIFormatUtil.h"

namespace SharpDXTex
{
	public ref class ScratchImage
	{
	internal:
		DirectX::ScratchImage* _native;

	private:
		~ScratchImage();

	public:
		ScratchImage();

		static ScratchImage^ Create(TexMetadata mdata, ComputePitchFlags flags);

		static ScratchImage^ Create(TexMetadata mdata);

		static ScratchImage^ Create1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels, ComputePitchFlags flags);
		
		static ScratchImage^ Create1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels);
		
		static ScratchImage^ Create2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels, ComputePitchFlags flags);
		
		static ScratchImage^ Create2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels);
		
		static ScratchImage^ Create3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels, ComputePitchFlags flags);
		
		static ScratchImage^ Create3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevelss);
		
		static ScratchImage^ CreateCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels, ComputePitchFlags flags);
		
		static ScratchImage^ CreateCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels);
		
		static ScratchImage^ CreateFromImage(Image srcImage, bool allow1D, ComputePitchFlags flags);
		
		static ScratchImage^ CreateFromImage(Image srcImage, bool allow1D);
		
		static ScratchImage^ CreateArrayFromImages(array<Image>^ images, bool allow1D, ComputePitchFlags flags);
		
		static ScratchImage^ CreateArrayFromImages(array<Image>^ images, bool allow1D);
		
		static ScratchImage^ CreateCubeFromImages(array<Image>^ srcImage, ComputePitchFlags flags);
		
		static ScratchImage^ CreateCubeFromImages(array<Image>^ srcImage);
		
		static ScratchImage^ Create3DFromImages(array<Image>^ srcImage, int depth, ComputePitchFlags flags);
		
		static ScratchImage^ Create3DFromImages(array<Image>^ srcImage, int depth);

		static ScratchImage^ LoadFromDDSFile(System::String^ file, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromDDSFile(System::String^ file, DDSFlags flags);
		static ScratchImage^ LoadFromDDSMemory(array<byte>^ source, DDSFlags flasgs, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromDDSMemory(array<byte>^ source, DDSFlags flasgs);

		static ScratchImage^ LoadFromTGAFile(System::String^ file, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromTGAFile(System::String^ file);
		static ScratchImage^ LoadFromTGAMemory(array<byte>^ source, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromTGAMemory(array<byte>^ source);

		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICFile(System::String^ file, WICFlags flags);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs, [System::Runtime::InteropServices::Out] TexMetadata% metadata);
		static ScratchImage^ LoadFromWICMemory(array<byte>^ source, WICFlags flasgs);

		static SharpDXTex::ScratchImage^ CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext^ context, SharpDX::Direct3D11::Resource^ resource);

		bool OverrideFormat(SharpDX::DXGI::Format f);

		TexMetadata GetMetadata();

		Image GetImage(int mip, int item, int slice);

		property array<Image>^ Images {
			array<Image>^ get();
		}

		property int ImageCount {
			int get();
		}

		property System::IntPtr Pixels {
			System::IntPtr get();
		}

		property int PixelsSize {
			int get();
		}

		property bool IsAlphaAllOpaque {
			bool get();
		}


		SharpDX::Direct3D11::Resource^ CreateTexture(SharpDX::Direct3D11::Device^ device);

		SharpDX::Direct3D11::ShaderResourceView^ CreateShaderResourceView(SharpDX::Direct3D11::Device^ device);

		SharpDX::Direct3D11::Resource^ CreateTexture(SharpDX::Direct3D11::Device^ device,
			SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB);

		SharpDX::Direct3D11::ShaderResourceView^ CreateShaderResourceView(SharpDX::Direct3D11::Device^ device,
			SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB);

	};
}
