//=====================================
//
// 
// Author:������
//
//=====================================
#include "objectX.h"
#include "renderer.h"
#include "manager.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CObjectX::CObjectX(int nPriority = 6) : CObject(nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//m_model->pTexture = NULL;
	//m_model->pMeshModel = NULL;
	//m_model->pBuffMatModel = NULL;					//���_�����i�[
	//m_model->dwNumMatModel = 0;
	//m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

CObjectX::~CObjectX()
{
}

//=====================================
// ��������
//=====================================
CObjectX *CObjectX::Create(void)
{
	CObjectX *pObject3D;

	//2D�I�u�W�F�N�g�̐���
	pObject3D = new CObjectX();

	if (pObject3D != NULL)
	{
		//������
		if (FAILED(pObject3D->Init()))
		{
			pObject3D->Release();
		}
	}

	return pObject3D;
}


//=====================================
// �|���S���̏���������
//=====================================
HRESULT CObjectX::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CObjectX::Uninit(void)
{
	Release();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CObjectX::Update(void)
{
	
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CObjectX::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;
	D3DXMATERIAL *pMat;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���̃f�[�^�̃|�C���g���擾
	pMat = (D3DXMATERIAL*)m_model->pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_model->dwNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_model->pTexture[nCntMat]);

		//���f��(�p�[�c)�̕`��
		m_model->pMeshModel->DrawSubset(nCntMat);
	}

	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//=====================================
// �|���S���̐ݒ菈��
//=====================================
void CObjectX::Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight)
{
	m_pos = pos;
	m_rot = rot;
}