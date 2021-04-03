/***************************************************************
 * Name:      SeriaCommunicationApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Tarik (tarik semrade)
 * Created:   2021-03-29
 * Copyright: Tarik ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "SeriaCommunicationApp.h"
#include "SeriaCommunicationMain.h"
#include "MainFrame.h"
IMPLEMENT_APP(SeriaCommunicationApp);
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/


bool SeriaCommunicationApp::OnInit()
{
    SeriaCommunicationFrame* frame = new SeriaCommunicationFrame(0L);
    frame->SetIcon(wxICON(aaaa));
    frame->Show();

    return true;
}



