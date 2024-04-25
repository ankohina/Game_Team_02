#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"




ScenePlay::ScenePlay() {
	for (int i = 0; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = -1;
	}
}

ScenePlay::~ScenePlay() {

}


// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込

	enemy.InitEnemy();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = LoadGraph(LIFE_PATH);
	}

	life_x = 130;
	life_y = 900;
	

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	
	enemy.DrawEnemy();
	player.DrawPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		DrawGraph(life_x * i, life_y, LifeHndl[i], true);
	}
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	//クリアフラグを確認して遷移先を決定
	if (!isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
	}
}
