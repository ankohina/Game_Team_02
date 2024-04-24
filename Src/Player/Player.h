#pragma once


#define PLAYER_PATH "data/Playimage/kari_canon.png"


//プレイヤークラス
class Player
{
public:
	int m_handle;		 //プレイヤー画像ハンドル
	float m_x, m_y;		 //座標
	float m_moveSpeed;   //移動速度
	bool m_isUse;        //使用中フラグ
	
	Player();
	~Player();

	void InitPlayer();		//プレイ初期化

	void StepPlayer();		//プレイ通常処理

	void DrawPlayer();		//プレイ描画処理

	void FinPlayer();		//プレイ終了処理

	void MovePlayer();      //プレイヤーの移動処理

	void BulletShot();      //弾の発射処理

	void BulletMove();      //弾の移動処理


};