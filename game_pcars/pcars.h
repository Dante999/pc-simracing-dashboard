#ifndef PCARS_H
#define PCARS_H

#include "../game.h"
#include "../gamedata.h"
#include "pcarssharedmemory.h"
#include <QSharedMemory>

class Pcars : public Game {
      private:
	MemoryMap_Pcars *m_pcarsData;
	QSharedMemory m_sharedMemory;

      public:
	Pcars();

	bool writeDataTo(struct gamedata *data);
	bool isRunning();
};

#endif // PCARS_H
