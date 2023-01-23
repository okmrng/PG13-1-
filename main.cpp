#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "ScreenPrintf.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "GC1A_06_オクムラ_ナギ_タイトル";

//静的メンバ変数宣言
int Enemy::enemyAlive_ = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//初期化
	//自機
	Player* player = new Player();
	player->Initialize();

	//敵
	Enemy* enemy = new Enemy();
	enemy->Initialize();

	//文字
	ScreenPrintf* screenPrintf = new ScreenPrintf();

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

		//自機
		player->Update(keys, preKeys);

		//敵
		enemy->Update(keys);

		//当たり判定
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 2; j++) {
				float collisionX = player->bullet_->posX_[i] - enemy->posX_[j];
				float collisionY = player->bullet_->posY_[i] - enemy->posY_[j];
				float dis = sqrtf(collisionX * collisionX + collisionY * collisionY);

				if (enemy->enemyAlive_ == 1) {
					if (dis < 30) {
					  	enemy->enemyAlive_ = 0;
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//自機
		player->Draw();

		//敵
		enemy->Draw();

		//文字
		screenPrintf->Draw(enemy->enemyAlive_);

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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
