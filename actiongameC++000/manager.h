//=====================================
//
// manager�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "main.h"
#include "scene.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CRenderer;
class CInput;
class CSound;
class CCamera;
class CLight;
class CDebugProc;
class CTexture;
class CPlayer;
class CObject3D;
class CEnemyManager;
class CManager
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CManager();				//�f�t�H���g
	~CManager();

	//�����o�֐�
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	CRenderer *GetRenderer(void) { return m_pRenderer; }

	CInput *GetInputKeyboard(void) { return m_pInputKeyboard; }

	CInput *GetInputPad(void) { return m_pInputPad; }

	CInput *GetInputMouse(void) { return m_pInputMouse; }

	CLight *GetLight(void) { return m_pLight; }

	CDebugProc *GetDebugProc(void) { return m_pDebugProc; }

	CTexture *GetTexture(void) { return m_pTexture; }

	void SetMode(CScene::MODE mode);
	CScene::MODE GetMode(void) { return m_pScene->GetMode(); }

	CScene *GetScene(void) { return m_pScene; }

	void SetFPS(int nCountFPS) { m_nCountFPS = nCountFPS; }

	//�ÓI�����o�֐�
	static CManager *Get(void);
	static HRESULT Release(void);

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	CRenderer *m_pRenderer;
	CInput *m_pInputKeyboard;
	CInput *m_pInputPad;
	CInput *m_pInputMouse;
	CSound *m_pSound;
	CLight *m_pLight;
	CDebugProc *m_pDebugProc;
	CTexture *m_pTexture;
	CScene *m_pScene;
	CEnemyManager *m_pEnemyManager;
	int m_nCountFPS;

	//�ÓI�����o�ϐ�
	static CManager *pManager;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_MANAGER_H_