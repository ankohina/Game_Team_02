#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"
#include "../../Player/Player.h"



Player player;
Player::Bullet bullet[BULLET_MAX_NUM];


ScenePlay::ScenePlay() {
	for (int i = 0; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = -1;
	}
}

ScenePlay::~ScenePlay() {

}


// �Q�[���v���C������
void ScenePlay::InitPlay() {
	// �v���C�摜�̓Ǎ�

	//�w�i�֘A
	m_background = LoadGraph(BACK_GROUND);
	enemy.InitEnemy();
	player.InitPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = LoadGraph(LIFE_PATH);
	}

	life_x = 130;
	life_y = 900;
	

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
	//�w�i�̕`��
	DrawGraph(0, 0, m_background, true);
	enemy.DrawEnemy();
	player.DrawPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		DrawGraph(life_x * i, life_y, LifeHndl[i], true);
	}
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	//�N���A�t���O���m�F���đJ�ڐ������
	if (!isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}
}
