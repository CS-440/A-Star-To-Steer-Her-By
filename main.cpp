//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Stars up SDL and creates a window
bool init();

// Load media
bool loadMedia();

// Shut down SDL
void end();

// Load individual image as texture
SDL_Texture *loadTexture(std::string path);

// SDL WIndow object
SDL_Window *gWindow = NULL;

// Render window object to display
SDL_Renderer *gRenderer = NULL;

bool init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not be initialized!\nExiting...\n");
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

		// Create window
		gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Error initializing SDL window!\nExiting...\n");
			success = false;
		}
		else
		{
			// Create window renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

			if (gRenderer == NULL)
			{
				printf("Error creating window renderer (Error code: %s)!\nExiting...\n", SDL_GetError());

				success = false;
			}
			else
			{
				// Set window renderer to white
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initize PNG loading (sprites)
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not be initialized!\nExiting...\n");
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	// Current not loading any forms of media, just primitize SDL geometry

	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

/*
// SDL_Texture is not defined or used at all at the moment
SDL_Texture *loadTexture(std::string path)
{
	// code...
}
}
*/

int main(int argc, char **argv)
{
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\nExiting...\n");
		}
		else
		{
			// Main loop flag
			bool quit = false;

			// SDL event handler
			SDL_Event event;

			while (!quit)
			{
				// Handle event queue
				while (SDL_PollEvent(&event) != 0)
				{
					
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}
				}

						
			// Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			// Render red filled quad
			SDL_Rect fillRect = 
			{ 
				// Width
				SCREEN_WIDTH/4,
				// Height
				SCREEN_HEIGHT/4,
				
				// X Position
				SCREEN_WIDTH/2,
				// YPosition
				SCREEN_HEIGHT/2 
			};
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
			SDL_RenderFillRect(gRenderer, &fillRect);

			// Render green outlined quad
			SDL_Rect outlineRect = 
			{ 
				SCREEN_WIDTH / 6,
				SCREEN_HEIGHT / 6,
				
				SCREEN_WIDTH * 2 / 3,
				SCREEN_HEIGHT * 2 / 3 
			};
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );					  SDL_RenderDrawRect( gRenderer, &outlineRect );
				
			//Draw blue horizontal line
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );					SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

			//Draw vertical line of yellow dots
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
			for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
			{
				SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
			}

			SDL_RenderPresent(gRenderer);

			}
		}
	}

	// Free resources and close SDL
	close();

	return 0;
}

































