QT       += core gui sql texttospeech
QT += multimedia
QT += network
QT += printsupport
QT += multimediawidgets
QMAKE_CXXFLAGS += -std=gnu++14
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
    CameraLumiere.cpp \
    Etages.cpp \
    LoisirDevoir.cpp \
    Profil.cpp \
    camera.cpp \
    chambres.cpp \
    connexion.cpp \
    course.cpp \
    devoir.cpp \
    duscene.cpp \
    equipement.cpp \
    exportexcelobject.cpp \
    fenetre.cpp \
    fenetre_Etage_Chambre.cpp \
    fenetre_Porte_Fenetre.cpp \
    fenetre_equip_course.cpp \
    gifanimation.cpp \
    login.cpp \
    loisir.cpp \
    lumiere.cpp \
    main.cpp \
    mainwindow.cpp \
    porte.cpp \
    statistique.cpp

HEADERS += \
    CameraLumiere.h \
    Etages.h \
    LoisirDevoir.h \
    camera.h \
    chambres.h \
    connexion.h \
    course.h \
    devoir.h \
    duscene.h \
    equipement.h \
    exportexcelobject.h \
    fenetre.h \
    fenetre_Etage_Chambre.h \
    fenetre_Porte_Fenetre.h \
    fenetre_equip_course.h \
    gifanimation.h \
    login.h \
    loisir.h \
    lumiere.h \
    mainwindow.h \
    porte.h \
    profil.h \
    statistique.h

FORMS += \
    CameraLumiere.ui \
    LoisirDevoir.ui \
    fenetre_Etage_Chambre.ui \
    fenetre_Porte_Fenetre.ui \
    fenetre_equip_course.ui \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
