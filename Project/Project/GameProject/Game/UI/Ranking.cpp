
#include "Ranking.h"
Ranking* Ranking::mp_instance = nullptr;
Ranking::Ranking()
{
}

void Ranking::WriteScore()
{
	FILE* fp;//値を引き継がないので関数毎に作る

	//「ranking.txt」のファイルを書き込みモード（"w"）で開く
	fopen_s(&fp, "ranking.txt", "w");


	//「ranking.txt」のファイルに書き込む
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
	//「eanking.txt」のファイルをよみ込みモード（"ｒ"）で開く
	fopen_s(&fp, "ranking.txt", "r");


	if (fp == NULL)
		return;//voidなので戻り値なし
	while (fscanf_s(fp, "%d\n", &score)!=EOF)//EOF＝最後
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
	m_ranking.push_back(score);//追加
	std::sort(m_ranking.begin(), m_ranking.end(), std::greater<int>());//sortで小さい順に並べ替え、greaterで降順
	if (m_ranking.size() >= 6/*個数調べる*/) {
		m_ranking.pop_back();//削除
	}

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
