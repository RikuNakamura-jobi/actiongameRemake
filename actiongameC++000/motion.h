//=====================================
//
// model�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _MOTION_H_
#define _MOTION_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------
#define MAX_KEY (64)
#define MAX_MOTION (64)

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CModel;
class CMotion
{
public:				//�O������A�N�Z�X�\

	//�v���C���[�̍\����
	typedef struct
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
	}Key;

	//�v���C���[�̍\����
	typedef struct
	{
		Key aKey[MAX_KEY];
		int nFrame;
	}KeyInfo;

	typedef struct
	{
		KeyInfo aKeyInfo[MAX_KEY];
		int nLoop;
		int nNumKey;
	}Info;

	//�R���X�g���N�^�E�f�X�g���N�^
	CMotion();
	~CMotion();

	//�����o�֐�
	HRESULT Init(void);
	void Update(void);

	void Set(int nType);
	void SetInfo(Info Info);
	void SetModel(CModel **ppModel, int nNumModel);

	int GetType(void) { return m_nType; }
	bool IsFinish(void) { return m_bFinish; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	Info m_aInfo[MAX_MOTION];
	int m_nNumInfo;

	int m_nType;
	bool m_bLoop;
	int m_nNumKey;
	int m_nKey;
	int m_nNumCounter;
	bool m_bFinish;

	CModel **m_ppModel;
	int m_nNumModel;
	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_MOTION_H_