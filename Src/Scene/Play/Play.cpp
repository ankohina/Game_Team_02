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


// ƒQ[ƒ€ƒvƒŒƒC‰Šú‰»
void ScenePlay::InitPlay() {
	// ƒvƒŒƒC‰æ‘œ‚Ì“Çž

	//”wŒiŠÖ˜A
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

// ƒQ[ƒ€ƒvƒŒƒC’Êíˆ—
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();
}

// ƒQ[ƒ€ƒvƒŒƒC•`‰æˆ—
void ScenePlay::DrawPlay() {
	//‰æ‘œ•`‰æ
	//”wŒi‚Ì•`‰æ
	DrawGraph(0, 0, m_background, true);
	enemy.DrawEnemy();
	player.DrawPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		DrawGraph(life_x * i, life_y, LifeHndl[i], true);
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
