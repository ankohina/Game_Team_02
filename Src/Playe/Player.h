#pragma once


//�v���C���[�N���X
class Player
{
public:
	int m_handle;		//�v���C���[�摜�n���h��
	int m_x, m_y;		//���W
	int moveSpeed;      //�ړ����x
	bool isUse;         //�g�p���t���O
	
	Player();
	~Player();

	void InitPlayer();		//�v���C������

	void StepPlayer();		//�v���C�ʏ폈��

	void DrawPlayer();		//�v���C�`�揈��

	void FinPlayer();		//�v���C�I������


};