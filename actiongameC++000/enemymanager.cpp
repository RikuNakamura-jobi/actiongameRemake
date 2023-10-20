//=====================================
//
// 
// Author:������
//
//=====================================
#include "enemymanager.h"
#include "renderer.h"
#include "manager.h"
#include "object2D.h"
#include "bg.h"
#include "enemy.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CEnemyManager::CEnemyManager(int nPriority = 0)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_WAVE; nCnt++)
	{
		m_apEnemyWave[nCnt] = NULL;
	}
}

CEnemyManager::~CEnemyManager()
{
}

//=====================================
// ��������
//=====================================
CEnemyManager *CEnemyManager::Create(void)
{
	CEnemyManager *pEnemyManager;

	//2D�I�u�W�F�N�g�̐���
	pEnemyManager = new CEnemyManager();

	if (pEnemyManager != NULL)
	{
		//������
		if (FAILED(pEnemyManager->Init()))
		{
			return NULL;
		}
	}

	return pEnemyManager;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CEnemyManager::Init(void)
{
	m_apEnemyWave[0] = CEnemySpawn::Create(0, 5);
	m_apEnemyWave[1] = CEnemySpawn::Create(1, 1);

	for (int nCnt = 0; nCnt < MAX_ENEMY_WAVE; nCnt++)
	{
		if (m_apEnemyWave[nCnt] != NULL)
		{
			//m_apEnemyWave[nCnt]->Init();
		}
	}

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CEnemyManager::Uninit(void)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_WAVE; nCnt++)
	{
		if (m_apEnemyWave[nCnt] != NULL)
		{
			m_apEnemyWave[nCnt]->Uninit();

			delete m_apEnemyWave[nCnt];
			m_apEnemyWave[nCnt] = NULL;
		}
	}
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CEnemyManager::Update(void)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_WAVE; nCnt++)
	{
		if (m_apEnemyWave[nCnt] != NULL)
		{
			if (m_apEnemyWave[nCnt]->Update() == 0)
			{
				if (nCnt == 0)
				{
					m_apEnemyWave[nCnt]->Uninit();

					delete m_apEnemyWave[nCnt];
					m_apEnemyWave[nCnt] = NULL;
					//CManager::Get()->GetScene()->SetFinish();

					//m_apEnemyWave[nCnt] = CEnemySpawn::Create(nCnt, 5);
				}
				else
				{
					m_apEnemyWave[nCnt]->Uninit();

					delete m_apEnemyWave[nCnt];
					m_apEnemyWave[nCnt] = NULL;

					CManager::Get()->GetScene()->SetFinish();
				}
			}
		}
	}
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CEnemyManager::Draw(void)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_WAVE; nCnt++)
	{
		if (m_apEnemyWave[nCnt] != NULL)
		{
			m_apEnemyWave[nCnt]->Draw();
		}
	}
}

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CEnemySpawn::CEnemySpawn(int nPriority = 0)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
	{
		m_apObject2D[nCnt] = NULL;
	}

	m_nNumEnemy = 0;
}

CEnemySpawn::~CEnemySpawn()
{
}

//=====================================
// ��������
//=====================================
CEnemySpawn *CEnemySpawn::Create(int nWave, int nEnemySpaen)
{
	CEnemySpawn *pEnemyManager;

	//2D�I�u�W�F�N�g�̐���
	pEnemyManager = new CEnemySpawn();

	if (pEnemyManager != NULL)
	{
		//������
		if (FAILED(pEnemyManager->Init()))
		{
			return NULL;
		}

		for (int nCnt = 0; nCnt < nEnemySpaen; nCnt++)
		{
			if (pEnemyManager->m_apObject2D[nCnt] == NULL)
			{
				if (nWave == 0)
				{
					pEnemyManager->m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(300.0f * nCnt + 1.0f, 100.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, nWave);
					pEnemyManager->m_apObject2D[nCnt]->SetIdxSpawn(nCnt);
				}
				else
				{
					pEnemyManager->m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(-2000.0f, 100.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, nWave);
					pEnemyManager->m_apObject2D[nCnt]->SetIdxSpawn(nCnt);
				}
			}
		}

		pEnemyManager->m_nNumEnemy = nEnemySpaen;
	}

	return pEnemyManager;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CEnemySpawn::Init(void)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
	{
		if (m_apObject2D[nCnt] != NULL)
		{
			//m_apObject2D[nCnt]->Init();
		}
	}

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CEnemySpawn::Uninit(void)
{
	
}

//=====================================
// �|���S���̍X�V����
//=====================================
int CEnemySpawn::Update(void)
{
	return m_nNumEnemy;
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CEnemySpawn::Draw(void)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
	{
		if (m_apObject2D[nCnt] != NULL)
		{
			m_apObject2D[nCnt]->Draw();
		}
	}
}