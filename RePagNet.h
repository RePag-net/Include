/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: RePagNet.h
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
#ifndef RePagNetH
#define RePagNetH
#include "Cryptography.h"
//---------------------------------------------------------------------------
class __declspec(dllimport) COServer
{
private:
	bool __vectorcall RePagVerbindung(void);
	bool __vectorcall IPHolen(void);
	bool __vectorcall NeueSitzung(void);
	bool __vectorcall Anmeldung(void);
	void __vectorcall ProgrammeSuchen(void);
	void __vectorcall SchlusselSuchen(HKEY& hAdminSchlussel, COList* vlstProgVersion, COStringA* vasHauptSchlussel, COList* vlProgramme);
	bool __vectorcall Update(COList* vlstProgVersion);
	void __vectorcall AdminNews(void);
	bool __vectorcall NewsAdmin(COStream* vsNews);
	bool __vectorcall Passwort(void);
	HKEY hSchlussel;
	HWND hWndHaupt;
	COStringA* vasBenutzer;
	COStringA* vasPasswort;
	COStringA* vasComputerName;
	COStringA* vasIPServer;
	COStringA* vasinternIPNummer;
	COTime* vzAnmeldung;
	long long llZufall;
	COStringA* vasProgServerDNS_1;
	COStringA* vasProgServerDNS_2;

protected:

public:
	void __vectorcall COServerV(HWND hWndHauptA, const char* pcProgServerDNS_1, const char* pcProgServerDNS_2, unsigned short usPort);
	VMEMORY __vectorcall COFreiV(void);
	void __vectorcall WM_Command(LPARAM lParam);
	VMEMORY __vectorcall VMProtokoll(void);
	bool __vectorcall Verbunden(void);
	void __vectorcall Trennen(void);
	void __vectorcall Monitortext(char* pcText);
	bool __vectorcall NeuesPasswort(void);
	bool bUnterbrochen;
	BIT128 bit128Sitzung;
	STServer* vstLoginServer;
	STServer* vstAdminServer;
	STServer* vstProgServer;

};
__declspec(dllimport) COServer* vServer;
__declspec(dllimport) COServer* __vectorcall COServerV(HWND hWndHaupt, const char* pcProgServerDNS_1, const char* pcProgServerDNS_2, unsigned short usPort);
__declspec(dllimport) extern char pcKeineSitzung[];
__declspec(dllimport) extern char pcKeinRecht[];
//---------------------------------------------------------------------------
#endif