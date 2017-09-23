//
//  EnemyStyle.hpp
//  TheLostPlanet
//
//  Created by 付镇宇 on 16/8/27.
//
//

#ifndef EnemyStyle_h
#define EnemyStyle_h
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class EnemyStyle : public Sprite {
public:
	EnemyStyle(int t);

	//接收传入的英雄飞机
	void inPlane(Node * plane);
	int enemyFlySpeed = 0;
	Node * plane;
	//void changeStyle(float num);

	//飞机不同飞行方式函数
	void newEnemyStyle_1(int t);
	void newEnemyStyle_2(int t);
	void newEnemyStyle_3(int t);
	void newEnemyStyle_4(int t);
	void newEnemyStyle_5(int t);
	void newEnemyStyle_6(int t);
	void newEnemyStyle_7(int t);
	void newEnemyStyle_8(int t);
	void newEnemyStyle_9(int t);
	void newEnemyStyle_10(int t);
	void newEnemyStyle_11(int t);
	void newEnemyStyle_12(int t);
	void boss1();
	void boss2();
	void del(Node * pSender);
	void moveEnemyPlane_2(Node *pNode);
	void moveEnemyPlane_6(Node *pNode);
	void moveEnemyPlane_7(Node *pNode);
	//boss警告
	void warning();


	//static CCEaseInOut* create(float t, CCPoint startPoint, CCPoint endPoint, float height = 0, float angle = 60);
	//int num = 0;


	//敌机容器
	Vector<Sprite *> allEnemy;
	Sprite *enemyPlane;
	CallFuncN  * actionDone;
	//批次渲染节点
	SpriteBatchNode* enemyBatchNode_1;
	SpriteBatchNode* enemyBatchNode_2;
	SpriteBatchNode* enemyBatchNode_3;
	SpriteBatchNode* enemyBatchNode_4;
	SpriteBatchNode* enemyBatchNode_5;
	SpriteBatchNode* enemyBatchNode_6;
	SpriteBatchNode* enemyBatchNode_7;
	SpriteBatchNode* enemyBatchNode_8;
	SpriteBatchNode* enemyBatchNode_9;
	SpriteBatchNode* enemyBatchNode_10;
	SpriteBatchNode* enemyBatchNode_11;

	Sprite * enemyPlane_1;
	Sprite * enemyPlane_2;
	Sprite * enemyPlane_3;
	Sprite * enemyPlane_4;
	Sprite * enemyPlane_5;
	Sprite * enemyPlane_6;
	Sprite * enemyPlane_7;

	Size winSize = Director::getInstance()->getVisibleSize();
};
#endif /* EnemyStyle_hpp */
