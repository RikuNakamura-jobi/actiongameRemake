//=====================================
//
// orbit�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _ORBIT_H_
#define _ORBIT_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------
#define MAX_EDGE	(100)	//�ӂ̍ő吔
#define NUM_OFFSET	(2)	//�I�t�Z�b�g�̐�

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class COrbit : public CObject
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	COrbit(int nPriority);
	~COrbit();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	
	static HRESULT Load(void);
	static void Unload(void);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);
	void SetPos(D3DXVECTOR3 pos) { return; }
	D3DXVECTOR3 GetPos(void) { return D3DXVECTOR3(0.0f, 0.0f, 0.0f); }
	void SetMove(D3DXVECTOR3 move) { return; }
	D3DXVECTOR3 GetMove(void) { return D3DXVECTOR3(0.0f, 0.0f, 0.0f); }
	void SetRot(D3DXVECTOR3 rot) { return; }
	D3DXVECTOR3 GetRot(void) { return D3DXVECTOR3(0.0f, 0.0f, 0.0f); }

	void SetEdge(int nNumEdge) { m_nNumEdge = nNumEdge; }
	void SetCol(D3DXCOLOR col) { m_col = col; }
	void SetposOffset(D3DXVECTOR3 posOffset, int nOffset) { m_posOffset[nOffset] = posOffset; }
	void SetPosPoint(D3DXVECTOR3 posPoint, int nNumEdge, int nOffset) { m_aPosPoint[nNumEdge][nOffset] = posPoint; }
	void SetmtxWorldOffset(D3DXMATRIX mtxWorldOffset, int nOffset) { m_mtxWorldOffset[nOffset] = mtxWorldOffset; }
	void SetMtx(D3DXMATRIX mtx) { m_mtxWorld = mtx; }

	//�ݒ菈��
	void SetPositionOffset(D3DXMATRIX mtxWorld);

	//�ÓI�����o�֐�
	static COrbit *Create(D3DXMATRIX mtxWorld, D3DXVECTOR3 posOffset1, D3DXVECTOR3 posOffset2, D3DXCOLOR col, int nNumEdge);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�
	void UpdatePolygon(void);

	//�����o�ϐ�
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;					//���_�����i�[
	static LPDIRECT3DTEXTURE9 m_pTexture;						//�e�N�X�`���ւ̃|�C���^
	D3DXMATRIX m_mtxWorld;								//�}�g���b�N�X
	D3DXVECTOR3 m_posOffset[NUM_OFFSET];				//�I�t�Z�b�g�ʒu
	D3DXVECTOR3 m_aPosPoint[MAX_EDGE][NUM_OFFSET];		//���_���W�ۑ��p
	D3DXCOLOR m_col;									//�F
	D3DXCOLOR m_aColPoint[MAX_EDGE][NUM_OFFSET];		//���_�J���[�ۑ��p
	D3DXMATRIX m_mtxWorldOffset[NUM_OFFSET];			//�I�t�Z�b�g�̃}�g���b�N�X
	int m_nNumEdge;										//�ӂ̐�

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_ORBIT_H_