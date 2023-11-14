#include <cassert>
#include <combaseapi.h>
#include "TextureConverter.h"

// コマンドライン引数
enum Argument
{
	kApplicationPath, // アプリケーションのパス
	kFilePath,		  // 渡されたファイルのパス

	NumArgument
};

int main(int argc, char* argv[])
{
	assert(argc >= NumArgument);

	// COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバーター
	TextureConverter converter;

	// テクスチャ変換
	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	// COMライブラリの終了
	CoUninitialize();

	system("pause");

	return 0;
}