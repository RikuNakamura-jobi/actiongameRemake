//=============================================================================
//
// 
// Author :中村陸
//
//=============================================================================
#include "collision.h"
#include "manager.h"
#include "renderer.h"

//マクロ定義---------------------------

//列挙型定義---------------------------

//クラス定義---------------------------

//構造体定義---------------------------

//プロトタイプ宣言---------------------

//静的メンバ変数宣言-------------------
CCollision *CCollision::m_pCollision = NULL;

//=====================================
// コンストラクタ・デストラクタ
//=====================================
CCollision::CCollision()
{
	m_pTop = NULL;
	m_pCur = NULL;
	m_nNumAll = 0;
}

CCollision::~CCollision()
{
}

CCollision *CCollision::Get(void)
{
	if (m_pCollision == NULL)
	{
		return m_pCollision = new CCollision;
	}
	else
	{
		return m_pCollision;
	}
}

HRESULT CCollision::Release(void)
{
	if (m_pCollision != NULL)
	{
		m_pCollision->Uninit();

		delete m_pCollision;
		m_pCollision = NULL;
	}

	return S_OK;
}

//=====================================
// ポリゴンの初期化処理
//=====================================
HRESULT CCollision::Init(void)
{
	return S_OK;
}

//=====================================
// ポリゴンの終了処理
//=====================================
void CCollision::Uninit(void)
{

}

//=====================================
// ポリゴンの更新処理
//=====================================
void CCollision::Update(void)
{

}


//=====================================
// コンストラクタ・デストラクタ
//=====================================
CCollider::CCollider()
{

}

CCollider::~CCollider()
{
}

CCollider *CCollider::Create(void)
{
	return NULL;
}

//=====================================
// ポリゴンの初期化処理
//=====================================
HRESULT CCollider::Init(void)
{
	return S_OK;
}

//=====================================
// ポリゴンの終了処理
//=====================================
void CCollider::Uninit(void)
{

}

//=====================================
// ポリゴンの更新処理
//=====================================
void CCollider::Update(void)
{

}