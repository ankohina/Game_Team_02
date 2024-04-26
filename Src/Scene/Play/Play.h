#pragma once
#include "../../Enemy/Enemy.h"
#include "../../Player/Player.h"

#define LIFE_MAX_NUM		(5)

#define LIFE_PATH		"data/Playimage/life.png"

class ScenePlay {
private:
	Enemy enemy;
	
	int m_background;     //背景
	//画像用変数
	
	//クリアかオーバーか画面遷移時に確認するフラグ
	bool isClear = false;

	int LifeHndl[LIFE_MAX_NUM];
	
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		//プレイ初期化

	void StepPlay();		//プレイ通常処理

	void DrawPlay();		//プレイ描画処理

	void FinPlay();			//プレイ終了処理
};
