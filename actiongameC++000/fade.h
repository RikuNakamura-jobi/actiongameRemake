//=====================================
//
// bg�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _FADE_H_
#define _FADE_H_

#include "main.h"
#include "object2D.h"
#include "scene.h"

//�}�N����`---------------------------
#define SLIDE_SPEED (0.017f)

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CFade : public CObject2D
{
public:				//�O������A�N�Z�X�\

	//�t�F�[�h�̏��
	typedef enum
	{
		STATE_NONE = 0,			//�Ȃɂ����ĂȂ����
		STATE_IN,				//�t�F�[�h�C�����
		STATE_OUT,				//�t�F�[�h�A�E�g���
		STATE_MAX
	}STATE;

	//���
	typedef enum
	{
		TYPE_NONE = 0,			//�^�C�v����
		TYPE_SLIDE,				//�X���C�h
		TYPE_CURTAIN,			//�J�[�e��
		TYPE_CURTAIN_L,			//�J�[�e��
		TYPE_CURTAIN_R,			//�J�[�e��
		TYPE_OUT,				//�G
		TYPE_MAX
	}TYPE;

	//�R���X�g���N�^�E�f�X�g���N�^
	CFade(int nPriority);				//�f�t�H���g
	~CFade();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//�ÓI�����o�֐�
	static CFade *Create(TYPE type, CScene::MODE mode);
	static HRESULT Load(void);
	static void Unload(void);
	static int GetState(void) { return m_state; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	TYPE m_type;
	int m_timer;
	CScene::MODE m_modeNext;

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture[TYPE_MAX];		//�e�N�X�`���ւ̃|�C���^
	static STATE m_state;
	static const char *CFade::m_apFilename[TYPE_MAX];
};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_BG_H_