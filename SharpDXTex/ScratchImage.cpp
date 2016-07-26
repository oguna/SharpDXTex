#include "stdafx.h"
#include "ScratchImage.h"
#include <memory>
using namespace System::Runtime::InteropServices;
using namespace SharpDXTex;

SharpDXTex::ScratchImage::ScratchImage() {
	_native = new DirectX::ScratchImage();
}

SharpDXTex::ScratchImage::~ScratchImage() {
	_native->Release();
	delete(_native);
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create(TexMetadata mdata, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize(mdata.toNative(), (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create(TexMetadata mdata) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize(mdata.toNative());
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize1D((DXGI_FORMAT)fmt, length, arraySize, mipLevels, (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create1D(SharpDX::DXGI::Format fmt, int length, int arraySize, int mipLevels) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize1D((DXGI_FORMAT)fmt, length, arraySize, mipLevels);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize2D((DXGI_FORMAT)fmt, width, height, arraySize, mipLevels, (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create2D(SharpDX::DXGI::Format fmt, int width, int height, int arraySize, int mipLevels) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize2D((DXGI_FORMAT)fmt, width, height, arraySize, mipLevels);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize3D((DXGI_FORMAT)fmt, width, height, depth, mipLevels, (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create3D(SharpDX::DXGI::Format fmt, int width, int height, int depth, int mipLevels) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->Initialize3D((DXGI_FORMAT)fmt, width, height, depth, mipLevels);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->InitializeCube((DXGI_FORMAT)fmt, width, height, nCubes, mipLevels, (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateCube(SharpDX::DXGI::Format fmt, int width, int height, int nCubes, int mipLevels) {
	auto image = gcnew SharpDXTex::ScratchImage();
	image->_native->InitializeCube((DXGI_FORMAT)fmt, width, height, nCubes, mipLevels);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateFromImage(Image srcImage, bool allow2D, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = srcImage.toNative();
	image->_native->InitializeFromImage(nativeImage, allow2D, (DWORD)flags);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateFromImage(Image srcImage, bool allow2D) {
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = srcImage.toNative();
	image->_native->InitializeFromImage(nativeImage, allow2D);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateArrayFromImages(array<Image>^ images, bool allow1D, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &images[0];
	image->_native->InitializeArrayFromImages((DirectX::Image*)p, allow1D, (DWORD)flags);
	p = nullptr;
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateArrayFromImages(array<Image>^ images, bool allow1D) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &images[0];
	image->_native->InitializeArrayFromImages((DirectX::Image*)p, allow1D);
	p = nullptr;
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateCubeFromImages(array<Image>^ srcImage, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &srcImage[0];
	image->_native->InitializeCubeFromImages((DirectX::Image*)p, (DWORD)flags);
	p = nullptr;
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CreateCubeFromImages(array<Image>^ srcImage) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &srcImage[0];
	image->_native->InitializeCubeFromImages((DirectX::Image*)p, srcImage->Length);
	p = nullptr;
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create3DFromImages(array<Image>^ srcImage, int depth, ComputePitchFlags flags) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &srcImage[0];
	image->_native->Initialize3DFromImages((DirectX::Image*)p, depth, (DWORD)flags);
	p = nullptr;
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::Create3DFromImages(array<Image>^ srcImage, int depth) {
	auto image = gcnew SharpDXTex::ScratchImage();
	pin_ptr<Image> p = &srcImage[0];
	image->_native->Initialize3DFromImages((DirectX::Image*)p, depth);
	p = nullptr;
	return image;
}


SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromWICFile(System::String^ file, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromWICFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromWICFile(System::String^ file, WICFlags flags)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromWICFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromWICMemory(array<byte>^ source, WICFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromWICMemory(p, source->Length, (DWORD)flags, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromWICMemory(array<byte>^ source, WICFlags flags) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromDDSMemory(p, source->Length, (DWORD)flags, nullptr, *image->_native);
	return image;
}


SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromDDSFile(System::String^ file, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromDDSFile(System::String^ file, DDSFlags flags)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromDDSFile((LPCTSTR)nativeName.ToPointer(), (DWORD)flags, nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromDDSMemory(array<byte>^ source, DDSFlags flags, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromWICMemory(p, source->Length, (DWORD)flags, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromDDSMemory(array<byte>^ source, DDSFlags flags) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromDDSMemory(p, source->Length, (DWORD)flags, nullptr, *image->_native);
	return image;
}



SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromTGAFile(System::String^ file, [System::Runtime::InteropServices::Out] TexMetadata% metadata)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	DirectX::TexMetadata nativeMetadata;
	auto hr = DirectX::LoadFromTGAFile((LPCTSTR)nativeName.ToPointer(), &nativeMetadata, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	metadata = SharpDXTex::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromTGAFile(System::String^ file)
{
	auto nativeName = Marshal::StringToHGlobalUni(file);
	auto image = gcnew SharpDXTex::ScratchImage();
	auto nativeImage = image->_native;
	auto hr = DirectX::LoadFromTGAFile((LPCTSTR)nativeName.ToPointer(), nullptr, *nativeImage);
	Marshal::FreeHGlobal(nativeName);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromTGAMemory(array<byte>^ source, [System::Runtime::InteropServices::Out] TexMetadata% metadata) {
	pin_ptr<byte> p = &source[0];
	DirectX::TexMetadata nativeMetadata;
	auto image = gcnew ScratchImage();
	DirectX::LoadFromTGAMemory(p, source->Length, &nativeMetadata, *image->_native);
	metadata = TexMetadata::TexMetadata(nativeMetadata);
	return image;
}

SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::LoadFromTGAMemory(array<byte>^ source) {
	pin_ptr<byte> p = &source[0];
	auto image = gcnew ScratchImage();
	DirectX::LoadFromTGAMemory(p, source->Length, nullptr, *image->_native);
	return image;
}

bool SharpDXTex::ScratchImage::OverrideFormat(SharpDX::DXGI::Format f) {
	return _native->OverrideFormat((DXGI_FORMAT)f);
}

SharpDXTex::TexMetadata SharpDXTex::ScratchImage::GetMetadata() {
	auto nativeMetadata = _native->GetMetadata();
	return TexMetadata::TexMetadata(nativeMetadata);
}

SharpDXTex::Image SharpDXTex::ScratchImage::GetImage(int mip, int item, int slice) {
	auto nativeImage = _native->GetImage(mip, item, slice);
	return Image::Image(*nativeImage);
}

array<SharpDXTex::Image>^ SharpDXTex::ScratchImage::Images::get() {
	array<Image>^ images = gcnew array<Image>(_native->GetImageCount());
	for (int i = 0; i < _native->GetImageCount(); i++) {
		images[i] = Image::Image(_native->GetImages()[i]);
	}
	return images;
}

int SharpDXTex::ScratchImage::ImageCount::get() {
	return _native->GetImageCount();
}

System::IntPtr SharpDXTex::ScratchImage::Pixels::get() {
	return (System::IntPtr)_native->GetPixels();
}

int SharpDXTex::ScratchImage::PixelsSize::get() {
	return _native->GetPixelsSize();
}

bool SharpDXTex::ScratchImage::IsAlphaAllOpaque::get() {
	return _native->IsAlphaAllOpaque();
}


SharpDX::Direct3D11::Resource^ CreateTextureResource(ID3D11Resource* pResource) {
	ID3D11Texture1D* pTexture1D;
	auto hr1 = pResource->QueryInterface(__uuidof(ID3D11Texture1D), (void**)&pTexture1D);
	if (SUCCEEDED(hr1)) {
		return gcnew SharpDX::Direct3D11::Texture1D((System::IntPtr)pTexture1D);
	}
	ID3D11Texture2D* pTexture2D;
	auto hr2 = pResource->QueryInterface(__uuidof(ID3D11Texture2D), (void**)&pTexture2D);
	if (SUCCEEDED(hr2)) {
		return gcnew SharpDX::Direct3D11::Texture2D((System::IntPtr)pTexture2D);
	}
	ID3D11Texture3D* pTexture3D;
	auto hr3 = pResource->QueryInterface(__uuidof(ID3D11Texture3D), (void**)&pTexture3D);
	if (SUCCEEDED(hr3)) {
		return gcnew SharpDX::Direct3D11::Texture3D((System::IntPtr)pTexture3D);
	}
	if (pResource) {
		pResource->Release();
	}
	return nullptr;
}

SharpDX::Direct3D11::Resource^ SharpDXTex::ScratchImage::CreateTexture(SharpDX::Direct3D11::Device^ device)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	auto nativeMetadata = this->GetMetadata().toNative();
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	ID3D11Resource* pResource;
	auto hr = DirectX::CreateTexture(nativeDevice, this->_native->GetImages(), this->_native->GetImageCount(), nativeMetadata, &pResource);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return CreateTextureResource(pResource);
}

SharpDX::Direct3D11::ShaderResourceView^ SharpDXTex::ScratchImage::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	auto nativeMetadata = this->GetMetadata().toNative();
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	ID3D11ShaderResourceView* nativeSRV;
	auto hr = DirectX::CreateShaderResourceView(nativeDevice, this->_native->GetImages(), this->_native->GetImageCount(), nativeMetadata, &nativeSRV);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return gcnew SharpDX::Direct3D11::ShaderResourceView((System::IntPtr)(void*)nativeSRV);
}

SharpDX::Direct3D11::Resource^ SharpDXTex::ScratchImage::CreateTexture(SharpDX::Direct3D11::Device^ device,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	auto nativeMetadata = this->GetMetadata().toNative();
	ID3D11Resource* pResource;
	auto hr = DirectX::CreateTextureEx(nativeDevice, this->_native->GetImages(), this->_native->GetImageCount(), nativeMetadata,
		(D3D11_USAGE)usage, (uint32_t)bindFlags, (uint32_t)cpuAccessFlags, (uint32_t)miscFlags, forceSRGB, &pResource);
	if (FAILED(hr)) {
		throw(gcnew System::Exception());
	}
	return CreateTextureResource(pResource);
}

SharpDX::Direct3D11::ShaderResourceView^ SharpDXTex::ScratchImage::CreateShaderResourceView(SharpDX::Direct3D11::Device^ device,
	SharpDX::Direct3D11::ResourceUsage usage, SharpDX::Direct3D11::BindFlags bindFlags, SharpDX::Direct3D11::CpuAccessFlags cpuAccessFlags, SharpDX::Direct3D11::ResourceOptionFlags miscFlags, bool forceSRGB)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)(device->NativePointer);
	auto nativeMetadata = this->GetMetadata().toNative();
	ID3D11ShaderResourceView* nativeSRV;
	DirectX::CreateShaderResourceViewEx(nativeDevice, this->_native->GetImages(), this->_native->GetImageCount(), nativeMetadata,
		(D3D11_USAGE)usage, (uint32_t)bindFlags, (uint32_t)cpuAccessFlags, (uint32_t)miscFlags, forceSRGB, &nativeSRV);
	return gcnew SharpDX::Direct3D11::ShaderResourceView((System::IntPtr)(void*)nativeSRV);
}


SharpDXTex::ScratchImage^ SharpDXTex::ScratchImage::CaptureTexture(SharpDX::Direct3D11::Device^ device, SharpDX::Direct3D11::DeviceContext^ context, SharpDX::Direct3D11::Resource^ resource)
{
	if (device == nullptr) {
		throw(gcnew System::ArgumentNullException("device"));
	}
	if (context == nullptr) {
		throw(gcnew System::ArgumentNullException("context"));
	}
	if (resource == nullptr) {
		throw(gcnew System::ArgumentNullException("resource"));
	}
	auto nativeDevice = (ID3D11Device*)(void*)device->NativePointer;
	auto nativeContext = (ID3D11DeviceContext*)(void*)context->NativePointer;
	auto nativeResource = (ID3D11Resource*)(void*)resource->NativePointer;
	auto image = gcnew ScratchImage();
	DirectX::CaptureTexture(nativeDevice, nativeContext, nativeResource, *image->_native);
	return image;
}