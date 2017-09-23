#ifndef _Game_Layer_2_H__
#define _Game_Layer_2_H__

#include "cocos2d.h"
#include "Foodlayer.h"
#include "EnemyBulletLayer.h"
#include "PlayerLayer.h"
#include "PlayerBulletLayer.h"
#include "EnemyLayer_2.h"

using namespace cocos2d;

class GameLayer_2 : public Layer
{
public:

	static Scene* createScene();

	CREATE_FUNC(GameLayer_2);
	virtual bool init();

public:
	//�ص�
	void menuCallback(Ref* pSender);
	void menureStartCallBack(Ref * pSender);
	void menuBack(Ref * pSender);
	void death();
	//������
	//��ײ���
	void update(float t);

	//	void newEnemy(float t);
	//	void moveEnemy(float t);

	//��Ч




	void shield_F(Node * player);
	void fire_F(Node * player);
	void nuclear(int x, int y);
	void newBomb(int x, int y);
	void newBossBomb(int x, int y);
	void win();
	void Light(int x, int y);
	void Laser(Node * player);
	//��Ч��ɾ���ṩ����ľ���
	void del(Node * pSender);

	//�ӵ���Ʒ����ɾ��
	//	void scheduleOnceFOODManager();
	void scheduleOnceFOODManager_1();
	void scheduleOnceFOODManager_2();
	void scheduleOnceFOODManager_3();
	void scheduleOnceFOOD1(float t);
	void scheduleOnceFOOD2(float t);

	void scheduleOnceFOOD3(float t);
	//�л�����
	void enemySch(float t);
	//�л��ӵ�����
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
	//����
	Label *labScore;

public:
	//��Ҳ�
	PlayerLayer *myPlayerLayer;
	//�л���
	EnemyLayer_2*	myEnemyLayer;
	//�ӵ���
	PlayerBulletLayer* myPlayerBulletLayer;
	//������Ʒ��
	FoodLayer *myFoodlayer;
	//�л��ӵ���
	EnemyBulletLayer *myEnemyBulletLayer;
	//�ɻ�����	

	int px, py;
	//�޵��ж�
	int unlimited = 0;
	//�л�
	//Vector<Sprite *> allEnemy;	
	//�����÷�
	int score = 0;
	//�ж���Ʒ�Ƿ��ظ���
	//FOOD1
	int Food1 = 0;
	int Food2 = 0;
	int Food3 = 0;

};

#endif // _Game_Layer_H__
