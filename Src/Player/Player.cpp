#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"



//�R���X�g���N�^
Player::Player()
{
	m_handle = 0;	//�摜�n���h��


	m_x, m_y = 0;		//���W
	m_moveSpeed = 0;    //�ړ����x
	m_isUse = 0;        //�g�p���t���O
}

//�f�X�g���N�^
Player::~Player()
{
}

//�v���C������
void Player::InitPlayer()
{
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 200.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;


}

//�v���C�ʏ폈��
void Player::StepPlayer()
{
	MovePlayer();
}

//�v���C�`�揈��
void Player::DrawPlayer()
{
	//�v���C���[�`��
	DrawRotaGraph(m_x, m_y, 1.0, 0.0, m_handle, true, true);
}

//�v���C�I������
void Player::FinPlayer()
{

}

//�v���C���[�̈ړ�����
void Player::MovePlayer()
{
	//���ړ�����
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_x -= m_moveSpeed;
	}
	//�E�ړ�����
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_x += m_moveSpeed;
	}
}

//�e�̔��ˏ���
void Player::BulletShot()
{

}

//�e�̈ړ�����
void Player::BulletMove()
{

}