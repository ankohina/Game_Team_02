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


// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込

	//背景関連
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

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	
	enemy.StepEnemy();
	player.StepPlayer();


	//弾と敵の当たり判定
	for (int b = 0; b < BULLET_MAX_NUM; b++) {
		
		if (bullet[b].m_isUse2 == true) {

			for (int e = 0; e < ENEMY_MAX_NUM; e++) {

				if (Enemy_Alive[e] == true) {

					DrawBox(bullet[b].m_bullet_x, bullet[b].m_bullet_y, bullet[b].m_bullet_x + 100, bullet[b].m_bullet_y + 100, GetColor(255, 255, 255), true);
					DrawBox(enemy_x[e], enemy_y[e], enemy_x[e] + 100, enemy_y[e] + 100, GetColor(255, 255, 255), true);
					if (IsHitRect(enemy_x[e], enemy_y[e], 100, 100, bullet[b].m_bullet_x, bullet[b].m_bullet_y, 100,100)) {

						Score++;
						Enemy_Alive[e] = false;
					}

				}
			}
		}
	}

	//敵とライフの当たり判定
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

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	//背景の描画
	DrawGraph(0, 0, m_background, true);
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
