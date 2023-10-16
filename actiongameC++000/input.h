//===========================
//
//�_�C���N�gX.input�w�b�_�[
//Author:�����@��
//
//===========================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//�}�N����`---------------------------
#define NUM_KEY_MAX (256)			//�L�[�̍ő吔

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�C���v�b�g�N���X
class CInput
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CInput();				//�f�t�H���g
	virtual ~CInput();

	//�����o�֐�
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit(void);
	virtual void Update(void) = 0;

	virtual bool GetPress(int nKey) = 0;
	virtual bool GetTrigger(int nKey) = 0;
	virtual bool GetRelease(int nKey) = 0;
	virtual bool GetRepeat(int nKey) = 0;
	virtual bool GetAll(void) = 0;

	virtual bool GetButtonPress(int nKey) { return false; }
	virtual bool GetButtonTrigger(int nKey) { return false; }
	virtual bool GetButtonRelease(int nKey) { return false; }
	virtual bool GetButtonRepeat(int nKey) { return false; }
	virtual int GetButtonCrossPress(void) { return 0; }
	virtual int GetLStickLRPress(void) { return 0; }
	virtual int GetLStickUDPress(void) { return 0; }
	virtual int GetRStickLRPress(void) { return 0; }
	virtual int GetRStickUDPress(void) { return 0; }
	
	LPDIRECTINPUTDEVICE8 GetInputDevice(void) { return m_pDevice; }

	//�ÓI�����o�֐�
	static LPDIRECTINPUT8 GetInput(void) { return m_pInput; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

	//�����o�ϐ�
	LPDIRECTINPUTDEVICE8 m_pDevice;			//���̓f�o�C�X�ւ̃|�C���^

	//�ÓI�����o�ϐ�
	

private:			//�O������A�N�Z�X�s�\

	//�����o�ϐ�

	//�ÓI�����o�ϐ�
	static LPDIRECTINPUT8 m_pInput;						//DirectInput�I�u�W�F�N�g�ւ̃|�C���^
};

//�L�[�{�[�h
class CInputKeyboard : public CInput
{
public:				//�O������A�N�Z�X�\

					//�R���X�g���N�^�E�f�X�g���N�^
	CInputKeyboard();				//�f�t�H���g
	~CInputKeyboard();

	//�����o�֐�
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
	bool GetRepeat(int nKey);
	bool GetAll(void);

	//�ÓI�����o�֐�

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�ϐ�
	BYTE m_aKeyState[NUM_KEY_MAX];						//�L�[�{�[�h�̃v���X���
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX];				//�L�[�{�[�h�̃g���K�[���
	BYTE m_aKeyStateRelease[NUM_KEY_MAX];				//�L�[�{�[�h�̃����[�X���
	BYTE m_aKeyStateRepeat[NUM_KEY_MAX];				//�L�[�{�[�h�̃��s�[�g���
	int m_nCountRepeat;

	//�ÓI�����o�ϐ�

};

//�}�E�X
class CInputMouse : public CInput
{
public:				//�O������A�N�Z�X�\

					//�R���X�g���N�^�E�f�X�g���N�^
	CInputMouse();				//�f�t�H���g
	~CInputMouse();

	//�����o�֐�
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey) { return false; }
	bool GetRepeat(int nKey);
	bool GetAll(void);

	int GetRStickLRPress(void);
	int GetRStickUDPress(void);

	//�ÓI�����o�֐�

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�ϐ�
	DIMOUSESTATE2 m_State;							//�S���͏��
	DIMOUSESTATE2 m_StateTrigger;					//�S���͏��
	DIMOUSESTATE2 m_StateRepeat;					//�S���͏��
	int m_nCountRepeat;

	//�ÓI�����o�ϐ�

};

//�p�b�h
class CInputPad : public CInput
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CInputPad();				//�f�t�H���g
	~CInputPad();

	//�����o�֐�
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);

	bool GetButtonPress(int nKey);
	bool GetButtonTrigger(int nKey);
	bool GetButtonRelease(int nKey);
	bool GetButtonRepeat(int nKey);
	int GetButtonCrossPress(void);
	int GetLStickLRPress(void);
	int GetLStickUDPress(void);
	int GetRStickLRPress(void);
	int GetRStickUDPress(void);

	bool GetPress(int nKey) { return false; }
	bool GetTrigger(int nKey) { return false; }
	bool GetRelease(int nKey) { return false; }
	bool GetRepeat(int nKey) { return false; }
	bool GetAll(void);

	//�ÓI�����o�֐�

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�ÓI�����o�֐�

	//�����o�ϐ�
	DIJOYSTATE2 m_PadState;							//�S���͏��
	DIJOYSTATE2 m_PadStateTrigger;					//�S���͏��
	DIJOYSTATE2 m_PadStateRelease;					//�S���͏��
	DIJOYSTATE2 m_PadStateRepeat;					//�S���͏��
	int m_nCountRepeat;

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_INPUT_H_