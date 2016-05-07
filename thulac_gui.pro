#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T19:18:53
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thulac_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \
    src/cb_decoder.h \
    src/cb_model.h \
    src/cb_ngram_feature.h \
    src/cb_tagging_decoder.h \
    src/cb_tagging_learner.h \
    src/dat.h \
    src/filter.h \
    src/negword.h \
    src/postprocess.h \
    src/preprocess.h \
    src/punctuation.h \
    src/thulac_base.h \
    src/thulac_character.h \
    src/thulac_raw.h \
    src/timeword.h \
    src/verbword.h \
    src/thulac.h

FORMS    += mainwindow.ui \

RESOURCES += icons.qrc \
