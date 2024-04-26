#pragma once

//タイトルクラス
class SceneTitle {
private:
	//画像用変数
	int BackGround_img;
	int canon_img;
	int text_img;
	int bomb_img;

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// タイトル初期化

	void StepTitle();		// タイトル通常処理

	void DrawTitle();		// タイトル描画処理

	void FinTitle();		// タイトル終了処理
};