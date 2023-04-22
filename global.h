#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

class CBackend;

#define MAGIC_FILE_MARK 0x05150515

extern CBackend *g_pBackend;
extern QString g_sSshAskPass;

#endif // GLOBAL_H
