#pragma once
#include <DirectXTex.h>
#include "Image.h"
#include "TexMetadata.h"

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

		void Initialize(TexMetadata mdata, int flags) {
			_native->Initialize(mdata.toNative(), flags);
		}

		void Initialize(TexMetadata mdata) {
			_native->Initialize(mdata.toNative());
		}

		void InitializeFromImage(Image srcImage, bool allow2D, int flags);

		void Release() {
			_native->Release();
		}

		bool OverrideFormat(SharpDX::DXGI::Format f) {
			return _native->OverrideFormat((DXGI_FORMAT)f);
		}

		TexMetadata GetMetadata() {
			auto nativeMetadata = _native->GetMetadata();
			return TexMetadata::TexMetadata(nativeMetadata);
		}

		Image GetImage(int mip, int item, int slice) {
			auto nativeImage = _native->GetImage(mip, item, slice);
			return Image::Image(*nativeImage);
		}

		array<Image>^ GetImages() {
			array<Image>^ images = gcnew array<Image>(_native->GetImageCount());
			for (int i = 0; i < _native->GetImageCount(); i++) {
				images[i] = Image::Image(_native->GetImages()[i]);
			}
			return images;
		}
	};
}
