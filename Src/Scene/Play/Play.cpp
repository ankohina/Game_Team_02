#include "DxLib.h"
#include "../Scene.h"
#include "Play.h"
#include "../../Input/Input.h"




ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}


// �Q�[���v���C������
void ScenePlay::InitPlay() {
	// �v���C�摜�̓Ǎ�
	

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {
	
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
	
	enemy.DrawEnemy();
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	//�N���A�t���O���m�F���đJ�ڐ������
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}
