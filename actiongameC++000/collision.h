//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "main.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------
class CCollider;
class CCollision
{
public:

	CCollision();
	~CCollision();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	CCollider *GetTop(void) { return m_pTop; }
	void SetTop(CCollider *collider) { m_pTop = collider; }

	CCollider *GetCur(void) { return m_pCur; }
	void SetCur(CCollider *collider) { m_pCur = collider; }

	int GetNumAll(void) { return m_nNumAll; }
	void SetNumAll(int nNumAll) { m_nNumAll = nNumAll; }

	//�ÓI�����o�֐�
	static CCollision *Get(void);
	static HRESULT Release(void);

private:

	//�����o�֐�

	//�����o�ϐ�
	CCollider *m_pTop;
	CCollider *m_pCur;

	int m_nNumAll;						//�I�u�W�F�N�g����

	//�ÓI�����o�ϐ�
	static CCollision *m_pCollision;

};

class CCollider
{
public:

	typedef enum
	{
		TYPE_NONE = 0,			//�^�C�v����
		TYPE_POINT,			//�v���C���[
		TYPE_BOX,			//�v���C���[
		TYPE_MAX
	}TYPE;

	CCollider();
	~CCollider();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	CCollider *GetPrev(void) { return m_pPrev; }
	void SetPrev(CCollider *collider) { m_pPrev = collider; }

	CCollider *GetNext(void) { return m_pNext; }
	void SetNext(CCollider *collider) { m_pNext = collider; }

	bool GetDeath(void) { return m_bDeath; }
	void SetDeath(bool bDeath) { m_bDeath = bDeath; }

	//�ÓI�����o�֐�
	static CCollider *Create(void);

private:

	//�����o�֐�
	bool CollisionSquare(D3DXVECTOR3 *posTarget, D3DXVECTOR3 posTargetOld);			//���̓����蔻��(�����߂�����)
	bool CollisionSquareTrigger(D3DXVECTOR3 posTarget);			//���̓����蔻��(���O����̂�)
	D3DXVECTOR3 PosRelativeMtx(D3DXVECTOR3 posO, D3DXVECTOR3 rot, D3DXVECTOR3 offset);

	//�����o�ϐ�
	D3DXVECTOR3 *m_pos;
	D3DXVECTOR3 *m_rot;
	D3DXVECTOR3 m_offsetMax;
	D3DXVECTOR3 m_offsetMin;

	int m_nID;									//�������g��ID
	int m_nPriority;							//�������g��ID
	TYPE m_type;

	CCollider *m_pPrev;
	CCollider *m_pNext;

	bool m_bDeath;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_COLLISION_H_
