//=====================================
//
// 
// Author:������
//
//=====================================
#include "field.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CField::m_pTexture = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CField::CField(int nPriority = 0) : CObject3D(nPriority)
{
}

CField::~CField()
{
}

//=====================================
// ��������
//=====================================
CField *CField::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CField *pObjectBg;

	//2D�I�u�W�F�N�g�̐���
	pObjectBg = new CField();

	if (pObjectBg != NULL)
	{
		pObjectBg->SetPos(pos);
		pObjectBg->SetSize(size);

		//������
		if (FAILED(pObjectBg->Init()))
		{
			pObjectBg->Release();
		}

		pObjectBg->BindTexture(m_pTexture);
	}

	return pObjectBg;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CField::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	if (FAILED(D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\field001.png",
		&m_pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}
void CField::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CField::Init(void)
{
	CObject3D::Init();

	//SetType(TYPE_BG);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CField::Uninit(void)
{
	CObject3D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CField::Update(void)
{
	//Set(D3DXVECTOR3(640.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1280.0f, 720.0f);
	CObject3D::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CField::Draw(void)
{
	CObject3D::Draw();
}