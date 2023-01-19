#pragma once
class Bullet
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Draw();

	//弾最大値
	int bulletMAX_;

	float posX_[10];
	float posY_[10];
	float speed_[10];
	float radius_[10];
	bool isShot_[10];
};

