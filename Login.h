/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Login.h
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
#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
//AdminServer
#define CS_EINTRAGPROTOKOLL 1
#define CS_PROTODATEI 2

//LoginServer
#define CS_NEUESITZUNG 1
#define CS_LOGINSYSTEMABMELDUNG 2
#define CS_UPDATE 3
#define CS_PROGVERSION 4
#define CS_ADMINNEWS 5
#define CS_LOGINLOGOUT 6
#define CS_BENUTZERVORGABE 7
#define CS_SUCHBENUTZER 8
#define CS_BENUTZERDATEN 9
#define CS_BENUTZERANDERN 10
#define CS_NEUESPASSWORT 11

//---------------------------------------------------------------------------
#define TAB_BENUTZER 0
#define TAB_ANMELDUNG 1
#define TAB_PASSWORT 2
#define TAB_BERECHTIGUNG 3
#define TAB_GRUPPEN 4
#define TAB_LOGINLOGOUT 5
#define TAB_FALSCHPASS 6
#define TAB_NEWS 7
#define TAB_NEWSTEXTE 8
#define TAB_PROGRAMME 9
#define TAB_UPDATES 10

#define SPL_BENUTZER_ULBENUTZER 0
#define SPL_BENUTZER_KSANREDE 1
#define SPL_BENUTZER_KSTITEL 2
#define SPL_BENUTZER_KSVORNAME 3
#define SPL_BENUTZER_KSNACHNAME 4
#define SPL_BENUTZER_KBBILD 5
#define SPL_BENUTZER_UCGRUPPE 6
#define SPL_BENUTZER_MSMEMO 7
#define SPL_BENUTZER_BERLOSCHEN 8
#define BST_BENUTZER_ULBENUTZER 0

#define SPL_ANMELDUNG_KSBENUTZERNAME 0
#define SPL_ANMELDUNG_ULBENUTZER 1
#define SPL_ANMELDUNG_BFALSCHPASS 2
#define SPL_ANMELDUNG_BGESPERRT 3
#define BST_ANMELDUNG_KSBENUTZERNAME 0
#define BST_ANMELDUNG_ULBENUTZER 1

#define SPL_PASSWORT_ULBENUTZER 0
#define SPL_PASSWORT_KSPASSWORT 1
#define BST_PASSWORT_ULBENUTZER 0

#define SPL_BERECHTIGUNG_ULBENUTZER 0
#define SPL_BERECHTIGUNG_UCPROGRAMM 1
#define SPL_BERECHTIGUNG_UCRECHTE 2
#define BST_BERECHTIGUNG_ULBENUTZER 0

#define SPL_GRUPPEN_UCNUMMER 0
#define SPL_GRUPPEN_KSNAME 1

#define SPL_LOGINLOGOUT_ZLOGIN 0
#define SPL_LOGINLOGOUT_ZLOGOUT 1
#define SPL_LOGINLOGOUT_ULBENUTZER 2
#define SPL_LOGINLOGOUT_UCPROGRAMM 3
#define SPL_LOGINLOGOUT_KSCOMPUTER 4
#define SPL_LOGINLOGOUT_KSEXTERNIPNUMMER 5
#define SPL_LOGINLOGOUT_KSINTERNIPNUMMER 6
#define SPL_LOGINLOGOUT_BSYSTEM 7

#define SPL_FALSCHPASS_ULBENUTZER 0
#define SPL_FALSCHPASS_ZDATUM 1
#define SPL_FALSCHPASS_KSPASSWORT 2
#define SPL_FALSCHPASS_UCPROGRAMM 3
#define SPL_FALSCHPASS_KSCOMPUTER 4
#define SPL_FALSCHPASS_KSIPNUMMER 5

#define SPL_NEWS_ULNUMMER 0
#define SPL_NEWS_ULEMPFANGER 1
#define SPL_NEWS_USTEXT 2
#define SPL_NEWS_ZGELESEN 3

#define SPL_NEWSTEXTE_USTEXT 0
#define SPL_NEWSTEXTE_ZDATUM 1
#define SPL_NEWSTEXTE_KSBETREFF 2
#define SPL_NEWSTEXTE_MSMEMO 3

#define SPL_PROGRAMME_UCNUMMER 0
#define SPL_PROGRAMME_KSNAME 1
#define SPL_PROGRAMME_KSVERSION 2
#define SPL_PROGRAMME_KSUSER 3
#define SPL_PROGRAMME_KSPFAD 4
#define SPL_PROGRAMME_KSPASSWORT 5
#define SPL_PROGRAMME_KSSERVER 6
#define BST_PROGRAMME_UCNUMMER 0

#define SPL_UPDATES_KSPROGRAMM 0
#define SPL_UPDATES_KSVERSION 1
#define SPL_UPDATES_ZDATUM 2
#define SPL_UPDATES_KSDATEIEN 3
#define SPL_UPDATES_BGESPERRT 4
#define BST_UPDATES_KSPROGRAMM 0
//---------------------------------------------------------------------------
typedef struct STLogout
{                               
  COTime* vzAnmeldung;
  unsigned char ucProgramm;
  unsigned long ulBenutzer;
  BIT128 bit128Sitzung;
} STLogout;
//---------------------------------------------------------------------------
#endif