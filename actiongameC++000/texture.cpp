//=============================================================================
//
// 
// Author :������
//
//=============================================================================
#include "texture.h"
#include "manager.h"
#include "renderer.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
int CTexture::m_nNumAll = 0;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CTexture::CTexture()
{
	memset(m_apTexture, 0, sizeof(m_apTexture));
}

CTexture::~CTexture()
{
}

//===========================
//�e�N�X�`���̏���������
//===========================
HRESULT CTexture::Load(void)
{


	return S_OK;
}

//===========================
//�e�N�X�`���̏I������
//===========================
void CTexture::Unload(void)
{
	for (int nCnt = 0; nCnt < MAX_TEXTURE; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_apTexture[nCnt] != NULL)
		{
			m_apTexture[nCnt]->Release();
			m_apTexture[nCnt] = NULL;
		}
	}
}

//===========================
//�e�N�X�`���̏I������
//===========================
int CTexture::Regist(const char *pFilename)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for (int nCnt = 0; nCnt < MAX_TEXTURE; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_apTexture[nCnt] == NULL)
		{
			if (FAILED(D3DXCreateTextureFromFile(pDevice,
				pFilename,
				&m_apTexture[nCnt])))
			{
				return -1;
			}

			return nCnt;
		}
	}

	return -1;
}

//===========================
//�e�N�X�`���̏I������
//===========================
LPDIRECT3DTEXTURE9 CTexture::GetAddress(int nIdx)
{
	if (nIdx == -1)
	{
		return NULL;
	}

	return m_apTexture[nIdx];
}