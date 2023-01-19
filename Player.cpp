#include "Player.h"
#include <Novice.h>

//èâä˙âª
void Player::Initialize() {
	//é©ã@
	posX_ = 640.0f;
	posY_ = 650.0f;
	speed_ = 10.0f;
	radius_ = 30.0f;

	//íe
	bullet_ = new Bullet();
	bullet_->Initialize();
}

//çXêVèàóù
void Player::Update(char* keys, char* preKeys) {
	//à⁄ìÆ
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

	//íe
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

//ï`âÊèàóù
void Player::Draw() {
	//íe
	bullet_->Draw();

	//é©ã@
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
}