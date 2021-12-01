QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auditoriuminsertform.cpp \
    departmentdeleteform.cpp \
    departmentinsertform.cpp \
    groupinsertform.cpp \
    info.cpp \
    lessoninsertform.cpp \
    main.cpp \
    mainwindow.cpp \
    requestsform.cpp \
    subjectinsertform.cpp \
    teacherinsertform.cpp

HEADERS += \
    auditoriuminsertform.h \
    departmentdeleteform.h \
    departmentinsertform.h \
    groupinsertform.h \
    info.h \
    lessoninsertform.h \
    mainwindow.h \
    requestsform.h \
    subjectinsertform.h \
    teacherinsertform.h

FORMS += \
    auditoriuminsertform.ui \
    departmentdeleteform.ui \
    departmentinsertform.ui \
    groupinsertform.ui \
    info.ui \
    lessoninsertform.ui \
    mainwindow.ui \
    requestsform.ui \
    subjectinsertform.ui \
    teacherinsertform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
