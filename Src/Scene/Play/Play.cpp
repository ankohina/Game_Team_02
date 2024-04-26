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


// ƒQ[ƒ€ƒvƒŒƒC‰Šú‰»
void ScenePlay::InitPlay() {
	// ƒvƒŒƒC‰æ‘œ‚Ì“Çž

	//”wŒiŠÖ˜A
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

// ƒQ[ƒ€ƒvƒŒƒC’Êíˆ—
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();

	//“G‚Æƒ‰ƒCƒt‚Ì“–‚½‚è”»’è
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

// ƒQ[ƒ€ƒvƒŒƒC•`‰æˆ—
void ScenePlay::DrawPlay() {
	//‰æ‘œ•`‰æ
	//”wŒi‚Ì•`‰æ
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

//ƒQ[ƒ€ƒvƒŒƒCI—¹ˆ—
void ScenePlay::FinPlay() {
	//ƒNƒŠƒAƒtƒ‰ƒO‚ðŠm”F‚µ‚Ä‘JˆÚæ‚ðŒˆ’è
	if (!isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}
}
