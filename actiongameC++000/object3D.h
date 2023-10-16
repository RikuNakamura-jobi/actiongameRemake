//=====================================
//
// object�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _OBJECT3D_H_
#define _OBJECT3D_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CObject3D : public CObject
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CObject3D(int nPriority);
	virtual ~CObject3D();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { m_pTexturePolygon = pTexture; }

	//�܂Ƃ߂Đݒ�
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	void SetPosSize(D3DXVECTOR3 pos, D3DXVECTOR3 size);
	void SetPosSizeX(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	//�ʒu
	void SetPos(D3DXVECTOR3 pos){ m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	//�O�̈ʒu
	void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }

	//�ړ���
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }

	//�p�x
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	//�傫��
	void SetSize(D3DXVECTOR3 size) { m_size = size; }
	D3DXVECTOR3 GetSize(void) { return m_size; }

	//�F
	void SetCol(D3DXCOLOR col) { m_col = col; }
	D3DXCOLOR GetCol(void) { return m_col; }

	//�e�N�X�`�����W
	D3DXVECTOR2 *GetTexPos(void) { return &m_texPos[0]; }

	//��
	void SetWidth(float fWidth) { m_fWidth = fWidth; }
	float GetWidth(void) { return m_fWidth; }

	//����
	void SetHeight(float fHeight) { m_fHeight = fHeight; }
	float GetHeight(void) { return m_fHeight; }

	//����
	float GetColHeight(D3DXVECTOR3 pos, D3DXVECTOR3 posOld, D3DXVECTOR3 *move);

	LPDIRECT3DVERTEXBUFFER9 *GetBuff(void) { return &m_pVtxBuff; }
	void SetBuff(LPDIRECT3DVERTEXBUFFER9 pVtxBuff) { m_pVtxBuff =  pVtxBuff; }

	LPDIRECT3DTEXTURE9 *GetTex(void) { return &m_pTexturePolygon; }
	void SetTex(LPDIRECT3DTEXTURE9 pTexture) { m_pTexturePolygon = pTexture; }

	//�ÓI�����o�֐�
	static CObject3D *Create(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;					//���_�����i�[
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;				//�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_size;
	D3DXCOLOR m_col;
	D3DXVECTOR2 m_texPos[4];
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X

	float m_fWidth;
	float m_fHeight;
	float m_fLength;
	float m_fAngle;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_OBJECT3D_H_