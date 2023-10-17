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

	//�ÓI�����o�֐�
	static CCollider *Create(void);

private:

	//�����o�֐�

	//�����o�ϐ�
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
