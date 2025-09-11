#ifndef CoreH
#define CoreH
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE CORE_KEINFEHLER = 0;
constexpr BYTE CORE_NUMMERUNBEKANNT = 1;
constexpr BYTE CORE_UNBEKANNT = 48;
constexpr BYTE CORE_SYSTEMFEHLER = 0xFE;
constexpr BYTE CORE_ZEITENDE = 0xFF;
constexpr BYTE CORE_UPDATE_NEUER = 1;
constexpr BYTE CORE_ISOS_NEUER = 1;
constexpr BYTE CORE_ISOS_NEU = 2;
constexpr BYTE CORE_QUORRA_NEUER = 1;
constexpr BYTE CORE_KEINECONNECTCORES = 1;
constexpr BYTE CORE_TRENNENFEHLER = 5;
constexpr BYTE CORE_REGISTRYFEHLER = 1;
constexpr BYTE CORE_KEINCONNECTCORE = 1;

constexpr USHORT CORE_WARTEN = 10000;
constexpr BYTE CORE_TTL = 20;
constexpr USHORT CORE_SITZUNGGULTIG = 600;
constexpr ULONG CORE_CONNECTGULTIG = 86400;
constexpr USHORT CORE_CONNECTCORES = 10800;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE CS_CORE_VERBINDEN = 1;
constexpr BYTE CS_CORE_TRENNEN = 2;
constexpr BYTE CS_CORE_NEU = 3;
constexpr BYTE CS_TRANSFERKEYTOCOMPUTER = 4;
constexpr BYTE CS_TRANSFERKEYFROMCOMPUTER = 5;
constexpr BYTE CS_CORE_RESET = 6;
constexpr BYTE CS_FILEUPDATE = 7;
constexpr BYTE CS_ISOS = 8;
constexpr BYTE CS_QUORRA = 9;
constexpr BYTE CS_CORE_CHANCEKEY = 10;
constexpr BYTE CS_CORE_CONNECTCORES = 11;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE TAB_SAFE_1 = 0;
constexpr BYTE TAB_SAFE_2 = 1;
constexpr BYTE TAB_SAFE_3 = 2;
constexpr BYTE TAB_CORES = 3;
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr BYTE SPL_SAFE_1_BIT128_KEYNUMBER = 0;
constexpr BYTE SPL_SAFE_1_KS_KEYNAME = 1;
constexpr BYTE BST_SAFE_1_BIT128_KEYNUMBER = 0;
constexpr BYTE BST_SAFE_1_KS_KEYNAME = 1;

constexpr BYTE SPL_SAFE_2_BIT128_KEYNUMBER = 0;
constexpr BYTE SPL_SAFE_2_KS_PASSWORD = 1;
constexpr BYTE SPL_SAFE_2_BIT128_VECTOR = 2;
constexpr BYTE BST_SAFE_2_BIT128_KEYNUMBER = 0;

constexpr BYTE SPL_SAFE_3_BIT128_KEYNUMBER = 0;
constexpr BYTE SPL_SAFE_3_BIT256_KEY = 1;
constexpr BYTE BST_SAFE_3_BIT128_KEYNUMBER = 0;

constexpr BYTE SPL_CORES_BIT128_CORENUMBER = 0;
constexpr BYTE SPL_CORES_Z_ERSTERKONTAKT = 1;
constexpr BYTE SPL_CORES_Z_LETZTERKONTAKT = 2;
constexpr BYTE SPL_CORES_UC_TTL = 3;
constexpr BYTE BST_CORES_BIT128_CORENUMBER = 0;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STProgVersion
{
  COStringA asName;
  COStringA asVersion;
} STProgVersion;
//---------------------------------------------------------------------------
#endif