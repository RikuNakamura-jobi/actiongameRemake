//=====================================
//
// 
// Author:������
//
//=====================================
#include "bg.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CBg::m_pTexture[TEXTURE_MAX] = {};
const char *CBg::m_apFilename[TEXTURE_MAX] =
{
	"data\\TEXTURE\\result001.png",
	"data\\TEXTURE\\tutorialKey000.png",
	"data\\TEXTURE\\tutorialKey001.png",
	"data\\TEXTURE\\tutorialKey002.png",
	"data\\TEXTURE\\tutorialPad000.png",
	"data\\TEXTURE\\tutorialPad001.png",
	"data\\TEXTURE\\tutorialPad002.png",
	"data\\TEXTURE\\game000.png",
	"data\\TEXTURE\\success000.png",
	"data\\TEXTURE\\Failed.png",
	"data\\TEXTURE\\tutorialStart000.png"
};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CBg::CBg(int nPriority = 6) : CObject2D(nPriority)
{
}

CBg::~CBg()
{
}

//=====================================
// ��������
//=====================================
CBg *CBg::Create(TEXTURE texture)
{
	CBg *pObjectBg;

	//2D�I�u�W�F�N�g�̐���
	pObjectBg = new CBg();

	if (pObjectBg != NULL)
	{
		//������
		if (FAILED(pObjectBg->Init()))
		{
			pObjectBg->Release();
		}

		if (texture == TEXTURE_MAX)
		{
			pObjectBg->BindTexture(NULL);
		}
		else
		{
			pObjectBg->BindTexture(m_pTexture[texture]);
			pObjectBg->m_textureType = texture;
		}
	}

	return pObjectBg;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CBg::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->Get()->GetRenderer()->GetDevice();

	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		//�e�N�X�`���̓ǂݍ���
		if (FAILED(D3DXCreateTextureFromFile(pDevice,
			m_apFilename[nCnt],
			&m_pTexture[nCnt])))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}
void CBg::Unload(void)
{
	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nCnt] != NULL)
		{
			m_pTexture[nCnt]->Release();
			m_pTexture[nCnt] = NULL;
		}
	}
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CBg::Init(void)
{
	CObject2D::Init();

	SetType(TYPE_BG);

	Set(D3DXVECTOR3(640.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1280.0f, 720.0f);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CBg::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CBg::Update(void)
{
	CObject2D::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CBg::Draw(void)
{
	CObject2D::Draw();
}