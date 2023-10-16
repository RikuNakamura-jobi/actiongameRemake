//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#include "light.h"
#include "input.h"
#include "manager.h"
#include "renderer.h"

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CLight::CLight()
{
	
}

CLight::~CLight()
{
}

//===========================
//���C�g�̏���������
//===========================
HRESULT CLight::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	D3DXVECTOR3 vecDir;		//�ݒ�p�����x�N�g��

	for (int nCntLight = 0; nCntLight < NUM_LIGHT; nCntLight++)
	{
		//���C�g�̏����N���A����
		ZeroMemory(&m_aLight[nCntLight], sizeof(D3DLIGHT9));

		//���C�g�̎�ނ�ݒ�
		m_aLight[nCntLight].Type = D3DLIGHT_DIRECTIONAL;

		if (nCntLight == 0)
		{
			//���C�g�̊g�U����ݒ�
			m_aLight[nCntLight].Diffuse = D3DXCOLOR(0.75f, 0.75f, 0.75f, 0.75f);

			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(0.5f, -0.37f, -0.5f);
		}
		else if (nCntLight == 1)
		{
			//���C�g�̊g�U����ݒ�
			m_aLight[nCntLight].Diffuse = D3DXCOLOR(0.75f, 0.75f, 0.75f, 0.75f);

			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(-0.18f, 0.88f, -0.44f);
		}
		else if (nCntLight == 2)
		{
			//���C�g�̊g�U����ݒ�
			m_aLight[nCntLight].Diffuse = D3DXCOLOR(0.55f, 0.55f, 0.55f, 0.55f);

			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(0.89f, -0.11f, 0.44f);
		}
		else if (nCntLight == 3)
		{
			//���C�g�̊g�U����ݒ�
			m_aLight[nCntLight].Diffuse = D3DXCOLOR(0.25f, 0.25f, 0.25f, 0.25f);

			//���C�g�̕�����ݒ�
			vecDir = D3DXVECTOR3(-0.69f, -0.11f, 0.54f);
		}

		D3DXVec3Normalize(&vecDir, &vecDir);		//�x�N�g���𐳋K������
		m_aLight[nCntLight].Direction = vecDir;

		//���C�g��ݒ肷��
		pDevice->SetLight(nCntLight, &m_aLight[nCntLight]);

		//���C�g��L���ɂ���
		pDevice->LightEnable(nCntLight, TRUE);
	}

	return S_OK;
}

//===========================
//���C�g�̏I������
//===========================
void CLight::Uninit(void)
{

}

//===========================
//���C�g�̍X�V����
//===========================
void CLight::Update(void)
{

}