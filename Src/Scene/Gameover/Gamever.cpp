#include "DxLib.h"
#include "Gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

#define  RESULT_PATH "data/Clearimage/result.png"

SceneGameOver::SceneGameOver() {
	BackGround_img = 0;
}

SceneGameOver::~SceneGameOver() {}

// �Q�[���I�[�o�[������
void SceneGameOver::InitGameOver() {
	//�摜�ǂݍ���
	BackGround_img = LoadGraph(RESULT_PATH);


	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
	
}

// �Q�[���I�[�o�[�ʏ폈��
void SceneGameOver::StepGameOver() {
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}

}

// �Q�[���I�[�o�[�`�揈��
void SceneGameOver::DrawGameOver() {
	DrawGraph(0, 0, BackGround_img, true);
}

//�Q�[���I�[�o�[�I������
void SceneGameOver::FinGameOver() {
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
