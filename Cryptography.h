/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Cryptography.h
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
#ifndef CryptographyH
#define CryptographyH
#ifdef HCORE
#include "OZeit.h"
#endif
using namespace RePag::System;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STAES_CryptKeys
{
	BYTE uc256DecryptKey[256];
	BYTE uc256EncryptKey[256];
	BIT128 bit128Vector;
} STAES_CryptKeys;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STSchlussel_Daten
{
	STAES_CryptKeys* av16AES_CryptKeys;
	unsigned char ucVerfahren;
} STSchlussel_Daten;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STSchlussel
{
	VMBLOCK vbSchlussel;
	unsigned char ucVerfahren;
} STSchlussel;
//#define BY_STSCHLUSSEL 12
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STSchlusselFeile
{
	long long llZufall;
	STSchlussel *pstSchlussel;
	COTime* vzDatum;
} STSchlusselFeile;
//#define BY_STSCHLUSSELFEILE 16
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STSchlussel_Klein
{
	STSchlussel stSchlussel;
	bool bVerschlusseln;
	char* pcDaten;
	long lKontrolle;
	unsigned short usBytes;
} STSchlussel_Klein;
//#define BY_STVERSCHLUSSELUNG 32
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STServer
{
  STAES_CryptKeys* av16AES_CryptKeys;
	CRITICAL_SECTION csServer;
	COStringA asIPClient;
	STSockAdresse stSockaddrIV4_1;
	STSockAdresse stSockaddrIV4_2;
	STSockAdresse stSockaddrIV6_1;
	STSockAdresse stSockaddrIV6_2;
	BIT128 bit128Core_1;
	BIT128 bit128Core_2;
	unsigned short usPort;
	bool bServer_2;
} STServer;
//#define BY_STSERVER 76
//------------------------------------------------------------------------------------------------------------------------------------------
void __vectorcall ErstellSchlussel(STSchlusselFeile& stSchlusselFeile);
char* __vectorcall Codieren(STSchlussel_Klein& stSchlussel_Klein);
inline void __vectorcall Modus(STSchlussel_Klein& stSchlussel_Klein, char* cSchlussel, unsigned short& usSchlusselPosition, unsigned short usSchlusselGrosse);
inline char* __vectorcall Code_1(STSchlussel_Klein& stSchlussel_Klein);
inline char* __vectorcall Code_50(STSchlussel_Klein& stSchlussel_Klein);
inline char* __vectorcall Code_51(STSchlussel_Klein& stSchlussel_Klein);
inline char* __vectorcall Code_52(STSchlussel_Klein& stSchlussel_Klein);
inline char* __vectorcall Code_53(STSchlussel_Klein& stSchlussel_Klein);
inline void __vectorcall ErstellSchlussel_1(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_50(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_51(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_52(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_53(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_54(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_55(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_56(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_57(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_58(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_59(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_60(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_61(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_62(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_63(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_64(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_65(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_66(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_67(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_68(STSchlusselFeile& stSchlusselFeile);
inline void __vectorcall ErstellSchlussel_69(STSchlusselFeile& stSchlusselFeile);
//------------------------------------------------------------------------------------------------------------------------------------------
#endif
