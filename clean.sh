#!/bin/sh

echo "[+] Cleaning autotools files..."
rm -rf autom4te.cache
rm -f aclocal.m4
rm -f config.log
rm -f config.status
rm -f configure
rm -f Makefile.in
rm -f src/Makefile.in
rm -f config.h
rm -f config.h.in
rm -f stamp-h1
rm -f Makefile
rm -f src/Makefile
rm -rf src/.deps
rm -f *~
