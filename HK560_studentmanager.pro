QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    globle.cpp \
    main.cpp \
    mainwindow.cpp \
    manage.cpp \
    manage_admin.cpp \
    manage_course.cpp \
    manage_grade.cpp \
    manage_student.cpp \
    manage_teacher.cpp \
    student.cpp \
    student_course.cpp \
    student_info.cpp

HEADERS += \
    globle.h \
    mainwindow.h \
    manage.h \
    manage_admin.h \
    manage_course.h \
    manage_grade.h \
    manage_student.h \
    manage_teacher.h \
    student.h \
    student_course.h \
    student_info.h

FORMS += \
    mainwindow.ui \
    manage.ui \
    manage_admin.ui \
    manage_course.ui \
    manage_grade.ui \
    manage_student.ui \
    manage_teacher.ui \
    student.ui \
    student_course.ui \
    student_info.ui


QT       += sql


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
