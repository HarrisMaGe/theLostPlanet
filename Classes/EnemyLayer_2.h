//
//  EnemyLayer_2.hpp
//  theLostPlane
//
//  Created by 付镇宇 on 16/8/30.
//
//

#ifndef EnemyLayer_2_h
#define EnemyLayer_2_h
#include "EnemyStyle.h"
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;


class EnemyLayer_2 :public Layer {
public:
	virtual bool init();
	EnemyLayer_2(Node* heroPlane);
	static EnemyLayer_2 *create(Node* heroPlane);

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
	void warning(float t);
	void boss2(float t);
	



	EnemyStyle * myEnemyStlyle;
	int enemyNumber;
	int speed;
	Node * heroPlane;
};
#endif /* EnemyLayer_2_hpp */
