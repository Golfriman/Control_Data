QT -= gui
QT += core network sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        authorization.cpp \
        booking.cpp \
        checkin.cpp \
        command.cpp \
        employee.cpp \
        main.cpp \
        mainmenu.cpp \
        report.cpp \
        rooms.cpp \
        server.cpp \
        settings.cpp \
        signup.cpp \
        sqlworker.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    authorization.h \
    booking.h \
    checkin.h \
    command.h \
    employee.h \
    mainmenu.h \
    report.h \
    rooms.h \
    server.h \
    settings.h \
    signup.h \
    ..\const.h \
    sqlworker.h

RESOURCES +=

win32:RC_FILE = icon.rc
