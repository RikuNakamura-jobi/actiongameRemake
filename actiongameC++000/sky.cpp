//=====================================
//
// 
// Author:������
//
//=====================================
#include "sky.h"
#include "renderer.h"
#include "manager.h"
#include "object3D.h"
#include "bg.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CSky::m_pTexture[MAX_SKY] = {};
const char *CSky::m_apFilename[MAX_SKY] =
{
	"data\\TEXTURE\\sky001.png",
	"data\\TEXTURE\\sky001.png",
	"data\\TEXTURE\\sky001.png",
	"data\\TEXTURE\\sky001.png",
	"data\\TEXTURE\\sky002.png"
};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CSky::CSky(int nPriority = 0) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fWidth = 0.0f;
	m_fHeight = 0.0f;
}

CSky::~CSky()
{
}

//=====================================
// ��������
//=====================================
CSky *CSky::Create(void)
{
	CSky *pBgMulti;

	//2D�I�u�W�F�N�g�̐���
	pBgMulti = new CSky();

	if (pBgMulti != NULL)
	{
		//������
		if (FAILED(pBgMulti->Init()))
		{
			pBgMulti->Release();
		}
	}

	return NULL;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CSky::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	for (int nCnt = 0; nCnt < MAX_SKY; nCnt++)
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
void CSky::Unload(void)
{
	for (int nCnt = 0; nCnt < MAX_SKY; nCnt++)
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
HRESULT CSky::Init(void)
{
	for (int nCnt = 0; nCnt < MAX_SKY; nCnt++)
	{
		m_apObject3D[nCnt] = CObject3D::Create();

		switch (nCnt)
		{
		case 0:

			m_apObject3D[nCnt]->SetPosSizeX(D3DXVECTOR3(SKY_LENGTH, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, SKY_LENGTH, SKY_LENGTH));

			break;

		case 1:

			m_apObject3D[nCnt]->SetPosSize(D3DXVECTOR3(0.0f, 1000.0f, -SKY_LENGTH), D3DXVECTOR3(SKY_LENGTH, SKY_LENGTH, 0.0f));

			break;

		case 2:

			m_apObject3D[nCnt]->SetPosSizeX(D3DXVECTOR3(-SKY_LENGTH, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, SKY_LENGTH, -SKY_LENGTH));

			break;

		case 3:

			m_apObject3D[nCnt]->SetPosSize(D3DXVECTOR3(0.0f, 1000.0f, SKY_LENGTH), D3DXVECTOR3(-SKY_LENGTH, SKY_LENGTH, 0.0f));

			break;

		case 4:

			m_apObject3D[nCnt]->SetPosSize(D3DXVECTOR3(0.0f, SKY_LENGTH + 1000.0f, 0.0f), D3DXVECTOR3(-SKY_LENGTH * 1.1f, 0.0f, SKY_LENGTH * 1.1f));

			break;
		}

		if (m_apObject3D[nCnt] != NULL)
		{
			m_apObject3D[nCnt]->BindTexture(m_pTexture[nCnt]);
			m_apObject3D[nCnt]->SetType(CObject::TYPE_SKY);
		}
	}

	SetType(TYPE_BGMULTI);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CSky::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_SKY; nCnt++)
	{
		if (m_apObject3D[nCnt] != NULL)
		{
			m_apObject3D[nCnt]->Uninit();
		}
	}

	Release();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CSky::Update(void)
{
	m_posOld = m_pos;

	/*for (int nCnt = 0; nCnt < MAX_SKY; nCnt++)
	{
		if (m_apObject3D[nCnt] != NULL)
		{
			D3DXVECTOR2 *texPos = NULL;

			texPos = m_apObject3D[nCnt]->GetTexPos();

			texPos[0].x += 0.001f * nCnt;
			texPos[1].x += 0.001f * nCnt;
			texPos[2].x += 0.001f * nCnt;
			texPos[3].x += 0.001f * nCnt;

			m_apObject3D[nCnt]->Update();
		}
	}*/
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CSky::Draw(void)
{

}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void CSky::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	m_pos = pos;
	m_rot = rot;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
}