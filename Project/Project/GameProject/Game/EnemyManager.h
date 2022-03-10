#pragma once
#include <GLLibrary.h>
#include "../Base/Base.h"
#include "../TaskSystem/TaskManager.h"
struct EnemyData {//�\���́i�f�[�^���܂Ƃ߂�j
	CVector3D pos;
	int cnt;

};
class EnemyManager :public Base {//�G�̏o�����Ǘ�����N���X
private:

	int m_cnt;//���Ԍv���p
	int m_idx;//�f�[�^�ʒu�i�O�`���Ԗڂ��j
	int m_size;//�f�[�^�T�C�Y(��������̂����߂�z��̒��g�I�ȁj
public:
	EnemyManager();//type�͒e�̎�ނ���ʂ���(�^�̓x�[�X�Œ�`�������̂ɍ��킹��j

	void Update();

	void Draw();

	bool isEnd();//bool�^��true��false���̓��
};