TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    data_structures/dataelement.cpp \
    data_structures/cluster.cpp \
    filemanagement.cpp \
    clope.cpp

HEADERS += \
    data_structures/dataelement.h \
    data_structures/cluster.h \
    filemanagement.h \
    clope.h

INCLUDEPATH += /home/gosciunew/Dokumenty/ChimneyLABS_documents/tbb41_20130116oss/include

LIBS += -L/home/gosciunew/Dokumenty/ChimneyLABS_documents/tbb41_20130116oss/lib/ia32/cc4.1.0_libc2.4_kernel2.6.16.21 \
        -ltbb

LIBS += -L/lib/i386-linux-gnu \
        -lrt

