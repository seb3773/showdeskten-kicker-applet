#include <tdeglobal.h>
#include <tdelocale.h>
#include <tdeapplication.h>
#include <tqpixmap.h> 
#include <tqimage.h>
#include "showdeskten_applet.h"
#include <dcopclient.h>


showdeskten_applet::showdeskten_applet(const TQString& configFile, Type type, int actions, TQWidget *parent, const char *name)
    : KPanelApplet(configFile, type, actions, parent, name)
{
    TQPixmap icon("/opt/trinity/share/apps/kicker/pics/showdesk10.png");

    m_iconLabel = new TQLabel(this);
    m_iconLabel->setBackgroundOrigin(AncestorOrigin);
    m_iconLabel->setPixmap(icon);
    m_iconLabel->setAlignment(TQt::AlignCenter);
    m_iconLabel->setGeometry(0, 0, icon.width(), icon.height());
    m_iconLabel->installEventFilter(this);
    
    setFixedSize(icon.width(), icon.height());

    if (!kapp->dcopClient()->isAttached())
        kapp->dcopClient()->attach();

    mainView = m_iconLabel;
    mainView->show();
}

showdeskten_applet::~showdeskten_applet()
{
}

bool showdeskten_applet::eventFilter(TQObject *obj, TQEvent *event)
{
    if (obj == mainView && event->type() == TQEvent::MouseButtonRelease) {
        iconClicked();
        return true;
    }
    return KPanelApplet::eventFilter(obj, event);
}

void showdeskten_applet::iconClicked()
{
    TQCString appname("kdesktop");
    int kicker_screen_number = tqt_xscreen();
    if (kicker_screen_number)
        appname.sprintf("kdesktop-screen-%d", kicker_screen_number);
    kapp->dcopClient()->send(appname, "KDesktopIface", "toggleShowDesktop()", TQString(""));

   // KRun::runCommand("dcop kdesktop KDesktopIface toggleShowDesktop");
}

int showdeskten_applet::widthForHeight(int height) const
{
    return width();
}

int showdeskten_applet::heightForWidth(int width) const
{
    return height();
}

void showdeskten_applet::resizeEvent(TQResizeEvent *e)
{
}

extern "C"
{
    KPanelApplet* init(TQWidget *parent, const TQString& configFile)
    {
        TDEGlobal::locale()->insertCatalogue("showdeskten_applet");
        return new showdeskten_applet(configFile, KPanelApplet::Normal, 0, parent, "showdeskten_applet");
    }
}