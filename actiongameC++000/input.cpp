//=====================================
//
//�_�C���N�gX.input�t�@�C��
//Author:�����@��
//
//=====================================
#include "input.h"
#include "dinput.h"
#include "manager.h"
#include "debugproc.h"

//�}�N����`

//�ÓI�����o�ϐ��錾-------------------
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CInput::CInput()
{
	m_pDevice = NULL;
}

CInput::~CInput()
{
}

//=====================================
//�C���v�b�g�̏���������
//=====================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{
		//DirectInput�I�u�W�F�N�g�̐���
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//=====================================
//�f�o�C�X�̏I������
//=====================================
void CInput::Uninit(void)
{
	//�f�o�C�X�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//=====================================
//�L�[�{�[�h
//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CInputKeyboard::CInputKeyboard()
{
	memset(&m_aKeyState[0], 0, NUM_KEY_MAX);
	memset(&m_aKeyStateTrigger[0], 0, NUM_KEY_MAX);
	memset(&m_aKeyStateRelease[0], 0, NUM_KEY_MAX);
	memset(&m_aKeyStateRepeat[0], 0, NUM_KEY_MAX);
	m_nCountRepeat = 0;
}

CInputKeyboard::~CInputKeyboard()
{
}

//=====================================
//����������
//=====================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);
	LPDIRECTINPUT8 pInput = GetInput();						//DirectInput�I�u�W�F�N�g�ւ̃|�C���^

	//���̓f�o�C�X�̐���
	if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//=====================================
//�L�[�{�[�h�̏I������
//=====================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//=====================================
//�L�[�{�[�h�̍X�V����
//=====================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX];				//�L�[�{�[�h�̓��͏��
	int nCntKey;

	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];

			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey];

			m_aKeyState[nCntKey] = aKeyState[nCntKey];				//�L�[�{�[�h�̃v���X�����擾

			m_nCountRepeat++;
			if ((m_nCountRepeat % 10) == 0)
			{
				m_nCountRepeat = (m_nCountRepeat + 1) % 10;
				m_aKeyStateRepeat[nCntKey] = aKeyState[nCntKey];			//�����[�X����ۑ�
			}
			else
			{
				m_aKeyStateRepeat[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey];	//���s�[�g�Ƀ����[�X�̏��ۑ�
			}
		}
	}
	else
	{
		m_pDevice->Acquire();								//�L�[�{�[�h�̃A�N�Z�X�����擾
	}
}

//=====================================
//�v���X���擾����
//=====================================
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//=====================================
//�g���K�[���擾����
//=====================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//=====================================
//�����[�X���擾����
//=====================================
bool CInputKeyboard::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

//=====================================
//���s�[�g���擾����
//=====================================
bool CInputKeyboard::GetRepeat(int nKey)
{
	return (m_aKeyStateRepeat[nKey] & 0x80) ? true : false;
}

//=====================================
//�S���擾����
//=====================================
bool CInputKeyboard::GetAll(void)
{
	for (int nCntKey = 0; nCntKey < 256; nCntKey++)
	{
		if ((m_aKeyState[nCntKey] & 0x80) ? true : false)
		{
			return true;
		}
	}

	return false;
}
//�L�[�{�[�h
//=====================================

//=====================================
//�p�b�h
//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CInputPad::CInputPad()
{
	m_nCountRepeat = 0;
}

CInputPad::~CInputPad()
{
}

//=====================================
//�R�[���o�b�N
//=====================================
BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE *pdidInstance, VOID *pContext)
{
	HRESULT hr;
	LPDIRECTINPUT8 pInput = CInput::GetInput();						//DirectInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8 pDevice = CManager::Get()->GetInputPad()->CInput::GetInputDevice();			//���̓f�o�C�X�ւ̃|�C���^

	hr = pInput->CreateDevice(pdidInstance->guidInstance, &pDevice, NULL);

	if (FAILED(hr)) return DIENUM_CONTINUE;

	return DIENUM_STOP;
}

BOOL CALLBACK EnumAxesCallback(const DIDEVICEOBJECTINSTANCE *pdidoi, VOID *pContext)
{
	HRESULT     hr;
	DIPROPRANGE diprg;
	LPDIRECTINPUTDEVICE8 pDevice = CManager::Get()->GetInputPad()->CInput::GetInputDevice();			//���̓f�o�C�X�ւ̃|�C���^

	diprg.diph.dwSize = sizeof(DIPROPRANGE);
	diprg.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	diprg.diph.dwHow = DIPH_BYID;
	diprg.diph.dwObj = pdidoi->dwType;
	diprg.lMin = 0 - 1000;
	diprg.lMax = 0 + 1000;
	hr = pDevice->SetProperty(DIPROP_RANGE, &diprg.diph);

	if (FAILED(hr)) return DIENUM_STOP;

	return DIENUM_CONTINUE;
}

