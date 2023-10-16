//=====================================
//
// 
// Author:������
//
//=====================================
#include "objectbillboard.h"
#include "renderer.h"
#include "manager.h"
#include "debugproc.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CObjectBillboard::CObjectBillboard(int nPriority = 7) : CObject(nPriority)
{
	m_pVtxBuff = NULL;						//���_�����i�[
	m_pTexturePolygon = NULL;				//�e�N�X�`���ւ̃|�C���^
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	m_texPos[0] = D3DXVECTOR2(0.0f, 0.0f);
	m_texPos[1] = D3DXVECTOR2(1.0f, 0.0f);
	m_texPos[2] = D3DXVECTOR2(0.0f, 1.0f);
	m_texPos[3] = D3DXVECTOR2(1.0f, 1.0f);

	m_fWidth = 100.0f;
	m_fHeight = 100.0f;
	m_fLength = 0.0f;
	m_fAngle = 0.0f;
}

CObjectBillboard::~CObjectBillboard()
{
}

//=====================================
// ��������
//=====================================
CObjectBillboard *CObjectBillboard::Create(void)
{
	CObjectBillboard *pObjectBillboard;

	//2D�I�u�W�F�N�g�̐���
	pObjectBillboard = new CObjectBillboard();

	if (pObjectBillboard != NULL)
	{
		//������
		if (FAILED(pObjectBillboard->Init()))
		{
			pObjectBillboard->Release();
		}
	}

	return pObjectBillboard;
}


//=====================================
// �|���S���̏���������
//=====================================
HRESULT CObjectBillboard::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		{ FVF_VERTEX_3D },
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx;

	//�Ίp���̒������Z�o����
	m_fLength = sqrtf((m_fWidth * m_fWidth) + (m_fHeight * m_fHeight)) * 0.5f;

	//�Ίp���̊p�x���Z�o����
	m_fAngle = atan2f(m_fWidth, m_fHeight);

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos.x = sinf(m_rot.z - m_fAngle) * m_fLength;
	pVtx[0].pos.y = cosf(m_rot.z - m_fAngle) * m_fLength;
	pVtx[0].pos.z = 0.0f;

	pVtx[1].pos.x = sinf(m_rot.z + m_fAngle) * m_fLength;
	pVtx[1].pos.y = cosf(m_rot.z + m_fAngle) * m_fLength;
	pVtx[1].pos.z = 0.0f;

	pVtx[2].pos.x = sinf(m_rot.z - D3DX_PI + m_fAngle) * m_fLength;
	pVtx[2].pos.y = cosf(m_rot.z - D3DX_PI + m_fAngle) * m_fLength;
	pVtx[2].pos.z = 0.0f;

	pVtx[3].pos.x = sinf(m_rot.z + D3DX_PI - m_fAngle) * m_fLength;
	pVtx[3].pos.y = cosf(m_rot.z + D3DX_PI - m_fAngle) * m_fLength;
	pVtx[3].pos.z = 0.0f;

	//���_���W�̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CObjectBillboard::Uninit(void)
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
void CObjectBillboard::Update(void)
{
	//�Ίp���̒������Z�o����
	m_fLength = sqrtf((m_fWidth * m_fWidth) + (m_fHeight * m_fHeight)) * 0.5f;

	//�Ίp���̊p�x���Z�o����
	m_fAngle = atan2f(m_fWidth, m_fHeight);

	VERTEX_3D *pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos.x = sinf(m_rot.z - m_fAngle) * m_fLength;
	pVtx[0].pos.y = cosf(m_rot.z - m_fAngle) * m_fLength;
	pVtx[0].pos.z = 0.0f;

	pVtx[1].pos.x = sinf(m_rot.z + m_fAngle) * m_fLength;
	pVtx[1].pos.y = cosf(m_rot.z + m_fAngle) * m_fLength;
	pVtx[1].pos.z = 0.0f;

	pVtx[2].pos.x = sinf(m_rot.z - D3DX_PI + m_fAngle) * m_fLength;
	pVtx[2].pos.y = cosf(m_rot.z - D3DX_PI + m_fAngle) * m_fLength;
	pVtx[2].pos.z = 0.0f;

	pVtx[3].pos.x = sinf(m_rot.z + D3DX_PI - m_fAngle) * m_fLength;
	pVtx[3].pos.y = cosf(m_rot.z + D3DX_PI - m_fAngle) * m_fLength;
	pVtx[3].pos.z = 0.0f;

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		pVtx[nCnt].col = m_col;
		pVtx[nCnt].tex = m_texPos[nCnt];
	}

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CObjectBillboard::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxView;			//�r���[�}�g���b�N�X�擾�p

	//�e����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//���e�X�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 100);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�r���[�}�g���b�N�X���擾
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	//�|���S�����J�����ɑ΂��Đ��ʂɌ�����
	D3DXMatrixInverse(&m_mtxWorld, NULL, &mtxView);
	m_mtxWorld._41 = 0.0f;
	m_mtxWorld._42 = 0.0f;
	m_mtxWorld._43 = 0.0f;

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexturePolygon);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	//�e����
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//���e�X�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void CObjectBillboard::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	m_pos = pos;
	m_rot = rot;
	m_fWidth = fWidth;
	m_fHeight = fHeight;
}