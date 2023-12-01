#define PHYSAC_STANDALONE
#define PHYSAC_NO_THREADS
#define PHYSAC_IMPLEMENTATION
#include "../src/physac.h"

int main() {
	InitPhysics();
	RunPhysicsStep();
	return 0;
}
