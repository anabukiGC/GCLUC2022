#pragma once
#include <GLLibrary.h>
#include <list>

class Map;

//種類の列挙
enum  BaseType{
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Effect,
	eType_UI,
};
#define GRAVITY (9.8f/60)
#define GROUND (500)
class Base {
public:
	//オブジェクトの種類
	BaseType m_type;
	//画像オブジェクト
	CImage m_img;
	//座標データ
	CVector3D m_pos;
	//移動ベクトル
	CVector3D m_vec;
	//ジャンプフラグ
	bool m_jump;
	//反転フラグ
	bool m_flip;
	//半径
	float m_rad;
	//矩形
	CRect	m_rect;
	//削除フラグ
	bool m_kill;
	//スクロール値
	static CVector2D m_scroll;
	//コンテナ
	static std::list<Base*> m_list;
public:
	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">オブジェクトの種類</param>
	/// <returns></returns>
	Base(BaseType type);
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	/// <returns></returns>
	virtual ~Base();


	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update();


	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();
	
	virtual void Draw3D();
	
	/// <summary>
	/// 当たり判定検証
	/// </summary>
	/// <param name="b">判定対象オブジェクト</param>
	virtual void Collision(Base* b);
	
	/// <summary>
	/// 全てのオブジェクトの更新
	/// </summary>
	static void UpdateAll();

	/// <summary>
	/// 全てのオブジェクトの描画
	/// </summary>
	static void DrawAll();

	/// <summary>
	/// 全てのオブジェクトの衝突チェック
	/// </summary>
	static void CollisionAll();
	
	/// <summary>
	/// 全てのオブジェクトの削除チェック
	/// </summary>
	static void CheckKillAll();
	
	/// <summary>
	/// 円同士の判定
	/// </summary>
	/// <param name="b1">判定オブジェクト１</param>
	/// <param name="b2">判定オブジェクト２</param>
	/// <returns>true:接触</returns>
	static bool CollisionCircle(Base* b1, Base* b2);
	/// <summary>
	/// オブジェクトの追加
	/// </summary>
	/// <param name="b">追加するオブジェクト</param>
	static void Add(Base* b);

	/// <summary>
	/// オブジェクトの検索
	/// </summary>
	/// <param name="type">検索するオブジェクトの種類</param>
	/// <returns>一番初めに見つけたオブジェクトへのポインタ</returns>
	static Base* FindObject(BaseType type);
	
	/// <summary>
	/// オブジェクトの検索
	/// </summary>
	/// <param name="type">検索するオブジェクトの種類</param>
	/// <returns>見つけたオブジェクトのリスト</returns>
	static std::list<Base*> FindObjects(BaseType type);


};