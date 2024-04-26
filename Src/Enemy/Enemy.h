#pragma once

#define ENEMY_MAX_NUM		(10)

#define ENEMY_INTERVAL		(180)
#define ENEMY_PATH		"data/Playimage/enemy.png"

class Enemy
{
private:
	int EnemyHndl[ENEMY_MAX_NUM];
	int distance_x;
	int distance_y;
	float Enemy_Count;

	float e_spd_x, e_spd_y;

public:
	//�R���X�g���N�^
	Enemy();
	//�f�X�g���N�^
	~Enemy();

	//������
	void InitEnemy();

	//�ʏ�
	void StepEnemy();

	//�`��
	void DrawEnemy();
	//�I��
	void FinEnemy();

};