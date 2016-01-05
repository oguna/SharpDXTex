#include "Stdafx.h"
#include "ImageHelper.h"
#include <string>
#include <codecvt> 

using namespace System::Runtime::InteropServices;

void SharpDXTex::ImageHelper::LoadFromWICFile(System::String^ file, int flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata, ScratchImage^ image)
{
	if (image == nullptr) {
		throw(gcnew System::ArgumentNullException("image can't be null"));
	}
	auto uniname = Marshal::StringToHGlobalUni(file);
	auto nativeMetadata = metadata.getNative();
	auto nativeImage = image->_native;
	DirectX::LoadFromWICFile((LPCTSTR)uniname.ToPointer(), flags, &nativeMetadata, *nativeImage);
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	Marshal::FreeHGlobal(uniname);
}