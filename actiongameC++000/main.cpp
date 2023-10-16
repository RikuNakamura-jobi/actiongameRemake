//===========================
//
//�_�C���N�gX.main�t�@�C��
//Author:�����@��
//
//===========================
#include "main.h"
#include "manager.h"
#include "debugproc.h"

//�}�N����`
#define CLASS_NAME "WindowClass"												//�E�B���h�E�N���X�̖��O
#define WINDOW_NAME "actiongame"												//�E�B���h�E�̖��O

//�v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//�O���[�o���ϐ��錾

//=====================================
//���C���֐�
//=====================================
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hinstancePrev, LPSTR lpCmdLine, int nCmdShow)
{
	//���������[�N���o��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CManager *pManager = NULL;

	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),										//WNDCLASSEX�̃������T�C�Y
		CS_CLASSDC,												//�E�B���h�E�̃X�^�C��
		WindowProc,												//�E�B���h�E�v���V�[�W��
		0,														//0�ɂ���(�ʏ�͎g�p���Ȃ�)
		0,														//0�ɂ���(�ʏ�͎g�p���Ȃ�)
		hinstance,												//�C���X�^���X�n���h��
		LoadIcon(NULL, IDI_APPLICATION),						//�^�X�N�o�[�A�C�R��
		LoadCursor(NULL, IDC_ARROW),							//�}�E�X�J�[�\��
		(HBRUSH)(COLOR_WINDOW + 1),								//�N���C�A���g�̈�̔w�i�F
		NULL,													//���j���[�o�[
		CLASS_NAME,												//�E�B���h�E�N���X�̖��O
		LoadIcon(NULL, IDI_APPLICATION),						//�t�@�C���̃A�C�R��
	};

	HWND hWnd;													//�E�B���h�E�n���h��(���ʎq)
	MSG msg;													//���b�Z�[�W���i�[����ϐ�
	DWORD dwCurrentTime;										//���ݎ���
	DWORD dwExecLastTime;										//�Ō�ɏ�����������
	DWORD dwFrameCount;											//�t���[���J�E���g
	DWORD dwFPSLastTime;										//�Ō��FPS���v����������

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//�E�B���h�E���쐬
	hWnd = CreateWindowEx
	(0,															//�g���E�B���h�E�X�^�C��
		CLASS_NAME,												//�E�B���h�E�N���X�̖��O
		WINDOW_NAME,											//�E�B���h�E�̖��O
		WS_OVERLAPPEDWINDOW,									//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,											//�E�B���h�E�̍���X���W
		CW_USEDEFAULT,											//�E�B���h�E�̍���Y���W
		(rect.right - rect.left),								//�E�B���h�E�̕�
		(rect.bottom - rect.top),								//�E�B���h�E�̍���
		NULL,													//�V�E�B���h�E�̃n���h��
		NULL,													//���j���[�n���h���܂��͎q�E�B���h�EID
		hinstance,												//�C���X�^���X�n���h��
		NULL);													//�E�B���h�E�쐬�f�[�^

	//�}�l�[�W���[�̐�������������
	pManager = new CManager;
	if (pManager != NULL)
	{
#ifdef _DEBUG
		if (FAILED(pManager->Init(hinstance, hWnd, TRUE)))
		{
			return -1;
		}
#else
		if (FAILED(pManager->Init(hinstance, hWnd, TRUE)))
		{
			return -1;
		}
#endif //_DEBUG
	}
	else
	{
		return -1;
	}

	//����\��ݒ�
	timeBeginPeriod(1);

	dwCurrentTime = 0;								//������
	dwExecLastTime = timeGetTime();								//���ݎ������擾
	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();

	//�E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);									//�E�B���h�E�̕\����Ԃ�ݒ�
	UpdateWindow(hWnd);											//�N���C�A���g�̈���X�V

	//���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//Windows�̏���
			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W���󂯎�����烁�b�Z�[�W���[�v�𔲂���
				break;
			}
			else
			{
				//���b�Z�[�W�̐ݒ�
				TranslateMessage(&msg);									//���z���b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�
				DispatchMessage(&msg);									//�E�B���h�E�v���V�[�W���փ��b�Z�[�W�𑗏o
			}
		}
		else
		{//DirectX�̕`�揈��
			dwCurrentTime = timeGetTime();								//���ݎ������擾

			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{//0.5�b�o��
				pManager->SetFPS((dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime));

				dwFPSLastTime = dwCurrentTime;							//FPS�𑪒肵��������ۑ�
				dwFrameCount = 0;							//�t���[���J�E���g���N���A
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{//60����1�b�o��
				dwExecLastTime = dwCurrentTime;							//�����̊J�n��ۑ�
				
				if (pManager != NULL)
				{
					//�}�l�[�W���[�̍X�V����
					pManager->Update();

					//�}�l�[�W���[�̕`�揈��
					pManager->Draw();
				}

				dwFrameCount++;											//�t���[���J�E���g�����Z
			}
		}
	}

	//�}�l�[�W���[�̔j��
	if (pManager != NULL)
	{
		//�I������
		pManager->Uninit();

		delete pManager;
		pManager = NULL;
	}

	//����\��߂�
	timeEndPeriod(1);

	//�E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//=====================================
//�E�B���h�E�v���V�[�W��
//=====================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;													//�Ԃ�l���i�[

	switch (uMsg)
	{
	case WM_DESTROY:											//�E�B���h�E�j���̃��b�Z�[�W
		//WM_QUIT���b�Z�[�W�𑗂�
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:											//�L�[�����̃��b�Z�[�W
		switch (wParam)
		{
		case VK_ESCAPE:

#ifdef _DEBUG
			//�E�B���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
			DestroyWindow(hWnd);
#else
			nID = MessageBox(hWnd, "�I�����܂���?", "�I�����b�Z�[�W", MB_YESNO);
			if (nID == IDYES)
			{
				//�E�B���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
				DestroyWindow(hWnd);
			}
#endif
			break;
		}
		break;

	case WM_CLOSE:												//�{�^�������̃��b�Z�[�W
		nID = MessageBox(hWnd, "�I�����܂���?", "�I�����b�Z�[�W", MB_YESNO);
		if (nID == IDYES)
		{
			//�E�B���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;
		}
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}