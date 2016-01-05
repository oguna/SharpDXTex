#include "Stdafx.h"
#include "ImageHelper.h"
#include <string>
#include <codecvt> 

using namespace System::Runtime::InteropServices;

void SharpDXTex::ImageHelper::LoadFromWICFile(System::String^ file, int flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata, ScratchImage^ image)
{
	if (image == nullptr) {
		throw(gcnew System::ArgumentNullException("image"));
	}
	auto uniname = Marshal::StringToHGlobalUni(file);
	auto nativeMetadata = metadata.toNative();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromWICFile((LPCTSTR)uniname.ToPointer(), flags, &nativeMetadata, *nativeImage);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	Marshal::FreeHGlobal(uniname);
}