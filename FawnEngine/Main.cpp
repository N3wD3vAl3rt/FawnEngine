#include "Engine.h"

int main()
{
	Engine engine;

	if (!engine.Initialize())
		return 1;

	int result = engine.Run();

	engine.Shutdown();

	return result;
}