//=====================================
//
// 
// Author:������
//
//=====================================
#include "particle.h"
#include "renderer.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "effect.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CParticle::CParticle(int nPriority = 2) : CObjectBillboard(nPriority)
{
	m_nLife = 0; 
	m_nLifePtcl = 0;
	m_nNumEffect = 0;
	m_nSpeed = 0;
}

CParticle::~CParticle()
{
}

//=====================================
// ��������
//=====================================
CParticle *CParticle::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col, int nLife, int nLifePtcl, int nNumEffect, int nSpeed, float fWidth, float fHeight)
{
	CParticle *pObjectEffect;

	//2D�I�u�W�F�N�g�̐���
	pObjectEffect = new CParticle();

	if (pObjectEffect != NULL)
	{
		//������
		if (FAILED(pObjectEffect->Init()))
		{
			pObjectEffect->Release();

			return NULL;
		}

		pObjectEffect->Set(pos, rot, fWidth, fHeight);
		pObjectEffect->SetCol(col);
		pObjectEffect->m_nLife = nLife;
		pObjectEffect->m_nLifePtcl = nLifePtcl;
		pObjectEffect->m_nSpeed = nSpeed;
		pObjectEffect->m_nNumEffect = nNumEffect;
	}

	return pObjectEffect;
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CParticle::Init(void)
{
	SetType(TYPE_PARTICLE);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CParticle::Uninit(void)
{
	Release();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CParticle::Update(void)
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXVECTOR3 move = GetMove();
	float fHeight = GetHeight();
	float fWidth = GetWidth();

	for (int nCntEf = 0; nCntEf < m_nNumEffect; nCntEf++)
	{
		//�ړ��ʂ����肷��
		D3DXVec3Normalize(&move, &D3DXVECTOR3((float)(rand() % (m_nSpeed * 2) - m_nSpeed), (float)(rand() % (m_nSpeed * 2) - m_nSpeed), (float)(rand() % (m_nSpeed * 2) - m_nSpeed)));

		pos.x = (float)(rand() % 21) + GetPos().x;
		pos.y = (float)(rand() % 21) + GetPos().y;
		pos.z = (float)(rand() % 21) + GetPos().z;

		move.x *= rand() % m_nSpeed;
		move.y *= rand() % m_nSpeed;
		move.z *= rand() % m_nSpeed;

		fHeight = (rand() % 20) * 0.1f + GetHeight();
		fWidth = fHeight;

		CEffect::Create(pos, move, rot, GetCol(), rand() % 60 + m_nLife, fWidth, fHeight);
	}

	//��������
	m_nLifePtcl--;

	if (m_nLifePtcl <= 0)
	{
		//�g�p���Ă��Ȃ���Ԃɂ���
		Uninit();
	}
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CParticle::Draw(void)
{
	
}