//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#include "collision.h"
#include "manager.h"
#include "renderer.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
CCollision *CCollision::m_pCollision = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
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
// �|���S���̏���������
//=====================================
HRESULT CCollision::Init(void)
{
	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CCollision::Uninit(void)
{

}

//=====================================
// �|���S���̍X�V����
//=====================================
void CCollision::Update(void)
{

}


//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
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
// �|���S���̏���������
//=====================================
HRESULT CCollider::Init(void)
{
	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CCollider::Uninit(void)
{

}

//=====================================
// �|���S���̍X�V����
//=====================================
void CCollider::Update(void)
{

}