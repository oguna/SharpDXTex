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
	public:
		ScratchImage();

		void Initialize(TexMetadata mdata, int flags) {
			_native->Initialize(mdata.getNative(), flags);
		}

		void Initialize(TexMetadata mdata) {
			_native->Initialize(mdata.getNative());
		}

		void InitializeFromImage(Image^ srcImage, bool allow2D, int flags);
	};
}
