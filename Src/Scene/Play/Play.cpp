#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"




ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}


// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込
	

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {
	
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
	
	enemy.DrawEnemy();
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	//クリアフラグを確認して遷移先を決定
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}
