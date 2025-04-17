#include <Novice.h>
#include "Matrix4x4Math.h"
const char kWindowTitle[] = "LE2B_05_カシワギハルカ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Matrix4x4Math* matrix4M=new Matrix4x4Math;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Matrix4x4 Mat1 = {
		3.2f, 0.7f, 9.6f, 4.4f,
		5.5f, 1.3f, 7.8f, 2.1f,
		6.9f, 8.0f, 2.6f, 1.0f,
		0.5f, 7.2f, 5.1f, 3.3f
	};
	
	Matrix4x4 Mat2 = {
		4.1f, 6.5f, 3.3f, 2.2f,
		8.8f, 0.6f, 9.9f, 7.7f,
		1.1f, 5.5f, 6.6f, 0.0f, 
		3.3f, 9.9f, 8.8f, 2.2f
	};
	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		matrix4M->Math(Mat1, Mat2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		matrix4M->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete matrix4M;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
