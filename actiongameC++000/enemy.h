//=====================================
//
// enemy�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "main.h"
#include "objectX.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CLockon;
class CEnemy : public CObjectX
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemy(int nPriority);				//�f�t�H���g
	~CEnemy();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetModel(MODELX model) { m_modelTemp = model; }
	MODELX *GetModel(void) { return &m_modelTemp; }

	void SetLockon(void);
	CLockon *GetLockon(void) { return m_lockon; }

	void Damage(int damage) { m_nLife -= damage; }
	int GetLife(void) { return m_nLife; }

	void SetIdxSpawn(int idx){ m_nIdxSpawn = idx; }

	//�ÓI�����o�֐�
	static CEnemy *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight, int nWave);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	int m_nCounter;											//�s���J�E���^�[
	int m_nPattern;											//�s���p�^�[��No.
	int m_nWave;
	int m_nLife;
	int m_nIdxSpawn;
	CLockon *m_lockon;

	MODELX m_modelTemp;

	//�ÓI�����o�ϐ�
	static MODELX m_model;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_ENEMY_H_