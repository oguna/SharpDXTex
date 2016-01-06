#include "Stdafx.h"
#include "TexMetadata.h"

using namespace System::Runtime::InteropServices;

DirectX::TexMetadata SharpDXTex::TexMetadata::toNative()
{
	DirectX::TexMetadata native;
	native.arraySize = this->ArraySize;
	native.height = this->Height;
	native.width = this->Width;
	native.depth = this->Depth;
	native.miscFlags = (uint32_t)this->MiscFlags;
	native.miscFlags2 = (uint32_t)this->MiscFlags2;
	native.format = (DXGI_FORMAT) this->Format;
	native.dimension = (DirectX::TEX_DIMENSION)this->Dimension;
	native.mipLevels = this->MipLevels;
	return native;
}

SharpDXTex::TexMetadata::TexMetadata(const DirectX::TexMetadata& metadata)
{
	this->Width = metadata.width;
	this->Height = metadata.height;
	this->Depth = metadata.depth;
	this->ArraySize = metadata.arraySize;
	this->MipLevels = metadata.mipLevels;
	this->MiscFlags = (SharpDXTex::MiscFlag)metadata.miscFlags;
	this->MiscFlags2 = (SharpDXTex::MiscFlag2)metadata.miscFlags2;
	this->Format = (SharpDX::DXGI::Format)metadata.format;
	this->Dimension = (SharpDXTex::Dimension)metadata.dimension;
}

int SharpDXTex::TexMetadata::ComputeIndex(int mip, int item, int slice)
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.ComputeIndex(mip, item, slice);
}

bool SharpDXTex::TexMetadata::IsCubemap()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsCubemap();
}

bool SharpDXTex::TexMetadata::IsPMAlpha()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsPMAlpha();
}

void SharpDXTex::TexMetadata::SetAlphaMode(AlphaMode mode)
{
	auto native = this->toNative();
	native.SetAlphaMode((DirectX::TEX_ALPHA_MODE)mode);
	this->MiscFlags2 = (SharpDXTex::MiscFlag2)native.miscFlags2;
}

bool SharpDXTex::TexMetadata::IsVolumemap()
{
	auto native = SharpDXTex::TexMetadata(*this);
	return native.IsVolumemap();
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromDDSMemory(array<byte>^ buffer, DDSFlags flags) {
	if (buffer == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	pin_ptr<byte> p = &buffer[0];
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromDDSMemory(p, buffer->Length, (DWORD)flags, nativeMetadata);
	p = nullptr;
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromDDSFile(System::String^ file, DDSFlags flags) {
	if (file == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	auto nativeName = Marshal::StringToHGlobalUni(file);
	DirectX:: TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nativeMetadata);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromTGAMemory(array<byte>^ buffer) {
	if (buffer == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	pin_ptr<byte> p = &buffer[0];
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromTGAMemory(p, buffer->Length, nativeMetadata);
	p = nullptr;
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromTGAFile(System::String^ file) {
	if (file == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	auto nativeName = Marshal::StringToHGlobalUni(file);
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromTGAFile((LPCTSTR)nativeName.ToPointer(), nativeMetadata);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromWICMemory(array<byte>^ buffer, WICFlags flags) {
	if (buffer == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	pin_ptr<byte> p = &buffer[0];
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromDDSMemory(p, buffer->Length, (DWORD)flags, nativeMetadata);
	p = nullptr;
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::TexMetadata SharpDXTex::TexMetadata::FromWICFile(System::String^ file, WICFlags flags) {
	if (file == nullptr) {
		throw(gcnew System::ArgumentNullException("buffer"));
	}
	auto nativeName = Marshal::StringToHGlobalUni(file);
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::GetMetadataFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nativeMetadata);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return SharpDXTex::TexMetadata::TexMetadata(nativeMetadata);
}