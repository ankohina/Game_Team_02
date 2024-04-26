#include "DxLib.h"
#include "Gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

#define  RESULT_PATH "data/Clearimage/result.png"

SceneGameOver::SceneGameOver() {
	BackGround_img = 0;
}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
	//画像読み込み
	BackGround_img = LoadGraph(RESULT_PATH);


	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
	
}

// ゲームオーバー通常処理
void SceneGameOver::StepGameOver() {
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}

}

// ゲームオーバー描画処理
void SceneGameOver::DrawGameOver() {
	DrawGraph(0, 0, BackGround_img, true);
}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
