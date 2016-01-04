#include "Stdafx.h"
#include "Blob.h"

SharpDXTex::Blob::Blob(DirectX::Blob* native)
	:_native(native)
{
}
SharpDXTex::Blob::Blob()
	:_native(new DirectX::Blob())
{
}
void SharpDXTex::Blob::Initialize(int size)
{
	_native->Initialize(size);
}
void SharpDXTex::Blob::Release()
{
	_native->Release();
}
System::IntPtr SharpDXTex::Blob::GetBufferPointer()
{
	return (System::IntPtr)_native->GetBufferPointer();
}
int SharpDXTex::Blob::GetBufferSize()
{
	return _native->GetBufferSize();
}