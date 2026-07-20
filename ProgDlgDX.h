/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: ProgDlgDX.h
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
#ifndef ProgDlgDXH
#define ProgDlgDXH
#include <d3d11_4.h>
#include <d2d1_3.h>
#include <dxgi1_6.h>
#include <dwrite_3.h>
//-------------------------------------------------------------------------------------------------------------------------------------------
namespace RePag
{
  namespace DirectX
  {
    //---------------------------------------------------------------------------------------------------------------------------------------
    constexpr BYTE DLG_LEFT = 1;
    constexpr BYTE DLG_RIGHT = 2;
    constexpr BYTE DLG_TOP = 4;
    constexpr BYTE DLG_BOTTOM = 8;
    constexpr BYTE DLG_CENTERVERTICAL = 16;
    constexpr BYTE DLG_CENTERHORIZONTAL = 32;
    constexpr BYTE DLG_MINIMAL = 64;
    constexpr BYTE DLG_MAXIMAL = 128;
    constexpr USHORT IDE_DLG_VISIBLE = 0xFFFF;
    constexpr BYTE IDE_DLG_WM_QUIT = 0xFFFE;
    //---------------------------------------------------------------------------------------------------------------------------------------
    typedef struct STDeviceResources
    {
      ID2D1Factory7* ifd2d1Factory7;
      ID3D11Device5* ifD311Device5;
      ID2D1Device6* ifD2D1Device6;
      IDXGIFactory7* ifDXGIFactory7;
      IDWriteFactory7* ifdwriteFactory7;
      FLOAT dpiX;
      FLOAT dpiY;
    } STDeviceResources;
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) COElement
    {
      private:
        struct STThread
        {
          HANDLE heElement[2];
          DWORD dwMain;
          DWORD dwActiv;
          unsigned char ucFunction;
          unsigned char ucWait;
        };
        STThread stThread;

      protected:
        VMEMORY vmMemory;
        HWND hWndElement;
        HANDLE htEffect_Timer;
        long lHeight;
        long lWidth;
        POINT ptPosition;
        D2D1_COLOR_F crfBackground;
        ID2D1SolidColorBrush* ifBackColor;
        RECT rclDirty;
        DXGI_PRESENT_PARAMETERS dxgiPresent;
        void __vectorcall WM_Create_Element(_In_ HWND hWnd);
        void __vectorcall WM_Size_Element(_In_ HWND hWnd, _In_ LPARAM lParam);
        inline void __vectorcall ThreadSafe_Begin(void);
        inline void __vectorcall ThreadSafe_End(void);
        void __vectorcall COElementV(_In_ const VMEMORY vmMemoryA, _In_ STDeviceResources* pstDeviceResourcesA);

        STDeviceResources* pstDeviceResources;
        ID2D1DeviceContext6* ifD2D1Context6;
        IDXGISwapChain4* ifDXGISwapChain4;
        ID2D1Bitmap1* ifd2dBitmap1;
        IDXGISurface2* ifDXGIBackBuffer;
        void __vectorcall CreateWindowSizeDependentResources(void);

      public:
        VMEMORY __vectorcall COFreiV(void);
        void(__vectorcall* pfnWM_Size)(_In_ COElement*, _In_ WPARAM, _In_ LPARAM);
        HWND __vectorcall HWND_Element(void);
        HWND __vectorcall HWND_Main(void);
        long& __vectorcall Width(_Out_ long& lWidthA);
        long& __vectorcall Height(_Out_ long& lHeightA);
        long& __vectorcall Pos_X(_Out_ long& lPos_x);
        long& __vectorcall Pos_Y(_Out_ long& lPos_y);
        POINT& __vectorcall Position(_Out_ POINT& ptPositionA);
        RECT& __vectorcall Window(_Out_ RECT& rcWindow);
        void __vectorcall NewWindowPosition(_In_ long lPos_x, _In_ long lPos_y);
        void __vectorcall NewWindowPosition(_In_ POINT& ptPositionA);
        void __vectorcall NewWindow(long lHeightA, long lWidthA, long lPos_x, long lPos_y);
        void __vectorcall NewWindowSize(_In_ long lHeightA, _In_ long lWidthA);
        void __vectorcall NewWindowHeight(_In_ long lHeightA);
        void __vectorcall NewWindowWidth(_In_ long lWidthA);
        void __vectorcall ChangeWindowSize(_In_ long lHeightA, _In_ long lWidthA);
        void __vectorcall ChangeWindowPosition(_In_ long lPos_x, _In_ long lPos_y);
        void __vectorcall SetBackgroundColor(_In_ unsigned char ucRed, _In_ unsigned char ucGreen, _In_ unsigned char ucBlue, _In_ unsigned char ucAlpha);
        void __vectorcall SetBackgroundColor(_In_ D2D1_COLOR_F& crfBackgroundA);
        void __vectorcall GetBackgroundColor(_Out_ D2D1_COLOR_F& crfBackgroundA);
        void __vectorcall Effect_Timer(_In_ bool bStart, _In_ unsigned long ulInterval_msek, _In_ void CALLBACK fnEffect_Timer(COElement*, bool bTimerOrWaitFired));

    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) CODialog : public COElement
    {
      friend LRESULT CALLBACK WndProc_Dialog(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);
      friend DWORD WINAPI thWM_Command_Dialog(_In_ void* pvParam);

      private:
        struct STWindowConstraction
        {
          COStringA asName;
          VMBLOCK vbTitel;
          DWORD dwWindowStyle;
          DWORD dwExtendStyle;
          WNDCLASSEX wndClass;
        };
        STWindowConstraction* vstWindowConstraction;
        long lReturn;
        bool bModal;
        DWORD dwThreadID;
        void __vectorcall WM_Move_Dialog(void);
        void __vectorcall WM_Paint_Dialog(void);
        void __vectorcall WM_Command_Dialog(_In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);
        LRESULT(CALLBACK* pfnWndProc_DLGDialog)(_In_ HWND, _In_ unsigned int, _In_ WPARAM, _In_ LPARAM);

      protected:
        void __vectorcall WM_Create(void);
        void __vectorcall WindowStyle(_In_ DWORD dwFensterStilA);
        void __vectorcall ExtendStyle(_In_ DWORD dwErweitertStilA);
        void __vectorcall WindowTitel(_In_ const char* pcFensterTitel);
        void __vectorcall Icon(_In_ long lIcon);
        void __vectorcall IconSm(_In_ long lIconSm);
        void __vectorcall Menu(_In_ long lMenu);

      public:
        void __vectorcall CODialogV(_In_z_ const char* pcWindowName, _In_ bool bModalA, _In_ LRESULT CALLBACK WndProc_DLG(HWND, unsigned int, WPARAM, LPARAM),
                                    _In_ STDeviceResources* pstDeviceResourcesA);
        void __vectorcall CODialogV(_In_ const VMEMORY vmMemory, _In_z_ const char* pcWindowName, _In_ bool bModalA,
                                    _In_ LRESULT CALLBACK WndProc_DLG(HWND, unsigned int, WPARAM, LPARAM), _In_ STDeviceResources* pstDeviceResourcesA);
        VMEMORY __vectorcall COFreiV(void);
        LRESULT(CALLBACK* pfnWndProc_Dialog)(_In_ HWND, _In_ unsigned int, _In_ WPARAM, _In_ LPARAM);
        void(__vectorcall* pfnWM_Move)(_In_ CODialog*, LPARAM);
        void(__vectorcall* pfnWM_Command)(_In_ HWND, _In_ unsigned int, _In_ WPARAM, _In_ LPARAM);
        void __vectorcall CreateWindowDialog(_In_ HWND hWndMain, _In_ long lHeightA, _In_ long lWidthA, _In_ long lPos_x, _In_ long lPos_y);
        long __vectorcall SetVisible(_In_ bool bSichtbar, _In_ unsigned char ucAusrichtung, _In_ long lRuckgabeA);
        void __vectorcall Close(void);

    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) COGraphic : public COElement
    {
      private:
        struct STWindowConstraction
        {
          VMBLOCK vbClassName;
          COStringA asWindowName;
          DWORD dwWindowStyle;
          DWORD dwExtendStyle;
          unsigned int uiIDElement;
        };
        STWindowConstraction* vstWindowConstraction;

        protected:
        void __vectorcall COGraphicV(_In_ const VMEMORY vmMemory, _In_ const char* pcClassName, _In_ const char* pcWindowName, _In_ unsigned int uiElementA,
                                     _In_ STDeviceResources* pstDeviceResourcesA);
        HANDLE heRender;

      public:
        VMEMORY __vectorcall COFreiV(void);
        void __vectorcall WindowStyle(_In_ DWORD dwWindowStyleA);
        void __vectorcall ExtendStyle(_In_ DWORD dwExtendStyleA);
        void __vectorcall CreateWindowGraphic(_In_ HWND hWndMain, _In_ long lHeightA, _In_ long lWidthA, _In_ long lPos_x, _In_ long lPos_y);
        unsigned int __vectorcall IDElement(void);
        void __vectorcall SetVisible(_In_ bool bVisible);
        bool __vectorcall Visible(void);
    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) COGraphicGroup : public COGraphic
    {
      friend LRESULT CALLBACK WndProc_GraphicGroup(_In_ HWND hWnd, _In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);
      friend DWORD WINAPI thWM_Command_GraphicGroup(_In_ void* pvParam);

      private:
        void __vectorcall WM_Paint(void);
        void __vectorcall WM_Command_GrafikGruppe(_In_ unsigned int uiMessage, _In_ WPARAM wParam, _In_ LPARAM lParam);

      protected:

      public:
        void __vectorcall COGraphicGroupV(_In_ const VMEMORY vmMemory, _In_ const char* pcWindowName, _In_ unsigned int uiDElementA,
                                          _In_ STDeviceResources* pstDeviceResourcesA);
        void __vectorcall CreteWindowInGroup(_In_ COGraphic* pGraphic, _In_ long lHeightA, _In_ long lWidthA, _In_ long lPos_x, _In_ long lPos_y);
        void(__vectorcall* pfnWM_Command)(_In_ HWND, _In_ unsigned int, _In_ WPARAM, _In_ LPARAM);
        void __vectorcall SetVisible(_In_ bool bVisible);
    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    __declspec(dllimport) COGraphicGroup* __vectorcall COGraphicGroupV(_In_ const char* pcWindowName, _In_ unsigned int uiIDElement,
                                                                       _In_ STDeviceResources* pstDeviceResourcesA);
    __declspec(dllimport) COGraphicGroup* __vectorcall COGraphicGroupV(_In_ const VMEMORY vmMemory, _In_ const char* pcWindowName, _In_ unsigned int uiIDElement,
                                                                       _In_ STDeviceResources* pstDeviceResourcesA);
    //---------------------------------------------------------------------------------------------------------------------------------------
    __declspec(dllimport) VMEMORY __vectorcall VMDialog(void);
    __declspec(dllimport) HINSTANCE __vectorcall Hinstance(void);
    __declspec(dllimport) HACCEL __vectorcall Accelerator(void);
    __declspec(dllimport) HANDLE __vectorcall TimerQueue(void);
    __declspec(dllimport) void __vectorcall Cursorform(_In_ const char* pcCursor);
    __declspec(dllimport) void __vectorcall InsertAccelerator(_In_ const ACCEL* pacTasten, _In_ int iNumber);
    __declspec(dllimport) HRESULT __vectorcall CreateDeviceIndependentResources(_Out_ STDeviceResources* pstDeviceResources);
    __declspec(dllimport) HRESULT __vectorcall CreateDeviceResources(_Out_ STDeviceResources* pstDeviceResources);
    //---------------------------------------------------------------------------------------------------------------------------------------
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------------
template<class Interface>
inline void SafeRelease(Interface** ppInterfaceToRelease)
{
  if(*ppInterfaceToRelease != NULL){
    (*ppInterfaceToRelease)->Release();

    (*ppInterfaceToRelease) = NULL;
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------------
#endif