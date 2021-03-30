/***************************************************************
 * Name:      SeriaCommunicationMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tarik (tarik semrade)
 * Created:   2021-03-29
 * Copyright: Tarik ()
 * License:
 **************************************************************/

#ifndef SERIACOMMUNICATIONMAIN_H
#define SERIACOMMUNICATIONMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "SeriaCommunicationApp.h"
#include "MainFrame.h"

class SeriaCommunicationFrame: public MyFrame2
{
    public:
        SeriaCommunicationFrame(wxFrame *frame);
        ~SeriaCommunicationFrame();
    private:
        enum
        {

        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // SERIACOMMUNICATIONMAIN_H
