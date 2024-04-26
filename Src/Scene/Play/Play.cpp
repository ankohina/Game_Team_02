#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"
#include "../../Collision/Collison.h"



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


// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込

	enemy.InitEnemy();
	player.InitPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		LifeHndl[i] = LoadGraph(LIFE_PATH);
		Life_flag[i] = true;
	}
	life_x[0] = 130;
	life_x[1] = 260;
	life_x[2] = 390;
	life_x[3] = 520;

	life_y = 900;
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();

		for (int i = 0; i < ENEMY_MAX_NUM; i++)
		{
			if (Enemy_Alive[i] == true)
			{
				for (int a = 1; a < LIFE_MAX_NUM; a++)
				{
					if (Life_flag[a] == true)
					{
						DrawBox(life_x[a], life_y, life_x[a] + 64, life_y + 64, GetColor(255, 255, 255), true);
						if (IsHitRect(enemy_x[i], enemy_y[i], 100, 100, life_x[a], life_y, 64, 64))
						{
							Life_flag[a] = false;
							Enemy_Alive[i] = false;

							break;
						}
					}
				}
			}
			
		}
	
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	
	enemy.DrawEnemy();
	player.DrawPlayer();

	for (int i = 1; i < LIFE_MAX_NUM; i++)
	{
		if (Life_flag[i] == true)
		{
			DrawGraph(life_x[i], life_y, LifeHndl[i], true);
		}
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
