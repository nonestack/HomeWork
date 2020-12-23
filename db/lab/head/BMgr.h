#ifndef __BMGR_H__
#define __BMGR_H__

#include "init.h"

class BMgr
{
public:
    BMgr();
    //Interface functions
    int FixPage(int page_id, int prot);
    void FixNewPage();
    int UnfixPage(int page_id);
    int NumFreeFrames();

    //Internal functions
    int SelectVictim();
    int Hash(int page_id);
    void RemoveBCB(BCB *ptr, int page_id);
    void RemoveLRUEle(int frid);
    void SetDirty(int frame_id);
    void UnsetDirty(int frame_id);
    void WriteDirtys();
    void PrintFrame(int frame_id);

private:
    //Hash Table
    int ftop[DEFBUFSIZE];
    BCB *ptof[DEFBUFSIZE];
};

#endif
