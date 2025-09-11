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
    constexpr BYTE DLG_LINKS = 1;
    constexpr BYTE DLG_RECHTS = 2;
    constexpr BYTE DLG_OBEN = 4;
    constexpr BYTE DLG_UNTEN = 8;
    constexpr BYTE DLG_MITTEVERTICAL = 16;
    constexpr BYTE DLG_MITTEHORIZONTAL = 32;
    constexpr BYTE DLG_MINIMAL = 64;
    constexpr BYTE DLG_MAXIMAL = 128;
    constexpr USHORT IDE_DLG_SICHTBAR = 0xFFFF;

    constexpr BYTE HGE_KEINHINTERGRUND = 0;
    constexpr BYTE HGE_HINTERGRUND = 1;
    constexpr BYTE HGE_BELEUCHTUNG_H = 2;
    constexpr BYTE HGE_BELEUCHTUNG_V = 4;
    constexpr BYTE HGE_RAND_H = 8;
    constexpr BYTE HGE_RAND_V = 16;
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
        DWORD dwHaupt;
        DWORD dwAktiv;
        unsigned char ucFunktion;
        unsigned char ucWarten;
      };
      STThread stThread;
      HBITMAP hbmBild;
      bool bHintergrund;
      unsigned char ucHintergrundeffekt;
      D2D1_COLOR_F stBackColorEffect;
      void __vectorcall Hintergrund(RECT& rcZeichnen);
      void __vectorcall Hintergrund_Effekt(RECT* prcZeichnen);
      void __vectorcall Effekt_Beleuchtung_Horizontal(void);
      void __vectorcall Effekt_Beleuchtung_Vertical(void);
      void __vectorcall Effekt_Rand_Horizontal(void);
      void __vectorcall Effekt_Rand_Vertical(void);

      protected:
        VMEMORY vmSpeicher;
        HWND hWndElement;
        HANDLE htEffekt_Timer;
        long lHohe;
        long lBreite;
        POINT ptPosition;
        D2D1_COLOR_F stBackColor;
        ID2D1SolidColorBrush* ifBackColor;
        RECT rclDirty;
        DXGI_PRESENT_PARAMETERS dxgiPresent;
        RECT rcEffektrand;
        unsigned char ucRahmenbreite;
        void __vectorcall WM_Create_Element(HWND hWnd);
        void __vectorcall WM_Size_Element(HWND hWnd, LPARAM lParam);
        //void __vectorcall WM_Paint(void);
        //void __vectorcall WM_Paint_Hintergrund(PAINTSTRUCT& stPaint);
        inline void __vectorcall ThreadSicher_Anfang(void);
        inline void __vectorcall ThreadSicher_Ende(void);
        void __vectorcall COElementV(_In_ const VMEMORY vmSpeicherA, _In_ STDeviceResources* pstDeviceResourcesA);

        STDeviceResources* pstDeviceResources;
        ID2D1DeviceContext6* ifD2D1Context6;
        IDXGISwapChain4* ifDXGISwapChain4;
        ID2D1Bitmap1* ifd2dBitmap1;
        IDXGISurface2* ifDXGIBackBuffer;
        void __vectorcall CreateWindowSizeDependentResources(void);

      public:
      VMEMORY __vectorcall COFreiV(void);
      void(__vectorcall* pfnWM_Size)(COElement*, WPARAM, LPARAM);
      HWND __vectorcall HWND_Element(void);
      HWND __vectorcall HWND_Haupt(void);
      long& __vectorcall Breite(long& lBreiteA);
      long& __vectorcall Hohe(long& lHoheA);
      long& __vectorcall Pos_X(long& lPos_x);
      long& __vectorcall Pos_Y(long& lPos_y);
      POINT& __vectorcall Position(POINT& ptPositionA);
      RECT& __vectorcall Fenster(RECT& rcFenster);
      void __vectorcall NeueFensterPosition(long lPos_x, long lPos_y);
      void __vectorcall NeueFensterPosition(POINT& ptPositionA);
      void __vectorcall NeuesFenster(long lHoheA, long lBreiteA, long lPos_x, long lPos_y);
      void __vectorcall NeueFensterGrosse(long lHoheA, long lBreiteA);
      void __vectorcall NeueFensterHohe(long lHoheA);
      void __vectorcall NeueFensterBreite(long lBreiteA);
      void __vectorcall AndernFensterGrosse(long lHoheA, long lBreiteA);
      void __vectorcall AndernFensterPosition(long lPos_x, long lPos_y);
      void __vectorcall BackroundColor(_In_ unsigned char ucRot, _In_ unsigned char ucGrun, _In_ unsigned char ucBlau, _In_ unsigned char ucAlpha);
      void __vectorcall Hintergrundeffekt(unsigned char ucEffekt);
      void __vectorcall Hintergrundeffektfarbe(unsigned char ucRot, unsigned char ucGrun, unsigned char ucBlau, unsigned char ucAlpha);
      void __vectorcall Hintergrundeffektrand(long lOben, long lUnten, long lLinks, long lRechts);
      void __vectorcall Effekt_Timer(bool bStarten, unsigned long ulInterval_msek, void CALLBACK fnEffekt_Timer(COElement*, bool bTimerOrWaitFired));
      void __vectorcall UpdateFenster(RECT* prcFenster, bool bUpdateHintergrund, bool bUpdateHintergrundeffekt);
      void __vectorcall SetzHintergrund(bool bMitHintergrund);
      void __vectorcall SetzVerfugbar(bool bVerfugbar);
      bool __vectorcall Verfugbar(void);
      void __vectorcall Loschen(void);

    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) CODialog : public COElement
    {
      friend LRESULT CALLBACK WndProc_Dialog(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
      friend DWORD WINAPI thWM_Command_Dialog(void* pvParam);

      private:
        struct STFensterBau
        {
          COStringA asName;
          VMBLOCK vbTitel;
          DWORD dwFensterStil;
          DWORD dwErweitertStil;
          WNDCLASSEX wndKlasse;
        };
        STFensterBau* vstFensterBau;
        long lRuckgabe;
        bool bModal;
        DWORD dwThreadID;
        void __vectorcall WM_Move_Dialog(void);
        void __vectorcall WM_Paint_Dialog(void);
        void __vectorcall WM_Command_Dialog(unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
        LRESULT(CALLBACK* pfnWndProc_DLGDialog)(HWND, unsigned int, WPARAM, LPARAM);

      protected:
        void __vectorcall WM_Create(void);
        void __vectorcall FensterStil(DWORD dwFensterStilA);
        void __vectorcall ErweitertStil(DWORD dwErweitertStilA);
        void __vectorcall FensterTitel(const char* pcFensterTitel);
        void __vectorcall Icon(long lIcon);
        void __vectorcall IconSm(long lIconSm);
        void __vectorcall Menu(long lMenu);

      public:
        void __vectorcall CODialogV(_In_z_ const char* pcFensterName, _In_ bool bModalA, _In_ LRESULT CALLBACK WndProc_DLG(HWND, unsigned int, WPARAM, LPARAM),
                                    _In_ STDeviceResources* pstDeviceResourcesA);
        void __vectorcall CODialogV(_In_ const VMEMORY vmSpeicher, _In_z_ const char* pcFensterName, _In_ bool bModalA,
                                    _In_ LRESULT CALLBACK WndProc_DLG(HWND, unsigned int, WPARAM, LPARAM), _In_ STDeviceResources* pstDeviceResourcesA);
        VMEMORY __vectorcall COFreiV(void);
        LRESULT(CALLBACK* pfnWndProc_Dialog)(HWND, unsigned int, WPARAM, LPARAM);
        void(__vectorcall* pfnWM_Paint)(CODialog*, PAINTSTRUCT&);
        void(__vectorcall* pfnWM_Move)(CODialog*, LPARAM);
        void(__vectorcall* pfnWM_Command)(HWND, unsigned int, WPARAM, LPARAM);
        void __vectorcall ErstellFenster(HWND hWndHaupt, long lHoheA, long lBreiteA, long lPos_x, long lPos_y);
        long __vectorcall SetzSichtbar(bool bSichtbar, unsigned char ucAusrichtung, long lRuckgabeA);
        void __vectorcall Schliessen(void);
        LOGFONT lfSchrift;

    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) COGraphic : public COElement
    {
      private:
        struct STFensterBau
        {
          VMBLOCK vbKlassenName;
          COStringA asFensterName;
          DWORD dwFensterStil;
          DWORD dwErweitertStil;
          unsigned int uiIDElement;
        };
        STFensterBau* vstFensterBau;

        protected:
        void __vectorcall COGraphicV(_In_ const VMEMORY vmMemory, _In_ const char* pcClassName, _In_ const char* pcWindowName, _In_ unsigned int uiElementA,
                                     _In_ STDeviceResources* pstDeviceResourcesA);
        HANDLE heRender;

      public:
        VMEMORY __vectorcall COFreiV(void);
        void __vectorcall FensterStil(DWORD dwFensterStilA);
        void __vectorcall ErweitertStil(DWORD dwErweitertStilA);
        void __vectorcall ErstellFenster(HWND hWndHaupt, long lHoheA, long lBreiteA, long lPos_x, long lPos_y);
        unsigned int __vectorcall IDElement(void);
        void __vectorcall SetzSichtbar(bool bSichtbar);
        bool __vectorcall Sichtbar(void);
    };
    //---------------------------------------------------------------------------------------------------------------------------------------
    class __declspec(dllimport) COGraphicGroup : public COGraphic
    {
      friend LRESULT CALLBACK WndProc_GraphicGroup(HWND hWnd, unsigned int uiMessage, WPARAM wParam, LPARAM lParam);
      friend DWORD WINAPI thWM_Command_GraphicGroup(void* pvParam);

    private:
      void __vectorcall WM_Paint(void);
      void __vectorcall WM_Command_GrafikGruppe(unsigned int uiMessage, WPARAM wParam, LPARAM lParam);

    protected:

    public:
      void __vectorcall COGraphicGroupV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcFensterName, _In_ unsigned int uiDElementA,
                                        _In_ STDeviceResources* pstDeviceResourcesA);
      void __vectorcall ErstellFensterInRahmen(COGraphic* pGraphic);
      void __vectorcall ErstellFensterInGruppe(COGraphic* pGraphic, long lHoheA, long lBreiteA, long lPos_x, long lPos_y);
      void(__vectorcall* pfnWM_Paint)(COGraphicGroup*, PAINTSTRUCT&);
      void(__vectorcall* pfnWM_Command)(HWND, unsigned int, WPARAM, LPARAM);
      void __vectorcall SetzSichtbar(bool bSichtbar);
    };
    __declspec(dllimport) COGraphicGroup* __vectorcall COGraphicGroupV(_In_ const char* pcFensterName, _In_ unsigned int uiIDElement,
                                                                       _In_ STDeviceResources* pstDeviceResourcesA);
    __declspec(dllimport) COGraphicGroup* __vectorcall COGraphicGroupV(_In_ const VMEMORY vmSpeicher, _In_ const char* pcFensterName, _In_ unsigned int uiIDElement,
                                                                       _In_ STDeviceResources* pstDeviceResourcesA);
    //---------------------------------------------------------------------------------------------------------------------------------------
    __declspec(dllimport) VMEMORY __vectorcall VMDialog(void);
    __declspec(dllimport) HINSTANCE __vectorcall Hinstance(void);
    __declspec(dllimport) HACCEL __vectorcall Accelerator(void);
    __declspec(dllimport) HANDLE __vectorcall TimerQueue(void);
    __declspec(dllimport) void __vectorcall Cursorform(const char* pcCursor);
    __declspec(dllimport) void __vectorcall EinfugenKurzTasten(const ACCEL* pacTasten, int iAnzahl);
    __declspec(dllimport) ID2D1Factory7* __vectorcall D2D1Factory7(void);
    __declspec(dllimport) ID3D11Device5* __vectorcall D3D11Device5(void);
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