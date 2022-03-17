#pragma once
#include <GLLibrary.h>
#include "Base.h"
#include "TaskManager.h"
struct EnemyData {//�\���́i�f�[�^���܂Ƃ߂�j
	CVector3D pos;
	int cnt;
	enum {
		eEnemy1,
		eEnemy2,
		eBoss
	};
	int type;//��ޕ���

};

struct EnemyWave {
	int pos_x;
	EnemyData* data;
	int size;
};
class EnemyManager :public Base {//�G�̏o�����Ǘ�����N���X
private:
	int m_wave_idx;//wave�̐��i��WAVE����̂��j
	int m_wave_size;//�S�̂̃T�C�Y
	int m_cnt;//���Ԍv���p
	int m_idx;//�f�[�^�ʒu�i�O�`���Ԗڂ��j
	int m_size;//�f�[�^�T�C�Y(��������̂����߂�z��̒��g�I�ȁj
	bool m_ivent = false;
public:
	EnemyManager();//type�͒e�̎�ނ���ʂ���(�^�̓x�[�X�Œ�`�������̂ɍ��킹��j

	void Update();

	void Draw();

	bool isEnd();//bool�^��true��false���̓��
	
	bool GetWave();//�G�����邩����
};