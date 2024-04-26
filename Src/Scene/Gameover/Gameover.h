#pragma once

class SceneGameOver {
private:
	//背景画像
	int BackGround_img;
public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();		// ゲームオーバー初期化

	void StepGameOver();		// ゲームオーバー通常処理

	void DrawGameOver();		// ゲームオーバー描画処理

	void FinGameOver();		    // ゲームオーバー終了処理
};