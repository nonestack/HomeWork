#include "../head/DSMgr.h"

#include <stdio.h>
#include <strings.h>


DSMgr::DSMgr()
{
    currFile = NULL;
    numPages = 0;
    bzero(page, sizeof(page));
}

int DSMgr::OpenFile(string filename)
{
    currFile = fopen(filename.c_str(), "a+");
    if(currFile == NULL)
    {
        return -1;
    }
    return 0;
}

int DSMgr::CloseFile()
{
    int err = fclose(currFile);
    if(err == 0)
        return 0;
    return -1;
}

bFrame DSMgr::ReadPage(int page_id)
{
    OpenFile(std::string(FILENAME));
    bFrame tmp;
    fseek(currFile, page_id * FRAMESIZE, SEEK_SET);
    fread(&tmp, 1, FRAMESIZE, currFile);
    CloseFile();
    return tmp;
}

int DSMgr::WritePage(int frame_id, bFrame *frm)
{
    OpenFile(std::string(FILENAME));
    //fseek(currFile, page_id * FRAMESIZE, SEEK_SET);
    Seek(page_id * FRAMESIZE, SEEK_SET);
    int count = fwrite(frm, 1, FRAMESIZE, currFile);
    CloseFile();
    return count;
}

int DSMgr::Seek(int offset, int pos)
{
    int err = fseek(currFile, offset, pos);
    if(err != 0)
    {
        perror();
        exit(-1);
    }
    return 0;
}

FILE* DSMgr::GetFile()
{
    return currFile;
}

void DSMgr::IncNumPages()
{
    ++numPages;
}

void DSMgr::SetUse(int index, int use_bit)
{
    page[index] = use_bit;
}

int DSMgr::GetUse(int index)
{
    return page[index];
}

int DSMgr::GetNumPages()
{
    return numPages;
}

