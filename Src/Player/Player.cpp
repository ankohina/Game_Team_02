#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"
#include "../Scene/Scene.h"



//コンストラクタ
Player::Player()
{
	m_handle;	        //画像ハンドル
	m_background;       //背景
	m_x, m_y = 0;		//座標
	m_moveSpeed = 0;    //移動速度
	m_isUse = 0;        //使用中フラグ


	m_bullet1_handle;   //弾の画像ハンドル
	m_bullet_x, m_bullet_y = 0;       //弾の座標
	m_bulletSpeed = 0;  //弾の移動速度
	m_isUse2 = 0;        //使用中フラグ

}

//デストラクタ
Player::~Player()
{
}

//プレイ初期化
void Player::InitPlayer()
{
	//背景関連
	m_background = LoadGraph(BACK_GROUND);

	//プレイヤー関連
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 400.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;

	//弾関連
	m_bullet1_handle = LoadGraph(BULLET_PATH);
	m_bullet_x = 0;
	m_bullet_y = 0;
	m_bulletSpeed; 
	m_isUse2;

	//弾初期化
	for (int i = 0; i < BULLET_MAX_NUM; i++) {

		//bullet[i].m_bullet1_handle = LoadGraph(BULLET_PATH);
	}


}

//プレイ通常処理
void Player::StepPlayer()
{
	MovePlayer();


	//プレイヤーが右画面から左画面に行き来する処理
	if (m_x < -100.0f) {
		m_x = 630.0f;
	}
	if (m_x > 700.0f) {
		m_x = -100.0f;
	}
}

//プレイ描画処理
void Player::DrawPlayer()
{
	//プレイヤー描画
	DrawGraph(0, 0, m_background, true);
	DrawGraph(m_x, m_y, m_handle, true);
	
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


////弾の発射間隔の調整関数
//void BulletTrigerCount() {
//
//	player.count++;
//	if (player.count > PLAYER_SHOT_INTERVAL) {
//		player.count = PLAYER_SHOT_INTERVAL;
//	}
//
//}
//
////チャージショットの発射処理関数
//void ChargebulletShot() {
//	if (IsKeyKeep(KEY_INPUT_Z))
//		BulletTrigerCount();
//
//	//弾の発射処理
//	if (IsKeyRelease(KEY_INPUT_Z)) {
//		if (player.count == PLAYER_SHOT_INTERVAL) {
//			for (int i = 0; i < BULLET_MAX_NUM; i++) {
//				if (!bullet[i].m_isUse) {
//					// プレイヤーの中心座標から弾を発射するために
//					// 弾座標の初期位置にプレイヤーの座標を設定
//					bullet[i].m_bullet_x = player.m_x + 90;
//					bullet[i].m_bullet_y = player.m_y + 20;
//					bullet[i].m_isUse = true;
//					break;
//				}
//			}
//		}
//		player.count = 0;
//	}
//
//	ChargebulletMove();
//}
//
////チャージショットの移動処理関数
//void ChargebulletMove() {
//
//	for (int i = 0; i < BULLET_MAX_NUM; i++) {
//		if (bullet[i].m_isUse) {
//			// 弾が使用中なら移動させる
//			bullet[i].m_y += 15;
//
//			// 画面外に出たら未使用に戻す
//			if (bullet[i].m_y > SCREEN_SIZE_Y) {
//				bullet[i].m_isUse = false;
//			}
//		}
//
//	}
//
//
//}