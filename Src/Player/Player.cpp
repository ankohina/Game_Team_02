#include <DxLib.h>
#include "Player.h"
#include "../Collision/Collison.h"
#include "../Input/Input.h"
#include "../Scene/Scene.h"



//�R���X�g���N�^
Player::Player()
{
	m_handle;	        //�摜�n���h��
	m_x, m_y = 0;		//���W
	m_moveSpeed = 0;    //�ړ����x
	m_isUse = 0;        //�g�p���t���O


	bullet->m_bullet_handle;   //�e�̉摜�n���h��
	bullet->m_bullet_x = 0;     //�e�̍��WX
	bullet->m_bullet_y = 0;     //�e�̍��WY
	bullet->m_bulletSpeed = 0;  //�e�̈ړ����x
	bullet->m_isUse2 = 0;       //�g�p���t���O
}

//�f�X�g���N�^
Player::~Player()
{
}

//�v���C������
void Player::InitPlayer()
{
	

	//�v���C���[�֘A
	m_handle = LoadGraph(PLAYER_PATH);
	m_x = 200.0f;
	m_y = 780.0f;
	m_moveSpeed = 5.0f;
	m_isUse = true;

	//�e�֘A
	bullet->m_bullet_handle = LoadGraph(BULLET_PATH);
	bullet->m_bullet_x = 0;     
	bullet->m_bullet_y = 0;    
	bullet->m_bulletSpeed = 0;  
	bullet->m_isUse2 = true;     

	//�e������
	for (int i = 0; i < BULLET_MAX_NUM; i++) {

		bullet[i].m_bullet_handle = LoadGraph(BULLET_PATH);
	}


}

//�v���C�ʏ폈��
void Player::StepPlayer()
{
	//�v���C���[�̈ړ�����
	MovePlayer();


	//�v���C���[���E��ʂ��獶��ʂɍs�������鏈��
	if (m_x < -100.0f) {
		m_x = 630.0f;
	}
	if (m_x > 750.0f) {
		m_x = -100.0f;
	}

	//�e�̔��ˊԊu�̒����֐�
	BulletTrigerCount();

	//�e�̔��ˏ����֐�
	BulletShot();

	//�e�̈ړ������֐�
	BulletMove();

}

//�v���C�`�揈��
void Player::DrawPlayer()
{
	
	//�v���C���[�`��
	DrawGraph(m_x, m_y, m_handle, true);

	//�e�̕`��
	BulletDraw();
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

//�e�̔��ˊԊu�̒����֐�
void Player::BulletTrigerCount() {

	player.count++;
	if (player.count > PLAYER_SHOT_INTERVAL) {
		player.count = PLAYER_SHOT_INTERVAL;
	}

}

//�e�̔��ˏ����֐�
void Player::BulletShot() {
	if (IsKeyKeep(KEY_INPUT_SPACE))
		BulletTrigerCount();

	//�e�̔��ˏ���
	if (IsKeyRelease(KEY_INPUT_SPACE)) {
		if (player.count == PLAYER_SHOT_INTERVAL) {
			for (int i = 0; i < BULLET_MAX_NUM; i++) {
				if (!bullet[i].m_isUse2) {
					// �v���C���[�̒��S���W����e�𔭎˂��邽�߂�
					// �e���W�̏����ʒu�Ƀv���C���[�̍��W��ݒ�
					bullet[i].m_bullet_x = player.m_x + 105;
					bullet[i].m_bullet_y = player.m_y - 35;
					bullet[i].m_isUse2 = true;
					break;
				}
			}
		}
		player.count = 0;
	}

	BulletMove();
}

//�e�̈ړ������֐�
void Player::BulletMove() {

	for (int i = 0; i < BULLET_MAX_NUM; i++) {
		if (bullet[i].m_isUse2) {
			// �e���g�p���Ȃ�ړ�������
			bullet[i].m_bullet_y -= 12;

			// ��ʊO�ɏo���疢�g�p�ɖ߂�
			if (bullet[i].m_bullet_y > SCREEN_SIZE_Y) {
				bullet[i].m_isUse2 = false;
			}
		}

	}


}

//�e�̕`��֐�
void Player::BulletDraw() {
	//�e�̕`��
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		//�e���g�p���Ȃ�`�悷��
		if (bullet[i].m_isUse2)
		{
			DrawRotaGraph(bullet[i].m_bullet_x, bullet[i].m_bullet_y,
				1.0, 0.0, bullet[i].m_bullet_handle, true);
		}
	}
}