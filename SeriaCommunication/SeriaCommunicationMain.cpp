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

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };
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
END_EVENT_TABLE()
/********************************************//**
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

SeriaCommunicationFrame::SeriaCommunicationFrame(wxFrame *frame): MyFrame2(frame, -1)
{

    /* Constructeur de la classe mère et de la classe fille */
    /* Class mere est generé par wxFormBuilder*/
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
