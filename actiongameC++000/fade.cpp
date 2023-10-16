//=====================================
//
// 
// Author:������
//
//=====================================
#include "fade.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

//�ÓI�����o�ϐ��錾-------------------
LPDIRECT3DTEXTURE9 CFade::m_pTexture[TYPE_MAX] = {};
CFade::STATE CFade::m_state = STATE_NONE;
const char *CFade::m_apFilename[TYPE_MAX] =
{
	"data\\TEXTURE\\fade002.png",
	"data\\TEXTURE\\fade002.png",
	"data\\TEXTURE\\fade003.jpg",
	"data\\TEXTURE\\fade003.jpg",
	"data\\TEXTURE\\fade003.jpg",
	"data\\TEXTURE\\fade001.png",
};

//=====================================
// �R���X�g���N�^�E�f�X�g���N�^
//=====================================
CFade::CFade(int nPriority = 7) : CObject2D(nPriority)
{
	m_timer = 0;
}

CFade::~CFade()
{
}

//=====================================
// ��������
//=====================================
CFade *CFade::Create(TYPE type, CScene::MODE mode)
{
	CFade *pObjectFade = NULL;

	if (m_state == STATE_NONE)
	{
		//2D�I�u�W�F�N�g�̐���
		pObjectFade = new CFade();

		if (pObjectFade != NULL)
		{
			//������
			if (FAILED(pObjectFade->Init()))
			{
				pObjectFade->Release();
			}

			D3DXVECTOR2 *texPos = NULL;

			texPos = pObjectFade->GetTexPos();

			pObjectFade->Set(D3DXVECTOR3(640.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1280.0f, 720.0f);

			if (type == TYPE_SLIDE)
			{
				texPos[0] = D3DXVECTOR2(1.0f, 0.0f);
				texPos[1] = D3DXVECTOR2(1.0f, 0.0f);
				texPos[2] = D3DXVECTOR2(1.0f, 1.0f);
				texPos[3] = D3DXVECTOR2(1.0f, 1.0f);

				pObjectFade->SetPos(D3DXVECTOR3(1280.0f, 360.0f, 0.0f));
				pObjectFade->SetWidth(0.0f);
			}

			if (type == TYPE_CURTAIN)
			{
				pObjectFade->SetPos(D3DXVECTOR3(0.0f, 360.0f, 0.0f));
				pObjectFade->SetWidth(0.0f);
			}

			if (type == TYPE_CURTAIN_L)
			{
				pObjectFade->SetPos(D3DXVECTOR3(0.0f, 360.0f, 0.0f));
				pObjectFade->SetWidth(0.0f);
			}

			if (type == TYPE_CURTAIN_R)
			{
				pObjectFade->SetPos(D3DXVECTOR3(1280.0f, 360.0f, 0.0f));
				pObjectFade->SetWidth(0.0f);
			}

			if (type == TYPE_OUT)
			{
				pObjectFade->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
			}

			pObjectFade->BindTexture(m_pTexture[type]);
			pObjectFade->m_type = type;

			pObjectFade->m_modeNext = mode;

			if (type != TYPE_CURTAIN_R)
			{
				m_state = STATE_OUT;
			}
		}
	}

	return pObjectFade;
}

//=====================================
// �|���S���̃e�N�X�`������
//=====================================
HRESULT CFade::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::Get()->GetRenderer()->GetDevice();

	for (int nCntFade = 0; nCntFade < TYPE_MAX; nCntFade++)
	{
		//�e�N�X�`���̓ǂݍ���
		if (FAILED(D3DXCreateTextureFromFile(pDevice,
			m_apFilename[nCntFade],
			&m_pTexture[nCntFade])))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}
void CFade::Unload(void)
{
	for (int nCntFade = 0; nCntFade < TYPE_MAX; nCntFade++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nCntFade] != NULL)
		{
			m_pTexture[nCntFade]->Release();
			m_pTexture[nCntFade] = NULL;
		}
	}
}

//=====================================
// �|���S���̏���������
//=====================================
HRESULT CFade::Init(void)
{
	CObject2D::Init();

	SetType(TYPE_FADE);

	return S_OK;
}

//=====================================
// �|���S���̏I������
//=====================================
void CFade::Uninit(void)
{
	CObject2D::Uninit();
}

