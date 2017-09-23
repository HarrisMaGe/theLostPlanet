#pragma once  
#ifndef __EnemyBulletLayer_H__  
#define __EnemyBulletLayer_H__  
#include "cocos2d.h"  
using namespace cocos2d;

class EnemyBulletLayer : public Layer
{
public:
	EnemyBulletLayer(Node * player);
	static EnemyBulletLayer* create(Node * player);

	virtual bool init();
	void removeEnemyBullet1(Node * myEnemyBullet);

	void removeEnemyBullet2(Node * myEnemyBullet);

	void removeEnemyBullet3(Node * myEnemyBullet);
	void removeEnemyBullet4(Node * myEnemyBullet);
	void removeEnemyBullet5(Node * myEnemyBullet);
	void removeEnemyBullet6(Node * myEnemyBullet);
	void removeEnemyBullet7(Node * myEnemyBullet);
	void removeEnemyBullet8(Node * myEnemyBullet);
	void removeEnemyBullet9(Node * myEnemyBullet);
	void removeEnemyBullet10(Node * myEnemyBullet);
	void removeEnemyBullet11(Node * myEnemyBullet);
	void removeEnemyBullet12(Node * myEnemyBullet);
	
	void newEnemyBullet(Node * oB,int type,float flyVelocity);

	void newEnemyBulletB(Node * oB, int type, float flyVelocity);
	
	void removeEnemyBullet(Node* myEnemyBullet);
	
	
	Node * oB;//传入的坐标
	Node * player;//传入玩家坐标
	int type;//EnemyBullet的类型

	SpriteBatchNode* bulletBatchNode1; //子弹渲染节点
	SpriteBatchNode* bulletBatchNode2;
	SpriteBatchNode* bulletBatchNode3;
	SpriteBatchNode* bulletBatchNode4;
	SpriteBatchNode* bulletBatchNode5;
	SpriteBatchNode* bulletBatchNode6;
	SpriteBatchNode* bulletBatchNode7;
	SpriteBatchNode* bulletBatchNode8;
	SpriteBatchNode* bulletBatchNode9;
	SpriteBatchNode* bulletBatchNode10;
	SpriteBatchNode* bulletBatchNode11;
	SpriteBatchNode* bulletBatchNode12;

	Vector<Sprite *> allEnemyBullet;//用于迭代器使用敌机子弹
};
#endif
