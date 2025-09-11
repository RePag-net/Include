/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: ProgIntern.h
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
#ifndef ProgInternH
#define ProgInternH

constexpr BYTE PR_3DOBJEKT = 0;
constexpr BYTE PR_CORE = 1;
constexpr BYTE PR_UPDATE_C = 2;
constexpr BYTE PR_CLIENT_C = 3;
constexpr BYTE PR_ADMIN_C = 128;
constexpr BYTE PR_SERVER_S = 253;
constexpr BYTE PR_LOGIN_S = 254;
constexpr BYTE PR_ADMIN_S = 255;
//------------------------------------------------------------------------------------
#define _Schlussel(c30Schlussel, iStrLange) (c30Schlussel[iStrLange = LoadString(GetModuleHandle(NULL), 11999, c30Schlussel, 30)] = 0)
#define _ProgName(c30ProgName, iStrLange) (c30ProgName[iStrLange = LoadString(GetModuleHandle(NULL), 11998, c30ProgName, 30)] = 0)
//------------------------------------------------------------------------------------
#ifndef FILEVERS

using namespace RePag::System;

#define _Account_Benutzer "S-1-5-32-545"
#define _Account_System "S-1-5-18"
#define _Account_Jeder "S-1-1-0"
#define _Account_Administratoren "S-1-5-32-544"

constexpr DWORD WAIT_VMBLOCKM = 10000;
constexpr DWORD WAIT_VMBLOCKMSHARED = 10000;
constexpr DWORD WAIT_AESKEY = 10000;
constexpr DWORD WAIT_REGISTRYKEY = 10000;
constexpr DWORD WAIT_PROZESSPLATZE = 10000;
constexpr DWORD TAKT_PROZESSPLATZE_MONITOR = 3000;
constexpr DWORD TAKT_PROZESSPLATZE_CORE = 30000;

#ifndef _64bit
constexpr BYTE BY_PROGINTERN = 60;
#else
constexpr BYTE BY_PROGINTERN = 120;
#endif

constexpr BYTE FN_COREENCRYPT = 1;
constexpr BYTE FN_REPAGNETCRYPT = 2;
constexpr BYTE FN_DNSTOCORE = 4;
constexpr BYTE FN_COREDECRYPT = 5;
constexpr BYTE FN_DATABASEKEY = 7;
constexpr BYTE FN_CONNECTCORES = 11;
constexpr BYTE FN_SELFCORENUMBER = 13;

constexpr BYTE IPADRESSE_V4 = 4;
constexpr BYTE IPADRESSE_V6 = 6;

constexpr BYTE Adresse_32bit = 4;
constexpr BYTE Adresse_64bit = 8;

//------------------------------------------------------------------------------------
typedef struct STSockAdresse
{
	ULONG ulLange;
	VMBLOCK vbSockaddr;
} STSockAdresse;
//------------------------------------------------------------------------------------
typedef struct STTransferData
{
	HWND hWndDBTabelle;
	HWND hWndElement;
	HANDLE heMessageLoop;
	bool bAbbruch;
	CRITICAL_SECTION csAbbruch;
	void(__vectorcall* pfnVisible)(STTransferData*, ULONG);
	void(__vectorcall* pfnUnvisible)(void);
	void(__vectorcall* pfnPosition)(ULONG);
} STTransferData;
//------------------------------------------------------------------------------------
typedef BYTE(__vectorcall* FnDatabaseKey)(const char[16], const char[16], BIT128, BYTE[240], BYTE[240]);
typedef VMBLOCK(__vectorcall* FnRePagNet_Crypt)(VMBLOCK, unsigned long&, bool);
typedef BYTE(__vectorcall* FnDNSToCore)(const char*, BIT128&);
typedef BYTE*(__vectorcall* FnSelfCoreNumber)(BIT128&);
typedef VMBLOCK(__vectorcall* FnCoreEncrypt)(VMEMORY, BIT128, VMBLOCK, unsigned long&);
typedef VMBLOCK(__vectorcall* FnCoreDecrypt)(VMEMORY, BIT128, VMBLOCK, unsigned long&);
typedef BYTE(__vectorcall* FnConnectCores)(const char*);
#endif
#endif