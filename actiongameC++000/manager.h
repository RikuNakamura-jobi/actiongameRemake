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

	//�ÓI�����o�֐�
	static CRenderer *GetRenderer(void) { return m_pRenderer; }

	static CInput *GetInputKeyboard(void) { return m_pInputKeyboard; }

	static CInput *GetInputPad(void) { return m_pInputPad; }

	static CInput *GetInputMouse(void) { return m_pInputMouse; }

	static CLight *GetLight(void) { return m_pLight; }

	static CDebugProc *GetDebugProc(void) { return m_pDebugProc; }

	static CTexture *GetTexture(void) { return m_pTexture; }

	static void SetMode(CScene::MODE mode);
	static CScene::MODE GetMode(void) { return m_pScene->GetMode(); }

	static CScene *GetScene(void) { return m_pScene; }

	void SetFPS(int nCountFPS) { m_nCountFPS = nCountFPS; }

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	int m_nCountFPS;

	//�ÓI�����o�ϐ�
	static CRenderer *m_pRenderer;
	static CInput *m_pInputKeyboard;
	static CInput *m_pInputPad;
	static CInput *m_pInputMouse;
	static CSound *m_pSound;
	static CLight *m_pLight;
	static CDebugProc *m_pDebugProc;
	static CTexture *m_pTexture;
	static CScene *m_pScene;
	static CEnemyManager *m_pEnemyManager;

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_MANAGER_H_