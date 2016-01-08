# SharpDXTex

[![Build status](https://ci.appveyor.com/api/projects/status/bqrmws8lowx7gv5k/branch/master?svg=true)](https://ci.appveyor.com/project/oguna/sharpdxtex/branch/master)

- Texture library for SharpDX3.0
- Managed wrapper of [DirectXTex](https://github.com/Microsoft/DirectXTex)

In SharpDX3.0, D3DX libraries, Texture.LoadFromFile or Texture.LoadFromStream, were removed.
If you want to use taht functions, you can use this library alternatively.

## DirectXTex version

tag : `nov2015`

## Usage

```csharp
TexMetadata metadata;
var image = ImageUtil.LoadFromWICFile("GeneticaMortarlessBlocks.jpg", WICFlags.None, out metadata);
var texture = TextureUtil.CreateTexture(device, image.GetImages(), image.GetMetadata());
var textureView = new ShaderResourceView(device, texture);
```

## Build with MSBuild

```
> msbuild SharpDXTex.sln /p:Configuration=Release /p:Platform=x64
```

## License

```
The MIT License (MIT)

Copyright (c) 2016 oguna

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
