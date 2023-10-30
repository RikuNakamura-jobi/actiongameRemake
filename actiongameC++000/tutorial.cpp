//=====================================
//
// 
// Author:������
//
//=====================================
#include "tutorial.h"
#include "renderer.h"
#include "manager.h"
#include "camera.h"
#include "object.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CTutorialBillboard::m_pTexture[5] = {};
const char *CTutorialBillboard::m_apFilename[5] =
{
	"data\\TEXTURE\\tutorial001.png",
	"data\\TEXTURE\\tutorial002.png",
	"data\\TEXTURE\\tutorial003.png",
	"data\\TEXTURE\\tutorial004.png",
	"data\\TEXTURE\\tutorial005.png"
};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CTutorialBillboard::CTutorialBillboard(int nPriority = 3) : CObjectBillboard(nPriority)
{
	
}

CTutorialBillboard::~CTutorialBillboard()
{
}

//=====================================
// ��������
//=====================================
CTutorialBillboard *CTutorialBillboard::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, float fWidth, float fHeight)
{
	CTutorialBillboard *pObjectEffect;

	//2D�I�u�W�F�N�g�̐���
	pObjectEffect = new CTutorialBillboard();

	if (pObjectEffect != NULL)
	{
		pObjectEffect->Set(pos, rot, fWidth, fHeight);

		//������
		if (FAILED(pObjectEffect->Init()))
		{
			pObjectEffect->Release();
		}

		pObjectEffect->SetMove(move);
		pObjectEffect->SetCol(col);

		pObjectEffect->BindTexture(m_pTexture[nLife]);
	}

	return pObjectEffect;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CTutorialBillboard::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	for (int nCnt = 0; nCnt < 5; nCnt++)
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
void CTutorialBillboard::Unload(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
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
HRESULT CTutorialBillboard::Init(void)
{
	CObjectBillboard::Init();

	SetType(TYPE_LOCKON);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CTutorialBillboard::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CTutorialBillboard::Update(void)
{
	CInput *input = CManager::Get()->GetInputKeyboard();
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXVECTOR3 move = GetMove();
	float fHeight = GetHeight();
	float fWidth = GetWidth();

	SetPos(pos);
	SetRot(rot);
	SetMove(move);
	SetHeight(fHeight);
	SetWidth(fWidth);

	//target();

	CObjectBillboard::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CTutorialBillboard::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//Z�e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	CObjectBillboard::Draw();

	//Z�e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}