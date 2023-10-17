//=============================================================================
//
// 
// Author :中村陸
//
//=============================================================================
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "main.h"

//マクロ定義---------------------------

//列挙型定義---------------------------
class CCollider;
class CCollision
{
public:

	CCollision();
	~CCollision();

	//メンバ関数
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	//静的メンバ関数
	static CCollision *Get(void);
	static HRESULT Release(void);

private:

	//メンバ関数

	//メンバ変数
	CCollider *m_pTop;
	CCollider *m_pCur;

	int m_nNumAll;						//オブジェクト総数

	//静的メンバ変数
	static CCollision *m_pCollision;

};

class CCollider
{
public:

	typedef enum
	{
		TYPE_NONE = 0,			//タイプ無し
		TYPE_POINT,			//プレイヤー
		TYPE_BOX,			//プレイヤー
		TYPE_MAX
	}TYPE;

	CCollider();
	~CCollider();

	//メンバ関数
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	//静的メンバ関数
	static CCollider *Create(void);

private:

	//メンバ関数

	//メンバ変数
	int m_nID;									//自分自身のID
	int m_nPriority;							//自分自身のID
	TYPE m_type;

	CCollider *m_pPrev;
	CCollider *m_pNext;

	bool m_bDeath;

	//静的メンバ変数

};

//構造体定義---------------------------

//プロトタイプ宣言---------------------

#endif // !_COLLISION_H_
