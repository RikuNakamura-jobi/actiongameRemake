//=============================================================================
//
// �T�E���h���� [sound.h]
// Author :������
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//�T�E���h�N���X
class CSound
{
public:

	// �T�E���h�ꗗ
	typedef enum
	{
		SOUND_LABEL_BGM000 = 0,			// BGM0
		SOUND_LABEL_BGM001,				// BGM0
		SOUND_LABEL_BGM002,				// BGM0
		SOUND_LABEL_BGM003,				// BGM0
		SOUND_LABEL_BGM004,				// BGM0
		SOUND_LABEL_BGM005,				// BGM0
		SOUND_LABEL_SE_SHOT000,			// �e���ˉ�1
		SOUND_LABEL_SE_SCORE,			// �e���ˉ�1
		SOUND_LABEL_SE_YES,				// �e���ˉ�1
		SOUND_LABEL_SE_DAMAGE,			// �e���ˉ�1
		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	// �T�E���h���̍\���̒�`
	typedef struct
	{
		char *pFilename;	// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g
	} SOUNDINFO;

	CSound();
	~CSound();

	//�����o�֐�
	HRESULT Init(HWND hWnd);
	void Uninit(void);

	//�ÓI�����o�֐�
	static HRESULT PlaySound(SOUND_LABEL label);
	static void StopSound(SOUND_LABEL label);
	static void StopSound(void);

private:

	

	//�����o�֐�
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	//�����o�ϐ�
	IXAudio2 *m_pXAudio2;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice;			// �}�X�^�[�{�C�X

	//�ÓI�����o�ϐ�
	static SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX];
	static IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX];	// �\�[�X�{�C�X
	static BYTE *m_apDataAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^
	static DWORD m_aSizeAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^�T�C�Y
};

#endif
