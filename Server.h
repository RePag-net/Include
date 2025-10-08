/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Server.h
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
#ifndef ServerH
#define ServerH
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE CS_COREMEMORY = 235;
constexpr BYTE CS_CORECONNECT = 236;
constexpr BYTE CS_VIRTUALMEMORY = 237;
constexpr BYTE CS_DBSTARTOPTIMIERUNG = 238;
constexpr BYTE CS_DBAUSGLEICHEN = 239;
constexpr BYTE CS_DBSYNCHRON = 240;
constexpr BYTE CS_DBDATENSATZLOSCHEN = 241;
constexpr BYTE CS_DBDATENSATZMAXEINFUGEN = 242; 
constexpr BYTE CS_DBDATENSATZEINFUGEN = 243;
constexpr BYTE CS_DBDATENSATZANDERN = 244;
constexpr BYTE CS_DBTABELLELESEN = 245;
constexpr BYTE CS_SITZUNGEN = 246;
constexpr BYTE CS_PROTOKOLLANMELDUNG = 247; 
constexpr BYTE CS_PROTOKOLLABMELDUNG = 248;
constexpr BYTE CS_CLIENTWECHSEL = 249; 
constexpr BYTE CS_EXTERNSYSTEMABMELDUNG = 250; 
constexpr BYTE CS_SERVER2ANMELDUNG = 251;
constexpr BYTE CS_SERVER2ABMELDUNG = 252;
constexpr BYTE CS_BENUTZERANMELDUNG = 253;
constexpr BYTE CS_BENUTZERABMELDUNG = 254;
constexpr BYTE CS_SITZUNGSLISTE = 255;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr USHORT CS_VINTERN = 0;
constexpr BYTE CS_V1 = 1;
constexpr BYTE CS_V2 = 2;
constexpr BYTE CS_LINGERWARTEN = 10;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr DWORD SV_WARTEN = 20000;
constexpr DWORD DB_SERVER2WARTEN = 10000;
constexpr DWORD DB_SYNCHRONWARTEN = 30000;
constexpr DWORD CS_THREADWARTEN = 10000;
constexpr DWORD SV_SITZUNGGULTIG = 600;
constexpr BYTE SF_ZEITENDE = 0xFF;
constexpr BYTE CF_ZEITENDE = 0xFE;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE SF_KEINFEHLER = 0;
constexpr BYTE DB_KEINFEHLER = 0;
constexpr BYTE DB_KEINSUCHPARAM = 48;
constexpr BYTE DB_KEINEDATEN = 49;
constexpr BYTE DB_KEINEANDERUNG = 50;
// 80 - 90 ADT und Speicherfehler
constexpr BYTE PF_ABBRUCH = 92; 
constexpr BYTE SF_KEINTHREAD = 93;
constexpr BYTE SF_UNBEKANNTEAUFGABE = 94;
constexpr BYTE DB_DATENFEHLER = 95;
constexpr BYTE DB_GEANDERTEDATEN = 96;
constexpr BYTE DB_CRYPTFEHLER = 97;
constexpr BYTE DB_DATEIFEHLER = 98;
constexpr BYTE SF_KEINRECHT = 99;
constexpr BYTE SF_KEINESITZUNG = 100;
constexpr BYTE SF_DECODIERFEHLER = 101;
// 101 - 199 Serverfehler
constexpr BYTE PF_KEINEVERBINDUNG = 221;
// 201 - 219 Protokollfehler
// 220 - 229 Protokollclientfehler
// 230 - 239 Protokollserverfehler
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STBenutzer
{
  COTime* vzAnmeldung;
  COTime* vzLetzteAktion;
	BIT128 bit128Sitzung;
	STSockAdresse stSockAdresse;
  unsigned long ulNummer;
  unsigned char ucProgramm;
  unsigned char ucRechte;
  bool bServer_2;
} STBenutzer;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STCore
{
	STAES_CryptKeys* av16AES_CryptKeys;
	COTime* vzLetzteAktion;
	BIT128 bit128CoreNummer;
	COStringA* vasComputerName;
	BIT128 bit128Sitzung;
	STSockAdresse stSockAdresse;
	unsigned char ucRechte;
} STCore;
//------------------------------------------------------------------------------------------------------------------------------------------
#endif