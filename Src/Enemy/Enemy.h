#pragma once

#define ENEMY_MAX_NUM		(10)


class Enemy
{
private:
	int EnemyHndl[ENEMY_MAX_NUM];
	int enemy_x, enemy_y;
	bool Enemy_Alive;

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