QT       += core gui network charts printsupport
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    'Form Menu'\Booking\calendar.cpp \
    'Form Authorization'\formauthorization.cpp \
    'Form Menu'\Booking\formbooking.cpp \
    'Form Menu'\\'Check In'\formcheckin.cpp \
    'Form Menu'\Employee\formconcreteemployee.cpp \
    'Form Menu'\Booking\formcreatebooking.cpp \
    'Form Menu'\Employee\formemployee.cpp \
    'Form Menu'\\'Main Menu'\formmainmenu.cpp \
    'Form Menu'\formmenu.cpp \
    'Form Menu'\Report\formreport.cpp \
    'Form Menu'\Rooms\formrooms.cpp \
    'Form Menu'\Settings\formsettings.cpp \
    'Form Menu'\\'Sign Up'\formsignup.cpp \
    'Form Authorization'\validator.cpp \
    'Form Menu'\Employee\formconfirmation.cpp \
    'Form Menu'\Employee\employeedelegate.cpp \
    'Form Menu'\Booking\itembooking.cpp \
    'Form Menu'\Rooms\itemroom.cpp \
    'Form Menu'\\'Check In'\itemcheckin.cpp \
    'Form Menu'/'Check In'/service.cpp \
    'Form Menu'/Settings/editservice.cpp \
    'Form Menu'/Settings/itemservice.cpp \
    'Form Menu'/Employee/itememployee.cpp \
    'Form Menu'/Employee/itemworkhotel.cpp \
    'Form Menu'/Booking/phonevalidator.cpp \
    'Form Menu'/Booking/acceptbooking.cpp \
    main.cpp \
    client.cpp \
    workerconnect.cpp

HEADERS += \
    'Form Menu'\Booking\calendar.h \
    'Form Menu'\Employee\formconfirmation.h \
    'Form Menu'\Employee\employeedelegate.h \
    'Form Menu'\Booking\itembooking.h \
    'Form Menu'\Rooms\itemroom.h \
    'Form Menu'\\'Check In'\itemcheckin.h \
    'Form Menu'\\'Check In'\service.h \
    'Form Menu'\\Settings\editservice.h \
    'Form Menu'/Settings/itemservice.h \
    'Form Menu'/Employee/itememployee.h \
    'Form Menu'/Employee/itemworkhotel.h \
    'Form Menu'/Booking/phonevalidator.h \
    'Form Menu'/Booking/acceptbooking.h \
    client.h \
    'Form Authorization'\formauthorization.h \
    'Form Menu'\Booking\formbooking.h \
    'Form Menu'\\'Check In'\formcheckin.h \
    'Form Menu'\Employee\formconcreteemployee.h \
    'Form Menu'\Booking\formcreatebooking.h \
    'Form Menu'\Employee\formemployee.h \
    'Form Menu'\\'Main Menu'\formmainmenu.h \
    'Form Menu'\formmenu.h \
    'Form Menu'\Report\formreport.h \
    'Form Menu'\Rooms\formrooms.h \
    'Form Menu'\Settings\formsettings.h \
    'Form Menu'\\'Sign Up'\formsignup.h \
    'Form Authorization'\validator.h \
    ..\const.h \
    workerconnect.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
   'Form Authorization'\formauthorization.ui \
   'Form Menu'\Booking\formbooking.ui \
   'Form Menu'\\'Check In'\formcheckin.ui \
   'Form Menu'\Employee\formconcreteemployee.ui \
   'Form Menu'\Booking\formcreatebooking.ui \
   'Form Menu'\Employee\formemployee.ui \
   'Form Menu'\\'Main Menu'\formmainmenu.ui \
   'Form Menu'\formmenu.ui \
   'Form Menu'\Report\formreport.ui \
   'Form Menu'\Rooms\formrooms.ui \
   'Form Menu'\Settings\formsettings.ui \
   'Form Menu'\\'Sign Up'\formsignup.ui \
   'Form Menu'/Employee/formconfirmation.ui \
   'Form Menu'/Booking/itembooking.ui \
   'Form Menu'/Rooms/itemroom.ui \
   'Form Menu'\\'Check In'/itemcheckin.ui \
   'Form Menu'\\'Check In'/service.ui \
   'Form Menu'/Settings/editservice.ui \
   'Form Menu'/Settings/itemservice.ui \
   'Form Menu'/Employee/itememployee.ui \
   'Form Menu'/Employee/itemworkhotel.ui \
   'Form Menu'/Booking/acceptbooking.ui

RESOURCES += \
   source.qrc

win32:RC_FILE = icon.rc
