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
#include "Tserial.h"

class SeriaCommunicationFrame: public MyFrame2, public Tserial{
    public:
        SeriaCommunicationFrame(wxFrame *frame);
        ~SeriaCommunicationFrame();

    protected:
        void m_button5OnButtonClick( wxCommandEvent& event ) override;
        void m_choice6OnChoice( wxCommandEvent& event ) override;
        void m_choice2OnChoice( wxCommandEvent& event ) override;
		void m_choice3OnChoice( wxCommandEvent& event ) override;
		void m_choice4OnChoice( wxCommandEvent& event ) override;
		void m_choice5OnChoice( wxCommandEvent& event ) override;
    private:
        enum
        {
            idButtonClick = 2000,
            idChoice
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        DECLARE_EVENT_TABLE()
};


#endif // SERIACOMMUNICATIONMAIN_H
