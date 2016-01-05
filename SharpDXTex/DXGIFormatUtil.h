#pragma once
#include <DirectXTex.h>

namespace SharpDXTex
{
	[System::FlagsAttribute]
	public enum class CompareFlags
	{
		None = 0x0,
		LegacyDWord = 0x1,
		Paragraph = 0x2,
		YMM = 0x4,
		ZMM = 0x8,
		Page4K = 0x200,
		BPP24 = 0x10000,
		BPP16 = 0x20000,
		BPP8 = 0x40000
	};

	public ref class DXGIFormatUtil
	{
	private:
		DXGIFormatUtil()
		{
		}

	public:
		static bool IsValid(SharpDX::DXGI::Format fmt) {
			return DirectX::IsValid((DXGI_FORMAT)fmt);
		}
		static bool IsCompressed(SharpDX::DXGI::Format fmt) {
			return DirectX::IsCompressed((DXGI_FORMAT)fmt);
		}
		static bool IsPacked(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPacked((DXGI_FORMAT)fmt);
		}
		static bool IsVideo(SharpDX::DXGI::Format fmt) {
			return DirectX::IsVideo((DXGI_FORMAT)fmt);
		}
		static bool IsPlanar(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPlanar((DXGI_FORMAT)fmt);
		}
		static bool IsPalettized(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPalettized((DXGI_FORMAT)fmt);
		}
		static bool IsDepthStencil(SharpDX::DXGI::Format fmt) {
			return DirectX::IsDepthStencil((DXGI_FORMAT)fmt);
		}
		static bool IsSRGB(SharpDX::DXGI::Format fmt) {
			return DirectX::IsSRGB((DXGI_FORMAT)fmt);
		}
		static bool IsTypeless(SharpDX::DXGI::Format fmt) {
			return DirectX::IsTypeless((DXGI_FORMAT)fmt);
		}
		static bool IsTypeless(SharpDX::DXGI::Format fmt, bool partialTypeless) {
			return DirectX::IsTypeless((DXGI_FORMAT)fmt, partialTypeless);
		}
		static bool HasAlpha(SharpDX::DXGI::Format fmt) {
			return DirectX::HasAlpha((DXGI_FORMAT)fmt);
		}
		static int BitsPerPixel(SharpDX::DXGI::Format fmt) {
			return DirectX::BitsPerPixel((DXGI_FORMAT)fmt);
		}
		static int BitsPerColor(SharpDX::DXGI::Format fmt) {
			return DirectX::BitsPerColor((DXGI_FORMAT)fmt);
		}
		static void ComputePitch(SharpDX::DXGI::Format fmt, int width, int height,
			[System::Runtime::InteropServices::Out]int% rowPitch, [System::Runtime::InteropServices::Out]int% slicePitch, CompareFlags flags) {
			size_t _rowPitch;
			size_t _slicePitch;
			DirectX::ComputePitch((DXGI_FORMAT)fmt, width, height, _rowPitch, _slicePitch, (DWORD)flags);
			rowPitch = _rowPitch;
			slicePitch = _slicePitch;
		}
		static int ComputeScanlines(SharpDX::DXGI::Format fmt, int height) {
			return DirectX::ComputeScanlines((DXGI_FORMAT)fmt, height);
		}
		static SharpDX::DXGI::Format MakeSRGB(SharpDX::DXGI::Format fmt) {
			return (SharpDX::DXGI::Format)DirectX::MakeSRGB((DXGI_FORMAT)fmt);
		}
		static SharpDX::DXGI::Format MakeTypeless(SharpDX::DXGI::Format fmt) {
			return (SharpDX::DXGI::Format)DirectX::MakeSRGB((DXGI_FORMAT)fmt);
		}
		static SharpDX::DXGI::Format MakeTypelessUNORM(SharpDX::DXGI::Format fmt) {
			return (SharpDX::DXGI::Format)DirectX::MakeSRGB((DXGI_FORMAT)fmt);
		}
		static SharpDX::DXGI::Format MakeTypelessFLOAT(SharpDX::DXGI::Format fmt) {
			return (SharpDX::DXGI::Format)DirectX::MakeSRGB((DXGI_FORMAT)fmt);
		}
	};
}