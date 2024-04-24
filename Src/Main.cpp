#include "DxLib.h"	//DXライブラリのインクルード
#include "Scene/Scene.h"
#include "Playe/Player.h"
//#include "../Src/Scene/Title/Title.h"


// 現在のシーンID
//SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

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

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------

		//switch (g_CurrentSceneID)
		//{
		//case SCENE_ID_INIT_TITLE:
		//{
		//	// タイトルの初期化

		//}
		//break;

		player.InitPlayer();
		player.StepPlayer();
		player.DrawPlayer();
		player.FinPlayer();




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



