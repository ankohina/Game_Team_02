#pragma once
#include "../../Enemy/Enemy.h"
#include "../../Player/Player.h"


class ScenePlay {
private:
	Enemy enemy;
	Player player;
	//画像用変数
	
	//クリアかオーバーか画面遷移時に確認するフラグ
	bool isClear = false;

	
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		//プレイ初期化

	void StepPlay();		//プレイ通常処理

	void DrawPlay();		//プレイ描画処理

	void FinPlay();			//プレイ終了処理
};
