//
//  EnemyLayer.hpp
//  theLostPlane
//
//  Created by 付镇宇 on 16/8/29.
//
//

#ifndef EnemyLayer_h
#define EnemyLayer_h
#include "EnemyStyle.h"
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class EnemyLayer :public Layer {
public:
	virtual bool init();
	EnemyLayer(Node* heroPlane);
	static EnemyLayer *create(Node* heroPlane);
	Node * heroPlane;

	//飞机方式的切换
	void changeStyle_1(float t);
	void changeStyle_2(float t);
	void changeStyle_3(float t);
	void changeStyle_4(float t);
	void changeStyle_5(float t);
	void changeStyle_6(float t);
	void changeStyle_7(float t);
	void changeStyle_10(float t);
	void boss1(float t);
	void judge(float t);
	void closeSch(float t);
	void warning(float t);

	void del(Node *pSender);


	EnemyStyle * myEnemyStlyle;
	int enemyNumber;
	int speed;

};
#endif /* EnemyLayer_hpp */