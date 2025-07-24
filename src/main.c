#include <assert.h>

#ifdef EDITOR
#include <editor.h>
#endif
#include <engine.h>

int main(int argc, char** argv)
{
	#ifdef DEBUG
	printf("Initializing Engine\n");
	#endif

	#ifdef EDITOR
	editorStart();
	atexit(editorEnd);
	#else
	engineStart();
	atexit(engineEnd);
	#endif

	return 0;
}
