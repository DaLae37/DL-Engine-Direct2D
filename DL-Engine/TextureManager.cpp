#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

ID2D1Bitmap* TextureManager::LoadTextureFromFile(const wchar_t* path) {

	ID2D1Bitmap* texture;

	IWICBitmapDecoder* pDecoder = nullptr;
	IWICBitmapFrameDecode* pSource = nullptr;
	IWICFormatConverter* pConverter = nullptr;

	if (textureMap[path] == nullptr) {
		HRESULT hr = wicFactory->CreateDecoderFromFilename(path, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);
		if (SUCCEEDED(hr)) {
			hr = pDecoder->GetFrame(0, &pSource);
		}

		if (SUCCEEDED(hr)) {
			hr = wicFactory->CreateFormatConverter(&pConverter);
		}

		if (SUCCEEDED(hr)) {
			hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, nullptr, 0.f, WICBitmapPaletteTypeMedianCut);
		}

		if (SUCCEEDED(hr)) {
			hr = renderTarget->CreateBitmapFromWicBitmap(pConverter, nullptr, &texture);
		}

		if (SUCCEEDED(hr)) {
			textureMap[path] = texture;
		}
	}

	SAFE_RELEASE(pDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pConverter);

	return textureMap[path];
}