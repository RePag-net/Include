/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: StdElemDX.h
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
#ifndef StdElemDXH
#define StdElemDXH
//#ifndef HPROGDLGDX
#include "ProgDlgDX.h"
//#endif
namespace RePag
{
	namespace DirectX
	{
		//---------------------------------------------------------------------------------------------------------------------------------------
		#define TXA_OBEN 0
		#define TXA_LINKS 1
		#define TXA_RECHTS 2
		#define TXA_UNTEN 4
		#define TXA_MITTEVERTICAL 8
		#define TXA_MITTEHORIZONTAL 16

		#define ZV_KEINE 0
		#define ZV_BUCHSTABEN 1
		#define ZV_ZIFFERN 2
		#define ZV_SONDERBUCHSTABEN 4
		#define ZV_SONDERZEICHEN 8
		#define ZV_UBERLANGE 16
		#define ZV_SICHTBAR 32
		#define ZV_ALLE 15

		#define SGM_KEINWECHSEL 0
		#define SGM_EINAUS 1
		#define SGM_EINAUSINAKTIV 2

		#define BI_PIXEL 0
		#define BI_MILLIMETER 1

		#define LEF_RUND 0
		#define LEF_ECKIG 1

		typedef struct STFont
		{
			const WCHAR* fontFamilyName;
			IDWriteFontCollection* fontCollection;
			DWRITE_FONT_WEIGHT fontWeight;
			DWRITE_FONT_STYLE fontSytle;
			DWRITE_FONT_STRETCH fontStretch;
			float fontSize;
			const WCHAR* localeName;
		} STFont;
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COTextLine : public COGraphic
		{
			friend LRESULT CALLBACK WndProc_TextLine(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

			private:

			protected:
			//LOGFONT lfSchrift;
			//HFONT hFont;
			COStringA* vasInhalt;
			STFont stFont;
			IDWriteTextFormat* ifText;
			D2D1_COLOR_F crfText;
			ID2D1SolidColorBrush* ifTextColor;
			long lZeichen_mittel;
			long lZeichen_hohe;
			unsigned char ucSchriftausrichtung;
			void __vectorcall OnRender(void);
			void __vectorcall OnPaint(void);
			void __vectorcall WM_Create(void);
			void __vectorcall CharacterMetric(void);
			//void __vectorcall Schriftausrichtung(HDC hdc, SIZE& stZeichengrosse, POINT& ptText);
			void __vectorcall TextAlignment(_In_ IDWriteTextLayout* ifTextLayout, _Out_ float& fTextWidth, _Out_ D2D1_POINT_2F& ptfText);
			void __vectorcall TextAlignment(_In_ IDWriteTextLayout* ifTextLayout, _Out_ float& fTextWidth, _Out_ D2D1_RECT_F& rcfText);
			void __vectorcall COTextLineV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcKlassenName, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElementA,
																		_In_ STDeviceResources* pstDeviceResourcesA);

			public:
			void __vectorcall COTextLineV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_z_ unsigned int uiIDElementA,
																		_In_ STDeviceResources* pstDeviceResourcesA);
			VMEMORY __vectorcall COFreiV(void);
			void __vectorcall Text(_In_z_ char* pcText);
			void __vectorcall Font(STFont& stFont);
			COStringA* __vectorcall Content(_Out_ COStringA* vasInhaltA);
			void __vectorcall SetTextColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetTextColor(_In_ D2D1_COLOR_F& crfTextA);
			void __vectorcall TextAlignment(_In_ unsigned char ucTextAlignment);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COTextLine* __vectorcall COTextLineV(_In_z_ const char* pcFensterName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COTextLine* __vectorcall COTextLineV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, unsigned int uiIDElement,
																															 _In_ STDeviceResources* pstDeviceResourcesA);
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COEditLine : public COTextLine
		{
			friend LRESULT CALLBACK WndProc_EditLine(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
			friend void CALLBACK Timer_Caret(void* pvParam, bool bTimerOrWaitFired);

			private:
			COStringA* vasZeichenMaske;
			bool __vectorcall ZeichenMaske_Einfugen(WPARAM wParam);
			bool __vectorcall ZeichenMaske_Einfugen_Prufen(WPARAM wParam, VMBLOCK vbZeichen_Maske);
			bool __vectorcall ZeichenMaske_Loschen(void);
			bool __vectorcall ZeichenMaske_FestRechts(void);
			bool __vectorcall ZeichenMaske_FestLinks(void);
			void __vectorcall DeSelect(void);
			void __vectorcall Select_Loschen();
			void __vectorcall ScrollRight(SIZE& stZeichengrosse);
			void __vectorcall ScrollLeft(SIZE& stZeichengrosse);

			protected:
			HMENU hMenu;
			POINT ptlCaret;
			HANDLE htCaret;
			HANDLE heCaret;
			char cSelect;
			RECT rclSelect;
			RECT rclScroll;
			POINT ptlScrollOffset;
			long lTextPos;
			unsigned long ulZeichen_max;
			unsigned char ucZeichenVorgabe;
			unsigned long ulZeichenPos;
			unsigned long ulSelectPos;
			D2D1_COLOR_F crfSelectText;
			D2D1_COLOR_F crfSelectBack;
			D2D1_COLOR_F crfCaret;
			ID2D1SolidColorBrush* ifSelectBackColor;
			ID2D1SolidColorBrush* ifCaretColor;
			//STRGBFarbe stSelectSchriftfarbe;
			//STRGBFarbe stSelectHintergrundfarbe;
			void __vectorcall OnRender(_In_ bool bCaret);
			void __vectorcall OnPaint(void);
			void __vectorcall WM_Create(void);
			void __vectorcall WM_SetFocus(void);
			void __vectorcall WM_KillFocus(void);
			void __vectorcall WM_KeyDown(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_Char(WPARAM wParam);
			bool __vectorcall WM_Command(WPARAM wParam);
			void __vectorcall WM_ContexMenu(LPARAM lParam);
			void __vectorcall WM_LButtonUp(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_LButtonDown(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_MouseMove(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_LButtonDBClick(WPARAM wParam, LPARAM lParam);
			bool __vectorcall ZeichenVorgabe(WPARAM wParam);
			void __vectorcall GetTextPoint(_In_ char* pcText, _In_ unsigned long ulTextLength, _Out_ SIZE& stTextPoint);
			void __vectorcall DeleteCaretPos(void);
			void __vectorcall SetCaretColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetCaretColor(_In_ D2D1_COLOR_F& crfCaretA);
			void __vectorcall COEditLineV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcKlassenName, _In_ const char* pcFensterName, _In_ unsigned int uiIDElementA,
																		_In_ STDeviceResources* pstDeviceResourcesA);

			public:
			void __vectorcall COEditLineV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcFensterName, _In_ unsigned int uiIDElementA,
																		_In_ STDeviceResources* pstDeviceResourcesA);
			VMEMORY __vectorcall COFreiV(void);
			void(__vectorcall* pfnWM_Char_Return)(COEditLine*);
			void(__vectorcall* pfnWM_Char_Escape)(COEditLine*);
			void(__vectorcall* pfnWM_KillFocus)(COEditLine*);
			bool(__vectorcall* pfnWM_Command)(COEditLine*, WPARAM);
			void(__vectorcall* pfnWM_LButtonDown)(COEditLine*, WPARAM, LPARAM);
			void(__vectorcall* pfnWM_LButtonUp)(COEditLine*, WPARAM, LPARAM);
			void(__vectorcall* pfnWM_LButtonDBClick)(COEditLine*, WPARAM, LPARAM);
			void __vectorcall SetzVerfugbar(bool bVerfugbar);
			void __vectorcall Text(char* pcText);
			void __vectorcall SetSelectTextColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetSelectTextColor(_In_ D2D1_COLOR_F& crfSelectTextA);
			void __vectorcall SetSelectBackgroundColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetSelectBackgroundColor(_In_ D2D1_COLOR_F& crfSelectBackA);
			void __vectorcall SetzZeichen_Max(unsigned long ulZeichen);
			unsigned long __vectorcall Zeichen_Max(void);
			void __vectorcall Zeichenvorgabe(unsigned char ucZeichenvorgabeA);
			void __vectorcall Zeichenmaske(const char* pcZeichenmaske);
			COStringA* __vectorcall Zeichenmaske(COStringA* pasZeichenmaske);
			void __vectorcall SelectAlles(void);
			void __vectorcall SelectEntfernen(void);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COEditLine* __vectorcall COEditLineV(_In_ const char* pcFensterName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COEditLine* __vectorcall COEditLineV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcFensterName, _In_ unsigned int uiIDElement,
																															 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
		typedef struct STScrollInfo
		{
			long lMin;
			long lMax;
			ULONG ulPage;
			long  lPos;
		}; STScrollInfo;
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COScrollBar : public COGraphic
		{

			friend LRESULT CALLBACK WndProc_ScrollBar(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

			private:
			STScrollInfo stScrollInfo;
			BYTE ucDirty;
			bool bMouseTracking;
			TRACKMOUSEEVENT stTrackMouseEvent;
			ID2D1RectangleGeometry* ifButton_Up;
			ID2D1RectangleGeometry* ifButton_Down;
			D2D1_COLOR_F crfButton;
			D2D1_COLOR_F crfButton_Click;
			D2D1_COLOR_F crfButton_Move;
			ID2D1SolidColorBrush* ifButtonColor;
			ID2D1PathGeometry* ifArrow_Up;
			ID2D1PathGeometry* ifArrow_Down;
			D2D1_COLOR_F crfArrow;
			D2D1_COLOR_F crfArrow_Click;
			D2D1_COLOR_F crfArrow_Move;
			ID2D1SolidColorBrush* ifArrowColor;
			FLOAT fScaleArrowThumb;
			D2D1_POINT_2F ptf3Arrow_Up[3];
			D2D1_POINT_2F ptf3Arrow_Down[3];
			ID2D1RoundedRectangleGeometry* ifThumb;
			D2D1_COLOR_F crfThumb;
			D2D1_COLOR_F crfThumb_Click;
			D2D1_COLOR_F crfThumb_Move;
			ID2D1SolidColorBrush* ifThumbColor;
			D2D1_RECT_L rclThumb;
			long lThumb_Hohe;
			void __vectorcall CreateThumb(bool bRender);

			protected:
			void __vectorcall OnRender(void);
			void __vectorcall OnPaint(void);
			void __vectorcall WM_Create(void);
			void __vectorcall WM_MouseMove(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_MouseLeave(void);
			void __vectorcall WM_MouseOver(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_LButtonDown(WPARAM wParam, LPARAM lParam);
			void __vectorcall WM_LButtonUp(WPARAM wParam, LPARAM lParam);
			void __vectorcall COScrollBarV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcKlassenName, _In_z_ const char* pcFensterName,
																		 _In_ unsigned int uiIDElementA, _In_ STDeviceResources* pstDeviceResourcesA);

			public:
			void __vectorcall COScrollBarV(_In_ VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElementA,
																		 _In_ STDeviceResources* pstDeviceResources);
			VMEMORY __vectorcall COFreiV(void);
			void __vectorcall GetScrollInfo(_In_ STScrollInfo& stScrollInfoA);
			void __vectorcall SetScrollInfo(_In_ STScrollInfo& stScrollInfoA);
			void __vectorcall ScaleArrowThumb(_In_ float fScale);
			void __vectorcall SetButtonColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetButtonColor(_In_ D2D1_COLOR_F& crfButtonA);
			void __vectorcall SetButtonColor_Move(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetButtonColor_Move(_In_ D2D1_COLOR_F& crfButton_MoveA);
			void __vectorcall SetButtonColor_Click(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetButtonColor_Click(_In_ D2D1_COLOR_F& crfButton_ClickA);
			void __vectorcall SetArrowColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetArrowColor(_In_ D2D1_COLOR_F& crfArrowA);
			void __vectorcall SetArrowColor_Move(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetArrowColor_Move(_In_ D2D1_COLOR_F& crfArrow_MoveA);
			void __vectorcall SetArrowColor_Click(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetArrowColor_Click(_In_ D2D1_COLOR_F& crfArrow_ClickA);
			void __vectorcall SetThumbColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetThumbColor(_In_ D2D1_COLOR_F& crfThumbA);
			void __vectorcall SetThumbColor_Move(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetThumbColor_Move(_In_ D2D1_COLOR_F& crfThumb_MoveA);
			void __vectorcall SetThumbColor_Click(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
			void __vectorcall SetThumbColor_Click(_In_ D2D1_COLOR_F& crfThumb_ClickA);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COScrollBar* __vectorcall COScrollBarV(_In_z_ const char* pcFensterName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COScrollBar* __vectorcall COScrollBarV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElement,
																																 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COTextBox : public COEditLine
		{
			friend LRESULT CALLBACK WndProc_TextBox(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

			private:
			STScrollInfo stScrollInfo_Horz;
			STScrollInfo stScrollInfo_Vert;
			void __vectorcall Text_Create(HWND hWnd);
			void __vectorcall OnRender(void);

			protected:
			COList* vliText;
			long lBreitesteZeile;
			long lRand_rechts;
			long lRand_unten;
			void __vectorcall WM_Create(HWND hWnd);
			void __vectorcall WM_Size(LPARAM lParam);
			void __vectorcall WM_VScroll(WPARAM wParam);
			void __vectorcall WM_HScroll(WPARAM wParam);
			void __vectorcall WM_LButtonDown(void);
			void __vectorcall WM_MouseWheel(WPARAM wParam, LPARAM lParam);
			void __vectorcall SetzScrollHorz(STScrollInfo& stScrollHorz);
			void __vectorcall SetzScrollVert(STScrollInfo& stScrollVert);
			void __vectorcall GetScrollInfo(int iBar, STScrollInfo& stScrollInfo);
			void __vectorcall SetScrollInfo(int iBar, STScrollInfo& stScrollInfo, bool bredraw);
			void __vectorcall DeSelect(void);
			void __vectorcall COTextBoxV(VMEMORY vmSpeicher, const char* pcKlassenName, const char* pcFensterName, unsigned int uiIDElementA,
																	 _In_ STDeviceResources* pstDeviceResourcesA);

			public:
			void __vectorcall COTextBoxV(VMEMORY vmSpeicher, const char* pcFensterName, unsigned int uiIDElementA,
																	 _In_ STDeviceResources* pstDeviceResources);
			VMEMORY __vectorcall COFreiV(void);
			void __vectorcall Text(char* pcText);
			void __vectorcall Text_NeueZeile(char* pcText);
			unsigned long __vectorcall Zeilenanzahl(void);
			long __vectorcall BreitesteZeile(void);
			void __vectorcall Scroll_Anfang(void);
			void __vectorcall Scroll_Ende(void);
			void __vectorcall Scroll_Zeile(bool bAbwarts);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COTextBox* __vectorcall COTextBoxV(_In_ const char* pcFensterName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COTextBox* __vectorcall COTextBoxV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcFensterName, _In_ unsigned int uiIDElement,
																														 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
	}
}
#endif