// FuBeautifyFilter.h
//
// Copyright 2019�� Zego. All rights reserved.
// 

#ifndef FUBeautifyFilter_h__
#define FUBeautifyFilter_h__

#include <vector>

#include "VideoFilterProcessBase.h"

#ifdef WIN32

#include< WinSock2.h> 
#include< WS2tcpip.h> 
#include <windows.h>

#endif

namespace ZEGO
{
    namespace VIDEO_BEAUTY_FILTER
    {

        // fu���սӿ�ʵ��
        class FuBeautifyFilter : public VideoFilterProcessBase
        {
        public:
            FuBeautifyFilter();
            ~FuBeautifyFilter();

            // ��ʼ�������˾�
            virtual bool InitFilter() override;

            // ���մ���YUV I420����
            virtual void FilterProcessI420Data(unsigned char * data, int frame_len, int frame_w, int frame_h) override;

            // �������յȼ�����Χ[0-10]
            virtual bool UpdateFilterLevel(int level) override;

            virtual void FilterProcessRGBAData(unsigned char * data, int frame_len, int frame_w, int frame_h) override;

            virtual void Release() override;

        protected:

            bool InitOpenGL();

            bool InitFuSdk();

            bool LoadFuResource();

            bool inited_ = false;

            int frame_id_ = 0;

            int beauty_handles_ = 0;

            std::vector<int> handles_;

            HGLRC hglrc_ = nullptr;

        };

    }

}

#endif // FUBeautifyFilter_h__

