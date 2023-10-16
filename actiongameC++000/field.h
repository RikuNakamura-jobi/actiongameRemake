//=====================================
//
// bg�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _FIELD_H_
#define _FIELD_H_

#include "main.h"
#include "object3D.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CField : public CObject3D
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CField(int nPriority);				//�f�t�H���g
	~CField();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ÓI�����o�֐�
	static CField *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���ւ̃|�C���^

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_FIELD_H_