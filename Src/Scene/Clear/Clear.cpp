#include "DxLib.h"
#include "Clear.h"
#include "../Scene.h"




SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// ゲームクリア初期化
void SceneClear::InitClear() {
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

// ゲームクリア通常処理
void SceneClear::StepClear() {
	g_CurrentSceneID = SCENE_ID_FIN_CLEAR;

}

// ゲームクリア描画処理
void SceneClear::DrawClear() {

}

//ゲームクリア終了処理
void SceneClear::FinClear() {
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}