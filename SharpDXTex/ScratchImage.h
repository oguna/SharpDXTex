#pragma once
#include <DirectXTex.h>
#include "Image.h"

namespace SharpDXTex
{
	public ref class ScratchImage
	{
	internal:
		DirectX::ScratchImage* _native;
	public:
		ScratchImage();
		void InitializeFromImage(Image^ srcImage, bool allow2D, int flags);
	};
}
