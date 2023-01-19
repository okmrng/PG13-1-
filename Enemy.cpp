#include "Enemy.h"
#include <Novice.h>

//初期化
void Enemy::Initialize() {
	//enemyAlive_ = 1;

	posX_[0] = 640.0f;
	posY_[0] = 500.0f;

	posX_[1] = 780.0f;
	posY_[1] = 420.0f;

	for (int i = 0; i < 2; i++) {
		radius_[i] = 15.0f;
		speed_[i] = 10.0f;
	}
}

//更新処理
void Enemy::Update(char* keys) {
	if (enemyAlive_ == 1) {
		for (int i = 0; i < 2; i++) {
			//移動
			posX_[i] += speed_[i];

			//反射
			if (posX_[i] >= radius_[i]) {
				speed_[i] *= -1;
			}
			if (posX_[i] <= 1280 - radius_[i]) {
				speed_[i] *= -1;
			}
		}
	}

	//リスポーン
	if (enemyAlive_ == 0) {
		if (keys[DIK_R]) {
			enemyAlive_ = 1;
		}
	}
}

//描画処理
void Enemy::Draw() {
	if (enemyAlive_ == 1) {
		for (int i = 0; i < 2; i++) {
			Novice::DrawEllipse(posX_[i], posY_[i], radius_[i], radius_[i], 0.0f, RED, kFillModeSolid);
		}
	}
}