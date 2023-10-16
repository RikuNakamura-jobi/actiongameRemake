//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "main.h"

//�}�N����`---------------------------
#define MAX_TEXTURE (256)

//�񋓌^��`---------------------------

//�T�E���h�N���X
class CTexture
{
public:

	CTexture();
	~CTexture();

	//�����o�֐�
	HRESULT Load(void);
	void Unload(void);

	int Regist(const char *pFilename);
	LPDIRECT3DTEXTURE9 GetAddress(int nIdx);

	//�ÓI�����o�֐�

private:

	//�����o�֐�

	//�����o�ϐ�
	LPDIRECT3DTEXTURE9 m_apTexture[MAX_TEXTURE];

	//�ÓI�����o�ϐ�
	static int m_nNumAll;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_TEXTURE_H_
