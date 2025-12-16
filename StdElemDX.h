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
		constexpr BYTE  TXA_TOP = 0;
		constexpr BYTE  TXA_LEFT = 1;
		constexpr BYTE  TXA_RIGHT = 2;
		constexpr BYTE  TXA_BOTTOM = 4;
		constexpr BYTE  TXA_CENTERVERTICAL = 8;
		constexpr BYTE  TXA_CENTERHORIZONTAL = 16;

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

		constexpr BYTE SBI_MAX = 1;
		constexpr BYTE SBI_PAGE = 2;
		constexpr BYTE SBI_POS = 4;
		constexpr BYTE SBI_CHARACTER_WIDTH = 8;
		constexpr BYTE SBI_CHARACTER_HEIGHT = 16;
		constexpr BYTE SBI_ALL = 31;

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
				void __vectorcall OnRender(void);

			protected:
				COStringA* vasContent;
				STFont stFont;
				IDWriteTextFormat* ifText;
				D2D1_COLOR_F crfText;
				ID2D1SolidColorBrush* ifTextColor;
				D2D_SIZE_F szfCharacter;
				float fTextLine_maxwidth;
				unsigned char ucTextAlignment;
				void __vectorcall WM_Create(void);
				void __vectorcall CharacterMetric(void);
				void __vectorcall TextAlignment(_In_ IDWriteTextLayout* ifTextLayout, _Out_ float& fTextWidth, _Out_ D2D1_POINT_2F& ptfText);
				void __vectorcall TextAlignment(_In_ IDWriteTextLayout* ifTextLayout, _Out_ float& fTextWidth, _Out_ D2D1_RECT_F& rcfText);
				void __vectorcall COTextLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcClassName, _In_z_ const char* pcWindowName,
																			_In_ unsigned int uiIDElementA,	_In_ STDeviceResources* pstDeviceResourcesA);

			public:
				void __vectorcall COTextLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																			_In_ STDeviceResources* pstDeviceResourcesA);
				VMEMORY __vectorcall COFreiV(void);
				void __vectorcall Text(_In_z_ char* pcText);
				void __vectorcall Font(STFont& stFont);
				COStringA* __vectorcall Content(_Out_ COStringA* vasInhaltA);
				void __vectorcall SetTextColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
				void __vectorcall SetTextColor(_In_ D2D1_COLOR_F& crfTextA);
				void __vectorcall TextAlignment(_In_ unsigned char ucTextAlignmentA);
				void __vectorcall OnPaint(void);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COTextLine* __vectorcall COTextLineV(_In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COTextLine* __vectorcall COTextLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement,
																															 _In_ STDeviceResources* pstDeviceResourcesA);
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllexport) COEditLine : public COTextLine
		{
			friend LRESULT CALLBACK WndProc_EditLine(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);
			friend void CALLBACK Timer_Caret(_In_ void* pvParam, _In_ bool bTimerOrWaitFired);

			private:
				COStringA* vasZeichenMaske;
				bool __vectorcall ZeichenMaske_Einfugen(_In_ WPARAM wParam);
				bool __vectorcall ZeichenMaske_Einfugen_Prufen(_In_ WPARAM wParam, _In_ VMBLOCK vbZeichen_Maske);
				bool __vectorcall ZeichenMaske_Loschen(void);
				bool __vectorcall ZeichenMaske_FestRechts(void);
				bool __vectorcall ZeichenMaske_FestLinks(void);
				void __vectorcall DeSelect(void);
				void __vectorcall Select_Loschen(void);

			protected:
				HMENU hMenu;
				HANDLE htCaret;
				HANDLE heCaret;
				D2D_POINT_2F ptfCaret;
				BYTE ucCaretStrength;
				char cSelect;
				D2D1_RECT_F rcfSelect;
				float fTextPos;
				unsigned long ulZeichen_max;
				unsigned char ucZeichenVorgabe;
				unsigned long ulCharacterPos;
				unsigned long ulSelectPos;
				D2D1_COLOR_F crfSelectText;
				D2D1_COLOR_F crfSelectBack;
				D2D1_COLOR_F crfCaret;
				ID2D1SolidColorBrush* ifSelectBackColor;
				ID2D1SolidColorBrush* ifCaretColor;
				void __vectorcall OnRender(_In_ bool bCaret);
				void __vectorcall OnPaint(void);
				void __vectorcall WM_Create(void);
				void __vectorcall WM_SetFocus(void);
				void __vectorcall WM_KillFocus(void);
				void __vectorcall WM_KeyDown(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_Char(_In_ WPARAM wParam);
				bool __vectorcall WM_Command(_In_ WPARAM wParam);
				void __vectorcall WM_ContexMenu(_In_ LPARAM lParam);
				void __vectorcall WM_LButtonUp(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_LButtonDown(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_MouseMove(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_LButtonDBClick(_In_ WPARAM wParam, _In_ LPARAM lParam);
				bool __vectorcall ZeichenVorgabe(_In_ WPARAM wParam);
				void __vectorcall GetTextPoint(_In_ char* pcText, _In_ unsigned long ulTextLength, _Out_ D2D_SIZE_F& szfTextPoint);
				inline long __vectorcall FloatToLong(_In_ float fNumber);
				void __vectorcall DeleteCaretPos(void);
				void __vectorcall SetCaretColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
				void __vectorcall SetCaretColor(_In_ D2D1_COLOR_F& crfCaretA);
				void __vectorcall COEditLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcClassName, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																			_In_ STDeviceResources* pstDeviceResourcesA);

			public:
				void __vectorcall COEditLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																			_In_ STDeviceResources* pstDeviceResourcesA);
				VMEMORY __vectorcall COFreiV(void);
				void(__vectorcall* pfnWM_Char_Return)(_In_ COEditLine*);
				void(__vectorcall* pfnWM_Char_Escape)(_In_ COEditLine*);
				void(__vectorcall* pfnWM_KillFocus)(_In_ COEditLine*);
				bool(__vectorcall* pfnWM_Command)(_In_ COEditLine*, _In_  WPARAM);
				void(__vectorcall* pfnWM_LButtonDown)(_In_ COEditLine*, _In_ WPARAM, _In_ LPARAM);
				void(__vectorcall* pfnWM_LButtonUp)(_In_ COEditLine*, _In_ WPARAM, _In_ LPARAM);
				void(__vectorcall* pfnWM_LButtonDBClick)(_In_ COEditLine*, _In_ WPARAM, _In_ LPARAM);
				void __vectorcall SetzVerfugbar(_In_ bool bVerfugbar);
				void __vectorcall Text(_In_ char* pcText);
				void __vectorcall SetSelectTextColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
				void __vectorcall SetSelectTextColor(_In_ D2D1_COLOR_F& crfSelectTextA);
				void __vectorcall SetSelectBackgroundColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
				void __vectorcall SetSelectBackgroundColor(_In_ D2D1_COLOR_F& crfSelectBackA);
				void __vectorcall SetzZeichen_Max(_In_ unsigned long ulZeichen);
				unsigned long __vectorcall Zeichen_Max(void);
				void __vectorcall Zeichenvorgabe(_In_ unsigned char ucZeichenvorgabeA);
				void __vectorcall Zeichenmaske(_In_ const char* pcZeichenmaske);
				COStringA* __vectorcall Zeichenmaske(_In_ COStringA* pasZeichenmaske);
				void __vectorcall SelectAlles(void);
				void __vectorcall SelectEntfernen(void);
				void __vectorcall CaretStrength(_In_ BYTE ucCaretStrengthA);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllexport) COEditLine* __vectorcall COEditLineV(_In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllexport) COEditLine* __vectorcall COEditLineV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement,
																															 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
		typedef struct STScrollInfo
		{
			float fMax;
			float fPage;
			float fPos;
			BYTE ucMask;
			D2D_SIZE_F szfCharacter;
		} STScrollInfo;
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COScrollBar : public COGraphic
		{

			friend LRESULT CALLBACK WndProc_ScrollBar(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);

			private:
				bool bHorizontal;
				STScrollInfo siScrollInfo;
				BYTE ucDirty;
				bool bMouseTracking;
				TRACKMOUSEEVENT stTrackMouseEvent;
				ID2D1RectangleGeometry* ifButton_Up;
				ID2D1RectangleGeometry* ifButton_Down;
				ID2D1SolidColorBrush* ifButtonColor_Up;
				ID2D1SolidColorBrush* ifButtonColor_Down;
				D2D1_COLOR_F crfButton;
				D2D1_COLOR_F crfButton_Click;
				D2D1_COLOR_F crfButton_Move;
				ID2D1PathGeometry* ifArrow_Up;
				ID2D1PathGeometry* ifArrow_Down;
				ID2D1SolidColorBrush* ifArrowColor_Up;
				ID2D1SolidColorBrush* ifArrowColor_Down;
				D2D1_COLOR_F crfArrow;
				D2D1_COLOR_F crfArrow_Click;
				D2D1_COLOR_F crfArrow_Move;
				ID2D1RoundedRectangleGeometry* ifThumb;
				ID2D1SolidColorBrush* ifThumbColor;
				D2D1_COLOR_F crfThumb;
				D2D1_COLOR_F crfThumb_Click;
				D2D1_COLOR_F crfThumb_Move;
				D2D1_RECT_F rcfThumb;
				float fScaleArrowThumb;
				float fThumb;
				float fStep;
				void __vectorcall Geometry(void);
				void __vectorcall CreateThumb(_In_ bool bRender);

			protected:
				void __vectorcall OnRender(void);
				void __vectorcall WM_Create(void);
				void __vectorcall WM_MouseMove(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_MouseLeave(void);
				void __vectorcall WM_MouseOver(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_LButtonDown(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_LButtonUp(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall WM_VScroll(_In_ WPARAM wParam);
				void __vectorcall WM_HScroll(_In_ WPARAM wParam);
				void __vectorcall COScrollBarV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcClassName, _In_z_ const char* pcWindowName,
																			 _In_ unsigned int uiIDElementA, _In_ STDeviceResources* pstDeviceResourcesA, bool bHorizontalA);

			public:
				void __vectorcall COScrollBarV(_In_ VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																			 _In_ STDeviceResources* pstDeviceResources, bool bHorizontalA);
			VMEMORY __vectorcall COFreiV(void);
				void __vectorcall GetScrollInfo(_In_ STScrollInfo& siScrollInfoA);
				void __vectorcall SetScrollInfo(_In_ STScrollInfo& siScrollInfoA);
				void __vectorcall NewSize(_In_ long lHeightA, _In_ long lWidthA, _In_ long lPos_x, _In_ long lPos_y);
				void __vectorcall NewWidth(_In_ long lWidthA);
				void __vectorcall NewHeight(_In_ long lHeightA);
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
				void __vectorcall OnPaint(void);
		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COScrollBar* __vectorcall COScrollBarV(_In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement,
																																 _In_ STDeviceResources* pstDeviceResources, bool bHorizontal);
		__declspec(dllimport) COScrollBar* __vectorcall COScrollBarV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement,
																																 _In_ STDeviceResources* pstDeviceResources, _In_ bool bHorizontal);
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COTextBox : public COEditLine
		{
			friend LRESULT CALLBACK WndProc_TextBox(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);

			private:
				COScrollBar* sbHorizontal;
				COScrollBar* sbVertical;
				void __vectorcall CreateText(void);
				void __vectorcall ChangeSizeVisibleScrollBars(void);

			protected:
				COList* vliText;
				BYTE ucScrollBarSize;
				void __vectorcall OnRender(void);
				void __vectorcall WM_Create(void);
				void __vectorcall WM_Size(_In_ LPARAM lParam);
				void __vectorcall WM_VHScroll(_In_ WPARAM wParam);
				void __vectorcall WM_KeyDown(_In_ WPARAM wParam);
				void __vectorcall WM_LButtonDown(void);
				void __vectorcall WM_MouseWheel(_In_ WPARAM wParam, _In_ LPARAM lParam);
				void __vectorcall GetScrollBar(_In_ BYTE ucBar, _Out_ STScrollInfo& siScrollInfo);
				void __vectorcall SetScrollBar(_In_ BYTE ucBar, _In_ STScrollInfo& stScrollInfo);
				void __vectorcall COTextBoxV(_In_ VMEMORY vmMemory, _In_z_ const char* pcClassName, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																		 _In_ STDeviceResources* pstDeviceResourcesA); // Note: three numbers uiIDElement, because COScrollBars !!!

			public:
				void __vectorcall COTextBoxV(_In_ VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElementA,
																		 _In_ STDeviceResources* pstDeviceResources);
				VMEMORY __vectorcall COFreiV(void);
				void __vectorcall Text(_In_ char* pcText);
				void __vectorcall Text_NewLine(_In_ char* pcText, _In_ bool bDraw);
				unsigned long __vectorcall LineNumbers(void);
				void __vectorcall Scroll_Begin(void);
				void __vectorcall Scroll_End(void);
				void __vectorcall Scroll_Line(_In_ BYTE ucDown_UP);
				void __vectorcall ScrollBarSize(_In_ BYTE ucWidth_Height);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COTextBox* __vectorcall COTextBoxV(_In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COTextBox* __vectorcall COTextBoxV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ unsigned int uiIDElement,
																														 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
		class __declspec(dllimport) COListBox : public COTextBox
		{
			friend LRESULT CALLBACK WndProc_ListBox(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);

			private:
			unsigned char ucIndex;

			protected:
			void __vectorcall WM_LButtonUp(_In_ LPARAM lParam);
			void __vectorcall WM_VScroll(_In_ WPARAM wParam);
			void __vectorcall WM_HScroll(_In_ WPARAM wParam);
			void __vectorcall WM_KeyDown(_In_ WPARAM wParam);
			void __vectorcall WM_Char(_In_ WPARAM wParam);
			void __vectorcall DeSelect(void);
			void __vectorcall COListBoxV(_In_ VMEMORY vmSpeicher, _In_z_ const char* pcKlassenName, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElementA,
																	 _In_ STDeviceResources* pstDeviceResourcesA); // Note: three numbers uiIDElement, because COScrollBars by COTextBox!!!

			public:
			void __vectorcall COListBoxV(_In_ VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElementA, _In_ STDeviceResources* pstDeviceResourcesA);
			VMEMORY __vectorcall COFreiV(void);
			void(__vectorcall* pfnWM_LButtonDown)(_In_ COListBox*);
			void(__vectorcall* pfnWM_LButtonUp)(_In_ COListBox*);
			void(__vectorcall* pfnWM_Char_Return)(_In_ COListBox*);
			void(__vectorcall* pfnWM_Char_Escape)(_In_ COListBox*);
			void(__vectorcall* pfnWM_KillFocus)(_In_ COListBox*);
			bool(__vectorcall* pfnWM_Command)(_In_ COListBox*, _In_ WPARAM);
			bool __vectorcall SetSelectIndex(_In_ unsigned char ucIndexA);
			unsigned char __vectorcall GetSelectIndex(void);
			COStringA* __vectorcall SelectEnum(_Out_ COStringA* vasEnum);
			COStringA* __vectorcall SetAndSearchEnum(_In_ unsigned char ucIndexA, _Out_ COStringA* vasEnum);
			bool __vectorcall SearchEnum(_In_ COStringA* vasEnum, _Out_ unsigned char& ucIndexA);
			bool __vectorcall SearchAndSetEnum(_In_ COStringA* vasEnum, _Out_ unsigned char& ucIndexA);
			unsigned long __vectorcall NUmberEnum(void);
			void __vectorcall DeSelectEnum(void);
			void __vectorcall Test(void);

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		__declspec(dllimport) COListBox* __vectorcall COListBoxV(_In_z_ const char* pcFensterName, _In_ unsigned int uiIDElement, _In_ STDeviceResources* pstDeviceResources);
		__declspec(dllimport) COListBox* __vectorcall COListBoxV(_In_ VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_ unsigned int uiIDElement,
																														 _In_ STDeviceResources* pstDeviceResources);
		//---------------------------------------------------------------------------------------------------------------------------------------
	}
}
#endif