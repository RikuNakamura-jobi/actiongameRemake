//=====================================
//
// 
// Author:������
//
//=====================================
#include "baselife.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CBaselife::m_pTexture = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CBaselife::CBaselife(int nPriority = 0) : CObject2D(nPriority)
{
}

CBaselife::~CBaselife()
{
}

//=====================================
// ��������
//=====================================
CBaselife *CBaselife::Create(void)
{
	CBaselife *pObjectBaselife;

	//2D�I�u�W�F�N�g�̐���
	pObjectBaselife = new CBaselife();

	if (pObjectBaselife != NULL)
	{
		//������
		if (FAILED(pObjectBaselife->Init()))
		{
			pObjectBaselife->Release();
		}

		pObjectBaselife->Set(D3DXVECTOR3(640.0f, 40.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 100.0f * pObjectBaselife->m_nLife, 30.0f);
		pObjectBaselife->BindTexture(m_pTexture);
	}

	return pObjectBaselife;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CBaselife::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	if (FAILED(D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\baselife000.png",
		&m_pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}
void CBaselife::Unload(void)
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
HRESULT CBaselife::Init(void)
{
	CObject2D::Init();

	m_nLife = 10;

	SetType(TYPE_BG);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CBaselife::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CBaselife::Update(void)
{
	m_nLife = CManager::Get()->GetScene()->GetPlayer()->GetEnegy();

	Set(D3DXVECTOR3(640.0f, 40.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 100.0f * m_nLife, 30.0f);
	CObject2D::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CBaselife::Draw(void)
{
	CObject2D::Draw();
}