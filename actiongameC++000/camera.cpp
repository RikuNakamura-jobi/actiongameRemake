//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#include "camera.h"
#include "input.h"
#include "manager.h"
#include "renderer.h"
#include "player.h"
#include "scene.h"
#include "debugproc.h"

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CCamera::CCamera()
{
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rotOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}

CCamera::~CCamera()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCamera::Init(void)
{
	//3�l��
	m_posV = D3DXVECTOR3(0.0f, 500.0f, -400.0f);
	m_posR = D3DXVECTOR3(0.0f, 500.0f, 200.0f);
	m_posVDest = D3DXVECTOR3(0.0f, 500.0f, -400.0f);
	m_posRDest = D3DXVECTOR3(0.0f, 500.0f, 200.0f);
	m_rot = D3DXVECTOR3(0.0f, 3.14f, 1.57f);
	m_rotOld = D3DXVECTOR3(0.0f, 3.14f, 1.57f);

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	Rot();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCamera::Uninit(void)
{
	
}

//=============================================================================
// �X�V����
//=============================================================================
void CCamera::Update(void)
{
	CInput *input = CManager::Get()->Get()->GetInputKeyboard();
	CInput *inputPad = CManager::Get()->Get()->GetInputPad();
	CInput *inputMouse = CManager::Get()->Get()->GetInputMouse();

	float RotStick = 0.0f;
	float lengthStick = 0.0f;

	if (inputPad != NULL)
	{
		RotStick = atan2f((float)inputPad->GetRStickLRPress(), (float)inputPad->GetRStickUDPress());
		lengthStick = hypotf((float)inputPad->GetRStickLRPress(), (float)inputPad->GetRStickUDPress());
	}
	
	CManager::Get()->Get()->GetDebugProc()->Print("R�X�e�B�b�N�̋���: %f\n", lengthStick);

	m_rotOld = m_rot;

	if (input->GetPress(DIK_J) == true)
	{//A�L�[�������ꂽ��
		//m_rot.y -= 0.04f;
	}
	if (input->GetPress(DIK_L) == true)
	{//D�L�[�������ꂽ��
		//m_rot.y += 0.04f;
	}
	if (input->GetPress(DIK_I) == true)
	{//A�L�[�������ꂽ��
		//m_rot.z -= 0.04f;
	}
	if (input->GetPress(DIK_K) == true)
	{//D�L�[�������ꂽ��
		//m_rot.z += 0.04f;
	}

	if (inputPad != NULL)
	{
		if (lengthStick > 10.0f)
		{
			//m_rot.y += (float)inputPad->GetRStickLRPress() * 0.001f * 0.04f;
			//m_rot.z += (float)inputPad->GetRStickUDPress() * 0.001f * 0.04f;
		}
	}

	lengthStick = hypotf((float)inputMouse->GetRStickLRPress(), (float)inputMouse->GetRStickUDPress());

	if (lengthStick > 10.0f)
	{
		//m_rot.y += (float)inputMouse->GetRStickLRPress() * 0.001f * 0.04f;
		//m_rot.z += (float)inputMouse->GetRStickUDPress() * 0.001f * 0.04f;
	}

	Rot();
}

//===========================
//�v���C���[�̕`�揈��
//===========================
void CCamera::Set(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->Get()->GetRenderer()->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f, 60000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION,
		&m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW,
		&m_mtxView);
}

//===========================
//�v���C���[�̕`�揈��
//===========================
void CCamera::Rot(void)
{
	float fLengthCamera;

	m_posVOld = m_posV;
	m_posROld = m_posR;

	if (m_rot.y > 3.14f)
	{
		m_rot.y -= 6.28f;
	}
	else if (m_rot.y < -3.14f)
	{
		m_rot.y += 6.28f;
	}

	if (m_rot.z < 0.0f)
	{
		m_rot.z = 0.0f;
	}
	else if (m_rot.z > 3.13f)
	{
		m_rot.z = 3.13f;
	}

	fLengthCamera = 800.0f;

	m_posRDest.x = CManager::Get()->Get()->GetScene()->GetPlayer()->GetPos().x - (sinf(0.0f) * 0.0f);
	m_posRDest.y = CManager::Get()->Get()->GetScene()->GetPlayer()->GetPos().y + 30.0f;
	m_posRDest.z = CManager::Get()->Get()->GetScene()->GetPlayer()->GetPos().z - (cosf(0.0f) * 0.0f);

	m_posVDest.x = m_posRDest.x - (sinf(m_rot.z) * sinf(m_rot.y)) * fLengthCamera;
	m_posVDest.y = m_posRDest.y + 0.0f - (cosf(m_rot.z) * fLengthCamera);
	m_posVDest.z = m_posRDest.z - (sinf(m_rot.z) * cosf(m_rot.y)) * fLengthCamera;

	m_posR.x += (m_posRDest.x - m_posR.x) * 0.7f;
	m_posR.y += (m_posRDest.y - m_posR.y) * 0.7f;
	m_posR.z += (m_posRDest.z - m_posR.z) * 0.7f;

	m_posV.x += (m_posVDest.x - m_posV.x) * 0.7f;
	m_posV.y += (m_posVDest.y - m_posV.y) * 0.7f;
	m_posV.z += (m_posVDest.z - m_posV.z) * 0.7f;
}