#include "DxLib.h"
#include "Title.h"
#include "../../Input/Input.h" 
#include "../Scene.h"

#define TITLE_BG_PATH "data/Titleimage/title_bg.png"
#define TITLE_CANON_PATH "data/Titleimage/title_canon.png"
#define TITLE_TEXT_PATH "data/Titleimage/title_text.png"
#define TITLE_BOMB_PATH "data/Titleimage/title_bomb.png"


SceneTitle::SceneTitle() {
	BackGround_img = 0;//初期化
	canon_img = 0;
	text_img = 0;
	bomb_img = 0;

}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込
	BackGround_img = LoadGraph(TITLE_BG_PATH);
	canon_img = LoadGraph(TITLE_CANON_PATH);
	text_img = LoadGraph(TITLE_TEXT_PATH);
	bomb_img = LoadGraph(TITLE_BOMB_PATH);

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

	DrawGraph(0, 0, BackGround_img,true);
	DrawGraph(0, 0, canon_img, true);
	DrawGraph(0, 0, text_img, true);
	DrawGraph(0, 0, bomb_img, true);

}

//タイトル終了処理
void SceneTitle::FinTitle() {
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
