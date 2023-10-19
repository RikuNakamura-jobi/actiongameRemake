//=====================================
//
// object�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "main.h"

//�}�N����`---------------------------
#define MAX_OBJECT (1024)
#define ALL_PRIORITY (8)

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CObject
{
public:				//�O������A�N�Z�X�\

	//���
	typedef enum
	{
		TYPE_NONE = 0,			//�^�C�v����
		TYPE_PLAYER,			//�v���C���[
		TYPE_ENEMY,				//�G
		TYPE_BULLET,			//�e
		TYPE_BG,				//�w�i
		TYPE_BGMULTI,			//���d�w�i
		TYPE_EFFECT,			//�G�t�F�N�g
		TYPE_PARTICLE,			//�p�[�e�B�N��
		TYPE_BLOCK,				//�u���b�N
		TYPE_NUMBER,			//����
		TYPE_SCORE,				//�X�R�A
		TYPE_IETM,
		TYPE_LOCKON,
		TYPE_FADE,
		TYPE_SKY,
		TYPE_MAX
	}TYPE;

	//�R���X�g���N�^�E�f�X�g���N�^
	CObject();				//�f�t�H���g
	CObject(int nPriority);
	virtual ~CObject();

	//�����o�֐�
	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	virtual void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight) = 0;
	virtual void SetPos(D3DXVECTOR3 pos) = 0;
	virtual D3DXVECTOR3 GetPos(void) = 0;
	virtual void SetMove(D3DXVECTOR3 move) = 0;
	virtual D3DXVECTOR3 GetMove(void) = 0;
	virtual void SetRot(D3DXVECTOR3 rot) = 0;
	virtual D3DXVECTOR3 GetRot(void) = 0;
	virtual void SetWidth(float fWidth) { return; }
	virtual float GetWidth(void) { return 0.0f; }
	virtual void SetHeight(float fHeight) { return; }
	virtual float GetHeight(void) { return 0.0f; }
	virtual void Damage(int damage) { return; }
	virtual int GetLife(void) { return 0; }

	int GetID(void) { return m_nID; }
	void SetID(int nID) { m_nID = nID; }

	int GetPriority(void) { return m_nPriority; }
	void SetPriority(int nPriority) { m_nPriority = nPriority; }

	void SetType(TYPE type) { m_type = type; }
	TYPE GetType(void) { return  m_type; }
	
	CObject *GetObjectNext(void) { return m_pNext; }
	void SetObjectNext(CObject *pNext) { m_pNext = pNext; }

	CObject *GetObjectPrev(void) { return m_pPrev; }
	void SetObjectPrev(CObject *pPrev) { m_pPrev = pPrev; }

	//�ÓI�����o�֐�
	static void ReleaseAll(void);
	static void ReleaseTYPE(TYPE type);
	static void ReleaseTYPEN(TYPE type);
	static void UpdateAll(void);
	static void DrawAll(void);

	static CObject *GetObjectTop(int nPriority) { return m_apTop[nPriority]; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)
	void Release(void);

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	int m_nID;									//�������g��ID
	int m_nPriority;							//�������g��ID
	TYPE m_type;

	CObject *m_pPrev;
	CObject *m_pNext;
	bool m_bDeath;

	//�ÓI�����o�ϐ�
	static int m_nNumAll;						//�I�u�W�F�N�g����

	static CObject *m_apTop[ALL_PRIORITY];
	static CObject *m_apCur[ALL_PRIORITY];

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_OBJECT_H_