#include "raylib-cpp.hpp"
#include <map>
#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

using std::string;
using std::map;

class Character{
private:
	map<string,pair<raylib::Rectangle,float>> limbs;
	float scale;
	int dir;//0-front, 1-right, 2-left, 3-back
	int state;//1-walking, 0-standing, 2-running, etc
	Vector2 pos;
	float speed;
	void updateChar();//fixes limb positions
public:
	Character(map<string,pair<raylib::Rectangle,float>>, float, int, int, Vector2);
	Character(Character);
	Character();
	void SetState(int);
	void DrawChar();
	void SetPos(float, float);
	void SetPos(Vector2);
	void setState(int);
	void setDir(int);
	float getSpeed();
}

#endif // CHARACTER_H
