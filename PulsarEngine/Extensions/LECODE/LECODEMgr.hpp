
#ifndef _LECODE_MGR_
#define _LECODE_MGR_
#include <kamek.hpp>
//CTDN - Delete line below
#include <Extensions/LECODE/Lex.hpp>
#include <Extensions/LECODE/XPF.hpp>

namespace LECODE {
class Mgr {
public:
//CTDN - Delete line below
    LexMgr lexMgr;
    XPFMgr xpfMgr;
};


}//namespace LECODE
#endif