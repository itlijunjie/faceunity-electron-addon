//
// NodeMessageLoop.h
//
// Copyright 2018�� Zego. All rights reserved.
//

#ifndef NodeMessageLoop_h__
#define NodeMessageLoop_h__

#include <mutex>
#include <string>
#include <nan.h>


namespace ZEGO
{
    namespace VIDEO_BEAUTY_FILTER
    {
        using std::string;


        typedef struct EventMsgInfo
        {
            // �������߳��ж��壬��uv�¼�ѭ���е���
            std::function<void()> get_data_and_notify_node_fun;

        } EventMsgInfo;


        class JSMessageLoop
        {
        public:
            static JSMessageLoop * Instance()
            {
                static JSMessageLoop n;
                return &n;
            }

            static NAUV_WORK_CB(MessageLoopProcess);

            void PostAsyncEventMsg(const EventMsgInfo& msg_info);

        private:
            JSMessageLoop();
            ~JSMessageLoop();

            std::mutex            msg_vec_mutex_;
            uv_async_t *          uv_async_;
            std::queue<EventMsgInfo> async_event_queue_;
        };

#define JSMessageLoopInstance JSMessageLoop::Instance

    }
}
#endif // NodeMessageLoop_h__

