#pragma once

#define ENEMY_MAX_NUM		(10)


class Enemy
{
private:
	int EnemyHndl[ENEMY_MAX_NUM];
	int enemy_x, enemy_y;
	bool Enemy_Alive;

public:
	//コンストラクタ
	Enemy();
	//デストラクタ
	~Enemy();

	//初期化
	void InitEnemy();

	//通常
	void StepEnemy();

	//描画
	void DrawEnemy();
	//終了
	void FinEnemy();

};