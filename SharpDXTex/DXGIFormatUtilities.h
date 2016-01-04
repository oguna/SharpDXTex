#pragma once
#include <DirectXTex.h>

namespace SharpDXTex
{
	public ref class DXGIFormatUtilities
	{
	private:
		DXGIFormatUtilities()
		{
		}

	public:
		bool IsValid(SharpDX::DXGI::Format fmt) {
			return DirectX::IsValid((DXGI_FORMAT)fmt);
		}
		bool IsCompressed(SharpDX::DXGI::Format fmt) {
			return DirectX::IsCompressed((DXGI_FORMAT)fmt);
		}
		bool IsPacked(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPacked((DXGI_FORMAT)fmt);
		}
		bool IsVideo(SharpDX::DXGI::Format fmt) {
			return DirectX::IsVideo((DXGI_FORMAT)fmt);
		}
		bool IsPlanar(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPlanar((DXGI_FORMAT)fmt);
		}
		bool IsPalettized(SharpDX::DXGI::Format fmt) {
			return DirectX::IsPalettized((DXGI_FORMAT)fmt);
		}
		bool IsDepthStencil(SharpDX::DXGI::Format fmt) {
			return DirectX::IsDepthStencil((DXGI_FORMAT)fmt);
		}
		bool IsSRGB(SharpDX::DXGI::Format fmt) {
			return DirectX::IsSRGB((DXGI_FORMAT)fmt);
		}
		bool IsTypeless(SharpDX::DXGI::Format fmt) {
			return DirectX::IsTypeless((DXGI_FORMAT)fmt);
		}
		bool IsTypeless(SharpDX::DXGI::Format fmt, bool partialTypeless) {
			return DirectX::IsTypeless((DXGI_FORMAT)fmt, partialTypeless);
		}
	};
}