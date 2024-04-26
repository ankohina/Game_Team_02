#include <DxLib.h>
#include "Enemy.h"
#include "../Scene/Play/Play.h"
#include "../Scene/Scene.h"

Enemy::Enemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		EnemyHndl[i] = -1;
		enemy_x[i] = GetRand(500);
		enemy_y[i] = 0;
		Enemy_Alive[i] = false;
	}
	

	distance_x = 0;
	distance_y = 0;

	e_spd_x = 0.0f;
	e_spd_y = 0.0f;

	Enemy_Count = 0.0f;
}

Enemy::~Enemy()
{

}

void Enemy::InitEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		EnemyHndl[i] = LoadGraph(ENEMY_PATH);
		enemy_x[i] = GetRand(500);
		enemy_y[i] = 0;

		Enemy_Alive[i] = false;
	}
	

	distance_x = 0;
	distance_y = 0;

	e_spd_x = 0.0f;
	e_spd_y = 0.0f;

	Enemy_Count = 0.0f;
}

void Enemy::StepEnemy()
{

	//フレームカウントでする処理
	Enemy_Count++;
	if (Enemy_Count > ENEMY_INTERVAL)
	{
		Enemy_Count = ENEMY_INTERVAL;
	}

	if (Enemy_Count == ENEMY_INTERVAL)
	{
		bool Flag = false;
		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			for (int a = 0; a < LIFE_MAX_NUM; a++)
			{
				if (Enemy_Alive[i] == false)
				{
					//敵出現処理
					enemy_x[i] = GetRand(500) + 100;
					enemy_y[i] = 0;
					Enemy_Alive[i] = true;
					Flag = true;

					//エネミーとライフの距離
					distance_x = life_x[a] - enemy_x[i];
					distance_y = life_y - enemy_y[i];

					//落ちる処理
					e_spd_x = distance_x / 300;
					e_spd_y = distance_y / 300;

					Enemy_Count = 0.0f;
					if (Flag == true)
					{
						break;
					}
				}
			}
			if (Flag == true)
			{
				break;
			}
			
		}
	}
	
	//毎秒の処理
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//生きているなら下に進行
		if (Enemy_Alive[i] == true)
		{
			enemy_y[i] += e_spd_y;
		}

		if (enemy_y[i] > 1050)
		{
			Enemy_Alive[i] = false;
		}
	}
}

void Enemy::DrawEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//フラグがtrueなら描画する
		if (Enemy_Alive[i] == true)
		{
			DrawGraph(enemy_x[i], enemy_y[i], EnemyHndl[i], true);
		}
		DrawFormatString(0, 15 * i, GetColor(255, 255, 255), "X座標：%d" "y座標：%d", enemy_x, enemy_y[i]);
		DrawFormatString(0, 500, GetColor(255, 255, 255), "%f", Enemy_Count);
	}

	
}

void Enemy::FinEnemy()
{

}