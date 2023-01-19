#include "Bullet.h"
#include <Novice.h>

//������
void Bullet::Initialize() {
	//�e�ő�l
	bulletMAX_ = 10;

	for (int i = 0; i < bulletMAX_; i++) {
		posX_[i] = 0.0f;
		posY_[i] = 0.0f;
		speed_[i] = 15.0f;
		radius_[i] = 15.0f;
		isShot_[i] = false;
	}
}

//�X�V����
void Bullet::Update() {
	for (int i = 0; i < bulletMAX_; i++) {
		if (isShot_[i] == true) {
			//�ړ�
			posY_[i] -= speed_[i];

			//��ʊO�ɍs������t���O��false�ɂ���
			if (posY_[i] <= -radius_[i]) {
				isShot_[i] = false;
			}
		}
	}
}

//�`�揈��
void Bullet::Draw() {
	for (int i = 0; i < bulletMAX_; i++) {
		if (isShot_[i] == true) {
			Novice::DrawEllipse(posX_[i], posY_[i], radius_[i], radius_[i], 0.0f, WHITE, kFillModeSolid);
		}
	}
}