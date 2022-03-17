
#include "Ranking.h"
Ranking* Ranking::mp_instance = nullptr;
Ranking::Ranking()
{
}

void Ranking::WriteScore()
{
	FILE* fp;//�l�������p���Ȃ��̂Ŋ֐����ɍ��

	//�uranking.txt�v�̃t�@�C�����������݃��[�h�i"w"�j�ŊJ��
	fopen_s(&fp, "ranking.txt", "w");


	//�uranking.txt�v�̃t�@�C���ɏ�������
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
	//�ueanking.txt�v�̃t�@�C������ݍ��݃��[�h�i"��"�j�ŊJ��
	fopen_s(&fp, "ranking.txt", "r");


	if (fp == NULL)
		return;//void�Ȃ̂Ŗ߂�l�Ȃ�
	while (fscanf_s(fp, "%d\n", &score)!=EOF)//EOF���Ō�
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
	m_ranking.push_back(score);//�ǉ�
	std::sort(m_ranking.begin(), m_ranking.end(), std::greater<int>());//sort�ŏ��������ɕ��בւ��Agreater�ō~��
	if (m_ranking.size() >= 6/*�����ׂ�*/) {
		m_ranking.pop_back();//�폜
	}

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
