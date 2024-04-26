#pragma once

#define BACK_GROUND "data/Playimage/Background.png"     //背景
#define PLAYER_PATH "data/Playimage/canon.png" //プレイヤー(大砲)
#define BULLET_PATH		"Data/PlayImage/Bullet.png"	//弾のパス
#define BULLET_MAX_NUM	(100)				        //弾の最大数（ハンドルの数）
#define PLAYER_SHOT_INTERVAL    (60)                //弾の発射間隔


//プレイヤークラス
class Player
{
public:
	int m_handle;		  //プレイヤー画像ハンドル
	float m_x, m_y;		  //プレイヤー座標
	float m_moveSpeed;    //移動速度
	int count;            //カウント
	bool m_isUse;         //使用中フラグ


	//弾クラス
	class Bullet {
	public:
		int m_bullet_handle;             //弾の画像ハンドル
		float m_bullet_x, m_bullet_y;    //弾の座標
		float m_bulletSpeed;             //弾の移動速度
		bool m_isUse2;                   //使用中フラグ

	};
	


	
	Player();
	~Player();

	void InitPlayer();		  //プレイ初期化

	void StepPlayer();		  //プレイ通常処理

	void DrawPlayer();		  //プレイ描画処理

	void FinPlayer();		  //プレイ終了処理

	void MovePlayer();        //プレイヤーの移動処理

	void BulletTrigerCount(); //弾の発射間隔の調整関数

	void BulletShot();        //弾の発射処理

	void BulletMove();        //弾の移動処理

	void BulletDraw();        //弾の描画関数
};


extern Player player;
extern Player::Bullet bullet[BULLET_MAX_NUM];

