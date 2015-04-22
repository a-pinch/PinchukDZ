#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define ROWS 60
#define COLS 60
#define OFF 0
#define ON 1
#define BLACK 8, 0, 0, 0, 0
#define scr_width 600
#define scr_height 600
#define cell_width (scr_width / ROWS)
#define cell_height (scr_height / COLS)

#define SCREEN_WIDTH 640
#define SCREEN_HIGHT 480

/** Note to self:
  * Always refer to the board as board[x][y] as to follow the general
  * standard for specifying coordinates. When looping, y must be declared
  * first in the outer loop so that it represents the rows while x, declared
  * within the y loop becomes the variable representing each column value.
 */

/** Bugs
  * = Severity -> Low
  *   - When ROWS or COLS is greater than the other, only a squared area
  *     is actually updated or a segfault is fired.
 */

/** We must hold two copies of the board so that we can analyze board and make
  * changes to temp when killing/creating cells so that we don't cause changes
  * to the board to affect the following cells.
 */
char board[ROWS][COLS];
char temp[ROWS][COLS];
SDL_Rect cells[ROWS][COLS]; /* Stores positions of each cell for blits. */

void randomize_board(void);
void initialize_grid(SDL_Surface* screen);
void blit_board(SDL_Surface* bcell, SDL_Surface* screen);
int num_neighbours(int x, int y);
void update_board(void);
int clear_board(SDL_Surface* screen, Uint32 color);
int clear_cell(SDL_Surface* screen, int x, int y, Uint32 color);
void initialize_cells_array(void);

int main(void) {
 //проинициализировать SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_INIT Error: %s\n", SDL_GetError());
        exit(1);

    }

    SDL_Window *win = SDL_CreateWindow("Hello World ^_^", 100, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }


    //Now lets draw our image
    //first clear the renderer
    SDL_RenderClear(ren);

    //update the screen
    SDL_RenderPresent(ren);

    initialize_cells_array();
    initialize_grid(win);

    //have the program wait for 4000ms so we get a chance to see the screen
    bool quit = false;

    SDL_Event e;

    int x = 10, y = 10;//координаты точки, которую рисуем

    while(!quit)
    {
        while(SDL_PollEvent(&e))//user requests quit
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            if(e.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent k_event = e.key;
                switch(k_event.keysym.scancode)
                {
                case SDL_SCANCODE_A:
                    x = (x-10+SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_D:
                    x = (x+10+SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_W:
                    y = (y-10+SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;
                case SDL_SCANCODE_S:
                    y = (y+10+SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;

                }

            }
            /*if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                quit = true;
            }*/
        }
        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawLine(ren, x, y, SCREEN_WIDTH / 2, SCREEN_HIGHT / 2);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

void randomize_board(void) {
    /* Clear the board then randomly set ~1/5 of them to ON. */
    memset((void *)board, OFF, ROWS * COLS);
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            if (rand() % 5 == 0) {
                board[x][y] = ON;
            }
            temp[x][y] = board[x][y];
        }
    }
}

void initialize_grid(SDL_Surface* screen) {
    /** Position horizontal and veritcal lines to form a grid to
      * make it easier to count cell spaces when trying to draw things.
     */
    SDL_Surface* linex = SDL_CreateRGBSurface( /* Vertical lines */
                              SDL_SWSURFACE, 1, scr_height, BLACK);
    SDL_Surface* liney = SDL_CreateRGBSurface( /* Horizontal lines */
                              SDL_SWSURFACE, scr_width, 1, BLACK);
    SDL_Rect pos_x;
    SDL_Rect pos_y;
    pos_x.y = pos_y.x = 0;
    for (int i = 0; i < scr_width / (cell_width); i++) {
        pos_x.x = cell_width + cell_width * i;
        SDL_BlitSurface(linex, &(linex->clip_rect), screen, &pos_x);
        SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer,
                                            SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            640, 480);
    }
    for (int i = 0; i < scr_height / (cell_height); i++) {
        pos_y.y = cell_height + cell_height * i;
        SDL_BlitSurface(liney, &(liney->clip_rect), screen, &pos_y);
    }
}

void blit_board(SDL_Surface* bcell, SDL_Surface* screen) {
    /* Blit all the live cells onto the board. */
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            if (board[x][y] == ON) {
                SDL_BlitSurface(
                    bcell,
                    &(bcell->clip_rect),
                    screen,
                    &cells[x][y]);
            }
        }
    }
}

