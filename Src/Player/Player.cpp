#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"
#include "../Scene/Scene.h"



//�R���X�g���N�^
Player::Player()
{
	m_handle;	        //�摜�n���h��
	m_background;       //�w�i
	m_x, m_y = 0;		//���W
	m_moveSpeed = 0;    //�ړ����x
	m_isUse = 0;        //�g�p���t���O


	m_bullet1_handle;   //�e�̉摜�n���h��
	m_bullet_x, m_bullet_y = 0;       //�e�̍��W
	m_bulletSpeed = 0;  //�e�̈ړ����x
	m_isUse2 = 0;        //�g�p���t���O

}

//�f�X�g���N�^
Player::~Player()
{
}

//�v���C������
void Player::InitPlayer()
{
	//�w�i�֘A
	m_background = LoadGraph(BACK_GROUND);

	//�v���C���[�֘A
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 400.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;

	//�e�֘A
	m_bullet1_handle = LoadGraph(BULLET_PATH);
	m_bullet_x = 0;
	m_bullet_y = 0;
	m_bulletSpeed; 
	m_isUse2;

	//�e������
	for (int i = 0; i < BULLET_MAX_NUM; i++) {

		//bullet[i].m_bullet1_handle = LoadGraph(BULLET_PATH);
	}


}

//�v���C�ʏ폈��
void Player::StepPlayer()
{
	MovePlayer();


	//�v���C���[���E��ʂ��獶��ʂɍs�������鏈��
	if (m_x < -100.0f) {
		m_x = 630.0f;
	}
	if (m_x > 700.0f) {
		m_x = -100.0f;
	}
}

//�v���C�`�揈��
void Player::DrawPlayer()
{
	//�v���C���[�`��
	DrawGraph(0, 0, m_background, true);
	DrawGraph(m_x, m_y, m_handle, true);
	
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


////�e�̔��ˊԊu�̒����֐�
//void BulletTrigerCount() {
//
//	player.count++;
//	if (player.count > PLAYER_SHOT_INTERVAL) {
//		player.count = PLAYER_SHOT_INTERVAL;
//	}
//
//}
//
////�`���[�W�V���b�g�̔��ˏ����֐�
//void ChargebulletShot() {
//	if (IsKeyKeep(KEY_INPUT_Z))
//		BulletTrigerCount();
//
//	//�e�̔��ˏ���
//	if (IsKeyRelease(KEY_INPUT_Z)) {
//		if (player.count == PLAYER_SHOT_INTERVAL) {
//			for (int i = 0; i < BULLET_MAX_NUM; i++) {
//				if (!bullet[i].m_isUse) {
//					// �v���C���[�̒��S���W����e�𔭎˂��邽�߂�
//					// �e���W�̏����ʒu�Ƀv���C���[�̍��W��ݒ�
//					bullet[i].m_bullet_x = player.m_x + 90;
//					bullet[i].m_bullet_y = player.m_y + 20;
//					bullet[i].m_isUse = true;
//					break;
//				}
//			}
//		}
//		player.count = 0;
//	}
//
//	ChargebulletMove();
//}
//
////�`���[�W�V���b�g�̈ړ������֐�
//void ChargebulletMove() {
//
//	for (int i = 0; i < BULLET_MAX_NUM; i++) {
//		if (bullet[i].m_isUse) {
//			// �e���g�p���Ȃ�ړ�������
//			bullet[i].m_y += 15;
//
//			// ��ʊO�ɏo���疢�g�p�ɖ߂�
//			if (bullet[i].m_y > SCREEN_SIZE_Y) {
//				bullet[i].m_isUse = false;
//			}
//		}
//
//	}
//
//
//}