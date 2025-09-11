/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Bank.h
For more information see https://github.com/RePag-net/Include

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/
#ifndef BankH
#define BankH
#include "Login.h"
//---------------------------------------------------------------------------
#define CS_TESTTABELLE 0
#define CS_TESTLISTE 1
//---------------------------------------------------------------------------
#define TAB_TEST 0
#define TAB_TESTLISTE 1
#define TAB_TESTDOKUMENT 2
#define TAB_TESTZAHLEN 3
#define TAB_TESTMEDIA 4
#define TAB_KLEINBILD 5
#define TAB_GROSSBILD 6
//---------------------------------------------------------------------------
#define SPL_TEST_ULTEST 0
#define SPL_TEST_KSTEST 1
#define SPL_TEST_UCTEST 2
#define SPL_TEST_KBTEST 3
#define SPL_TEST_GBTEST 4
#define SPL_TEST_MSTEST 5
#define SPL_TEST_LSTEST 6
#define SPL_TEST_ZTEST 7
#define SPL_TEST_K4TEST 8
#define BST_TEST_ULTEST 0
#define BST_TEST_KSTEST 1

#define SPL_TESTLISTE_UCNUMMER 0
#define SPL_TESTLISTE_KSTEXT 1
#define BST_TESTLISTE_UCNUMMER 0

#define SPL_TESTDOKUMENT_UCNUMMER 0
#define SPL_TESTDOKUMENT_DKTEST 1
#define SPL_TESTDOKUMENT_ZTEST 2
#define BST_TESTDOKUMENT_UCNUMMER 0

#define SPL_TESTZAHLEN_LLTEST 0
#define SPL_TESTZAHLEN_K4TEST 1
#define SPL_TESTZAHLEN_FTEST 2
#define SPL_TESTZAHLEN_DTEST 3
#define SPL_TESTZAHLEN_128BIT 4
#define BST_TESTZAHLEN_LLTEST 0

#define SPL_TESTMEDIA_ZTEST 0
#define SPL_TESTMEDIA_UCTEST 1
#define SPL_TESTMEDIA_MATEST 2
#define SPL_TESTMEDIA_MVTEST 3
#define BST_TESTMEDIA_ZTEST 0

#define SPL_KLEINBILD_ZDATUM 0
#define SPL_KLEINBILD_KBBILD 1
#define BST_KLEINBILD_ZDATUM 0

#define SPL_GROSSBILD_ZDATUM 0
#define SPL_GROSSBILD_GBBILD 1
#define BST_GROSSBILD_ZDATUM 0
//---------------------------------------------------------------------------
#endif