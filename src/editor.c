#include <editor.h>
#include <engine.h>
#include <SDL3/SDL.h>
#include <assert.h>

static char editorStarted = 0;
static char editorEnded = 0;

extern SDL_Window* window;
static SDL_FRect viewportRect;

extern SDL_Texture* viewportTexture;
extern SDL_Renderer* renderer;

static void init(void);
static void update(void);
static void end(void);
static void editorRender(void);

void editorStart()
{
	#ifdef DEBUG
	DEBUG_ASSERT(!editorStarted, "Error: the editor has already started, you cannot call start more than once");
	#else
	ASSERT(!editorStarted);
	#endif

	editorStarted = 1;
	init();
}

static void init(void)
{
	engineStart();

	viewportRect = (SDL_FRect){200, 150, 400, 300};

	update();
}

static void update(void)
{
	char editorRunning = 1;
	SDL_Event event;

	while(editorRunning)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_EVENT_QUIT:
					editorRunning = 0;
					break;
				default:
					break;
			}
		}

		engineRender();
		editorRender();

		SDL_Delay(16); //per ora simula 60 fps
	}

	editorEnd();
}

void editorEnd(void)
{
	engineEnd();
}

static void editorRender()
{
	SDL_SetRenderTarget(renderer, NULL);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderTexture(renderer, viewportTexture, NULL, &viewportRect);

	SDL_RenderPresent(renderer);
}
