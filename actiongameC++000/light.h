//=============================================================================
//
// �T�E���h���� [light.h]
// Author :������
//
//=============================================================================
#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "main.h"

//�}�N����`---------------------------
#define NUM_LIGHT (4)

//�񋓌^��`---------------------------

//�T�E���h�N���X
class CLight
{
public:

	CLight();
	~CLight();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	//�ÓI�����o�֐�

private:

	//�����o�֐�

	//�����o�ϐ�
	D3DLIGHT9 m_aLight[NUM_LIGHT];		//���C�g�̏��

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_LIGHT_H_
