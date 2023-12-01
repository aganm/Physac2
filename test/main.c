#define PHYSAC_STANDALONE
#define PHYSAC_NO_THREADS
#define PHYSAC_IMPLEMENTATION
#define PHYSAC_DEBUG
#include "../src/physac.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	InitPhysics();
	for (int i = 0; i < 1000; ++i) {
		RunPhysicsStep();
	}
	ClosePhysics();
	return 0;
}
