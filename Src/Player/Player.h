#pragma once


#define PLAYER_PATH "data/Playimage/kari_canon.png"


//�v���C���[�N���X
class Player
{
public:
	int m_handle;		 //�v���C���[�摜�n���h��
	float m_x, m_y;		 //���W
	float m_moveSpeed;   //�ړ����x
	bool m_isUse;        //�g�p���t���O
	
	Player();
	~Player();

	void InitPlayer();		//�v���C������

	void StepPlayer();		//�v���C�ʏ폈��

	void DrawPlayer();		//�v���C�`�揈��

	void FinPlayer();		//�v���C�I������

	void MovePlayer();      //�v���C���[�̈ړ�����

	void BulletShot();      //�e�̔��ˏ���

	void BulletMove();      //�e�̈ړ�����


};