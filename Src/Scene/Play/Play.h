#pragma once
#include "../../Enemy/Enemy.h"

class ScenePlay {
private:
	Enemy enemy;
	//�摜�p�ϐ�
	
	//�N���A���I�[�o�[����ʑJ�ڎ��Ɋm�F����t���O
	bool isClear = false;

	
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		//�v���C������

	void StepPlay();		//�v���C�ʏ폈��

	void DrawPlay();		//�v���C�`�揈��

	void FinPlay();			//�v���C�I������
};
