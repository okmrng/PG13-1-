#pragma once
#include "Bullet.h"

class Player
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys, char* preKeys);

	//�`�揈��
	void Draw();

	//���@
	float posX_;
	float posY_;
	float speed_;
	float radius_;

	//�e
	Bullet* bullet_;
};

