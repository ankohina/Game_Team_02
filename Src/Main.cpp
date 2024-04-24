#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Scene/Scene.h"
#include "Playe/Player.h"
//#include "../Src/Scene/Title/Title.h"


// ���݂̃V�[��ID
//SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

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

		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------

		//switch (g_CurrentSceneID)
		//{
		//case SCENE_ID_INIT_TITLE:
		//{
		//	// �^�C�g���̏�����

		//}
		//break;

		player.InitPlayer();
		player.StepPlayer();
		player.DrawPlayer();
		player.FinPlayer();




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



