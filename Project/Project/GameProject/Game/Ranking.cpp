
#include "Ranking.h"
Ranking* Ranking::mp_instance = nullptr;
Ranking::Ranking()
{
}

void Ranking::WriteScore()
{
	FILE* fp;//値を引き継がないので関数毎に作る

	//「fprintfExample.txt」のファイルを書き込みモード（"w"）で開く
	fopen_s(&fp, "ranking.txt", "w");

	//「fprintfExample.txt」に「aは100です」と書き込む

	for (auto& v : m_ranking) {
		fprintf(fp, "%d\n", v);

	}
	//「fprintfExample.txt」のファイルを閉じる
	fclose(fp);
}

void Ranking::ReadScore()
{
	m_ranking.clear();//何回も呼んでも大丈夫なように
	FILE* fp;//値を引き継がないので関数毎に作る
	int score;
	//「fprintfExample.txt」のファイルをよみ込みモード（"ｒ"）で開く
	fopen_s(&fp, "ranking.txt", "r");



	while (fscanf_s(fp, "%d\n", &score)!=EOF)
	{
		m_ranking.push_back(score);
	} 
	//「fprintfExample.txt」のファイルを閉じる
	fclose(fp);
}

std::vector<int> Ranking::GetScore()
{
	return m_ranking;
}

void Ranking::Add(int score)
{
	m_ranking.push_back(score);
	std::sort(m_ranking.begin(), m_ranking.end(), std::greater<int>());//sortで小さい順に並べ替え、greaterで降順
}

Ranking* Ranking::GetInstance()//シングルトン
{
	if (!mp_instance) mp_instance = new Ranking();//一回のみ格納される
	return mp_instance;
	
}

void Ranking::ClearInstance()//ゲーム終了時などに呼ぶ
{
	if (!mp_instance) return;
	delete mp_instance;
	mp_instance = nullptr;
}
