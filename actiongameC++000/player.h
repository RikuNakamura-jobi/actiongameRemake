//=====================================
//
// player�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"
#include "objectX.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CModel;
class CMotion;
class CPlayer : public CObject
{
public:				//�O������A�N�Z�X�\

	typedef enum
	{
		MOTION_NORMAL = 0,			//�ҋ@���[�V����
		MOTION_SHOT,				//�ҋ@���[�V����
		MOTION_MOVE,				//�ړ����[�V����
		MOTION_MOVE_SHOT,			//�A�N�V�������[�V����
		MOTION_MOVE_SHOT_BACK,		//�A�N�V�������[�V����
		MOTION_MOVE_SHOT_R,			//�A�N�V�������[�V����
		MOTION_MOVE_SHOT_L,			//�A�N�V�������[�V����
		MOTION_JUMP,				//�W�����v���[�V����
		MOTION_JUMP_SHOT,			//���n���[�V����
		MOTION_KICK,				//�󒆃��[�V����
		MOTION_MAX
	}MOTION;

	typedef enum
	{
		TYPE_NORMAL = 0,		//�ʏ�
		TYPE_SAVEDATA,
		TYPE_MAX
	}TYPE;

	typedef enum
	{
		STATE_NORMAL = 0,		//�ʏ�
		STATE_KICK,
		STATE_HIT,
		STATE_DAMAGE,
		STATE_MAX
	}STATE;

	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayer(int nPriority);				//�f�t�H���g
	~CPlayer();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight);

	//�ʒu
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	//�O�̈ʒu
	void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
	D3DXVECTOR3 GetPosOld(void) { return m_posOld; }

	//�ړ���
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }

	//�p�x
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	void SetSave(bool save) { m_bSave = save; }
	bool GetSave(void) { return m_bSave; }

	void SetSaveType(TYPE save) { m_Type = save; }
	TYPE GetSaveType(void) { return m_Type; }

	CModel *GetModel(int nIdx) { return m_apModel[nIdx]; }

	void SetSave(CPlayer *pPlayerSave);
	void GetSave(CPlayer *pPlayerSave);

	//�ÓI�����o�֐�
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, TYPE type);
	static HRESULT Load(void);
	static void Unload(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�
	bool Collision(D3DXVECTOR3 *pos, D3DXVECTOR3 *move);
	void SetRot(D3DXVECTOR3 *rot);
	void Easter(void);
	void Control(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *rot, D3DXVECTOR3 *move, float *fHeight, float *fWidth);
	void ControlPad(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *rot, D3DXVECTOR3 *move, float *fHeight, float *fWidth);
	void ControlMotion(D3DXVECTOR3 move);

	static void ReadFilePlayer(void);

	//�����o�ϐ�
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_rotDest;
	D3DXVECTOR3 m_rotMove;
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	CModel *m_apModel[32];
	CMotion *m_pMotion;
	TYPE m_Type;
	STATE m_state;

	bool m_bSave;
	bool m_bAir;
	bool m_bShot;
	int m_nEasterTimer;
	int m_nShotTimer;
	int m_nCombo;

	//�ÓI�����o�ϐ� 
	static int m_nNumModel;
	static CModel *m_apModelOrigin[32];
	static CModel *m_apModelSave[32];
	static CMotion *m_pMotionOrigin;
	static CMotion *m_pMotionSave;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_PLAYER_H_