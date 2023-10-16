//=====================================
//
// model�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _MODEL_H_
#define _MODEL_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CModel
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CModel();
	~CModel();

	//�����o�֐�
	HRESULT Init(char *pFilename);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ʒu
	void SetPos(D3DXVECTOR3 pos){ m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	void SetPosDef(D3DXVECTOR3 posDef) { m_posDef = posDef; }
	D3DXVECTOR3 GetPosDef(void) { return m_posDef; }

	//�p�x
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	void SetRotDef(D3DXVECTOR3 rotDef) { m_rotDef = rotDef; }
	D3DXVECTOR3 GetRotDef(void) { return m_rotDef; }

	//�e
	void SetParent(CModel *pModel) { m_pParent = pModel; }

	D3DXMATRIX GetMtxWorld(void) { return m_mtxWorld; }

	//�ÓI�����o�֐�
	static CModel *Create(char *pFilename);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	LPDIRECT3DTEXTURE9 *m_pTexture;
	LPD3DXMESH m_pMeshModel;
	LPD3DXBUFFER m_pBuffMatModel;					//���_�����i�[
	DWORD m_dwNumMatModel;

	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posDef;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_rotDef;
	D3DXMATRIX m_mtxWorld;				//���[���h�}�g���b�N�X

	CModel *m_pParent;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_MODEL_H_