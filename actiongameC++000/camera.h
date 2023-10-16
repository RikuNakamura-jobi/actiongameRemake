//=============================================================================
//
// �T�E���h���� [camera.h]
// Author :������
//
//=============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "main.h"

class CCamera
{
public:

	CCamera();
	~CCamera();

	//�����o�֐�
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Set(void);

	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	D3DXVECTOR3 GetPosV(void) { return m_posV; }
	D3DXVECTOR3 GetPosR(void) { return m_posR; }

	D3DXVECTOR3 GetPosVDest(void) { return m_posVDest; }
	D3DXVECTOR3 GetPosRDest(void) { return m_posRDest; }

	void Setzrot(D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }

	//�ÓI�����o�֐�

private:

	//�����o�֐�
	void Rot(void);

	//�����o�ϐ�
	D3DXMATRIX m_mtxProjection;	//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX m_mtxView;			//�r���[�}�g���b�N�X

	D3DXVECTOR3 m_posV;			//���_
	D3DXVECTOR3 m_posR;			//�����_
	D3DXVECTOR3 m_posVDest;		//�ړI�̎��_
	D3DXVECTOR3 m_posRDest;		//�ړI�̒����_
	D3DXVECTOR3 m_posVOld;		//�ړI�̎��_
	D3DXVECTOR3 m_posROld;		//�ړI�̒����_
	D3DXVECTOR3 m_vecU;			//������x�N�g��
	D3DXVECTOR3 m_pos;			//�p�x
	D3DXVECTOR3 m_rot;			//�p�x
	D3DXVECTOR3 m_rotOld;		//�p�x

	//�ÓI�����o�ϐ�

};

#endif // !_CAMERA_H_
