//=====================================
//
// 
// Author:������
//
//=====================================
#include "orbit.h"
#include "renderer.h"
#include "manager.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 COrbit::m_pTexture = NULL;

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
COrbit::COrbit(int nPriority = 5) : CObject(nPriority)
{
	m_pVtxBuff = NULL;				//���_�����i�[
	m_pTexture = NULL;				//�e�N�X�`���ւ̃|�C���^

	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

COrbit::~COrbit()
{
}

//=====================================
// ��������
//=====================================
COrbit *COrbit::Create(D3DXMATRIX mtxWorld, D3DXVECTOR3 posOffset1, D3DXVECTOR3 posOffset2, D3DXCOLOR col, int nNumEdge)
{
	COrbit *pOrbit = NULL;

	//2D�I�u�W�F�N�g�̐���
	pOrbit = new COrbit();

	if (pOrbit != NULL)
	{
		//������
		if (FAILED(pOrbit->Init()))
		{
			pOrbit->Release();

			return NULL;
		}

		//�F�̑��
		pOrbit->SetCol(col);

		//�I�t�Z�b�g�̑��
		pOrbit->SetposOffset(posOffset1, 0);
		pOrbit->SetposOffset(posOffset2, 1);
		
		//�ӂ̐��̑��
		pOrbit->SetEdge(nNumEdge);

		D3DXMATRIX mtxWorldOffsetTemp = {};
		mtxWorldOffsetTemp._41 = posOffset1.x + mtxWorld._41;
		mtxWorldOffsetTemp._42 = posOffset1.y + mtxWorld._42;
		mtxWorldOffsetTemp._43 = posOffset1.z + mtxWorld._43;
		pOrbit->SetmtxWorldOffset(mtxWorldOffsetTemp, 0);

		mtxWorldOffsetTemp._41 = posOffset2.x + mtxWorld._41;
		mtxWorldOffsetTemp._42 = posOffset2.y + mtxWorld._42;
		mtxWorldOffsetTemp._43 = posOffset2.z + mtxWorld._43;
		pOrbit->SetmtxWorldOffset(mtxWorldOffsetTemp, 1);

		for (int nCntVtx = 0; nCntVtx < pOrbit->m_nNumEdge; nCntVtx++)
		{
			pOrbit->SetPosPoint(D3DXVECTOR3(posOffset1.x + mtxWorld._41, posOffset1.y + mtxWorld._42, posOffset1.z + mtxWorld._43), nCntVtx, 0);
			pOrbit->SetPosPoint(D3DXVECTOR3(posOffset2.x + mtxWorld._41, posOffset2.y + mtxWorld._42, posOffset2.z + mtxWorld._43), nCntVtx, 1);
		}

		pOrbit->SetPositionOffset(mtxWorld);
	}

	return pOrbit;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT COrbit::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	if (FAILED(D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\orbit_000.png",
		&m_pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}
void COrbit::Unload(void)
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
HRESULT COrbit::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer
	(
		sizeof(VERTEX_3D) * MAX_EDGE * NUM_OFFSET,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL
	);

	VERTEX_3D *pVtx;		//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntVtx = 0; nCntVtx < MAX_EDGE * NUM_OFFSET; nCntVtx++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�@���x�N�g���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 1.0f * (nCntVtx % NUM_OFFSET));

		pVtx++;
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void COrbit::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	Release();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void COrbit::Update(void)
{
	
}

//=====================================
// �|���S���̍X�V����
//=====================================
void COrbit::UpdatePolygon(void)
{
	//�ϐ��錾
	int nCntOffset;
	D3DXMATRIX mtxRot, mtxTrans;						//�v�Z�p�}�g���b�N�X
	D3DXVECTOR3 posTemp[NUM_OFFSET];

	//�ۑ��������W�����炷==========
	for (int nCntVtx = 1; nCntVtx < m_nNumEdge; nCntVtx++)
	{
		for (nCntOffset = 0; nCntOffset < NUM_OFFSET; nCntOffset++)
		{
			//��O�̍��W�ɂ����
			m_aPosPoint[nCntVtx - 1][nCntOffset] = m_aPosPoint[nCntVtx][nCntOffset];
		}
	}

	for (nCntOffset = 0; nCntOffset < NUM_OFFSET; nCntOffset++)
	{
		//���݂̃t���[���̃I�t�Z�b�g�ʒu��ۑ�
		m_aPosPoint[m_nNumEdge - 1][nCntOffset] =
		{
			m_mtxWorldOffset[nCntOffset]._41,
			m_mtxWorldOffset[nCntOffset]._42,
			m_mtxWorldOffset[nCntOffset]._43
		};
	}
	//�ۑ��������W�����炷==========

	VERTEX_3D *pVtx;		//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntVtx = 0; nCntVtx < m_nNumEdge; nCntVtx++)
	{//�ӂ��Ƃ̒��_���W�ݒ�

		for (nCntOffset = 0; nCntOffset < NUM_OFFSET; nCntOffset++)
		{//�I�t�Z�b�g�̐����ݒ�

			//���_���W�̐ݒ�
			pVtx[nCntOffset].pos = m_aPosPoint[nCntVtx][nCntOffset];

			//���_�J���[�̐ݒ�
			pVtx[nCntOffset].col = D3DXCOLOR(m_col.r, m_col.g, m_col.b, (float)nCntVtx / m_nNumEdge);
		}

		//�|�C���^��i�߂�
		pVtx += NUM_OFFSET;
	}

	m_pVtxBuff->Unlock();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void COrbit::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;						//�v�Z�p�}�g���b�N�X

	//�J�����O�𖳌���
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//���u�����f�B���O�����Z�����ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//�A���t�@�e�X�g�̗L����
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 1);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, 0.0f, 0.0f, 0.0f);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, 0.0f, 0.0f, 0.0f);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive
	(D3DPT_TRIANGLESTRIP, 0, m_nNumEdge + (m_nNumEdge - 2));			//�`�悷��v���~�e�B�u��

	//�J�����O��L����
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�A���t�@�e�X�g�̖�����
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void COrbit::SetPositionOffset(D3DXMATRIX mtxWorld)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxOffset, mtxTrans;

	for (int nCntOffset = 0; nCntOffset < NUM_OFFSET; nCntOffset++)
	{
		mtxOffset = m_mtxWorldOffset[nCntOffset];

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&mtxOffset);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, m_posOffset[nCntOffset].x, m_posOffset[nCntOffset].y, m_posOffset[nCntOffset].z);
		D3DXMatrixMultiply(&mtxOffset, &mtxOffset, &mtxTrans);

		//�}�g���b�N�X���������킹��
		D3DXMatrixMultiply(&mtxOffset, &mtxOffset, &mtxWorld);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &mtxOffset);

		m_mtxWorldOffset[nCntOffset] = mtxOffset;
	}

	//�|���S���X�V����
	UpdatePolygon();
}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void COrbit::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	
}