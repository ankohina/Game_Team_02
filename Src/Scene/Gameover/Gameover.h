#pragma once

class SceneGameOver {
private:
	//�w�i�摜
	int BackGround_img;
public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();		// �Q�[���I�[�o�[������

	void StepGameOver();		// �Q�[���I�[�o�[�ʏ폈��

	void DrawGameOver();		// �Q�[���I�[�o�[�`�揈��

	void FinGameOver();		    // �Q�[���I�[�o�[�I������
};