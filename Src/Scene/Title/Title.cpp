#include "DxLib.h"
#include "Title.h"
#include "../../Input/Input.h" 
#include "../Scene.h"

#define TITLE_BG_PATH "data/Titleimage/title_bg.png"
#define TITLE_CANON_PATH "data/Titleimage/title_canon.png"
#define TITLE_TEXT_PATH "data/Titleimage/title_text.png"
#define TITLE_BOMB_PATH "data/Titleimage/title_bomb.png"


SceneTitle::SceneTitle() {
	BackGround_img = 0;//������
	canon_img = 0;
	text_img = 0;
	bomb_img = 0;

}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�
	BackGround_img = LoadGraph(TITLE_BG_PATH);
	canon_img = LoadGraph(TITLE_CANON_PATH);
	text_img = LoadGraph(TITLE_TEXT_PATH);
	bomb_img = LoadGraph(TITLE_BOMB_PATH);

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

	DrawGraph(0, 0, BackGround_img,true);
	DrawGraph(0, 0, canon_img, true);
	DrawGraph(0, 0, text_img, true);
	DrawGraph(0, 0, bomb_img, true);

}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
