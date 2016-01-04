#pragma once
#include <DirectXTex.h>

namespace SharpDXTex
{
	public ref class Blob
	{
	internal:
		DirectX::Blob* _native;
		Blob(DirectX::Blob* native);
	public:
		Blob();
		void Initialize(int size);
		void Release();
		System::IntPtr GetBufferPointer();
		int GetBufferSize();
	};
}
