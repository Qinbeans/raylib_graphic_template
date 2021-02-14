#include "raylib-cpp.hpp"
#include "character.h"
#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::cerr;

typedef struct ball{
    float rad_scale;
    float x_scale;
    float y_scale;
    raylib::Color color;
    Vector2 pos;
    Vector2 vel;
}ball;

int reinitialize_screen(pair<int,int> res,map<string,pair<int,int>> resols, string curr_res, ball b);

int main(){
    map<string,pair<int,int>> screen_res;
    int cur_screen_width = 0;
    int cur_screen_height = 0;
    string cur_screen = "FHD 16:9";
    screen_res.insert(pair<string,pair<int,int>>("4k UHD 16:9",pair<int,int>(3840,2160)));
    screen_res.insert(pair<string,pair<int,int>>("WQHD 21:9",pair<int,int>(3440,1440)));
    screen_res.insert(pair<string,pair<int,int>>("QHD 16:9",pair<int,int>(2560,1440)));
    screen_res.insert(pair<string,pair<int,int>>("WFHD 21:9",pair<int,int>(2560,1080)));
    screen_res.insert(pair<string,pair<int,int>>("QWXGA 16:9",pair<int,int>(2048,1152)));
    screen_res.insert(pair<string,pair<int,int>>("WUXGA 16:10",pair<int,int>(1920,1200)));
    screen_res.insert(pair<string,pair<int,int>>("FHD 16:9",pair<int,int>(1920,1080)));
    screen_res.insert(pair<string,pair<int,int>>("WSXGA+ 16:10",pair<int,int>(1680,1050)));
    screen_res.insert(pair<string,pair<int,int>>("HD+ 16:9",pair<int,int>(1600,900)));
    screen_res.insert(pair<string,pair<int,int>>("? 16:9",pair<int,int>(1536,864)));
    screen_res.insert(pair<string,pair<int,int>>("WXGA+ 16:10",pair<int,int>(1440,900)));
    screen_res.insert(pair<string,pair<int,int>>("HD 16:9",pair<int,int>(1366,768)));
    screen_res.insert(pair<string,pair<int,int>>("HD 16:9",pair<int,int>(1360,768)));
    screen_res.insert(pair<string,pair<int,int>>("SXGA 5:4",pair<int,int>(1280,1024)));
    screen_res.insert(pair<string,pair<int,int>>("WXGA 16:10",pair<int,int>(1280,800)));
    screen_res.insert(pair<string,pair<int,int>>("WXGA 16:9",pair<int,int>(1280,720)));
    screen_res.insert(pair<string,pair<int,int>>("XGA 4:3",pair<int,int>(1024,768)));
    screen_res.insert(pair<string,pair<int,int>>("SVGA 4:3",pair<int,int>(800,600)));
    screen_res.insert(pair<string,pair<int,int>>("nHD 16:10",pair<int,int>(640,360)));
    ball b;
    b.pos.x = cur_screen_width/2;
    b.pos.y = cur_screen_height;
    b.y_scale = 0.1;
    b.rad_scale = 0.2;
    b.vel.x = 0;
    b.vel.y = -1;
    b.color = RED;
    reinitialize_screen(screen_res[cur_screen],screen_res,cur_screen,b);
}

int reinitialize_screen(pair<int,int> res,map<string,pair<int,int>> resols, string curr_res, ball b){
    raylib::Image icon("res/icon.png");
    raylib::Color buttons(GRAY);
    raylib::Color curr_button(PURPLE);
    raylib::Color hover_button(YELLOW);
    raylib::Color textColor(LIGHTGRAY);
    raylib::Window window(res.first,res.second,"Testing");
    window.SetTargetFPS(144);
    window.SetIcon(icon);
    float scale = float(res.second)/100.0;
    int button_width = scale * 20.0;
    int button_height = scale * 4.0;
    int res_button_begin_height = (scale*10);
    int buffer = (scale*1.0) ;
    float font_size = (scale*2.0);
    cout<<font_size<<endl;
    while(!window.ShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        map<string,pair<int,int>>::iterator it;

        //edit resolution

        int counter = 0;
        for(it = resols.begin();it != resols.end();it++){
            int spacing = res_button_begin_height+(counter*(button_height+buffer));
            if(it->first != curr_res){
                bool detect_hover = (GetMouseY() > spacing && GetMouseY() < spacing + button_height) && (GetMouseX() > (int)scale && GetMouseX() < int(scale + button_width));
                if(detect_hover){
                    hover_button.DrawRectangle(scale, spacing, button_width, button_height);
                }else{
                    buttons.DrawRectangle(scale, spacing, button_width, button_height);
                }
                if(detect_hover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                    window.Close();
                    reinitialize_screen(it->second,resols, it->first, b);
                }
            }else{
                curr_button.DrawRectangle(scale, spacing, button_width, button_height);
            }
            textColor.DrawText(it->first,scale + 5, spacing + 5, font_size);
            counter++;
        }

        //animation
        
        if(b.pos.y >= res.second){
            b.vel.y = -1;
            b.pos.y = res.second;
        }else if(b.pos.y <= 0){
            b.vel.y = b.vel.y * -1;
            b.pos.x = 0;
        }else if(b.pos.y < res.second){
            b.vel.y += scale/1000;
        }else{
            b.vel.y -= scale/1000;
        }if(b.pos.x != res.first/2){
            b.pos.x = res.first/2;
        }
        DrawFPS(20,20);
        DrawCircle(b.pos.x,b.pos.y,scale/b.rad_scale,b.color);
        b.pos.y += b.vel.y*scale;

        EndDrawing();
    }
}