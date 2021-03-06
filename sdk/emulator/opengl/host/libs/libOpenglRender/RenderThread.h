/*
* Copyright (C) 2011 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef _LIB_OPENGL_RENDER_RENDER_THREAD_H
#define _LIB_OPENGL_RENDER_RENDER_THREAD_H

#include "IOStream.h"
#include "GLDecoder.h"
#include "renderControl_dec.h"
#include "osThread.h"

class RenderThread : public osUtils::Thread
{
public:
    static RenderThread *create(IOStream *p_stream);
    virtual ~RenderThread();
    bool isFinished() const { return m_finished; }

private:
    RenderThread();
    virtual int Main();

private:
    IOStream *m_stream;
    renderControl_decoder_context_t m_rcDec;
    bool m_finished;
};

#endif
