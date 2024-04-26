#pragma once
#include "../../Enemy/Enemy.h"
#include "../../Player/Player.h"

#define LIFE_MAX_NUM		(5)

#define LIFE_PATH		"data/Playimage/life.png"

class ScenePlay {
private:
	Enemy enemy;
	
	int m_background;     //�w�i
	//�摜�p�ϐ�
	
	//�N���A���I�[�o�[����ʑJ�ڎ��Ɋm�F����t���O
	bool isClear = false;

	int LifeHndl[LIFE_MAX_NUM];
	
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		//�v���C������

	void StepPlay();		//�v���C�ʏ폈��

	void DrawPlay();		//�v���C�`�揈��

	void FinPlay();			//�v���C�I������
};
