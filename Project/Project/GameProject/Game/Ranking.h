#pragma once
#include<vector>
#include<algorithm>

class Ranking{
public:
	Ranking();//対象の敵を渡せる用

	void WriteScore();//保存
	void ReadScore();//読み込み
	std::vector<int> GetScore();//取り出し複数あるのでベクター
	void Add(int score);
	static Ranking* GetInstance();			//インスタンス生成取得
	static void ClearInstance();				//格納されているものを削除

private:
	std::vector <int> m_ranking;//<型指定>

	static Ranking* mp_instance;			//自身ポインタ

	
};