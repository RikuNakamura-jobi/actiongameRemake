//=====================================
//
// effect�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "main.h"
#include "objectbillboard.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CEffect : public CObjectBillboard
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CEffect(int nPriority);				//�f�t�H���g
	~CEffect();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ÓI�����o�֐�
	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, float fWidth, float fHeight);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	int m_nCounterAnim;											//�A�j���[�V�����J�E���^�[
	int m_nPatternAnim;											//�A�j���[�V�����p�^�[��No.
	int m_nLife;
	int m_nLifeMax;

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���ւ̃|�C���^
};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_EFFECT_H_