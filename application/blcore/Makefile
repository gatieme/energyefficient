#############################################################################
# Makefile for building: BLCoreMonitor
# Generated by qmake (2.01a) (Qt 4.8.0) on: ?? 11? 21 16:33:39 2016
# Project:  BLCoreMonitor/BLCoreMonitor.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.8.0/bin/qmake -spec /usr/local/Trolltech/Qt-4.8.0/mkspecs/linux-g++ -o Makefile BLCoreMonitor/BLCoreMonitor.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.8.0/mkspecs/linux-g++ -IBLCoreMonitor -I/usr/local/Trolltech/Qt-4.8.0/include/QtCore -I/usr/local/Trolltech/Qt-4.8.0/include/QtGui -I/usr/local/Trolltech/Qt-4.8.0/include -I. -I. -IBLCoreMonitor -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/Qt-4.8.0/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.8.0/lib -lQtGui -L/usr/local/Trolltech/Qt-4.8.0/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.8.0/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = BLCoreMonitor/main.cpp \
		BLCoreMonitor/blcorewidget.cpp \
		BLCoreMonitor/cpufreqwidgettab.cpp moc_blcorewidget.cpp \
		moc_cpufreqwidgettab.cpp
OBJECTS       = main.o \
		blcorewidget.o \
		cpufreqwidgettab.o \
		moc_blcorewidget.o \
		moc_cpufreqwidgettab.o
DIST          = /usr/local/Trolltech/Qt-4.8.0/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/include_source_dir.prf \
		BLCoreMonitor/BLCoreMonitor.pro
QMAKE_TARGET  = BLCoreMonitor
DESTDIR       = 
TARGET        = BLCoreMonitor

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_blcorewidget.h ui_cpufreqwidgettab.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: BLCoreMonitor/BLCoreMonitor.pro  /usr/local/Trolltech/Qt-4.8.0/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.8.0/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.8.0/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.8.0/lib/libQtCore.prl
	$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.0/mkspecs/linux-g++ -o Makefile BLCoreMonitor/BLCoreMonitor.pro
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/gcc-base-unix.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/common/g++-unix.conf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.8.0/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.8.0/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.8.0/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.0/mkspecs/linux-g++ -o Makefile BLCoreMonitor/BLCoreMonitor.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/BLCoreMonitor1.0.0 || $(MKDIR) .tmp/BLCoreMonitor1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/BLCoreMonitor1.0.0/ && $(COPY_FILE) --parents BLCoreMonitor/blcorewidget.h BLCoreMonitor/cpufreqwidgettab.h .tmp/BLCoreMonitor1.0.0/ && $(COPY_FILE) --parents BLCoreMonitor/main.cpp BLCoreMonitor/blcorewidget.cpp BLCoreMonitor/cpufreqwidgettab.cpp .tmp/BLCoreMonitor1.0.0/ && $(COPY_FILE) --parents BLCoreMonitor/blcorewidget.ui BLCoreMonitor/cpufreqwidgettab.ui .tmp/BLCoreMonitor1.0.0/ && (cd `dirname .tmp/BLCoreMonitor1.0.0` && $(TAR) BLCoreMonitor1.0.0.tar BLCoreMonitor1.0.0 && $(COMPRESS) BLCoreMonitor1.0.0.tar) && $(MOVE) `dirname .tmp/BLCoreMonitor1.0.0`/BLCoreMonitor1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/BLCoreMonitor1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_blcorewidget.cpp moc_cpufreqwidgettab.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_blcorewidget.cpp moc_cpufreqwidgettab.cpp
moc_blcorewidget.cpp: BLCoreMonitor/blcorewidget.h
	/usr/local/Trolltech/Qt-4.8.0/bin/moc $(DEFINES) $(INCPATH) BLCoreMonitor/blcorewidget.h -o moc_blcorewidget.cpp

moc_cpufreqwidgettab.cpp: BLCoreMonitor/cpufreqwidgettab.h
	/usr/local/Trolltech/Qt-4.8.0/bin/moc $(DEFINES) $(INCPATH) BLCoreMonitor/cpufreqwidgettab.h -o moc_cpufreqwidgettab.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_blcorewidget.h ui_cpufreqwidgettab.h
compiler_uic_clean:
	-$(DEL_FILE) ui_blcorewidget.h ui_cpufreqwidgettab.h
ui_blcorewidget.h: BLCoreMonitor/blcorewidget.ui
	/usr/local/Trolltech/Qt-4.8.0/bin/uic BLCoreMonitor/blcorewidget.ui -o ui_blcorewidget.h

ui_cpufreqwidgettab.h: BLCoreMonitor/cpufreqwidgettab.ui
	/usr/local/Trolltech/Qt-4.8.0/bin/uic BLCoreMonitor/cpufreqwidgettab.ui -o ui_cpufreqwidgettab.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: BLCoreMonitor/main.cpp BLCoreMonitor/blcorewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o BLCoreMonitor/main.cpp

blcorewidget.o: BLCoreMonitor/blcorewidget.cpp BLCoreMonitor/blcorewidget.h \
		ui_blcorewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o blcorewidget.o BLCoreMonitor/blcorewidget.cpp

cpufreqwidgettab.o: BLCoreMonitor/cpufreqwidgettab.cpp BLCoreMonitor/cpufreqwidgettab.h \
		ui_cpufreqwidgettab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cpufreqwidgettab.o BLCoreMonitor/cpufreqwidgettab.cpp

moc_blcorewidget.o: moc_blcorewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_blcorewidget.o moc_blcorewidget.cpp

moc_cpufreqwidgettab.o: moc_cpufreqwidgettab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cpufreqwidgettab.o moc_cpufreqwidgettab.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

