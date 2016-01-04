#include "Stdafx.h"
#include "ImageHelper.h"
#include <string>
#include <codecvt> 

using namespace System::Runtime::InteropServices;

void SharpDXTex::ImageHelper::LoadFromWICFile(System::String^ file, int flags, [System::Runtime::InteropServices::Out] TexMetadata^ metadata, [System::Runtime::InteropServices::Out] ScratchImage^ image)
{
	auto ansi_name = std::string((const char*)Marshal::StringToHGlobalAnsi(file).ToPointer());
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	std::wstring w_name = cv.from_bytes(ansi_name);
	auto nativeMetadata = metadata->getNative();
	auto nativeImage = image->_native;
	DirectX::LoadFromWICFile((LPCTSTR)w_name.c_str, flags, &nativeMetadata, *nativeImage);
	metadata = gcnew SharpDXTex::TexMetadata(nativeMetadata);
}