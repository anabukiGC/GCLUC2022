
#include "Ranking.h"
Ranking* Ranking::mp_instance = nullptr;
Ranking::Ranking()
{
}

void Ranking::WriteScore()
{
	FILE* fp;//�l�������p���Ȃ��̂Ŋ֐����ɍ��

	//�ufprintfExample.txt�v�̃t�@�C�����������݃��[�h�i"w"�j�ŊJ��
	fopen_s(&fp, "ranking.txt", "w");

	//�ufprintfExample.txt�v�Ɂua��100�ł��v�Ə�������

	for (auto& v : m_ranking) {
		fprintf(fp, "%d\n", v);

	}
	//�ufprintfExample.txt�v�̃t�@�C�������
	fclose(fp);
}

void Ranking::ReadScore()
{
	m_ranking.clear();//������Ă�ł����v�Ȃ悤��
	FILE* fp;//�l�������p���Ȃ��̂Ŋ֐����ɍ��
	int score;
	//�ufprintfExample.txt�v�̃t�@�C������ݍ��݃��[�h�i"��"�j�ŊJ��
	fopen_s(&fp, "ranking.txt", "r");



	while (fscanf_s(fp, "%d\n", &score)!=EOF)
	{
		m_ranking.push_back(score);
	} 
	//�ufprintfExample.txt�v�̃t�@�C�������
	fclose(fp);
}

std::vector<int> Ranking::GetScore()
{
	return m_ranking;
}

void Ranking::Add(int score)
{
	m_ranking.push_back(score);
	std::sort(m_ranking.begin(), m_ranking.end(), std::greater<int>());//sort�ŏ��������ɕ��בւ��Agreater�ō~��
}

Ranking* Ranking::GetInstance()//�V���O���g��
{
	if (!mp_instance) mp_instance = new Ranking();//���̂݊i�[�����
	return mp_instance;
	
}

void Ranking::ClearInstance()//�Q�[���I�����ȂǂɌĂ�
{
	if (!mp_instance) return;
	delete mp_instance;
	mp_instance = nullptr;
}
