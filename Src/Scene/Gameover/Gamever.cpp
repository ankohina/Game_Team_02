#include "DxLib.h"
#include "Gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"
#include "string"

#define  RESULT_PATH "data/Clearimage/result.png"
#define  RESULT_TEXT_PATH "data/Clearimage/Number.png"
#define  RESULT_HIGH_SCORE_PATH "data/Clearimage/kari_highscore.png"

using namespace std;
SceneGameOver::SceneGameOver() {
    kari_highscore_img = 0;
}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
	//画像読み込み
	BackGround_img = LoadGraph(RESULT_PATH);
	score_text_img = LoadGraph(RESULT_TEXT_PATH);
    kari_highscore_img = LoadGraph(RESULT_HIGH_SCORE_PATH);

    LoadDivGraph("data/Clearimage/Number.png", 10, 10, 1, 30, 60, Number_handle);

	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

// ゲームオーバー通常処理
void SceneGameOver::StepGameOver() {
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
    SetPos(450, 400);
}

// ゲームオーバー描画処理
void SceneGameOver::DrawGameOver() {
	DrawGraph(0, 0, BackGround_img, true);
    DrawGraph(210, 495, kari_highscore_img, true);
   
    //DrawFont(kari_score);
    DrawNumber(Number_handle, Score, numberX, numberY);
}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {
    
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}


void SceneGameOver::SetPos(int num1, int num2)
{
    numberX = num1;
    numberY = num2;
}

void SceneGameOver::DrawFont(int number)
{
    Digit_1 = number % 10;
    Digit_2 = number / 10 % 10;
    Digit_3 = number / 100 %10;
    Digit_4 = number / 1000%10;
    Digit_5 = number / 10000%10;
    Digit_6 = number / 100000%10;
    Digit_7 = number / 1000000%10;
    Digit_8 = number / 10000000%10;
    Digit_9 = number / 100000000;

    DrawGraph(numberX, numberY, Number_handle[Digit_1], true);

    DrawGraph(numberX-30, numberY, Number_handle[Digit_2], true);

    DrawGraph(numberX - 60, numberY, Number_handle[Digit_3], true);
    
    DrawGraph(numberX - 90, numberY, Number_handle[Digit_4], true);
    
    DrawGraph(numberX - 120, numberY, Number_handle[Digit_5], true);
    
    DrawGraph(numberX - 150, numberY, Number_handle[Digit_6], true);
    
    DrawGraph(numberX - 180, numberY, Number_handle[Digit_7], true);
   
    DrawGraph(numberX - 210, numberY, Number_handle[Digit_8], true);
   
    DrawGraph(numberX - 240, numberY, Number_handle[Digit_9], true);

}

void SceneGameOver::DrawNumber(int Hndl[10], int Score, int X, int Y)//引数(数字画像格納ハンドル, 入れたいスコア, X座標, Y座標)
{
    //ポイント描画
    int DrawScore = Score;

    int count = 0;

    if (DrawScore == 0) {
        DrawRotaGraph(X - count * 30, Y, 1.0f, 0.0f, Hndl[0], true);
    }
    while (DrawScore > 0) {
        int num = DrawScore % 10;	//数字の確定
        DrawScore = DrawScore / 10;
        DrawRotaGraph(X - count * 30, Y, 1.0f, 0.0f, Hndl[num], true);
        count++;	//表示座標の変更
    }
}
