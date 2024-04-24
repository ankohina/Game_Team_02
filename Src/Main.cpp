#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Scene/Scene.h"
#include"../Src/Enemy/Enemy.h"
#include "../Src/Player/Player.h"
#include "../Src/Input/Input.h"
#include "../Src/Collision/Collison.h"
#include "../Src/Scene/Common.h"
#include "../Src/Scene/Clear/Clear.h"
#include "../Src/Scene/Gameover/Gameover.h"
#include "../Src/Scene/Title/Title.h"
#include "../Src/Scene/Play/Play.h"
#include "Playe/Player.h"
//#include "../Src/Scene/Title/Title.h"


// ���݂̃V�[��ID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	//SceneTitle Title;

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	//�N���X�̌Ăяo��
	SceneTitle title;
	SceneClear clear;
	ScenePlay play;
	SceneGameOver gameover;

	InitInput();
	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		StepInput();
		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------
		switch (g_CurrentSceneId)
		{

		case SCENE_ID_INIT_TITLE:
		{
			title.InitTitle();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			title.StepTitle();
			title.DrawTitle();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			title.FinTitle();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{

			play.InitPlay();

		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			play.StepPlay();
			//�`��
			play.DrawPlay();
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			play.FinPlay();
		}
		break;

		case SCENE_ID_INIT_GAMEOVER:
		{
			gameover.InitGameOver();
		}
		break;

		case SCENE_ID_LOOP_GAMEOVER:
		{
			gameover.StepGameOver();
			gameover.DrawGameOver();

		}
		break;

		case SCENE_ID_FIN_GAMEOVER:
		{
			gameover.FinGameOver();
		}
		break;

		case SCENE_ID_INIT_CLEAR:
		{
			clear.InitClear();
		}
		break;

		case SCENE_ID_LOOP_CLEAR:
		{
			clear.StepClear();
			clear.DrawClear();

		}
		break;

		case SCENE_ID_FIN_CLEAR:
		{
			clear.FinClear();
		}
		break;
		}




		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}


	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}



