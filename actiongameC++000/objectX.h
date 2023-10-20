//=====================================
//
// object�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _OBJECTX_H_
#define _OBJECTX_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CObjectX : public CObject
{
public:				//�O������A�N�Z�X�\

	typedef struct
	{
		LPDIRECT3DTEXTURE9 *pTexture;
		LPD3DXMESH pMeshModel;
		LPD3DXBUFFER pBuffMatModel;					//���_�����i�[
		DWORD dwNumMatModel;
		D3DXVECTOR3 vtxMin;
		D3DXVECTOR3 vtxMax;
	} MODELX;

	//�R���X�g���N�^�E�f�X�g���N�^
	CObjectX(int nPriority);
	virtual ~CObjectX();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	//�܂Ƃ߂Đݒ�
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	void BindModel(MODELX *model) { m_model = model; }

	//�ʒu
	void SetPos(D3DXVECTOR3 pos){ m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	D3DXVECTOR3 *GetPosPointa(void) { return &m_pos; }

	//�O�̈ʒu
	void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }

	//�ړ���
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }

	//�p�x
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	D3DXVECTOR3 *GetRotPointa(void) { return &m_rot; }

	//�p�x
	void SetMtx(D3DXMATRIX mtx) { m_mtxWorld = mtx; }
	D3DXMATRIX GetMtx(void) { return m_mtxWorld; }

	//�ÓI�����o�֐�
	static CObjectX *Create(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X

	MODELX *m_model;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_OBJECTX_H_