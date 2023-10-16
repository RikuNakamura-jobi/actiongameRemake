//=====================================
//
// 
// Author:������
//
//=====================================
#include "model.h"
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
CModel::CModel()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

CModel::~CModel()
{
}

//=====================================
// ��������
//=====================================
CModel *CModel::Create(char *pFilename)
{
	CModel *pModel;

	//2D�I�u�W�F�N�g�̐���
	pModel = new CModel;

	if (pModel != NULL)
	{
		//������
		if (FAILED(pModel->Init(pFilename)))
		{
			pModel->Uninit();

			return NULL;
		}
	}

	return pModel;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CModel::Init(char *pFilename)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	//x�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(pFilename,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_pBuffMatModel,
		NULL,
		&m_dwNumMatModel,
		&m_pMeshModel);

	//�}�e���A�����ɑ΂���|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMatModel->GetBufferPointer();

	m_pTexture = new LPDIRECT3DTEXTURE9[m_dwNumMatModel];

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
	{
		if (pMat[nCntMat].pTextureFilename != NULL)
		{
			//�e�N�X�`���̓ǂݍ���
			D3DXCreateTextureFromFile(pDevice,
				pMat[nCntMat].pTextureFilename,
				&m_pTexture[nCntMat]);
		}
		else
		{
			m_pTexture[nCntMat] = NULL;
		}
	}

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CModel::Uninit(void)
{
	//�e�N�X�`���̔j��
	if (m_pMeshModel != NULL)
	{
		m_pMeshModel->Release();
		m_pMeshModel = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_pBuffMatModel != NULL)
	{
		m_pBuffMatModel->Release();
		m_pBuffMatModel = NULL;
	}

	if (m_pTexture != NULL)
	{
		delete[] m_pTexture;
		m_pTexture = NULL;
	}
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CModel::Update(void)
{
	
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CModel::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;
	D3DXMATERIAL *pMat;
	D3DXMATRIX mtxRotModel, mtxTransModel, mtxPalent;		//�v�Z�p�}�g���b�N�X

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

	//�p�[�c�̐e�}�g���b�N�X��ݒ�
	if (m_pParent != NULL)
	{
		mtxPalent = m_pParent->GetMtxWorld();
	}
	else
	{
		pDevice->GetTransform(D3DTS_WORLD, &mtxPalent);
	}

	//�Z�o�����p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���������킹��
	D3DXMatrixMultiply(&m_mtxWorld,
		&m_mtxWorld,
		&mtxPalent);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���̃f�[�^�̃|�C���g���擾
	pMat = (D3DXMATERIAL*)m_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture[nCntMat]);

		//���f��(�p�[�c)�̕`��
		m_pMeshModel->DrawSubset(nCntMat);
	}

	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}