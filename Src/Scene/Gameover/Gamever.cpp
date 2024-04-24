#include "DxLib.h"
#include "Gameover.h"
#include "../Scene.h"
#include "../../Input/Input.h"

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// �Q�[���I�[�o�[������
void SceneGameOver::InitGameOver() {
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

}

//�Q�[���I�[�o�[�I������
void SceneGameOver::FinGameOver() {
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
