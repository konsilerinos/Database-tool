QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auditoriumdeleteform.cpp \
    auditoriuminsertform.cpp \
    changeinfoform.cpp \
    departmentdeleteform.cpp \
    departmentinsertform.cpp \
    groupdeleteform.cpp \
    groupinsertform.cpp \
    info.cpp \
    lessondeleteform.cpp \
    lessoninsertform.cpp \
    main.cpp \
    mainwindow.cpp \
    requestsform.cpp \
    subjectdeleteform.cpp \
    subjectinsertform.cpp \
    teacherdeleteform.cpp \
    teacherinsertform.cpp

HEADERS += \
    auditoriumdeleteform.h \
    auditoriuminsertform.h \
    changeinfoform.h \
    departmentdeleteform.h \
    departmentinsertform.h \
    groupdeleteform.h \
    groupinsertform.h \
    info.h \
    lessondeleteform.h \
    lessoninsertform.h \
    mainwindow.h \
    requestsform.h \
    subjectdeleteform.h \
    subjectinsertform.h \
    teacherdeleteform.h \
    teacherinsertform.h

FORMS += \
    auditoriumdeleteform.ui \
    auditoriuminsertform.ui \
    changeinfoform.ui \
    departmentdeleteform.ui \
    departmentinsertform.ui \
    groupdeleteform.ui \
    groupinsertform.ui \
    info.ui \
    lessondeleteform.ui \
    lessoninsertform.ui \
    mainwindow.ui \
    requestsform.ui \
    subjectdeleteform.ui \
    subjectinsertform.ui \
    teacherdeleteform.ui \
    teacherinsertform.ui

VERSION = 1.2.1.1
QMAKE_TARGET_COMPANY = Konsilerinos C
QMAKE_TARGET_PRODUCT = Database tool
QMAKE_TARGET_DESCRIPTION = Tool
QMAKE_TARGET_COPYRIGHT = Konsilerinos

RC_ICONS = Icon/Icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
