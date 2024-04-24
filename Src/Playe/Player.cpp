#include <DxLib.h>
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"


#define PLAYER_PATH "data/Playimage/kari_canon.png"
#define BACKGROUND_PATH "data/Playimage/kari_Background.png"




//コンストラクタ
Player::Player(){}

//デストラクタ
Player::~Player(){}

//ゲームプレイ初期化
void Player::InitPlayer()
{
	m_handle = LoadGraph(PLAYER_PATH);		//プレイヤー画像ハンドル




	m_x = 0;		//座標X
	m_y = 0;        //座標Y
	moveSpeed = 5;  //移動速度
	isUse = true;   //使用フラグ

	//g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//ゲームプレイ通常処理
void Player::StepPlayer()
{
	//左移動操作
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_x -= moveSpeed = 5;
	}
	//右移動操作
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_x += moveSpeed = 5;
	}

}

//ゲームプレイ描画処理
void Player::DrawPlayer()
{
	DrawGraph(200,500, m_handle, true);
}

//ゲームプレイ終了処理
void Player::FinPlayer()
{

}
