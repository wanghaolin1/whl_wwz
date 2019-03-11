#ifndef FUNC2_H 
#define FUNC2_H

#include "struct.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int creat_id(void);

int user_creat(Acc* acc);

int user_load(Acc* acc);

int user_save(Acc* acc);

int user_take(Acc* acc);

int user_query(Acc* acc);

int user_trans(Tra* tra);

int user_destory(Acc* acc);

int user_modify(Mod* mod);

int user_unlock(Acc* acc);

void atm_exit(Acc* acc);
#endif // FUNC2_H 
