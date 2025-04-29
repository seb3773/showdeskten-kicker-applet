#ifndef SHOWDESKTEN_APPLET_H
#define SHOWDESKTEN_APPLET_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kpanelapplet.h>
#include <tqstring.h>
#include <tqlabel.h>

class showdeskten_applet : public KPanelApplet
{
    TQ_OBJECT

public:
    showdeskten_applet(const TQString& configFile, Type t = Normal, int actions = 0, TQWidget *parent = 0, const char *name = 0);
    ~showdeskten_applet();

    virtual int widthForHeight(int height) const;
    virtual int heightForWidth(int width) const;

protected:
    void resizeEvent(TQResizeEvent *);
    bool eventFilter(TQObject *obj, TQEvent *event);

private slots:
    void iconClicked();

private:
    TDEConfig *ksConfig;
    TQWidget *mainView;
    TQLabel *m_iconLabel;
};

#endif