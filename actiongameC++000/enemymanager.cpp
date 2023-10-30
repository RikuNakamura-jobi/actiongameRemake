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
#include "sound.h"
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
	for (int nCnt = 0; nCnt < 1; nCnt++)
	{
		if (m_apEnemyWave[nCnt] != NULL)
		{
			if (m_apEnemyWave[nCnt]->Update() == 0)
			{
				if (nCnt == 0)
				{
					m_apEnemyWave[nCnt]->Uninit();
				}
				else
				{
					m_apEnemyWave[nCnt]->Uninit();

					delete m_apEnemyWave[nCnt];
					m_apEnemyWave[nCnt] = NULL;
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
	m_nWave = 0;
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

		//pEnemyManager->m_nNumEnemy = nEnemySpaen;
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
	if (CManager::Get()->GetScene()->GetPlayer() != NULL)
	{
		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= 6500.0f && m_nWave == 0)
		{
			for (int nCntSpawn = 0; nCntSpawn < 1; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(6000.0f, 30.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			m_nWave++;
		}

		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= 5500.0f && m_nWave == 1)
		{
			for (int nCntSpawn = 0; nCntSpawn < 1; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(5000.0f, 200.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			m_nWave++;
		}

		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= 4300.0f && m_nWave == 2)
		{
			for (int nCntSpawn = 0; nCntSpawn < 5; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(200.0f * nCntSpawn + 3000.0f, 250.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			m_nWave++;
		}

		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= 2400.0f && m_nWave == 3)
		{
			for (int nCntSpawn = 0; nCntSpawn < 3; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(200.0f * nCntSpawn + 1500.0f, 500.0f - (50.0f * nCntSpawn), 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			for (int nCntSpawn = 0; nCntSpawn < 2; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(200.0f * nCntSpawn + 1100.0f, 400.0f + (50.0f * nCntSpawn), 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			m_nWave++;
		}

		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= 0.0f && m_nWave == 4)
		{
			for (int nCntSpawn = 0; nCntSpawn < 10; nCntSpawn++)
			{
				for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
				{
					if (m_apObject2D[nCnt] == NULL)
					{
						m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(75.0f * nCntSpawn + (-1000.0f), 300.0f - (25.0f * nCntSpawn), 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0);
						m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

						m_nNumEnemy++;

						break;
					}
				}
			}

			m_nWave++;
		}

		if (CManager::Get()->GetScene()->GetPlayer()->GetPos().x <= -2000.0f && m_nWave == 5)
		{
			CSound::StopSound();
			CSound::PlaySound(CSound::SOUND_LABEL_BGM004);

			for (int nCnt = 0; nCnt < MAX_ENEMY_SPAWN; nCnt++)
			{
				if (m_apObject2D[nCnt] == NULL)
				{
					m_apObject2D[nCnt] = CEnemy::Create(D3DXVECTOR3(-3500.0f, 150.0f, 0.01f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 1);
					m_apObject2D[nCnt]->SetIdxSpawn(nCnt);

					m_nNumEnemy++;

					break;
				}
			}

			m_nWave++;
		}
	}

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