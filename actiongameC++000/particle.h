//=====================================
//
// particle�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "main.h"
#include "objectbillboard.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CParticle : public CObjectBillboard
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CParticle(int nPriority);				//�f�t�H���g
	~CParticle();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ÓI�����o�֐�
	static CParticle *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, int nLifePtcl, int nNumEffect, int nSpeed, float fWidth, float fHeight);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	int m_nNumEffect;
	int m_nLife;
	int m_nLifePtcl;
	int m_nSpeed;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_PARTICLE_H_