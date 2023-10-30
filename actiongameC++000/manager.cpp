//=====================================
//
// 
// Author:������
//
//=====================================
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include "objectX.h"
#include "objectbillboard.h"
#include "player.h"
#include "bg.h"
#include "bgmulti.h"
#include "input.h"
#include "bullet.h"
#include "enemy.h"
#include "number.h"
#include "score.h"
#include "effect.h"
#include "sound.h"
#include "camera.h"
#include "light.h"
#include "debugproc.h"
#include "texture.h"
#include "lockon.h"
#include "fade.h"
#include "field.h"
#include "sky.h"
#include "block.h"
#include "tutorial.h"
#include "baselife.h"
#include "collision.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
CManager *CManager::pManager = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CManager::CManager()
{
	m_nCountFPS = 0;
}

CManager::~CManager()
{
}

//=====================================
// ����������
//=====================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//�����_���[�̐���
	if (m_pRenderer != NULL)
	{
		//�I������
		m_pRenderer->Uninit();

		delete m_pRenderer;
		m_pRenderer = NULL;

		m_pRenderer = new CRenderer;
	}
	else
	{
		m_pRenderer = new CRenderer;
	}

	//����������
	if (m_pRenderer != NULL)
	{
		if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
		{//���������������s�����ꍇ
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//�C���v�b�g�̐���(�L�[�{�[�h)
	if (m_pInputKeyboard != NULL)
	{
		//�I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;

		m_pInputKeyboard = new CInputKeyboard;
	}
	else
	{
		m_pInputKeyboard = new CInputKeyboard;
	}

	//����������
	if (m_pInputKeyboard != NULL)
	{
		if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
		{//���������������s�����ꍇ
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//�C���v�b�g�̐���(�p�b�h)
	if (m_pInputPad != NULL)
	{
		//�I������
		m_pInputPad->Uninit();

		delete m_pInputPad;
		m_pInputPad = NULL;

		m_pInputPad = new CInputPad;
	}
	else
	{
		m_pInputPad = new CInputPad;
	}

	//����������
	if (m_pInputPad != NULL)
	{
		if (FAILED(m_pInputPad->Init(hInstance, hWnd)))
		{//���������������s�����ꍇ
			delete m_pInputPad; 
			m_pInputPad = NULL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//�C���v�b�g�̐���(�}�E�X)
	if (m_pInputMouse != NULL)
	{
		//�I������
		m_pInputMouse->Uninit();

		delete m_pInputMouse;
		m_pInputMouse = NULL;

		m_pInputMouse = new CInputMouse;
	}
	else
	{
		m_pInputMouse = new CInputMouse;
	}

	//����������
	if (m_pInputMouse != NULL)
	{
		if (FAILED(m_pInputMouse->Init(hInstance, hWnd)))
		{//���������������s�����ꍇ
			delete m_pInputMouse;
			m_pInputMouse = NULL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//�T�E���h�̐���
	if (m_pSound != NULL)
	{
		//�I������
		m_pSound->Uninit();

		delete m_pSound;
		m_pSound = NULL;

		m_pSound = new CSound;
	}
	else
	{
		m_pSound = new CSound;
	}

	//����������
	if (m_pSound != NULL)
	{
		if (FAILED(m_pSound->Init(hWnd)))
		{//���������������s�����ꍇ
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//���C�g�̐���
	if (m_pLight != NULL)
	{
		//�I������
		m_pLight->Uninit();

		delete m_pLight;
		m_pLight = NULL;

		m_pLight = new CLight;
	}
	else
	{
		m_pLight = new CLight;
	}

	//����������
	if (m_pLight != NULL)
	{
		if (FAILED(m_pLight->Init()))
		{//���������������s�����ꍇ
			return E_FAIL;
		}
	}
	else
	{
		return E_FAIL;
	}

	//�f�o�b�O�v���b�N�̐���
	if (m_pDebugProc != NULL)
	{
		//�I������
		m_pDebugProc->Uninit();

		delete m_pDebugProc;
		m_pDebugProc = NULL;

		m_pDebugProc = new CDebugProc;
	}
	else
	{
		m_pDebugProc = new CDebugProc;
	}

	//����������
	if (m_pDebugProc != NULL)
	{
		m_pDebugProc->Init();
	}
	else
	{
		return E_FAIL;
	}

	//�e�N�X�`���̐���
	if (m_pTexture != NULL)
	{
		//�I������
		m_pTexture->Unload();

		delete m_pTexture;
		m_pTexture = NULL;

		m_pTexture = new CTexture;
	}
	else
	{
		m_pTexture = new CTexture;
	}

	//����������
	if (m_pTexture != NULL)
	{
		m_pTexture->Load();
	}
	else
	{
		return E_FAIL;
	}

	m_pCollision = CCollision::Get();

	//�e�I�u�W�F�N�g�̃e�N�X�`���̐���
	CBullet::Load();
	CEnemy::Load();
	CBg::Load();
	CBgMulti::Load();
	CEffect::Load();
	CNumber::Load();
	CLockon::Load();
	CFade::Load();
	CField::Load();
	CSky::Load();
	CPlayer::Load();
	CBlock::Load();
	CBaselife::Load();
	CTutorialBillboard::Load();

	if (m_pScene != NULL)
	{
		//�I������
		m_pScene->Uninit();

		delete m_pScene;
		m_pScene = NULL;

		m_pScene = CScene::Create(CScene::MODE_TITLE);
	}
	else
	{
		m_pScene = CScene::Create(CScene::MODE_TITLE);
	}

	if (m_pScene != NULL)
	{
		m_pScene->Init();
	}

	return S_OK;
}

//=====================================
// �I������
//=====================================
void CManager::Uninit(void)
{
	//�e�I�u�W�F�N�g�̃e�N�X�`���̔j��
	CBullet::Unload();
	CEnemy::Unload();
	CBg::Unload();
	CBgMulti::Unload();
	CEffect::Unload();
	CNumber::Unload();
	CLockon::Unload();
	CFade::Unload();
	CField::Unload();
	CSky::Unload();
	CPlayer::Unload();
	CBlock::Unload();
	CBaselife::Unload();
	CTutorialBillboard::Unload();

	CObject::ReleaseAll();

	if (m_pInputKeyboard != NULL)
	{
		//�I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	if (m_pInputPad != NULL)
	{
		//�I������
		m_pInputPad->Uninit();

		delete m_pInputPad;
		m_pInputPad = NULL;
	}

	if (m_pInputMouse != NULL)
	{
		//�I������
		m_pInputMouse->Uninit();

		delete m_pInputMouse;
		m_pInputMouse = NULL;
	}

	if (m_pRenderer != NULL)
	{
		//�I������
		m_pRenderer->Uninit();

		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	if (m_pLight != NULL)
	{
		//�I������
		m_pLight->Uninit();

		delete m_pLight;
		m_pLight = NULL;
	}

	if (m_pSound != NULL)
	{
		//�I������
		m_pSound->Uninit();

		delete m_pSound;
		m_pSound = NULL;
	}

	if (m_pDebugProc != NULL)
	{
		//�I������
		m_pDebugProc->Uninit();

		delete m_pDebugProc;
		m_pDebugProc = NULL;
	}

	if (m_pScene != NULL)
	{
		//�I������
		m_pScene->Uninit();

		delete m_pScene;
		m_pScene = NULL;
	}

	if (m_pTexture != NULL)
	{
		//�I������
		m_pTexture->Unload();

		delete m_pTexture;
		m_pTexture = NULL;
	}

	if (m_pCollision != NULL)
	{
		//�I������
		m_pCollision->Release();
		m_pCollision = NULL;
	}
}

//=====================================
// �X�V����
//=====================================
void CManager::Update(void)
{
	m_pDebugProc->Print("FPS: %d\n", m_nCountFPS);

	//�X�V����
	m_pInputMouse->Update();
	m_pInputKeyboard->Update();
	if (m_pInputPad != NULL)
	{
		m_pInputPad->Update();
	}
	m_pRenderer->Update();
	m_pLight->Update();
	m_pDebugProc->Update();
	m_pCollision->Update();

	if (m_pScene != NULL)
	{
		//�X�V����
		m_pScene->Update();
	}
}

//=====================================
// �`�揈��
//=====================================
void CManager::Draw(void)
{
	//�`�揈��
	m_pRenderer->Draw();

	if (m_pScene != NULL)
	{
		//�`�揈��
		m_pScene->Draw();
	}
}

//=====================================
// �}�l�[�W���[�̔j��
//=====================================
HRESULT CManager::Release(void)
{
	if (pManager != NULL)
	{
		pManager->Uninit();

		delete pManager;
		pManager = NULL;
	}

	return S_OK;
}

//=====================================
// ���[�h�̐ݒ�
//=====================================
void CManager::SetMode(CScene::MODE mode)
{
	//���݂̉�ʂ̏I������
	if (m_pScene != NULL)
	{
		m_pScene->Uninit();

		delete m_pScene;
		m_pScene = NULL;
	}

	//�V������ʂ̏���������
	m_pScene = CScene::Create(mode);

	m_pScene->Init();
	m_pScene->SetMode(mode);
}

//=====================================
// �}�l�[�W���[�̎擾
//=====================================
CManager *CManager::Get(void)
{
	if (pManager == NULL)
	{
		return pManager = new CManager;
	}
	else
	{
		return pManager;
	}
}