#pragma once

#define	SCREEN_SIZE_X	700	    // X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	1000		// Y方向の画面サイズを指定

enum SCENE_ID
{
	//タイトルシーンID
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイシーンID
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//クリアシーンID
	SCENE_ID_INIT_CLEAR,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,

	//ゲームオーバーシーンID
	SCENE_ID_INIT_GAMEOVER,
	SCENE_ID_LOOP_GAMEOVER,
	SCENE_ID_FIN_GAMEOVER,
};

//　現在のシーンID
extern SCENE_ID g_CurrentSceneID;

extern int life_x;
extern int life_y;