int num_neighbours(int x, int y) {
    /** Count the number of live cells all around the cell given by
      * the position (x, y). Of course, this includes all diagonal, vertical,
      * and horizontal living cells. The program works using a toroidal array,
      * thus we must check to see if it is necessary to wrap to the other side
      * of the array in order to find cells that must be taken into account.
     */
    int num_adj = 0;
    int tmpy = y;
    int tmpx = x;

    if (y-1 < 0)
        tmpy = ROWS - 1;
    else
        tmpy = y - 1;
    if (board[x][tmpy] == ON) num_adj++;
    if (y+1 >= ROWS)
        tmpy = 0;
    else
        tmpy = y + 1;
    if (board[x][tmpy] == ON) num_adj++;
    if (x-1 < 0)
        tmpx = COLS - 1;
    else
        tmpx = x - 1;
    if (board[tmpx][y] == ON) num_adj++;
    if (x+1 >= COLS)
        tmpx = 0;
    else
        tmpx = x + 1;
    if (board[tmpx][y] == ON) num_adj++;
    if (y-1 < 0)
        tmpy = ROWS - 1;
    else
        tmpy = y - 1;
    if (x-1 < 0)
        tmpx = COLS - 1;
    else
        tmpx = x - 1;
    if (board[tmpx][tmpy] == ON) num_adj++;
    if (x+1 >= COLS)
        tmpx = 0;
    else
        tmpx = x + 1;
    if (board[tmpx][tmpy] == ON) num_adj++;
    if (y+1 >= ROWS)
        tmpy = 0;
    else
        tmpy = y + 1;
    if (x+1 >= COLS)
        tmpx = 0;
    else
        tmpx = x + 1;
    if (board[tmpx][tmpy] == ON) num_adj++;
    if (x-1 < 0)
        tmpx = COLS - 1;
    else
        tmpx = x - 1;
    if (board[tmpx][tmpy] == ON) num_adj++;
    return num_adj;
}

void update_board(void) {
    /** Detirmine which cells live and which die. Operate on temp so that
      * each change does not affect following changes, then copy temp into
      * the main board to be displayed.
     */
    int neighbours = 0;

    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            neighbours = num_neighbours(x, y);
            if (neighbours < 2 && board[x][y] == ON) {
                temp[x][y] = OFF; /* Dies by underpopulation. */
            } else if (neighbours > 3 && board[x][y] == ON) {
                temp[x][y] = OFF; /* Dies by overpopulation. */
            } else if (neighbours == 3 && board[x][y] == OFF) {
                temp[x][y] = ON; /* Become alive because of reproduction. */
            }
            /* Otherwise the cell lives with just the right company. */
        }
    }
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            board[x][y] = temp[x][y];
        }
    }
}

int clear_board(SDL_Surface* screen, Uint32 color) {
    /* Simply set both the main and temporary boards to completely off. */
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            board[x][y] = OFF;
            temp[x][y] = OFF;
        }
    }
    return SDL_FillRect(screen, &(screen->clip_rect), color);
}

int clear_cell(SDL_Surface* screen, int x, int y, Uint32 color) {
    /* Clear a cell by coloring it white and setting the board pos. to off. */
    SDL_Rect rect;
    rect.x = cell_width * x;
    rect.y = cell_height * y;
    board[x][y] = OFF;
    temp[x][y] = OFF;
    return SDL_FillRect(screen, &rect, color);
}

void initialize_cells_array(void) {
    /** Initialize the array of SDL_Rect structs that store the cell
      * coordinates by iteratively calculating their successive positions.
     */
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            (cells[x][y]).x = (cell_width * x);
            (cells[x][y]).y = (cell_height * y);
        }
    }
}
