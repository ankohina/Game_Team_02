#include "DxLib.h"
#include "Clear.h"
#include "../Scene.h"




SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// �Q�[���N���A������
void SceneClear::InitClear() {
	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// �Q�[���N���A�ʏ폈��
void SceneClear::StepClear() {
	g_CurrentSceneId = SCENE_ID_FIN_CLEAR;

}

// �Q�[���N���A�`�揈��
void SceneClear::DrawClear() {

}

//�Q�[���N���A�I������
void SceneClear::FinClear() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}