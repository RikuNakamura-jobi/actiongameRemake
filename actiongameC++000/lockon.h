//=====================================
//
// lockon�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _LOCKON_H_
#define _LOCKON_H_

#include "main.h"
#include "objectbillboard.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CLockon : public CObjectBillboard
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CLockon(int nPriority);				//�f�t�H���g
	~CLockon();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetWidthDef(float fWidth) { m_fWidthDef = fWidth; }
	void SetHeightDef(float fHeight) { m_fHeightDef = fHeight; }

	bool GetLock(void) { return m_bLock; }

	//�ÓI�����o�֐�
	static CLockon *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, float fWidth, float fHeight);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�
	void target(void);

	//�����o�ϐ�
	float m_fWidthDef;
	float m_fHeightDef;
	bool m_bLock;

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���ւ̃|�C���^
};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_LOCKON_H_