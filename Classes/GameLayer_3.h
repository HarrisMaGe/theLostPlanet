#ifndef _Game_Layer_3_H__
#define _Game_Layer_3_H__

#include "cocos2d.h"
#include "BackGround.h"
#include "Foodlayer.h"
#include "EnemyBulletLayer.h"
#include "PlayerLayer.h"
#include "PlayerBulletLayer.h"
#include "EnemyLayer_3.h"

using namespace cocos2d;

class GameLayer_3 : public Layer
{
public:

	static Scene* createScene();

	CREATE_FUNC(GameLayer_3);
	virtual bool init();

public:
	//回调
	void menuCallback(Ref* pSender);
	void menureStartCallBack(Ref * pSender);
	void menuBack(Ref * pSender);
	void death();
	//调度器
	//碰撞检测
	void update(float t);

	//	void newEnemy(float t);
	//	void moveEnemy(float t);

	//特效




	void shield_F(Node * player);
	void fire_F(Node * player);
	void nuclear(int x, int y);
	void newBomb(int x, int y);
	void newBossBomb(int x, int y);
	void win();
	void Light(int x, int y);
	void Laser(Node * player);
	//特效，删除提供坐标的精灵
	void del(Node * pSender);

	//子弹物品奖励删除
	//	void scheduleOnceFOODManager();
	void scheduleOnceFOODManager_1();
	void scheduleOnceFOODManager_2();
	void scheduleOnceFOODManager_3();
	void scheduleOnceFOOD1(float t);
	void scheduleOnceFOOD2(float t);

	void scheduleOnceFOOD3(float t);
	//敌机调度
	void enemySch(float t);
	//敌机子弹调度
	void enemyBulletManagerA(float t);
	void enemyBulletManagerB(float t);
	void enemyBulletManagerC(float t);
	void enemyBulletManagerD(float t);
	void scheduleOnceDeath(float t);
	void scheduleBossLaser1(float t);
	void scheduleBossLaser2(float t);
	void scheduleBossLaser3(float t);
	void scheduleBossLaserShoot1(float t);
	void scheduleBossShoot2(float t);
	void scheduleOnceWin(float t);
	void scheduleOnceWin2(float t);
	//分数
	Label *labScore;

public:
	//玩家层
	PlayerLayer *myPlayerLayer;
	//敌机层
	EnemyLayer_3*	myEnemyLayer;
	//子弹层
	PlayerBulletLayer* myPlayerBulletLayer;
	//掉落物品层
	FoodLayer *myFoodlayer;
	//敌机子弹层
	EnemyBulletLayer *myEnemyBulletLayer;
	//飞机坐标	

	int px, py;
	//无敌判断
	int unlimited = 0;
	//敌机
	//Vector<Sprite *> allEnemy;	
	//比赛得分
	int score = 0;
	//判断物品是否被重复吃
	//FOOD1
	int Food1 = 0;
	int Food2 = 0;
	int Food3 = 0;

};

#endif // _Game_Layer_H__
