//===========================
//
//�_�C���N�gX.main�w�b�_�[
//Author:�����@��
//
//===========================
#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include <time.h>
#include <string.h> 
#include <stdio.h>
#include "d3dx9.h"						//�`�揈���ɕK�v
#define DIRECTINPUT_VERSION (0x0800)	//�r���h���̌x���p�}�N��
#include "dinput.h"						//���͏����ɕK�v
#include "xaudio2.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef true

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define new new
#endif

#endif


//���C�u�����̃����N
#pragma comment(lib, "d3d9.lib")		//�`�揈���ɕK�v
#pragma comment(lib, "d3dx9.lib")		//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib, "dxguid.lib")		//�_�C���N�gX�R���|�[�l���g(���i)�g�p�ɕK�v
#pragma comment(lib, "winmm.lib")		//�V�X�e�������̎擾�ɕK�v
#pragma comment(lib, "dinput8.lib")		//���͏����ɕK�v

//�}�N����`
#define SCREEN_WIDTH (1280)				//�E�B���h�E�̕�
#define SCREEN_HEIGHT (720)				//�E�B���h�E�̍���
#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_DIFFUSE | D3DFVF_TEX1)

//���_���̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;					//���_���W
	float rhw;							//���W�ϊ��p�W��
	D3DCOLOR col;						//���_�J���[
	D3DXVECTOR2 tex;					//�e�N�X�`�����W
}VERTEX_2D;

//���_���[3D]�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;					//���_���W
	D3DXVECTOR3 nor;					//�@���x�N�g��
	D3DCOLOR col;						//���_�J���[
	D3DXVECTOR2 tex;					//�e�N�X�`�����W
}VERTEX_3D;

#endif // !_MAIN_H_