#include "ImageHelper.h"
#include <string>

using namespace System::Runtime::InteropServices;

void SharpDXTex::ImageHelper::LoadFromWICFile(System::String^ file, int flags, [System::Runtime::InteropServices::Out] TexMetadata^ metadata, [System::Runtime::InteropServices::Out] ScratchImage^ image)
{
	auto ansi_name = (const char*)Marshal::StringToHGlobalAnsi(file).ToPointer();
	DirectX::LoadFromWICFile(ansi_name, flags, metadata->_native, image->_native);
}