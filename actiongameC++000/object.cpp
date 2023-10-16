//=====================================
//
// 
// Author:������
//
//=====================================
#include "object.h"
#include "debugproc.h"
#include "manager.h"
#include "renderer.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
CObject *CObject::m_apTop[ALL_PRIORITY] = {};
CObject *CObject::m_apCur[ALL_PRIORITY] = {};
int CObject::m_nNumAll = 0;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CObject::CObject()
{
	if (m_apTop[3] == NULL)
	{
		m_apTop[3] = this;
	}

	if (m_apCur[3] == NULL)
	{
		m_apCur[3] = this;
		m_pPrev = NULL;
	}
	else
	{
		m_pPrev = m_apCur[3];
		m_apCur[3]->m_pNext = this;
		m_apCur[3] = this;
	}

	m_pNext = NULL;
	m_nID = m_nNumAll;
	m_nPriority = 3;
	m_bDeath = false;
	m_nNumAll++;
}

CObject::CObject(int nPriority = 3)
{
	if (m_apTop[nPriority] == NULL)
	{
		m_apTop[nPriority] = this;
	}

	if (m_apCur[nPriority] == NULL)
	{
		m_apCur[nPriority] = this;
		m_pPrev = NULL;
	}
	else
	{
		m_pPrev = m_apCur[nPriority];
		m_apCur[nPriority]->m_pNext = this;
		m_apCur[nPriority] = this;
	}

	m_pNext = NULL;
	m_nID = m_nNumAll;
	m_nPriority = nPriority;
	m_bDeath = false;
	m_nNumAll++;
}

CObject::~CObject()
{
}

//=====================================
// �S�ẴI�u�W�F�N�g�̔j��
//=====================================
void CObject::ReleaseAll(void)
{
	CObject *pObj;

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->m_pNext;
			pObj->Uninit();
			pObj = pObjNext;
		}
	}

	UpdateAll();
}

//=====================================
// �I�u�W�F�N�g�̃^�C�v�w��j��
//=====================================
void CObject::ReleaseTYPE(TYPE type)
{
	CObject *pObj;

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->m_pNext;

			if (pObj->m_type == type)
			{
				pObj->Uninit();
			}

			pObj = pObjNext;
		}
	}

	UpdateAll();
}

//=====================================
// �I�u�W�F�N�g�̃^�C�v�w��j��
//=====================================
void CObject::ReleaseTYPEN(TYPE type)
{
	CObject *pObj;

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->m_pNext;

			if (pObj->m_type != type)
			{
				pObj->Uninit();
			}

			pObj = pObjNext;
		}
	}

	UpdateAll();
}

//=====================================
// �S�ẴI�u�W�F�N�g�̍X�V
//=====================================
void CObject::UpdateAll(void)
{
	CObject *pObj;
	int nEffect = 0;

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->m_pNext;

			if (pObj->m_bDeath != true)
			{
				pObj->Update();
			}

			pObj = pObjNext;
		}
	}

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->m_pNext;

			if (pObj->m_bDeath == true)
			{
				if (pObj->m_pPrev == NULL)
				{
					m_apTop[nCntPriority] = pObj->m_pNext;
				}
				else
				{
					pObj->m_pPrev->m_pNext = pObj->m_pNext;
				}

				if (pObj->m_pNext == NULL)
				{
					m_apCur[nCntPriority] = pObj->m_pPrev;
				}
				else
				{
					pObj->m_pNext->m_pPrev = pObj->m_pPrev;
				}

				delete pObj;
			}

			pObj = pObjNext;
		}
	}
}

//=====================================
// �S�ẴI�u�W�F�N�g�̕`��
//=====================================
void CObject::DrawAll(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();
	CObject *pObj;

	for (int nCntPriority = 0; nCntPriority < ALL_PRIORITY; nCntPriority++)
	{
		pObj = m_apTop[nCntPriority];

		while (pObj != NULL)
		{
			if (pObj->m_type == TYPE_SKY)
			{
				//�e����
				pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
			}

			CObject *pObjNext = pObj->m_pNext;
			pObj->Draw();

			if (pObj->m_type == TYPE_SKY)
			{
				//�e����
				pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
			}

			pObj = pObjNext;
		}
	}
}

//=====================================
// �I�u�W�F�N�g�̔j��
//=====================================
void CObject::Release(void)
{
	int nIdx = m_nID;
	int nPriority = m_nPriority;

	m_bDeath = true;
}