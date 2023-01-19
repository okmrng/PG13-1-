#pragma once
#include "Bullet.h"

class Player
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys, char* preKeys);

	//描画処理
	void Draw();

	//自機
	float posX_;
	float posY_;
	float speed_;
	float radius_;

	//弾
	Bullet* bullet_;
};

