#pragma once
#include"Task.h"

class TaskManager 
{
private:
	static TaskManager* ms_instance;	//TaskManager�̃C���X�^���X
	Task* m_head;

public:
	//�R���X�g���N�^
	TaskManager();
	//�f�X�g���N�^
	~TaskManager();

	//TaskManager�̃C���X�^���X���擾
	static TaskManager* Instance();
	//TaskManager�̃C���X�^���X��j��
	static void ClearInstance();

	//���X�g�Ƀ^�X�N��ǉ�
	void AddTask(Task* task);
	//���X�g����^�X�N����菜��
	void RemoveTask(Task* task);
	//���폜�͂��Ȃ�
	//�X�V����
	void Update();


};