//=====================================
//����������
//=====================================
HRESULT CInputPad::Init(HINSTANCE hInstance, HWND hWnd)
{
	LPDIRECTINPUT8 pInput = GetInput();						//DirectInput�I�u�W�F�N�g�ւ̃|�C���^

	CInput::Init(hInstance, hWnd);

	if (FAILED(pInput->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback, NULL, DIEDFL_ATTACHEDONLY)))
	{
		return E_FAIL;
	}

	//���̓f�o�C�X�̐���
	if (FAILED(pInput->CreateDevice(GUID_Joystick, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	if (m_pDevice == NULL)
	{
		return S_OK;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIJoystick2)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	if (FAILED(m_pDevice->EnumObjects(EnumAxesCallback,NULL, DIDFT_ALL)))
		
	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//=====================================
//�I������
//=====================================
void CInputPad::Uninit(void)
{
	CInput::Uninit();
}

//=====================================
//�X�V����
//=====================================
void CInputPad::Update(void)
{
	DIJOYSTATE2 PadState = { 0 };				//�p�b�h�̓��͏��

	if (m_pDevice != NULL)
	{
		m_pDevice->Poll();
		if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(PadState), &PadState)))
		{
			for (int nCntPad = 0; nCntPad < 16; nCntPad++)
			{
				m_PadStateTrigger.rgbButtons[nCntPad] = (m_PadState.rgbButtons[nCntPad] ^ PadState.rgbButtons[nCntPad]) & PadState.rgbButtons[nCntPad];

				m_PadStateRelease.rgbButtons[nCntPad] = (m_PadState.rgbButtons[nCntPad] ^ PadState.rgbButtons[nCntPad]) & m_PadState.rgbButtons[nCntPad];

				m_nCountRepeat++;
				if ((m_nCountRepeat % 10) == 0)
				{
					m_nCountRepeat = (m_nCountRepeat + 1) % 10;
					m_PadStateRepeat.rgbButtons[nCntPad] = PadState.rgbButtons[nCntPad];			//�����[�X����ۑ�
				}
				else
				{
					m_PadStateRepeat.rgbButtons[nCntPad] = (m_PadState.rgbButtons[nCntPad] ^ PadState.rgbButtons[nCntPad]) & m_PadState.rgbButtons[nCntPad];	//���s�[�g�Ƀ����[�X�̏��ۑ�
				}
			}

			//���͏��̕ۑ�
			m_PadState = PadState;
		}
		else
		{
			m_pDevice->Acquire();								//�L�[�{�[�h�̃A�N�Z�X�����擾
		}
	}

	int nCheck = 1;
	CManager::Get()->GetDebugProc()->Print("Pad: %d\n", nCheck);

	nCheck = m_PadState.lX;
	CManager::Get()->GetDebugProc()->Print("���X�e�B�b�N��: %d\n", nCheck);

	nCheck = m_PadState.lY;
	CManager::Get()->GetDebugProc()->Print("���X�e�B�b�N�c: %d\n", nCheck);

	nCheck = m_PadState.lZ;
	CManager::Get()->GetDebugProc()->Print("�E�X�e�B�b�N��: %d\n", nCheck);

	nCheck = m_PadState.lRz;
	CManager::Get()->GetDebugProc()->Print("�E�X�e�B�b�N�c: %d\n", nCheck);

	for (int nCnt = 0; nCnt < 12; nCnt++)
	{
		nCheck = (m_PadState.rgbButtons[nCnt] & 0x80) ? 1 : 0;
		CManager::Get()->GetDebugProc()->Print("rgbButtons%d: %d\n", nCnt, nCheck);
	}

	nCheck = m_PadState.rgdwPOV[0];
	CManager::Get()->GetDebugProc()->Print("rgdwPOV0: %d\n", nCheck);
}

