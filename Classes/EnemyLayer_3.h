//
//  EnemyLayer_3.hpp
//  theLostPlane
//
//  Created by 付镇宇 on 16/8/31.
//
//

#ifndef EnemyLayer_3_h
#define EnemyLayer_3_h

#include <stdio.h>
#include "EnemyStyle.h"
#include "cocos2d.h"
USING_NS_CC;


class EnemyLayer_3 :public Layer {
public:
	virtual bool init();
	EnemyLayer_3(Node* heroPlane);
	static EnemyLayer_3 *create(Node* heroPlane);

	//飞机方式的切换
	void changeStyle_1(float t);
	void changeStyle_2(float t);
	void changeStyle_3(float t);
	void changeStyle_4(float t);
	void changeStyle_5(float t);
	void changeStyle_6(float t);
	void changeStyle_7(float t);
	void changeStyle_8(float t);
	void changeStyle_9(float t);
	void changeStyle_10(float t);
	void changeStyle_11(float t);
	void changeStyle_12(float t);
	void warning(float t);
	void boss2(float t);




	EnemyStyle * myEnemyStlyle;
	int enemyNumber;
	int speed;
	Node * heroPlane;
};

#endif /* EnemyLayer_3_hpp */
