#include <engine.h>
#include <SDL3/SDL.h>
#include <assert.h>
#include <gameobject.h>

static char engineStarted = 0;
static char engineEnded = 0;

//the engine is responsible for SDL initialization, renderer, viewportTexture and renderer initialization. The editor will use the window and the renderer as if it was its.
//is it also responsible for destroying the window and renderer, as well ass viewportTexture and quitting SDL.

SDL_Window* window; //the window is shared between editor and engine. The engine initializes it.

static void init(void);
static void update(void);
static void end(void);
static void render(void);

SDL_Texture* viewportTexture;
SDL_Renderer* renderer;

static SDL_FRect windowRect = {0, 0, 800, 600};

void engineStart()
{
	#ifdef DEBUG
	DEBUG_ASSERT(!engineStarted, "Error: the engine has already started, you cannot call start more than once");
	#else
	ASSERT(!engineStarted);
	#endif

	engineStarted = 1;
	init();
}

static void init(void)
{
	#ifdef DEBUG
	DEBUG_ASSERT(SDL_Init(SDL_INIT_VIDEO), SDL_GetError());
	#else
	ASSERT(SDL_Init(SDL_INIT_VIDEO));
	#endif

	window = SDL_CreateWindow("Finestra", 800, 600, 0);
	#ifdef DEBUG
	DEBUG_ASSERT(window, SDL_GetError());
	#else
	ASSERT(window);
	#endif

	renderer = SDL_CreateRenderer(window, NULL);

	#ifdef DEBUG
	DEBUG_ASSERT(renderer, SDL_GetError());
	#else
	ASSERT(renderer);
	#endif

	viewportTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 800, 600);
	#ifdef DEBUG
	DEBUG_ASSERT(renderer, SDL_GetError());
	#else
	ASSERT(renderer);
	#endif

	update();
}

static void update(void)
{
	#ifndef EDITOR
	char engineRunning = 1;
	SDL_Event event;
	while(engineRunning)
	{
		//events
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_EVENT_QUIT:
					engineRunning = 0;
					break;
				default:
					break;
			}
		}

		//logic

		//physics

		//render
		engineRender();
	}

	engineEnd();
	#endif
}

void engineEnd(void)
{
	if(window)
		SDL_DestroyWindow(window);
	if(renderer)
		SDL_DestroyRenderer(renderer);
	if(viewportTexture)
		SDL_DestroyTexture(viewportTexture);

	SDL_Quit();
}

void engineRender(void)
{
	SDL_SetRenderTarget(renderer, viewportTexture);
	SDL_SetRenderDrawColor(renderer, 44, 122, 212, 255);
	SDL_RenderClear(renderer);

	//Rendering here

	#ifndef EDITOR
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderTexture(renderer, viewportTexture, NULL, &windowRect);
	SDL_RenderPresent(renderer);
	#endif
}
