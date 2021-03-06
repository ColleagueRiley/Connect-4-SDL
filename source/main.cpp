#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_circle.h>
#include <SDL2/SDL_text.hpp>
#include "../include/tree.hpp"

bool running = true;
SDL_Event e;
const Uint8* keys = SDL_GetKeyboardState(NULL);
int playing = 1;
std::vector<SDL_Circle> board; std::vector<SDL_Color> Cboard; 
int boardlength = 7;int boardwidth = 6; int I=0;
int player = 0;int PX = 50;int px = PX;int py = 50;

int a = std::rand();

int AI(std::vector<SDL_Color> Cboard){
    int choice;
    for (int i=0; i < 7; i++){
        std::vector<SDL_Color> Cb = Cboard;
        for (int I=0; I < 7; I++){
            for (int j=0; j < 7; j++){
                for (int J=0; J < 7; J++){

                }
            }
        }
    }
    return choice;
}

SDL_Text text = {"Test",50,100,50,100,405,{255,255,255,0},"fonts/FreeSans.ttf", .background = true,.bgcolor ={0,0,0,0}, .fill = true};

int main(){
    bool ex = false;
    
    for (int i=0; i < (boardlength*boardwidth); i++){
        board.insert(board.end(),{px,py,25});
        Cboard.insert(Cboard.end(),{255,255,255,0});
        px+=65;I++;
        if (I == 7){px=PX;py+=65;I=0;}
    }

    if(!text.init()){text.TextGetError(); return 0;}
    
    int windowWidth = 500;
    int windowLength = 450; 
    SDL_Window* window = SDL_CreateWindow("Connect 4",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,windowWidth,windowLength,SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    while (running){
        if (player == 1){text.rect.w=text.width+50; text.text = "Yellow's Turn"; text.init();}
        if (!player){text.rect.w=text.width; text.text = "Red's Turn"; text.init();}
        if (playing==2 && player==4){text.text = "Yellow's Turn";text.init();Cboard[AI(Cboard)] = {255,255,0,0}; player=0;}
        
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
            if (keys[SDL_SCANCODE_ESCAPE]){
                running = false;
            }
            if (playing){
            for (int i=0; i < board.size(); i++){
                if (!player && Cboard[i].b == 255 && SDL_CircleCollidePoint(board[i],{e.motion.x,e.motion.y}) && e.type == SDL_MOUSEBUTTONDOWN && SDL_BUTTON(1)){
                    Cboard[i] = {255,0,0,0};player=1;
                }
                else if (player==1 && playing==1 && Cboard[i].b == 255 && SDL_CircleCollidePoint(board[i],{e.motion.x,e.motion.y}) && e.type == SDL_MOUSEBUTTONDOWN && SDL_BUTTON(1)){
                    Cboard[i] = {255,255,0,0};player=0;
                }

                    if (i+3 < board.size()&& board[i].y == board[i+3].y && Cboard[i].g != 255 && Cboard[i+1].g != 255 && Cboard[i+2].g != 255 && Cboard[i+3].g != 255){player = 2;}
                    else if (i+3 < board.size() && board[i].y == board[i+3].y && Cboard[i].g == 255 && Cboard[i].b != 255 && Cboard[i+1].g == 255 && Cboard[i+1].b != 255 && Cboard[i+2].g == 255 && Cboard[i+2].b != 255 && Cboard[i+3].g == 255 &&Cboard[i+3].b != 255){player = 3;}

                    if (i+(7*3) < board.size() && board[i].x == board[i+(7*3)].x && Cboard[i].g != 255 && Cboard[i+7].g != 255 && Cboard[i+(7*2)].g != 255 && Cboard[i+(7*3)].g != 255){player = 2;}
                    else if (i+(7*3) < board.size() && board[i].x == board[i+(7*3)].x && Cboard[i].g == 255 && Cboard[i].b != 255 && Cboard[i+7].g == 255 && Cboard[i+7].b != 255 && Cboard[i+(7*2)].g == 255 && Cboard[i+(7*2)].b != 255 && Cboard[i+(7*3)].g == 255 &&Cboard[i+(7*3)].b != 255){player = 3;}

                    if (i+(8*3) < board.size() && board[i].x == board[i+(8*3)].x +(65*3) && board[i].y == board[i+(8*3)].y +(65*3) && Cboard[i].g != 255 && Cboard[i+8].g != 255 && Cboard[i+(8*2)].g != 255 && Cboard[i+(8*3)].g != 255){player = 2;}
                    else if (i+(8*3) < board.size() && board[i].x == board[i+(8*3)].x +(65*3) && board[i].y == board[i+(8*3)].y +(65*3) && Cboard[i].g == 255 && Cboard[i].b != 255 && Cboard[i+8].g == 255 && Cboard[i+8].b != 255 && Cboard[i+(8*2)].g == 255 && Cboard[i+(8*2)].b != 255 && Cboard[i+(8*3)].g == 255 &&Cboard[i+(8*3)].b != 255){player = 3;}
                
                    if (i-(6*3) < board.size() && board[i].x == board[i-(6*3)].x -(65*3) && board[i].y == board[i-(6*3)].y -(65*3) && Cboard[i].g != 255 && Cboard[i-6].g != 255 && Cboard[i-(6*2)].g != 255 && Cboard[i-(6*3)].g != 255){player = 2;}
                    else if (i-(6*3) < board.size() && board[i].x == board[i-(6*3)].x -(65*3) && board[i].y == board[i-(6*3)].y -(65*3) && Cboard[i].g == 255 && Cboard[i].b != 255 && Cboard[i-6].g == 255 && Cboard[i-6].b != 255 && Cboard[i-(6*2)].g == 255 && Cboard[i-(6*2)].b != 255 && Cboard[i-(6*3)].g == 255 &&Cboard[i-(6*3)].b != 255){player = 3;}
                }
            }
        }
        
        if (player < 4){
            if(player == 2 && !ex){
                text.text = "Red has won the round";
                text.rect.w += 100;text.init();
                ex = true;
            } 
            else if(player == 3 && !ex){
                text.text = "Yellow has won the round";
                text.rect.w += 200;text.init();
                ex = true;
            }
        }
        
        SDL_RenderClear(renderer); 
        if (playing){        
            if(!text.draw(renderer)){text.TextGetError();}
            for (int i=0; i < board.size(); i++){
                if (i+7 < board.size() && Cboard[i].b  != 255 && Cboard[i+7].b == 255){
                    Cboard[i+7] = Cboard[i];
                    Cboard[i] = {255,255,255,0};
                }
                if (!player){SDL_SetRenderDrawColor(renderer,Cboard[i].r,Cboard[i].g,Cboard[i].b,Cboard[i].a);}
                else{SDL_SetRenderDrawColor(renderer,Cboard[i].r,Cboard[i].g,Cboard[i].b,Cboard[i].a);}
                SDL_RenderDrawCircle(renderer,board[i]);SDL_RenderFillCircle(renderer,board[i]);
            }
        }
        if(!playing){SDL_SetRenderDrawColor(renderer,255,255,0,0);  SDL_RenderDrawCircle(renderer,{windowWidth/2,windowLength/3,100});SDL_RenderFillCircle(renderer,{windowWidth/2,windowLength/3,100});}
        SDL_SetRenderDrawColor(renderer,0,0,120,0);
        SDL_RenderPresent(renderer);
    }
}