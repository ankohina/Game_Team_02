#include <DxLib.h>
#include "Enemy.h"
#include "../Scene/Play/Play.h"
#include "../Scene/Scene.h"

Enemy::Enemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		EnemyHndl[i] = -1;
		enemy_x[i] = GetRand(700);
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

		enemy_x[i] = GetRand(700);
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

	//�t���[���J�E���g�ł��鏈��
	Enemy_Count++;
	if (Enemy_Count > ENEMY_INTERVAL)
	{
		Enemy_Count = ENEMY_INTERVAL;
	}

	if (Enemy_Count == ENEMY_INTERVAL)
	{
		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			for (int a = 0; a < LIFE_MAX_NUM; a++)
			{
				if (Enemy_Alive[i] == false)
				{
					enemy_x[i] = GetRand(500) + 100;
					enemy_y[i] = 0;
					Enemy_Alive[i] = true;

					//�G�l�~�[�ƃ��C�t�̋���
					distance_x = life_x[a] - enemy_x[i];
					distance_y = life_y - enemy_y[i];

					//�����鏈��
					e_spd_x = distance_x / 300;
					e_spd_y = distance_y / 300;
					Enemy_Count = 0.0f;
					break;
				}
			}
		}
	}
	
	//���b�̏���
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//�����Ă���Ȃ牺�ɐi�s
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
		//�t���O��true�Ȃ�`�悷��
		if (Enemy_Alive[i] == true)
		{
			DrawGraph(enemy_x[i], enemy_y[i], EnemyHndl[i], true);
		}
		DrawFormatString(0, 15 * i, GetColor(255, 255, 255), "X���W�F%d" "y���W�F%d", enemy_x[i], enemy_y[i]);
	}

	
}

void Enemy::FinEnemy()
{

}