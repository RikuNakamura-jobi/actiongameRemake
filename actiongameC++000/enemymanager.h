//=====================================
//
// enemymanager�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _ENEMYMANAGER_H_
#define _ENEMYMANAGER_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------
#define MAX_ENEMY_WAVE (1)			//���d�X�N���[���p�w�i�̍ő吔
#define MAX_ENEMY_SPAWN (36)			//���d�X�N���[���p�w�i�̍ő吔

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CEnemy;
class CEnemySpawn
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemySpawn(int nPriority);				//�f�t�H���g
	virtual ~CEnemySpawn();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual int Update(void);
	virtual void Draw(void);

	void addNumEnemy(int nNumEnemy) { m_nNumEnemy += nNumEnemy; }
	int GetNumEnemy(void) { return m_nNumEnemy; }

	CEnemy *GetEnemy(int nIdxEnemy) { return m_apObject2D[nIdxEnemy]; }
	void SetEnemy(int nIdxEnemy, CEnemy *enemy) { m_apObject2D[nIdxEnemy] = enemy; }

	//�ÓI�����o�֐�
	static CEnemySpawn *Create(int nWave, int nEnemySpaen);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	CEnemy *m_apObject2D[MAX_ENEMY_SPAWN];
	int m_nNumEnemy;
	int m_nWave;

	//�ÓI�����o�ϐ�

};

class CEnemyManager
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyManager(int nPriority);				//�f�t�H���g
	virtual ~CEnemyManager();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	CEnemySpawn *GetEnemyWave(int nWave) { return m_apEnemyWave[nWave]; }

	//�ÓI�����o�֐�
	static CEnemyManager *Create(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	CEnemySpawn *m_apEnemyWave[MAX_ENEMY_WAVE];

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_ENEMYMANAGER_H_