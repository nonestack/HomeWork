#include <stdio.h>

#include "../BMgr.h"

BMgr::BMgr(){
}

int BMgr::FixPage(int page_id, int prot){
    
}

void BMgr::FixNewPage(){
}

int BMgr::UnfixPage(int page_id){
}

int BMgr::NumFreeFrames(){
}

int BMgr::SelectVictim(){
}

int BMgr::Hash(int page_id){
}

void BMgr::RemoveBCB(BCB *ptr, int page_id){
}

void BMgr::RemoveLRUEle(int frid){
}

void BMgr::SetDirty(int frame_id){
}

void BMgr::UnsetDirty(int frame_id){
}

void BMgr::WriteDirtys(){
}

void BMgr::PrintFrame(int frame_id){
}
