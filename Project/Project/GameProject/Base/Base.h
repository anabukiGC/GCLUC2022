#pragma once
#include <GLLibrary.h>
#include <list>
#include "../TaskSystem/Task.h"

class Map;

#define GRAVITY (9.8f/60)
#define GROUND (500)//地面の調整

class RectBox
{
public:
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;
	float m_near;
	float m_far;
	RectBox():m_left(0), m_top(0), m_right(0), m_bottom(0),m_near(0),m_far(0)
	{

	}

	/**
	* @fn
	* コンストラクタ（矩形設定）
	* @brief 矩形を設定する
	* @param l	[in]　左
	* @param t	[in]　上
	* @param r	[in]　右
	* @param b	[in]　下
	*/
	RectBox(float l, float t, float r, float b, float n, float f)
		: m_left(l), m_top(t), m_right(r), m_bottom(b), m_near(n), m_far(f)
	{

	}
};

class Base : public Task{
public:
	//種類分け
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

	int kind = 0;//種類識別用
	//矩形
	RectBox	m_rect;
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

	static  CVector2D Get2DPos(CVector3D pos);
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
	/// 矩形同士の判定
	/// </summary>
	/// <param name="b1">判定オブジェクト１</param>
	/// <param name="b2">判定オブジェクト２</param>
	/// <returns>true:接触</returns>
	static bool CollisionRect(Base* b1, Base* b2);

	/// <summary>
	/// オブジェクトの検索
	/// </summary>
	/// <param name="type">検索するオブジェクトの種類</param>
	/// <returns>見つけたオブジェクトのリスト</returns>
	static std::list<Base*> FindObjects(BaseType type);
};