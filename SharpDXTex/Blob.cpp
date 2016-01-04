#include "Blob.h"
#include "Stdafx.h"

using namespace SharpDXTex;

Blob::Blob(DirectX::Blob* native)
{
	this->_native = native;
}
Blob::Blob()
{
	this->_native = new DirectX::Blob();
}
void Blob::Initialize(int size)
{
	this->_native->Initialize(size);
}
void Blob::Release()
{
	this->_native->Release();
}
System::IntPtr Blob::GetBufferPointer()
{
	return (System::IntPtr)this->_native->GetBufferPointer();
}
int Blob::GetBufferSize()
{
	return this->_native->GetBufferSize();
}