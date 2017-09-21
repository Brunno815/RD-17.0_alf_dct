/* The copyright in this software is being made available under the BSD
* License, included below. This software may be subject to other third party
* and contributor rights, including patent rights, and no such rights are
* granted under this license.
*
* Copyright (c) 2002-2016, Audio Video coding Standard Workgroup of China
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  * Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*  * Neither the name of Audio Video coding Standard Workgroup of China
*    nor the names of its contributors maybe used to endorse or promote products
*    derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
*************************************************************************************
* File name: wquant.h
* Function:  Frequency Weighting Quantization,include
*               a). Frequency weighting model, quantization
*               b). Picture level user-defined frequency weighting
*               c). Macroblock level adaptive frequency weighting mode Decision
*            According to adopted proposals: m1878,m2148,m2331
* Author:    Jianhua Zheng, Hisilicon
*            Xiaozhen Zheng,Hisilicon
*************************************************************************************
*/


#ifndef _WEIGHT_QUANT_H_
#define _WEIGHT_QUANT_H_

#define PARAM_NUM  6
#define WQ_MODEL_NUM 3
#define SCENE_MODE_NUM 4

#define UNDETAILED 0
#define DETAILED   1

#define WQ_MODE_F  0  //M2331 2008-04
#define WQ_MODE_U  1  //M2331 2008-04
#define WQ_MODE_D  2  //M2331 2008-04

#define FRAME_WQ_DEFAULT    0
#define USER_DEF_UNDETAILED 1
#define USER_DEF_DETAILED   2
#define USER_DEF_BOTH       3

#define LAMBDA_MODE_OPT     1


extern int ** *LevelScale4x4;
extern int ** *LevelScale8x8;
extern int ** *LevelScale16x16;
extern int ** *LevelScale32x32;



extern int WeightQuantEnable;


extern short UseDefaultScalingMatrixFlag[2];


void Init_QMatrix(void);
void CalculateQuantParam();
void free_QMatrix();


void InitFrameQuantParam();
void GetUserDefParam(char *, int);
void FrameUpdateWQMatrix();


void InitSeqQuantParam();

void MBUpdateWQMatrix();               //M2331 2008-04

void GetDefaultWQM(int, int *);
void GetUserDefWQM(char *, int, int *);

extern int cur_frame_wq_param;  // 7.2.3.1 weighting_quant_param
extern int cur_frame_wq_model;  // 7.2.3.1 weighting_quant_model
extern int cur_picture_scene_model;

extern short cur_wq_matrix[4][64];
extern short wq_matrix[2][2][64];
extern short seq_wq_matrix[2][64];
extern short pic_user_wq_matrix[2][64];

extern int ScaleM[4][4];

extern short wq_param[2][6];

extern short wq_param_default[2][6];

extern int g_WqMDefault4x4[16];
extern int g_WqMDefault8x8[64];


static const int LambdaQPTab[3][3] = {       //M2331 2008-04
//      F   U   D
    0,  0, -2,
    -2, -1,  0,
    -1,  0,  0
};


static const  double LambdaFTab[3][3] = {    //M2331 2008-04
    //  F     U     D
    0.68, 0.70, 0.60,
    0.62, 0.68, 0.60,
    0.62, 0.70, 0.85
};


static const unsigned char WeightQuantModel[4][64] = {
//   l a b c d h
//   0 1 2 3 4 5
    {
        // Mode 0
        0, 0, 0, 4, 4, 4, 5, 5,
        0, 0, 3, 3, 3, 3, 5, 5,
        0, 3, 2, 2, 1, 1, 5, 5,
        4, 3, 2, 2, 1, 5, 5, 5,
        4, 3, 1, 1, 5, 5, 5, 5,
        4, 3, 1, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5
    },
    {
        // Mode 1
        0, 0, 0, 4, 4, 4, 5, 5,
        0, 0, 4, 4, 4, 4, 5, 5,
        0, 3, 2, 2, 2, 1, 5, 5,
        3, 3, 2, 2, 1, 5, 5, 5,
        3, 3, 2, 1, 5, 5, 5, 5,
        3, 3, 1, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5
    },
    {
        // Mode 2
        0, 0, 0, 4, 4, 3, 5, 5,
        0, 0, 4, 4, 3, 2, 5, 5,
        0, 4, 4, 3, 2, 1, 5, 5,
        4, 4, 3, 2, 1, 5, 5, 5,
        4, 3, 2, 1, 5, 5, 5, 5,
        3, 2, 1, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5
    },
    {
        // Mode 3
        0, 0, 0, 3, 2, 1, 5, 5,
        0, 0, 4, 3, 2, 1, 5, 5,
        0, 4, 4, 3, 2, 1, 5, 5,
        3, 3, 3, 3, 2, 5, 5, 5,
        2, 2, 2, 2, 5, 5, 5, 5,
        1, 1, 1, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5
    }
};

static const unsigned char WeightQuantModel4x4[4][16] = {
    //   l a b c d h
    //   0 1 2 3 4 5
    {
        // Mode 0
        0, 4, 3, 5,
        4, 2, 1, 5,
        3, 1, 1, 5,
        5, 5, 5, 5
    },
    {
        // Mode 1
        0, 4, 4, 5,
        3, 2, 2, 5,
        3, 2, 1, 5,
        5, 5, 5, 5
    },
    {
        // Mode 2
        0, 4, 3, 5,
        4, 3, 2, 5,
        3, 2, 1, 5,
        5, 5, 5, 5
    },
    {
        // Mode 3
        0, 3, 1, 5,
        3, 4, 2, 5,
        1, 2, 2, 5,
        5, 5, 5, 5
    }
};

static const unsigned char WQMType[2][10] = {
    "WQM_4X4",
    "WQM_8X8",
};

#endif