//=====================================
// �|���S���̍X�V����
//=====================================
void CFade::Update(void)
{
	D3DXVECTOR2 *texPos = NULL;
	D3DXCOLOR color = GetCol();
	D3DXVECTOR3 pos = GetPos();
	float width = GetWidth();

	texPos = GetTexPos();

	if (m_state != STATE_NONE)
	{
		if (m_state == STATE_IN)
		{//�t�F�[�h�C��

			if (m_type == TYPE_SLIDE)
			{
				texPos[1].x -= SLIDE_SPEED;
				texPos[3].x -= SLIDE_SPEED;

				pos.x -= SLIDE_SPEED * 640.0f;
				width -= SLIDE_SPEED * 1280.0f;

				if (pos.x <= 0.0f)
				{
					width = 0.0f;
					color.a = 0.0f;
					m_state = STATE_NONE;

					SetPos(pos);
					SetWidth(width);
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN)
			{
				pos.x -= SLIDE_SPEED * 640.0f;
				width -= SLIDE_SPEED * 1280.0f;

				if (pos.x <= 0.0f)
				{
					width = 0.0f;
					color.a = 0.0f;
					m_state = STATE_NONE;

					SetPos(pos);
					SetWidth(width);
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN_L)
			{
				pos.x -= SLIDE_SPEED * 320.0f;
				width -= SLIDE_SPEED * 640.0f;

				if (pos.x <= 0.0f)
				{
					width = 0.0f;
					color.a = 0.0f;

					SetPos(pos);
					SetWidth(width);
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN_R)
			{
				pos.x += SLIDE_SPEED * 320.0f;
				width -= SLIDE_SPEED * 640.0f;

				if (pos.x >= 1280.0f)
				{
					width = 0.0f;
					color.a = 0.0f;
					m_state = STATE_NONE;

					SetPos(pos);
					SetWidth(width);
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_OUT)
			{
				color.a -= 0.05f;

				if (color.a <= 0.0f)
				{
					color.a = 0.0f;
					m_state = STATE_NONE;
				}

				SetCol(color);
			}
		}
		else if (m_state == STATE_OUT)
		{//�t�F�[�h�A�E�g

			if (m_type == TYPE_SLIDE)
			{
				texPos[0].x -= SLIDE_SPEED;
				texPos[2].x -= SLIDE_SPEED;

				pos.x -= SLIDE_SPEED * 640.0f;
				width += SLIDE_SPEED * 1280.0f;

				if (pos.x < 640.0f)
				{
					if (m_timer == 10)
					{
						CManager::Get()->GetScene()->SetbFade(true);
					}

					texPos[0].x = 0.0f;
					texPos[2].x = 0.0f;
					pos.x = 640.0f;
					width = 1280.0f;
					color.a = 1.0f;
					m_timer++;

					if (m_timer >= 70)
					{
						m_state = STATE_IN;
						m_timer = 0;
					}
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN)
			{
				pos.x += SLIDE_SPEED * 640.0f;
				width += SLIDE_SPEED * 1280.0f;

				if (pos.x >= 640.0f)
				{
					if (m_timer == 10)
					{
						CManager::Get()->GetScene()->SetbFade(true);
					}

					pos.x = 640.0f;
					width = 1280.0f;
					color.a = 1.0f;
					m_timer++;

					if (m_timer >= 70)
					{
						m_state = STATE_IN;
						m_timer = 0;
					}
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN_L)
			{
				pos.x += SLIDE_SPEED * 320.0f;
				width += SLIDE_SPEED * 640.0f;

				if (pos.x >= 320.0f)
				{
					if (m_timer == 10)
					{

					}

					pos.x = 320.0f;
					width = 640.0f;
					color.a = 1.0f;
					m_timer++;

					if (m_timer >= 70)
					{
						m_state = STATE_IN;
						m_timer = 0;
					}
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_CURTAIN_R)
			{
				pos.x -= SLIDE_SPEED * 320.0f;
				width += SLIDE_SPEED * 640.0f;

				if (pos.x <= 960.0f)
				{
					if (m_timer == 10)
					{
						CManager::Get()->GetScene()->SetbFade(true);
					}

					pos.x = 960.0f;
					width = 640.0f;
					color.a = 1.0f;
					m_timer++;

					if (m_timer >= 70)
					{
						m_timer = 0;
					}
				}

				SetPos(pos);
				SetWidth(width);
			}

			if (m_type == TYPE_OUT)
			{
				color.a += 0.03f;

				if (color.a > 1.0f)
				{
					color.a = 1.0f;
					CManager::Get()->GetScene()->SetbFade(true);
					m_state = STATE_IN;
				}

				SetCol(color);
			}
		}

		CObject2D::Update();
	}
	else
	{
		Uninit();
	}
}

//=====================================
// �|���S���̕`�揈��
//=====================================
void CFade::Draw(void)
{
	CObject2D::Draw();
}