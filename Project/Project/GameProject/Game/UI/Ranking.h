#pragma once
#include<vector>
#include<algorithm>

class Ranking{
public:
	Ranking();//�Ώۂ̓G��n����p

	void WriteScore();//�ۑ�
	void ReadScore();//�ǂݍ���
	std::vector<int> GetScore();//���o����������̂Ńx�N�^�[
	void Add(int score);
	static Ranking* GetInstance();			//�C���X�^���X�����擾
	static void ClearInstance();				//�i�[����Ă�����̂��폜

private:
	std::vector <int> m_ranking;//<�^�w��>

	static Ranking* mp_instance;			//���g�|�C���^

	
};