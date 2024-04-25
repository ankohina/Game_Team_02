#include "DxLib.h"
#include "Title.h"
#include "../../Input/Input.h" 
#include "../Scene.h"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�
	

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() {
	
	//�G���^�[�L�[�Ńv���C��ʂ֑J��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() {
	//�摜�`��
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�^�C�g��Enter�Ői��");
}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
