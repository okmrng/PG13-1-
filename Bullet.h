#pragma once
class Bullet
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//�e�ő�l
	int bulletMAX_;

	float posX_[10];
	float posY_[10];
	float speed_[10];
	float radius_[10];
	bool isShot_[10];
};

