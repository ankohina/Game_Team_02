#include "DxLib.h"	//DXライブラリのインクルード
#include "Scene/Scene.h"
#include"../Src/Enemy/Enemy.h"
#include "../Src/Player/Player.h"
#include "../Src/Input/Input.h"
#include "../Src/Collision/Collison.h"
#include "../Src/Scene/Common.h"
#include "../Src/Scene/Clear/Clear.h"
#include "../Src/Scene/Gameover/Gameover.h"
#include "../Src/Scene/Title/Title.h"
#include "../Src/Scene/Play/Play.h"
#include "Playe/Player.h"
//#include "../Src/Scene/Title/Title.h"


// 現在のシーンID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	//SceneTitle Title;

	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	//クラスの呼び出し
	SceneTitle title;
	SceneClear clear;
	ScenePlay play;
	SceneGameOver gameover;

	InitInput();
	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		StepInput();
		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------
		switch (g_CurrentSceneId)
		{

		case SCENE_ID_INIT_TITLE:
		{
			title.InitTitle();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			title.StepTitle();
			title.DrawTitle();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			title.FinTitle();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{

			play.InitPlay();

		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			play.StepPlay();
			//描画
			play.DrawPlay();
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			play.FinPlay();
		}
		break;

		case SCENE_ID_INIT_GAMEOVER:
		{
			gameover.InitGameOver();
		}
		break;

		case SCENE_ID_LOOP_GAMEOVER:
		{
			gameover.StepGameOver();
			gameover.DrawGameOver();

		}
		break;

		case SCENE_ID_FIN_GAMEOVER:
		{
			gameover.FinGameOver();
		}
		break;

		case SCENE_ID_INIT_CLEAR:
		{
			clear.InitClear();
		}
		break;

		case SCENE_ID_LOOP_CLEAR:
		{
			clear.StepClear();
			clear.DrawClear();

		}
		break;

		case SCENE_ID_FIN_CLEAR:
		{
			clear.FinClear();
		}
		break;
		}




		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}


	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}



