//=====================================
//
// tutorial�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "main.h"
#include "objectbillboard.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CTutorialBillboard : public CObjectBillboard
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CTutorialBillboard(int nPriority);				//�f�t�H���g
	~CTutorialBillboard();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ÓI�����o�֐�
	static CTutorialBillboard *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, float fWidth, float fHeight);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture[5];		//�e�N�X�`���ւ̃|�C���^
	static const char *m_apFilename[5];				//�e�N�X�`���̖��O

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_LOCKON_H_