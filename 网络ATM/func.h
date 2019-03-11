#ifndef FUNC_H
#define FUNC_H

void creat(int fd,Acc* acc);

void load(int fd,Acc* acc);

void save(int fd,Acc* acc);

void take(int fd,Acc* acc);

void query(int fd,Acc* acc);

void trans(int fd,Tra* tra);

void modify(int fd,Mod* mod);

void unlock(int fd,Acc* acc);

void destory(int fd,Acc* acc);
#endif // FUNC_H
