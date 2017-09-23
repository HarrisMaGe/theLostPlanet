#ifndef _Player_Layer_H__
#define _Player_Layer_H__

#include "cocos2d.h"


using namespace cocos2d;

class PlayerLayer : public Layer
{
public:

	//初始化
	CREATE_FUNC(PlayerLayer);
	virtual bool init();

	void shootNuclear();

	void removeNuclearWeapon(Node * myEnemyBullet);

public:
	//玩家飞机
	Node * player;

	//血条蓝条检验
	void scheduleenergy(float t);
	void scheduleblood(float t);



	//键盘监听器
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	//键盘调度器
	void leftArrow(float t);
	void upArrow(float t);
	void downArrow(float t);
	void rightArrow(float t);



public:
	//玩家血量
	float life = 20;
	//速度
	double speed = 0.5;
	//血条判断值
	int blood;
	//能量判断值
	int energy;
	//核弹判断
	int nuclear = 0;


};

#endif // _Player_Layer_H__
