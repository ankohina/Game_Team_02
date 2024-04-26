#pragma once

#define BACK_GROUND "data/Playimage/Background.png"     //�w�i
#define PLAYER_PATH "data/Playimage/canon.png" //�v���C���[(��C)
#define BULLET_PATH		"Data/PlayImage/Bullet.png"	//�e�̃p�X
#define BULLET_MAX_NUM	(100)				        //�e�̍ő吔�i�n���h���̐��j
#define PLAYER_SHOT_INTERVAL    (60)                //�e�̔��ˊԊu


//�v���C���[�N���X
class Player
{
public:
	int m_handle;		  //�v���C���[�摜�n���h��
	float m_x, m_y;		  //�v���C���[���W
	float m_moveSpeed;    //�ړ����x
	int count;            //�J�E���g
	bool m_isUse;         //�g�p���t���O


	//�e�N���X
	class Bullet {
	public:
		int m_bullet_handle;             //�e�̉摜�n���h��
		float m_bullet_x, m_bullet_y;    //�e�̍��W
		float m_bulletSpeed;             //�e�̈ړ����x
		bool m_isUse2;                   //�g�p���t���O

	};
	


	
	Player();
	~Player();

	void InitPlayer();		  //�v���C������

	void StepPlayer();		  //�v���C�ʏ폈��

	void DrawPlayer();		  //�v���C�`�揈��

	void FinPlayer();		  //�v���C�I������

	void MovePlayer();        //�v���C���[�̈ړ�����

	void BulletTrigerCount(); //�e�̔��ˊԊu�̒����֐�

	void BulletShot();        //�e�̔��ˏ���

	void BulletMove();        //�e�̈ړ�����

	void BulletDraw();        //�e�̕`��֐�
};


extern Player player;
extern Player::Bullet bullet[BULLET_MAX_NUM];

