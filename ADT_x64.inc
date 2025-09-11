;******************************************************************************
;MIT License

;Copyright(c) 2025 René Pagel

;Filename: ADT_x64.inc
;For more information see https://github.com/RePag-net/Include

;Permission is hereby granted, free of charge, to any person obtaining a copy
;of this software and associated documentation files(the "Software"), to deal
;in the Software without restriction, including without limitation the rights
;to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
;copies of the Software, and to permit persons to whom the Software is
;furnished to do so, subject to the following conditions :

;The above copyright notice and this permission notice shall be included in all
;copies or substantial portions of the Software.

;THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
;AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;SOFTWARE.
;******************************************************************************
COComma4_lVorKomma = 0
COComma4_lVorKomma_A = 4
COComma4_sNachKomma = COComma4_lVorKomma_A + 4
COComma4_sNachKomma_A = COComma4_sNachKomma + 4
COComma4_vmSpeicher = COComma4_sNachKomma_A + 4
; BY_COKOMMMA4 = 24
;--------------------------------------------------------------------------------------------------
COComma4_80_llVorKomma = 0
COComma4_80_llVorKomma_A = 8
COComma4_80_sNachKomma = COComma4_80_llVorKomma_A + 8
COComma4_80_sNachKomma_A = COComma4_80_sNachKomma + 4
COComma4_80_vmSpeicher = COComma4_80_sNachKomma_A + 4
; BY_COKOMMMA4_80 = 32
;--------------------------------------------------------------------------------------------------
COList_pvDaten = 8
COList_pstErster = 0
COList_pstLetzer = 8 
COList_csIterator = COList_pstLetzer + 8
COList_ulAnzahl = COList_csIterator + 40
COList_bThread = COList_ulAnzahl + 4
COList_vmSpeicher = COList_bThread + 4 ; kein Fehler
; BY_COLIST = 72
;--------------------------------------------------------------------------------------------------
COStringA_vbInhalt = 0
COStringA_vbInhalt_A = 8
COStringA_ulLange = COStringA_vbInhalt_A + 8
COStringA_ulLange_A = COStringA_ulLange + 4
COStringA_vmSpeicher = COStringA_ulLange_A + 4
; BY_COStringA = 32
;--------------------------------------------------------------------------------------------------
COTime_FZeit_dwLowDateTime = 0
COTime_FZeit_dwHighDateTime = 4
COTime_FZeit_A_dwLowDateTime = COTime_FZeit_dwHighDateTime + 4
COTime_FZeit_A_dwHighDateTime = COTime_FZeit_A_dwLowDateTime + 4
COTime_vmSpeicher = COTime_FZeit_A_dwHighDateTime + 4
; BY_COTime = 24
;--------------------------------------------------------------------------------------------------
COStream = 0
COStream_COList = 0
COStream_COList_pstErster = 0
COStream_COList_pstLetzer = 8
COStream_COList_pvDaten = 8
COStream_COList_csIterator = COList_pstLetzer + 8
COStream_COList_ulAnzahl = COList_csIterator + 40
COStream_COList_bThread = COList_ulAnzahl + 4 
COStream_COList_vmSpeicher = COList_bThread + 4
COStream_csStream = COStream_COList_vmSpeicher + 8
COStream_ulBytes = COStream_csStream + 40
COStream_ulPosition = COStream_ulBytes + 4
COStream_bThread = COStream_ulPosition + 4
COStream_ucInfo = COStream_bThread + 1 ; kein Fehler
COStream_vmSpeicher = COStream_ucInfo + 7 ; kein Fehler
; BY_COStream = 136
;----------------------------------------------------------------------------