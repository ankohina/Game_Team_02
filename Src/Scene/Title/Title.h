#pragma once

//�^�C�g���N���X
class SceneTitle {
private:
	//�摜�p�ϐ�
	int BackGround_img;
	int canon_img;
	int text_img;
	int bomb_img;

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// �^�C�g��������

	void StepTitle();		// �^�C�g���ʏ폈��

	void DrawTitle();		// �^�C�g���`�揈��

	void FinTitle();		// �^�C�g���I������
};