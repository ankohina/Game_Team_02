#include "DxLib.h"
#include "Gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
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

}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
