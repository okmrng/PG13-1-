#pragma once
class Enemy
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys);

	//�`�揈��
	void Draw();

	//�����o�ϐ�
	static int enemyAlive_;

	float posX_[2];
	float posY_[2];
	float speed_[2];
	float radius_[2];
};

