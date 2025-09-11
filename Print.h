/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Print.h
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
#ifndef DruckenH
#define DruckenH

namespace RePag
{
	namespace Dialogs
	{
		namespace User
		{
			//-------------------------------------------------------------------------------------------------------------------------------------
			class CODLGDruckVorschau : public GUI::CODialog
			{
				friend LRESULT CALLBACK WndProc_DLGDruckVorschau(HWND hWndDlg, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
				friend void __vectorcall frDruckVorschau_WM_Command(HWND hWndDlg, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

			private:
				GUI::COKnopf* kErsteSeite;
				GUI::COKnopf* kVorherigeSeite;
				GUI::COKnopf* kNachsteSeite;
				GUI::COKnopf* kLetzteSeite;
				GUI::COKnopf* kKleiner;
				GUI::COKnopf* kGrosser;
				GUI::COKnopf* kDrucker;
				GUI::COKnopf* kDrucken;
				GUI::COKnopf* kSchliessen;
				GUI::COBildBox* bibSeite;
				char cZoom;
				COStringA* vasSchlussel;
				void __vectorcall WM_Create(HWND hWnd);
				void __vectorcall ErsteSeite(void);
				void __vectorcall LetzteSeite(void);
				void __vectorcall VorherigeSeite(void);
				void __vectorcall NachsteSeite(void);
				void __vectorcall Verkleinern(void);
				void __vectorcall Vergrossern(void);

			protected:

			public:
				void __vectorcall CODLGDruckVorschauV(const char* pcTitel);

			};
			//-------------------------------------------------------------------------------------------------------------------------------------
			class CODLGMDruckEinstellung : public GUI::CODialog
			{
				friend LRESULT CALLBACK WndProc_DLGMDruckEinstellung(HWND hWndDlg, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
				friend void __vectorcall frDruckEinstellung_WM_Paint(GUI::CODialog* pDialog, PAINTSTRUCT& stPaint);
				friend void __vectorcall frDruckEinstellung_WM_Command(HWND hWndDlg, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

			private:
				GUI::COKlappBox* kbDrucker;
				GUI::COEditZeile* ezVon;
				GUI::COEditZeile* ezBis;
				GUI::COEditZeile* ezKopien;
				GUI::COSchalterGruppe* sgSeiten;
				GUI::COKnopf* kDrucker;
				GUI::COKnopf* kDrucken;
				GUI::COKnopf* kVorschau;
				GUI::COKnopf* kSchliessen;
				unsigned long ulVonSeite;
				unsigned long ulBisSeite;
				unsigned long ulKopien;
				void __vectorcall WM_Create(HWND hWnd);
				void __vectorcall Text_Von(void);
				void __vectorcall Text_Bis(void);
				void __vectorcall Text_Kopien(void);

			protected:

			public:
				void __vectorcall CODLGMDruckEinstellungV(const char* pcTitel);
				unsigned long __vectorcall VonSeite(void);
				unsigned long __vectorcall BisSeite(void);
				unsigned long __vectorcall Kopien(void);
				void __vectorcall SetzKopien(unsigned long ulKopienA);
				void __vectorcall Drucker(COStringA* vasName);

			};
			//-------------------------------------------------------------------------------------------------------------------------------------
			class __declspec(dllimport) CODrucken
			{
			private:
				DEVMODE* vstDevMode;
				RECT rcSeite;
				unsigned long ulSeite;
				COList* vlSeiten;
				COStringA* vasDokument;
				CODLGMDruckEinstellung* dlgmDruckEinstellung;

			protected:

			public:
				void __vectorcall CODruckenV(HWND hWndHaupt, const char* pcTitel, unsigned long ulSeitenhohe, unsigned long ulSeitenbreite);
				VMEMORY __vectorcall COFreiV(void);
				void __vectorcall SeitenGrosse_mm(SIZE& stGrosse);
				HDC __vectorcall NeueSeite(void);
				void __vectorcall EndeSeite(HDC hdcEnh);
				void __vectorcall LoschSeiten(void);
				HENHMETAFILE __vectorcall Seite(void);
				void __vectorcall SetzSichtbar(void);
				void __vectorcall SetzSeitenNummer(unsigned long ulNummer);
				unsigned long __vectorcall SeitenNummer(void);
				void __vectorcall Drucken(void);
				void __vectorcall Drucker(HWND hWndDlg);
				void (__vectorcall* pfnDrucken)(CODrucken*);
				COStream* vsmDaten;
				CODLGDruckVorschau* dlgDruckVorschau;

			};
			__declspec(dllimport) CODrucken* __vectorcall CODruckenV(HWND hWndHaupt, const char* pcTitel, unsigned long ulSeitenhoehe_mm, unsigned long ulSeitenbreite_mm);
			__declspec(dllimport) CODrucken* vDrucken;
			//-------------------------------------------------------------------------------------------------------------------------------------
#define _TextLinks(hdcEmf, ulx, uly, pcText, uiZeichen) (TextOut(hdcEmf, ulx, uly, pcText, uiZeichen))
#define _MMzuPixel_HDC(hdc, iIndex, iMillimeter) (GetDeviceCaps(hdc, iIndex) * iMillimeter / 25.4)
#define _MMzuPixel(idpi, iMillimeter) (idpi * iMillimeter / 25.4)
#define _Schrifthohe(hdc, iPixel, idpi) (-MulDiv(iPixel, GetDeviceCaps(hdc, LOGPIXELSY), idpi))
			//-------------------------------------------------------------------------------------------------------------------------------------
			__declspec(dllimport) void __vectorcall TextMitte(HDC hdcEmf, unsigned long& uly, RECT& rcText, char* pcText);
			__declspec(dllimport) void __vectorcall TextMitte(HDC hdcEmf, unsigned long& uly, RECT& rcText, COStringA* vasText);
			__declspec(dllimport) void __vectorcall TextRechts(HDC hdcEmf, unsigned long& uly, RECT& rcText, char* pcText);
			__declspec(dllimport) void __vectorcall TextRechts(HDC hdcEmf, unsigned long& uly, RECT& rcText, COStringA* vasText);
			//-------------------------------------------------------------------------------------------------------------------------------------
		}
	}
}

#endif