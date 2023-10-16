//=====================================
//
// 
// Author:������
//
//=====================================
#include "number.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CNumber::m_pTexture = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CNumber::CNumber(int nPriority = 6) : CObject2D(nPriority)
{
	m_nNumber = 0;
}

CNumber::~CNumber()
{
}

//=====================================
// ��������
//=====================================
CNumber *CNumber::Create(void)
{
	CNumber *pObjectNumber;

	//2D�I�u�W�F�N�g�̐���
	pObjectNumber = new CNumber();

	if (pObjectNumber != NULL)
	{
		//������
		if (FAILED(pObjectNumber->Init()))
		{
			pObjectNumber->Release();
		}

		pObjectNumber->BindTexture(m_pTexture);
	}

	return pObjectNumber;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CNumber::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	if (FAILED(D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\number001.png",
		&m_pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}
void CNumber::Unload(void)
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
HRESULT CNumber::Init(void)
{
	CObject2D::Init();

	SetType(TYPE_NUMBER);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CNumber::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CNumber::Update(void)
{
	D3DXVECTOR2 *texpos = GetTexPos();

	texpos[0] = D3DXVECTOR2(0.1f * m_nNumber, 0.0f);
	texpos[1] = D3DXVECTOR2(0.1f + (0.1f * m_nNumber), 0.0f);
	texpos[2] = D3DXVECTOR2(0.1f * m_nNumber, 1.0f);
	texpos[3] = D3DXVECTOR2(0.1f + (0.1f * m_nNumber), 1.0f);

	CObject2D::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CNumber::Draw(void)
{
	CObject2D::Draw();
}