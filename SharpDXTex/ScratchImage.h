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

		void Initialize(TexMetadata mdata, ComputePitchFlags flags);

		void Initialize(TexMetadata mdata);

		void Initialize1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels, ComputePitchFlags flags);
		
		void Initialize1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels);
		
		void Initialize2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels, ComputePitchFlags flags);
		
		void Initialize2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels);
		
		void Initialize3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels, ComputePitchFlags flags);
		
		void Initialize3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevelss);
		
		void InitializeCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels, ComputePitchFlags flags);
		
		void InitializeCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels);
		
		void InitializeFromImage(Image srcImage, bool allow1D, ComputePitchFlags flags);
		
		void InitializeFromImage(Image srcImage, bool allow1D);
		
		void InitializeArrayFromImages(array<Image>^ images, bool allow1D, ComputePitchFlags flags);
		
		void InitializeArrayFromImages(array<Image>^ images, bool allow1D);
		
		void InitializeCubeFromImages(array<Image>^ srcImage, ComputePitchFlags flags);
		
		void InitializeCubeFromImages(array<Image>^ srcImage);
		
		void Initialize3DFromImages(array<Image>^ srcImage, int depth, ComputePitchFlags flags);
		
		void Initialize3DFromImages(array<Image>^ srcImage, int depth);

		void Release();

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
	};
}
