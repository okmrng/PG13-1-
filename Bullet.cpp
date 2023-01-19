#include "Bullet.h"
#include <Novice.h>

//初期化
void Bullet::Initialize() {
	//弾最大値
	bulletMAX_ = 10;

	for (int i = 0; i < bulletMAX_; i++) {
		posX_[i] = 0.0f;
		posY_[i] = 0.0f;
		speed_[i] = 15.0f;
		radius_[i] = 15.0f;
		isShot_[i] = false;
	}
}

//更新処理
void Bullet::Update() {
	for (int i = 0; i < bulletMAX_; i++) {
		if (isShot_[i] == true) {
			//移動
			posY_[i] -= speed_[i];

			//画面外に行ったらフラグをfalseにする
			if (posY_[i] <= -radius_[i]) {
				isShot_[i] = false;
			}
		}
	}
}

//描画処理
void Bullet::Draw() {
	for (int i = 0; i < bulletMAX_; i++) {
		if (isShot_[i] == true) {
			Novice::DrawEllipse(posX_[i], posY_[i], radius_[i], radius_[i], 0.0f, WHITE, kFillModeSolid);
		}
	}
}