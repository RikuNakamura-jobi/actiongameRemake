//=====================================
//
// renderer�w�b�_�[
// Author:�����@��
//
//=====================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "main.h"

//�}�N����`---------------------------

//�񋓌^��`---------------------------

//�N���X��`---------------------------
class CRenderer
{
public:				//�O������A�N�Z�X�\

	//�R���X�g���N�^�E�f�X�g���N�^
	CRenderer();				//�f�t�H���g
	~CRenderer();

	//�����o�֐�
	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	LPDIRECT3DDEVICE9 GetDevice(void) { return m_pD3DDevice; }

	//�ÓI�����o�֐�

protected:			//�q�Ȃ�A�N�Z�X�\(�g��Ȃ�)

private:			//�O������A�N�Z�X�s�\

	//�����o�֐�

	//�����o�ϐ�
	LPDIRECT3D9 m_pD3D;							//Direct3D�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECT3DDEVICE9 m_pD3DDevice;				//Direct3D�f�o�C�X�ւ̃|�C���^

	//�ÓI�����o�ϐ�

};

//�\���̒�`---------------------------

//�v���g�^�C�v�錾---------------------

#endif // !_RENDERER_H_