#ifndef DEBUG_H
#define DEBUG_H

extern int debug_level;
void mon_msg(int lvl, const char* dir, int len, void * buf);

void dbg_msg(int lvl, const char * format, ...);

#endif