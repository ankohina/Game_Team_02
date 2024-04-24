#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"



//コンストラクタ
Player::Player()
{
	m_handle = 0;	//画像ハンドル


	m_x, m_y = 0;		//座標
	m_moveSpeed = 0;    //移動速度
	m_isUse = 0;        //使用中フラグ
}

//デストラクタ
Player::~Player()
{
}

//プレイ初期化
void Player::InitPlayer()
{
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 200.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;


}

//プレイ通常処理
void Player::StepPlayer()
{
	MovePlayer();
}

//プレイ描画処理
void Player::DrawPlayer()
{
	//プレイヤー描画
	DrawRotaGraph(m_x, m_y, 1.0, 0.0, m_handle, true, true);
}

//プレイ終了処理
void Player::FinPlayer()
{

}

//プレイヤーの移動処理
void Player::MovePlayer()
{
	//左移動操作
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_x -= m_moveSpeed;
	}
	//右移動操作
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_x += m_moveSpeed;
	}
}

//弾の発射処理
void Player::BulletShot()
{

}

//弾の移動処理
void Player::BulletMove()
{

}