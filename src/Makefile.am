INCLUDES= $(all_includes)
METASOURCES = AUTO

kde_module_LTLIBRARIES = showdeskten_applet_panelapplet.la

showdeskten_applet_panelapplet_la_SOURCES = showdeskten_applet.cpp
showdeskten_applet_panelapplet_la_LDFLAGS = -module -avoid-version $(all_libraries) $(LIB_TQT) $(LIB_TDECORE) $(LIB_TDEUI) $(LIB_TDEPARTS)
showdeskten_applet_panelapplet_la_LIBADD = $(LIB_TDEUI) 

showdeskten_applet_DATA = showdeskten_applet.desktop
showdeskten_appletdir = $(kde_datadir)/kicker/applets

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/showdeskten_applet.pot
