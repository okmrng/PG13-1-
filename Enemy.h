#pragma once
class Enemy
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys);

	//描画処理
	void Draw();

	//メンバ変数
	static int enemyAlive_;

	float posX_[2];
	float posY_[2];
	float speed_[2];
	float radius_[2];
};

