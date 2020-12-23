#ifndef __INIT_H__
#define __INIT_H__

#define FRAMESIZE 4096
#define DEFBUFSIZE 1024
#define FILENAME "../data/data.dbf"

typedef struct {
    char fields[FRAMESIZE];
} bFrame;

bFrame buf[DEFBUFSIZE]; //Buffer

typedef struct bcb{
    int page_id;
    int frame_id;
    int latch;
    int count;
    int dirty;
    struct bcb *next;
} BCB;  //buffer control block

#endif
