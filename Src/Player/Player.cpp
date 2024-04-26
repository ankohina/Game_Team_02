#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"
#include "../Scene/Scene.h"



//コンストラクタ
Player::Player()
{
	m_handle;	        //画像ハンドル
	m_x, m_y = 0;		//座標
	m_moveSpeed = 0;    //移動速度
	m_isUse = 0;        //使用中フラグ


	bullet->m_bullet_handle;   //弾の画像ハンドル
	bullet->m_bullet_x = 0;     //弾の座標X
	bullet->m_bullet_y = 0;     //弾の座標Y
	bullet->m_bulletSpeed = 0;  //弾の移動速度
	bullet->m_isUse2 = 0;       //使用中フラグ
}

//デストラクタ
Player::~Player()
{
}

//プレイ初期化
void Player::InitPlayer()
{
	

	//プレイヤー関連
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 780.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;

	//弾関連
	bullet->m_bullet_handle = LoadGraph(BULLET_PATH);
	bullet->m_bullet_x = 0;     
	bullet->m_bullet_y = 0;    
	bullet->m_bulletSpeed = 0;  
	bullet->m_isUse2 = true;     

	//弾初期化
	for (int i = 0; i < BULLET_MAX_NUM; i++) {

		bullet[i].m_bullet_handle = LoadGraph(BULLET_PATH);
	}


}

//プレイ通常処理
void Player::StepPlayer()
{
	//プレイヤーの移動処理
	MovePlayer();


	//プレイヤーが右画面から左画面に行き来する処理
	if (m_x < -100.0f) {
		m_x = 630.0f;
	}
	if (m_x > 750.0f) {
		m_x = -100.0f;
	}

	//弾の発射間隔の調整関数
	BulletTrigerCount();

	//弾の発射処理関数
	BulletShot();

	//弾の移動処理関数
	BulletMove();

}

//プレイ描画処理
void Player::DrawPlayer()
{
	
	//プレイヤー描画
	DrawGraph(m_x, m_y, m_handle, true);

	//弾の描画
	BulletDraw();
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

//弾の発射間隔の調整関数
void Player::BulletTrigerCount() {

	player.count++;
	if (player.count > PLAYER_SHOT_INTERVAL) {
		player.count = PLAYER_SHOT_INTERVAL;
	}

}

//弾の発射処理関数
void Player::BulletShot() {
	if (IsKeyKeep(KEY_INPUT_SPACE))
		BulletTrigerCount();

	//弾の発射処理
	if (IsKeyRelease(KEY_INPUT_SPACE)) {
		if (player.count == PLAYER_SHOT_INTERVAL) {
			for (int i = 0; i < BULLET_MAX_NUM; i++) {
				if (!bullet[i].m_isUse2) {
					// プレイヤーの中心座標から弾を発射するために
					// 弾座標の初期位置にプレイヤーの座標を設定
					bullet[i].m_bullet_x = player.m_x + 105;
					bullet[i].m_bullet_y = player.m_y - 35;
					bullet[i].m_isUse2 = true;
					break;
				}
			}
		}
		player.count = 0;
	}

	BulletMove();
}

//弾の移動処理関数
void Player::BulletMove() {

	for (int i = 0; i < BULLET_MAX_NUM; i++) {
		if (bullet[i].m_isUse2) {
			// 弾が使用中なら移動させる
			bullet[i].m_bullet_y -= 12;

			// 画面外に出たら未使用に戻す
			if (bullet[i].m_bullet_y > SCREEN_SIZE_Y) {
				bullet[i].m_isUse2 = false;
			}
		}

	}


}

//弾の描画関数
void Player::BulletDraw() {
	//弾の描画
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		//弾が使用中なら描画する
		if (bullet[i].m_isUse2)
		{
			DrawRotaGraph(bullet[i].m_bullet_x, bullet[i].m_bullet_y,
				1.0, 0.0, bullet[i].m_bullet_handle, true);
		}
	}
}