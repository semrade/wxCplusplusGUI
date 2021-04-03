/***************************************************************
 * Name:      SeriaCommunicationMain.cpp
 * Purpose:   Code for Application Frame
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

#include "SeriaCommunicationMain.h"
#include "MainFrame.h"
#include "Tserial.h"
#include <list>
#include <stdlib.h>

using namespace std;
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

bool IsOpen = FALSE;
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

BEGIN_EVENT_TABLE(SeriaCommunicationFrame, wxFrame)
    EVT_CLOSE(SeriaCommunicationFrame::OnClose)
    EVT_MENU(idMenuQuit, SeriaCommunicationFrame::OnQuit)
    EVT_MENU(idMenuAbout, SeriaCommunicationFrame::OnAbout)
    EVT_BUTTON(wxID_OnOpenPort, SeriaCommunicationFrame::m_button5OnButtonClick)
    EVT_CHOICE(wxID_OnPortChoice,SeriaCommunicationFrame::m_choice6OnChoice)
    EVT_CHOICE(wxID_OnBaudRateChoice,SeriaCommunicationFrame::m_choice2OnChoice)
    EVT_CHOICE(wxID_OnParityChoice,SeriaCommunicationFrame::m_choice3OnChoice)
    EVT_CHOICE(wxID_OnData,SeriaCommunicationFrame::m_choice4OnChoice)
    EVT_CHOICE(wxID_OnTwoBits,SeriaCommunicationFrame::m_choice5OnChoice)
END_EVENT_TABLE()
/********************************************//**
 * \briidButtonClickef
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

SeriaCommunicationFrame::SeriaCommunicationFrame(wxFrame *frame): MyFrame2(frame, -1), Tserial()
{

    /* Constructeur de la classe mère et de la classe fille */
    /* Class mere est generé par wxFormBuilder*/

    /** Great the serial port object
        list the PORTS to the wxChoice port object.
    */

    Tserial str;
    std::list<std::string>::iterator ComPortIt;
    for (ComPortIt = str.ComPorts.begin(); ComPortIt != str.ComPorts.end(); ComPortIt++)
    {
        m_choice6->Append(*ComPortIt);
    }
    #if 0
    list<map<string,string>>    :: iterator list_it;
    map<string,string>          :: iterator map_it;

    list_it = str.ComPortsDes.begin();
    map_it  = (*list_it).begin();

    for(; map_it != (*list_it).end(); map_it++)
    {
        m_choice6->Append(map_it->first);
    }
    #endif // 0
    SetStatusText(_("Hello  Serial Communication Interface user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);



}

/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

SeriaCommunicationFrame::~SeriaCommunicationFrame()
{
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/
void SeriaCommunicationFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void SeriaCommunicationFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/


void SeriaCommunicationFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/
void SeriaCommunicationFrame::m_choice6OnChoice( wxCommandEvent& event )
{

    wxString l_sChoice6;
    l_sChoice6 = m_choice6->GetString(m_choice6->GetSelection());
    strncpy(this->port, (const char*)l_sChoice6.mb_str(wxConvUTF8), 1023);
    cout<<"The port chosen si "<<this->port<<endl;
    m_richText2->WriteText(l_sChoice6);

}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

void SeriaCommunicationFrame::m_choice2OnChoice( wxCommandEvent& event )
{
    unsigned l_uBaudRate;
    wxString l_sChoice2;
    l_sChoice2 = m_choice2->GetString(m_choice2->GetSelection());
    this->rate = atoi(l_sChoice2);
    cout<<"The chosen rate is "<<this->rate<<endl;
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

void SeriaCommunicationFrame::m_choice3OnChoice( wxCommandEvent& event )
{
    wxString l_sChoice3;
    l_sChoice3 = m_choice3->GetString(m_choice3->GetSelection());

    if ("Odd" == l_sChoice3 )
    {
        this->parityMode = spODD;
    }
    else if ("Even" == l_sChoice3)
    {
        this->parityMode = spEVEN;
    }
    else
    {
        this->parityMode = spNONE;
    }

    cout<<"The parity chosen si "<<this->parityMode<<endl;
    m_richText2->WriteText(l_sChoice3);
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

void SeriaCommunicationFrame::m_choice4OnChoice( wxCommandEvent& event )
{
    unsigned l_uDataBits;
    wxString l_sChoice4;
    l_sChoice4 = m_choice4->GetString(m_choice4->GetSelection());
    l_uDataBits = atoi(l_sChoice4);
    cout<<"The chosen data bits is "<<l_uDataBits<<endl;
}
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

void SeriaCommunicationFrame::m_choice5OnChoice( wxCommandEvent& event )
{

}

void SeriaCommunicationFrame::m_button5OnButtonClick( wxCommandEvent& event )
{
    if (IsOpen == false)
    {
        this->connect(port, rate, parityMode);
        IsOpen = true;
        m_button5->SetBackgroundColour("Red");
        cout<<"Port :"<<port<<" Baud rate :"<<rate<<" Parity :"<<parityMode<<" is opened"<<endl;
    }
    else
    {
        this->connect(port, rate, parityMode);
        IsOpen = false;
        m_button5->SetBackgroundColour("Green");
        cout<<"Port :"<<port<<" Baud rate :"<<rate<<" Parity :"<<parityMode<<" is closed"<<endl;
    }

}
