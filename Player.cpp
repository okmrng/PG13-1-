#include "Player.h"
#include <Novice.h>

//初期化
void Player::Initialize() {
	//自機
	posX_ = 640.0f;
	posY_ = 650.0f;
	speed_ = 10.0f;
	radius_ = 30.0f;

	//弾
	bullet_ = new Bullet();
	bullet_->Initialize();
}

//更新処理
void Player::Update(char* keys, char* preKeys) {
	//移動
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}

	//弾
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		for (int i = 0; i < bullet_->bulletMAX_; i++) {
			if (bullet_->isShot_[i] == false) {
				bullet_->posX_[i] = posX_;
				bullet_->posY_[i] = posY_;
				bullet_->isShot_[i] = true;

				break;
			}
		}
	}
	bullet_->Update();
}

//描画処理
void Player::Draw() {
	//弾
	bullet_->Draw();

	//自機
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
}