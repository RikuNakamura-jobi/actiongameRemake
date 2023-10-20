//=====================================
//
// bullet�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _BULLET_H_
#define _BULLET_H_

#include "main.h"
#include "objectX.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class COrbit;
class CLockon;
class CBullet : public CObjectX
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CBullet(int nPriority);				//�f�t�H���g
	~CBullet();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetModel(MODELX model) { m_modelTemp = model; }
	MODELX *GetModel(void) { return &m_modelTemp; }

	//�ÓI�����o�֐�
	static CBullet *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 rot, int nWave, int nSpawn, float fWidth, float fHeight, int nLife);

	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�
	void Reflect(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *rot, D3DXVECTOR3 *move, D3DXVECTOR3 posWall1, D3DXVECTOR3 posWall2);
	bool Collision(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *move, D3DXVECTOR3 *rot);

	//�����o�ϐ�
	int m_nLife;
	int m_nWave;
	int m_nSpawn;
	float m_pow;
	MODELX m_modelTemp;
	COrbit *m_orbit;

	//�ÓI�����o�ϐ�
	static MODELX m_model;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_BULLET_H_