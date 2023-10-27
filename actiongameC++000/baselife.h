//=====================================
//
// baselife�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _BASELIFE_H_
#define _BASELIFE_H_

#include "main.h"
#include "object2D.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CBaselife : public CObject2D
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CBaselife(int nPriority);				//�f�t�H���g
	~CBaselife();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetLife(void) { return m_nLife; }
	void SetLife(int nLife) { m_nLife = nLife; }
	void AddLife(int nLife) { m_nLife += nLife; }

	//�ÓI�����o�֐�
	static CBaselife *Create(void);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�
	int m_nLife;

	//�����o�ϐ�

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture;		//�e�N�X�`���ւ̃|�C���^

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_BASELIFE_H_