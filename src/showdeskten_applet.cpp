#include <tdeglobal.h>
#include <tdelocale.h>
#include <tdeapplication.h>
#include <tqpixmap.h> 
#include "showdeskten_applet.h"
#include <tqpushbutton.h>
#include <krun.h>

showdeskten_applet::showdeskten_applet(const TQString& configFile, Type type, int actions, TQWidget *parent, const char *name)
    : KPanelApplet(configFile, type, actions, parent, name)
{


    TQPixmap icon("/opt/trinity/share/apps/kicker/pics/showdesk10.png");
    TQPushButton *iconButton = new TQPushButton("", this);
    iconButton->setIcon(icon);
    iconButton->setIconSet(icon);
    iconButton->setFixedSize(icon.size() + TQSize(2, 2));
    setFixedSize(icon.size().width(), icon.size().height());

    connect(iconButton, SIGNAL(clicked()), this, SLOT(iconClicked()));
    mainView = iconButton;
    mainView->show();
}




showdeskten_applet::~showdeskten_applet()
{
}

void showdeskten_applet::iconClicked()
{
    KRun::runCommand("dcop kdesktop KDesktopIface toggleShowDesktop");
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
    KPanelApplet* init( TQWidget *parent, const TQString& configFile)
    {
        TDEGlobal::locale()->insertCatalogue("showdeskten_applet");
        return new showdeskten_applet(configFile, KPanelApplet::Normal, 0, parent, "showdeskten_applet");
    }
}
