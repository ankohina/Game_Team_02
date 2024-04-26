#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"
#include "../../Collision/Collison.h"
#include "../../Player/Player.h"


Player player;
Player::Bullet bullet[BULLET_MAX_NUM];


ScenePlay::ScenePlay() {
	for (int i = 0; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = -1;
		Life_flag[i] = false;
		life_x[i] = 0;
	}
	
	life_y = 0;
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

	for (int i = 0; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = LoadGraph(LIFE_PATH);
		Life_flag[i] = true;

		life_x[0] = 130;
		life_x[1] = 260;
		life_x[2] = 390;
		life_x[3] = 520;
	}
	

	life_y = 900;
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();

	//�G�ƃ��C�t�̓����蔻��
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (Enemy_Alive[i] == true)
		{
			for (int a = 0; a < LIFE_MAX_NUM; a++)
			{
				if (Life_flag[a] == true)
				{
					DrawBox(life_x[a], life_y, life_x[a] + 64, life_y + 64, GetColor(255, 255, 255), true);
					DrawBox(enemy_x[i], enemy_y[i], enemy_x[i] + 100, enemy_y[i] + 100, GetColor(255, 255, 255), true);
					if (IsHitRect(enemy_x[i], enemy_y[i], 100, 100, life_x[a], life_y, 64, 64))
					{
						Life_flag[a] = false;
						Enemy_Alive[i] = false;
					}
				}
			}
		}
	}
	
	if (Life_flag[0] == false && Life_flag[1] == false && Life_flag[2] == false && Life_flag[3] == false)
	{
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
	
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
	//�w�i�̕`��
	/*DrawGraph(0, 0, m_background, true);*/
	enemy.DrawEnemy();
	player.DrawPlayer();

	for (int i = 0; i < LIFE_MAX_NUM; i++)
	{
		if (Life_flag[i] == true)
		{
			DrawGraph(life_x[i], life_y, LifeHndl[i], true);
		}
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
