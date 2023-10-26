//=====================================
//
// bgmulti�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _SKY_H_
#define _SKY_H_

#include "main.h"
#include "object.h"

//�}�N����`---------------------------
#define MAX_SKY (5)						//���d�X�N���[���p�w�i�̍ő吔
#define SKY_LENGTH (20000.0f)			//���d�X�N���[���p�w�i�̍ő吔

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CObject3D;
class CSky : public CObject
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CSky(int nPriority);				//�f�t�H���g
	virtual ~CSky();

	//�����o�֐�
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	void SetPos(D3DXVECTOR3 pos){ m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	void SetWidth(float fWidth) { m_fWidth = fWidth; }
	float GetWidth(void) { return m_fWidth; }
	void SetHeight(float fHeight) { m_fHeight = fHeight; }
	float GetHeight(void) { return m_fHeight; }

	//�ÓI�����o�֐�
	static CSky *Create(void);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	CObject3D *m_apObject3D[MAX_SKY];
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	float m_fWidth;
	float m_fHeight;

	//�ÓI�����o�ϐ�
	static LPDIRECT3DTEXTURE9 m_pTexture[MAX_SKY];		//�e�N�X�`���ւ̃|�C���^
	static const char *m_apFilename[MAX_SKY];			//�e�N�X�`���̖��O

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_SKY_H_