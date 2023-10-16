//=====================================
//
// bg�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _BG_H_
#define _BG_H_

#include "main.h"
#include "object2D.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CBg : public CObject2D
{
public:				//�O������A�N�Z�X�\

	typedef enum
	{
		TEXTURE_RESULT = 0,		//�Ȃɂ����ĂȂ����
		TEXTURE_TUTORIAL_KEY_MOVE,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_KEY_SHOT,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_KEY_SAVE,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_PAD_MOVE,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_PAD_SHOT,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_PAD_SAVE,		//�t�F�[�h�C�����
		TEXTURE_TUTORIAL_GAME,			//�t�F�[�h�C�����
		TEXTURE_SUCCESS,				//�t�F�[�h�C�����
		TEXTURE_FAILED,					//�t�F�[�h�C�����
		TEXTURE_START,					//�t�F�[�h�C�����
		TEXTURE_MAX
	}TEXTURE;

	//�R���X�g���N�^�E�f�X�g���N�^
	CBg(int nPriority);				//�f�t�H���g
	~CBg();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	TEXTURE GetTextureType(void) { return m_textureType; }

	//�ÓI�����o�֐�
	static CBg *Create(TEXTURE texture);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	TEXTURE m_textureType;

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture[TEXTURE_MAX];		//�e�N�X�`���ւ̃|�C���^
	static const char *m_apFilename[TEXTURE_MAX];			//�e�N�X�`���̖��O

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_BG_H_