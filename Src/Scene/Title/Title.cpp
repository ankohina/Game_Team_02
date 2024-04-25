#include "DxLib.h"
#include "Title.h"
#include "../../Input/Input.h" 
#include "../Scene.h"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込
	

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() {
	
	//エンターキーでプレイ画面へ遷移
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle() {
	//画像描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトルEnterで進む");
}

//タイトル終了処理
void SceneTitle::FinTitle() {
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
