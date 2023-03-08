#pragma once
#include"DrawTask.h"

class DrawTaskManager
{
private:
	static DrawTaskManager* ms_instance;
	DrawTask* m_head;

public:
	//�R���X�g���N�^
	DrawTaskManager();
	//�f�X�g���N�^
	~DrawTaskManager();

	//DrawTaskManager�̃C���X�^���X���擾
	static DrawTaskManager* Instance();
	//DrawTaskManager�̃C���X�^���X��j��
	static void ClearInstance();

	//���X�g�Ƀ^�X�N��ǉ�
	void AddDrawTask(DrawTask* Task);
	//���X�g����^�X�N����菜��
	void RemoveDrawTask(DrawTask* Task);
	//�^�X�N���폜����
	void DeleteDrawTask(DrawTask* Task);
	//�`�揈��
	void Draw();

};