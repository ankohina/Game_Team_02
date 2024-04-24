#include <DxLib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		EnemyHndl[i] = -1;
	}
	enemy_x = GetRand(700);
	enemy_y = 0;

	Enemy_Alive = false;
}

Enemy::~Enemy()
{

}

void Enemy::InitEnemy()
{
	/*for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		EnemyHndl[i] = LoadGraph();
	}*/

	enemy_x = GetRand(700);
	enemy_y = 0;

	Enemy_Alive = false;
}

void Enemy::StepEnemy()
{
	if (Enemy_Alive == false)
	{
		enemy_x = GetRand(700);
		enemy_y = 0;
		Enemy_Alive = true;
	}

	//生きているなら下に進行
	if (Enemy_Alive == true)
	{
		enemy_y += 2;
	}

	if (enemy_y > 1050)
	{
		Enemy_Alive = false;
	}
}

void Enemy::DrawEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//フラグがtrueなら描画する
		if (Enemy_Alive == true)
		{
			DrawGraph(enemy_x, enemy_y, EnemyHndl[i], true);
		}
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "X座標：%d", enemy_x);
}

void Enemy::FinEnemy()
{

}