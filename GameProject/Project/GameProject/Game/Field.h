#pragma once
//Task���p��
class Field : public Task {
private:
	//�摜�I�u�W�F�N�g(�O�i)
	CImage m_foreground;
	//�摜�I�u�W�F�N�g(���i)
	CImage m_town;
	//�摜�I�u�W�F�N�g(�ŉ��i)
	//CImage m_sky;
	//�n�ʂ̍���
	float m_ground_y;
	//�`��^�X�N
	DrawTask* m_drawTask;
public:
	//�R���X�g���N�^
	Field();
	//�j�����ɕ`��^�X�N����菜���������߃f�X�g���N�^���K�v
	~Field();
	//�I�[�o�[���C�h�K�{
	void Update(float deltatime);
	//�`��
	void Draw();

	//�n�ʂ̍������擾
	float GetGroundY() {
		return m_ground_y;
	}
};