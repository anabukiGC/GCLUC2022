#pragma once
#include <GLLibrary.h>
#include <list>
#include "../TaskSystem/Task.h"

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
class Base : public Task{
public:
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
	//スクロール値
	static CVector2D m_scroll;
public:
	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">オブジェクトの種類</param>
	/// <returns></returns>
	Base(int id, int priority);
	
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
	/// 円同士の判定
	/// </summary>
	/// <param name="b1">判定オブジェクト１</param>
	/// <param name="b2">判定オブジェクト２</param>
	/// <returns>true:接触</returns>
	static bool CollisionCircle(Base* b1, Base* b2);
	
	/// <summary>
	/// オブジェクトの検索
	/// </summary>
	/// <param name="type">検索するオブジェクトの種類</param>
	/// <returns>見つけたオブジェクトのリスト</returns>
	static std::list<Base*> FindObjects(BaseType type);
};