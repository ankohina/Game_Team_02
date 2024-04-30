#pragma once

class SceneGameOver {
private:
	//背景画像
	int BackGround_img;
	int score_text_img;

	int kari_highscore_img;

	int Number_handle[10];
	float numberX, numberY;

	int kari_score;
public:
	SceneGameOver();
	~SceneGameOver();
	int Digit_1 = -1;
	int Digit_2 = -1;
	int Digit_3 = -1;
	int Digit_4 = -1;
	int Digit_5 = -1;
	int Digit_6 = -1;
	int Digit_7 = -1;
	int Digit_8 = -1;
	int Digit_9 = -1;

	void InitGameOver();		// ゲームオーバー初期化

	void StepGameOver();		// ゲームオーバー通常処理

	void DrawGameOver();		// ゲームオーバー描画処理

	void FinGameOver();		    // ゲームオーバー終了処理

	void SetPos(int num1, int num2);

	void DrawFont(int number);

	void DrawNumber(int Hndl[10], int Score, int X, int Y);
};
