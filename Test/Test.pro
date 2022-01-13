QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base.cpp \
    capacitor.cpp \
    circuit.cpp \
    current.cpp \
    gnd.cpp \
    help.cpp \
    ic.cpp \
    inductor.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    pc.cpp \
    resistor.cpp \
    scope.cpp \
    setpcdialog.cpp \
    setsourcedialog.cpp \
    simu_freq.cpp \
    simu_time.cpp \
    source.cpp \
    sweep.cpp \
    tools.cpp \
    voltage.cpp \
    wave.cpp \
    wire.cpp

HEADERS += \
    base.h \
    capacitor.h \
    circuit.h \
    current.h \
    gnd.h \
    help.h \
    ic.h \
    inductor.h \
    mainwindow.h \
    node.h \
    pc.h \
    resistor.h \
    scope.h \
    setpcdialog.h \
    setsourcedialog.h \
    simu_freq.h \
    simu_time.h \
    source.h \
    sweep.h \
    tools.h \
    voltage.h \
    wave.h \
    wire.h

FORMS += \
    help.ui \
    mainwindow.ui \
    setpcdialog.ui \
    setsourcedialog.ui \
    simu_freq.ui \
    simu_time.ui \
    sweep.ui \
    wave.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/resource.qrc
