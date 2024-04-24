#include <DxLib.h>
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"


#define PLAYER_PATH "data/Playimage/kari_canon.png"
#define BACKGROUND_PATH "data/Playimage/kari_Background.png"




//�R���X�g���N�^
Player::Player(){}

//�f�X�g���N�^
Player::~Player(){}

//�Q�[���v���C������
void Player::InitPlayer()
{
	m_handle = LoadGraph(PLAYER_PATH);		//�v���C���[�摜�n���h��




	m_x = 0;		//���WX
	m_y = 0;        //���WY
	moveSpeed = 5;  //�ړ����x
	isUse = true;   //�g�p�t���O

	//g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�Q�[���v���C�ʏ폈��
void Player::StepPlayer()
{
	//���ړ�����
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_x -= moveSpeed = 5;
	}
	//�E�ړ�����
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_x += moveSpeed = 5;
	}

}

//�Q�[���v���C�`�揈��
void Player::DrawPlayer()
{
	DrawGraph(200,500, m_handle, true);
}

//�Q�[���v���C�I������
void Player::FinPlayer()
{

}
