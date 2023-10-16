//=====================================
//
// 
// Author:������
//
//=====================================
#include "enemy.h"
#include "renderer.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "scene.h"
#include "lockon.h"
#include "enemymanager.h"
#include "objectX.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
CObjectX::MODELX CEnemy::m_model = {};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CEnemy::CEnemy(int nPriority = 3) : CObjectX(nPriority)
{
	m_nCounter = 0;
	m_nPattern = 0;
	m_nLife = 0;
}

CEnemy::~CEnemy()
{
}

//=====================================
// ��������
//=====================================
CEnemy *CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight, int nWave)
{
	CEnemy *pObjectEnemy;

	//2D�I�u�W�F�N�g�̐���
	pObjectEnemy = new CEnemy();

	if (pObjectEnemy != NULL)
	{
		pObjectEnemy->Set(pos, rot, fWidth, fHeight);

		pObjectEnemy->SetModel(m_model);
		pObjectEnemy->BindModel(pObjectEnemy->GetModel());

		//������
		if (FAILED(pObjectEnemy->Init()))
		{
			pObjectEnemy->Release();
		}

		pObjectEnemy->m_nWave = nWave;
	}

	return pObjectEnemy;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CEnemy::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	D3DXMATERIAL *pMat;

	//x�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data/MODEL/maidGobrin000.x",
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
void CEnemy::Unload(void)
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
HRESULT CEnemy::Init(void)
{
	CObjectX::Init();

	m_nLife = 10;
	SetType(TYPE_ENEMY);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CEnemy::Uninit(void)
{
	CManager::Get()->GetScene()->GetEnemyManager()->GetEnemyWave(m_nWave)->addNumEnemy(-1);
	CManager::Get()->GetScene()->GetEnemyManager()->GetEnemyWave(m_nWave)->SetEnemy(m_nIdxSpawn, NULL);

	if (m_lockon != NULL)
	{
		m_lockon->Uninit();
		m_lockon = NULL;
	}
	
	CObjectX::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CEnemy::Update(void)
{
	CInput *input = CManager::Get()->GetInputKeyboard();
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXVECTOR3 move = GetMove();
	float fHeight = GetHeight();
	float fWidth = GetWidth();
	D3DXVECTOR3 movePos;
	m_nCounter++;				//�J�E���^�[�����Z

	//�p�^�[��N0.���X�V����
	m_nPattern = (m_nCounter / 5) % 10;

	movePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	float fRotMove, fRotDest, fRotDiff;

	//���݂̊p�x�ƖړI�̊p�x�̍������v�Z
	fRotMove = rot.y;
	fRotDest = atan2f(move.x, move.z);
	fRotDiff = fRotDest - fRotMove;

	if (fRotDiff > 3.14f)
	{
		fRotDiff -= 6.28f;
	}
	else if (fRotDiff <= -3.14f)
	{
		fRotDiff += 6.28f;
	}

	//���X�ɑ����Ă�
	fRotMove += fRotDiff * 0.2f;

	if (fRotMove > 3.14f)
	{
		fRotMove -= 6.28f;
	}
	else if (fRotMove <= -3.14f)
	{
		fRotMove += 6.28f;
	}

	rot.y = fRotMove;

	//move.y -= 30.8f;

	pos += move;

	move.x += (0 - move.x) * 0.15f;
	move.z += (0 - move.z) * 0.15f;

	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
		move.y = 0.0f;
	}

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
void CEnemy::Draw(void)
{
	CObjectX::Draw();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CEnemy::SetLockon(void)
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXVECTOR3 move = GetMove();
	float fHeight = GetHeight();
	float fWidth = GetWidth();

	if (m_lockon == NULL)
	{
		m_lockon = CLockon::Create(pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1, 30.0f, 30.0f);
	}
}