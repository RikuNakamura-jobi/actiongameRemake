//=====================================
//
// 
// Author:������
//
//=====================================
#include "block.h"
#include "renderer.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "scene.h"
#include "lockon.h"
#include "collision.h"
#include "enemymanager.h"
#include "objectX.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
CObjectX::MODELX CBlock::m_model = {};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CBlock::CBlock(int nPriority = 3) : CObjectX(nPriority)
{
}

CBlock::~CBlock()
{
}

//=====================================
// ��������
//=====================================
CBlock *CBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	CBlock *pObjectBlock;

	//2D�I�u�W�F�N�g�̐���
	pObjectBlock = new CBlock();

	if (pObjectBlock != NULL)
	{
		pObjectBlock->Set(pos, rot, fWidth, fHeight);

		pObjectBlock->SetModel(m_model);
		pObjectBlock->BindModel(pObjectBlock->GetModel());

		//������
		if (FAILED(pObjectBlock->Init()))
		{
			pObjectBlock->Release();
		}
	}

	return pObjectBlock;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	D3DXMATERIAL *pMat;

	//x�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data/MODEL/block000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_model.pBuffMatModel,
		NULL,
		&m_model.dwNumMatModel,
		&m_model.pMeshModel);

	int nNumVtx;
	DWORD dwSizeFVF;
	BYTE *pVtxBuff;

	//���_���擾
	nNumVtx = m_model.pMeshModel->GetNumVertices();

	//���_�t�H�[�}�b�g�̃T�C�Y���擾
	dwSizeFVF = D3DXGetFVFVertexSize(m_model.pMeshModel->GetFVF());

	//���_�o�b�t�@�����b�N
	m_model.pMeshModel->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

		if (vtx.x >= m_model.vtxMax.x)
		{
			m_model.vtxMax.x = vtx.x;
		}
		if (vtx.x <= m_model.vtxMin.x)
		{
			m_model.vtxMin.x = vtx.x;
		}

		if (vtx.y >= m_model.vtxMax.y)
		{
			m_model.vtxMax.y = vtx.y;
		}
		if (vtx.y <= m_model.vtxMin.y)
		{
			m_model.vtxMin.y = vtx.y;
		}

		if (vtx.z >= m_model.vtxMax.z)
		{
			m_model.vtxMax.z = vtx.z;
		}
		if (vtx.z <= m_model.vtxMin.z)
		{
			m_model.vtxMin.z = vtx.z;
		}

		pVtxBuff += dwSizeFVF;
	}

	//���_�o�b�t�@���A�����b�N
	m_model.pMeshModel->UnlockVertexBuffer();

	//�}�e���A�����ɑ΂���|�C���^���擾
	pMat = (D3DXMATERIAL*)m_model.pBuffMatModel->GetBufferPointer();

	m_model.pTexture = new LPDIRECT3DTEXTURE9[m_model.dwNumMatModel];

	for (int nCntMat = 0; nCntMat < (int)m_model.dwNumMatModel; nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != NULL)
		{
			//�e�N�X�`���̓ǂݍ���
			D3DXCreateTextureFromFile(pDevice,
				pMat[nCntMat].pTextureFilename,
				&m_model.pTexture[nCntMat]);
		}
		else
		{
			m_model.pTexture[nCntMat] = NULL;
		}
	}

	return S_OK;
}
void CBlock::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_model.pMeshModel != NULL)
	{
		m_model.pMeshModel->Release();
		m_model.pMeshModel = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_model.pBuffMatModel != NULL)
	{
		m_model.pBuffMatModel->Release();
		m_model.pBuffMatModel = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_model.pTexture != NULL)
	{
		delete[] m_model.pTexture;
		m_model.pTexture = NULL;
	}
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CBlock::Init(void)
{
	CObjectX::Init();

	SetType(TYPE_BLOCK);

	SetCollider(CCollider::Create(GetPosPointa(), GetRotPointa(), D3DXVECTOR3(100.0f, 100.0f, 100.0f), D3DXVECTOR3(-100.0f, -100.0f, -100.0f)));
	GetCollider()->SetType(CCollider::TYPE_BOX);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CBlock::Uninit(void)
{	
	CObjectX::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CBlock::Update(void)
{
	CInput *input = CManager::Get()->GetInputKeyboard();
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXVECTOR3 move = GetMove();
	float fHeight = GetHeight();
	float fWidth = GetWidth();
	D3DXVECTOR3 movePos;

	SetPos(pos);
	SetRot(rot);
	SetMove(move);
	SetHeight(fHeight);
	SetWidth(fWidth);

	//CManager::Get()->GetDebugProc()->Print("�G�l�~�[��pos: %f, %f, %f\n", pos.x, pos.y, pos.z);

	CObjectX::Update();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CBlock::Draw(void)
{
	CObjectX::Draw();
}