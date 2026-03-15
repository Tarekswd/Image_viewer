#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    int width,height,maxval;
    char header[3];

    fscanf(stdin,"%2s",header);
    fscanf(stdin,"%d %d",&width,&height);
    fscanf(stdin,"%d",&maxval);
    fgetc(stdin);

    printf("width=%d height=%d\n",width,height);

    SDL_Window *window = SDL_CreateWindow("Image Viewer",width,height,0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    const SDL_PixelFormatDetails *format =
        SDL_GetPixelFormatDetails(surface->format);

    SDL_Rect pixel = {0,0,1,1};

    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            Uint8 r=getchar();
            Uint8 g=getchar();
            Uint8 b=getchar();

            pixel.x=x;
            pixel.y=y;

            Uint32 color=SDL_MapRGB(format,NULL,r,g,b);

            SDL_FillSurfaceRect(surface,&pixel,color);
        }
    }

    SDL_UpdateWindowSurface(window);

    int running=1;
    SDL_Event event;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_EVENT_QUIT)
                running=0;
        }
    }

    SDL_Quit();
}
