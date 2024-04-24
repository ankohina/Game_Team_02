#pragma once


//プレイヤークラス
class Player
{
public:
	int m_handle;		//プレイヤー画像ハンドル
	int m_x, m_y;		//座標
	int moveSpeed;      //移動速度
	bool isUse;         //使用中フラグ
	
	Player();
	~Player();

	void InitPlayer();		//プレイ初期化

	void StepPlayer();		//プレイ通常処理

	void DrawPlayer();		//プレイ描画処理

	void FinPlayer();		//プレイ終了処理


};