//=====================================
//�p�b�h�{�^���v���X���擾����
//=====================================
bool CInputPad::GetButtonPress(int nKey)
{
	return (m_PadState.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�p�b�h�{�^���g���K�[���擾����
//=====================================
bool CInputPad::GetButtonTrigger(int nKey)
{
	return (m_PadStateTrigger.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�p�b�h�{�^�������[�X���擾����
//=====================================
bool CInputPad::GetButtonRelease(int nKey)
{
	return (m_PadStateRelease.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�p�b�h�{�^�����s�[�g���擾����
//=====================================
bool CInputPad::GetButtonRepeat(int nKey)
{
	return (m_PadStateRepeat.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�p�b�h���E�X�e�B�b�N�v���X���擾����
//=====================================
int CInputPad::GetLStickLRPress(void)
{
	return m_PadState.lX;
}

//=====================================
//�p�b�h�㉺�X�e�B�b�N�v���X���擾����
//=====================================
int CInputPad::GetLStickUDPress(void)
{
	return m_PadState.lY;
}

//=====================================
//�p�b�h���E�X�e�B�b�N�v���X���擾����
//=====================================
int CInputPad::GetRStickLRPress(void)
{
	return m_PadState.lZ;
}

//=====================================
//�p�b�h�㉺�X�e�B�b�N�v���X���擾����
//=====================================
int CInputPad::GetRStickUDPress(void)
{
	return m_PadState.lRz;
}

//=====================================
//�p�b�h�\���{�^���v���X���擾����
//=====================================
int CInputPad::GetButtonCrossPress(void)
{
	return m_PadState.rgdwPOV[0];
}

//=====================================
//�p�b�h�\���{�^���v���X���擾����
//=====================================
bool CInputPad::GetAll(void)
{
	for (int nCntKey = 0; nCntKey < 128; nCntKey++)
	{
		if ((m_PadState.rgbButtons[nCntKey] & 0x80) ? true : false)
		{
			return true;
		}
	}

	if (m_PadState.lX != 0 ||
		m_PadState.lY != 0 ||
		m_PadState.lZ != 0 ||
		m_PadState.lRz != 0 ||
		m_PadState.rgdwPOV[0] != -1)
	{
		return true;
	}

	return false;
}
//�p�b�h
//=====================================

//=====================================
//�}�E�X
//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CInputMouse::CInputMouse()
{
	m_nCountRepeat = 0;
}

CInputMouse::~CInputMouse()
{
}

//=====================================
//�}�E�X�̏���������
//=====================================
HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);
	LPDIRECTINPUT8 pInput = GetInput();						//DirectInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8 pDevice = GetInputDevice();			//���̓f�o�C�X�ւ̃|�C���^

	//���̓f�o�C�X�̐���
	if (FAILED(pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�f�o�C�X�̐ݒ�
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;

	if (FAILED(m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	m_pDevice->Acquire();

	return S_OK;
}

//=====================================
//�}�E�X�̏I������
//=====================================
void CInputMouse::Uninit(void)
{
	LPDIRECTINPUTDEVICE8 pDevice = GetInputDevice();			//���̓f�o�C�X�ւ̃|�C���^

	//�L�[�{�[�h�̔j��
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}
}

//=====================================
//�}�E�X�̍X�V����
//=====================================
void CInputMouse::Update(void)
{
	DIMOUSESTATE2 mouse;
	LPDIRECTINPUTDEVICE8 pDevice = GetInputDevice();			//���̓f�o�C�X�ւ̃|�C���^

	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(mouse), &mouse)))
	{
		for (int nCntKey = 0; nCntKey < 5; nCntKey++)
		{
			m_StateTrigger.rgbButtons[nCntKey] = (m_State.rgbButtons[nCntKey] ^ mouse.rgbButtons[nCntKey]) & mouse.rgbButtons[nCntKey];

			m_nCountRepeat++;
			if ((m_nCountRepeat % 10) == 0)
			{
				m_nCountRepeat = (m_nCountRepeat + 1) % 10;
				m_StateRepeat.rgbButtons[nCntKey] = mouse.rgbButtons[nCntKey];			//�����[�X����ۑ�
			}
			else
			{
				m_StateRepeat.rgbButtons[nCntKey] = (m_StateRepeat.rgbButtons[nCntKey] ^ mouse.rgbButtons[nCntKey]) & m_StateRepeat.rgbButtons[nCntKey];	//���s�[�g�Ƀ����[�X�̏��ۑ�
			}
		}

		//���͏��̕ۑ�
		m_State = mouse;
	}
	else
	{
		m_pDevice->Acquire();								//�L�[�{�[�h�̃A�N�Z�X�����擾
	}
}

//=====================================
//�}�E�X�{�^���v���X���擾����
//=====================================
bool CInputMouse::GetPress(int nKey)
{
	return (m_State.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�}�E�X�g���K�[���擾����
//=====================================
bool CInputMouse::GetTrigger(int nKey)
{
	return (m_StateTrigger.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�}�E�X���s�[�g���擾����
//=====================================
bool CInputMouse::GetRepeat(int nKey)
{
	return (m_StateRepeat.rgbButtons[nKey] & 0x80) ? true : false;
}

//=====================================
//�}�E�X���ړ����擾����
//=====================================
int CInputMouse::GetRStickLRPress(void)
{
	return m_State.lX * 100;
}

//=====================================
//�}�E�X�c�ړ����擾����
//=====================================
int CInputMouse::GetRStickUDPress(void)
{
	return m_State.lY * 100;
}

//=====================================
//�}�E�X�S���擾����
//=====================================
bool CInputMouse::GetAll(void)
{
	for (int nCntKey = 0; nCntKey < 8; nCntKey++)
	{
		if ((m_State.rgbButtons[nCntKey] & 0x80) ? true : false)
		{
			return true;
		}
	}

	if (m_State.lX != 0 ||
		m_State.lY != 0)
	{
		return true;
	}

	return false;
}
//�}�E�X
//=====================================