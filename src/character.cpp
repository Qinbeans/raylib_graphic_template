#include "character.h"
#include <map>

//constants
//multiply by scale to get proper sizes on screen
#define L_WIDTH 10 
#define L_DEPTH 5
#define L_HEIGHT 50
#define B_WIDTH 20
#define B_DEPTH 5
#define B_HEIGHT 40
#define A_WIDTH 10
#define A_DEPTH 5
#define A_HEIGHT 40
#define H_WIDTH 25
#define H_DEPTH 20
#define H_HEIGHT 25

using std::map;

Character::Character(){
	scale = 1;
	dir = 0;
	state = 0;
	pos.x = 0;
	pos.y = 0;
	raylib::Rectangle store_temp(pos.x,pos.y,L_WIDTH,L_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("left leg",pair<raylib::Rectangle,float>(store_temp,1)));
	raylib::Rectangle store_temp(pos.x,pos.y,L_WIDTH,L_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("right leg",pair<raylib::Rectangle,float>(store_temp,1)));
	raylib::Rectangle store_temp(pos.x,pos.y,B_WIDTH,B_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("body",pair<raylib::Rectangle,float>(store_temp,1)));
	raylib::Rectangle store_temp(pos.x,pos.y,A_WIDTH,A_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("left arm",pair<raylib::Rectangle,float>(store_temp,1)));
	raylib::Rectangle store_temp(pos.x,pos.y,A_WIDTH,A_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("right arm",pair<raylib::Rectangle,float>(store_temp,1)));
	raylib::Rectangle store_temp(pos.x,pos.y,H_WIDTH,H_HEIGHT);
	limb.insert(pair<string,pair<raylib::Rectangle,float>>("head",pair<raylib::Rectangle,float>(store_temp,1)));
}

Character::Character(map<string,pair<raylib::Rectangle,float>> char_health, float char_scale, int char_state, int char_dir, Vector2 char_pos){
	scale = char_scale;
	dir = char_dir;
	state = char_state;
	pos = char_pos;
	limb = char_health;
}

Character::Character(Character other_char){
	scale = other_char.scale;
	state = other_char.state;
	pos = other_char.pos;
	dir = other_char.dir;
	limb = other_char.limb;
}

void Character::setState(int st){
	state = st;
	update_state();
}

void Character::setDir(int char_dir){
	dir = char_dir;
	update_state();
}

void Character::SetPos(float x, float y){
	pos.x = x;
	pos.y = y;
	update_state();
}

void Character::SetPos(Vector2 char_pos){
	pos = char_pos;
	update_state();
}

void Character::DrawChar(){
	//
}
void Character::updateChar(){
	switch(state){
		case 0:{
			switch(dir){//stand
				case 0:{}
				case 1:{}
				case 2:{}
				case 3:{}
			}
		}
		case 1:{//walking 10 deg
			switch(dir){
				case 0:{}
				case 1:{}
				case 2:{}
				case 3:{}
			}
		}
		case 2:{//running 20 deg
			switch(dir){
				case 0:{}
				case 1:{}
				case 2:{}
				case 3:{}
			}
		}
	}
}