//
//  EnemyLayer_2.cpp
//  theLostPlane
//
//  Created by ¸¶ÕòÓî on 16/8/30.
//
//

#include "EnemyLayer_2.h"


EnemyLayer_2::EnemyLayer_2(Node* heroPlane) {
	this->heroPlane = heroPlane;

}

EnemyLayer_2 * EnemyLayer_2::create(Node* heroPlane) {
	EnemyLayer_2* pRet = new EnemyLayer_2(heroPlane);
	if (pRet&&pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}

}
bool EnemyLayer_2::init() {
	if (!Layer::init())
	{
		return false;
	}

	myEnemyStlyle = new EnemyStyle(2);
	myEnemyStlyle->autorelease();
	myEnemyStlyle->inPlane(heroPlane);


	//Ëæ»ú³öÏÖ10Ãë
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_5), 1, 10, 0);
	//×óÓÒÒÆ¶¯ÕóÐÍ
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_3), 1, 5, 11);
	//³¯·É»ú³åÀ´
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_1), 1, 5, 17);
	//5+2
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_7), 7, 1, 24);
	// 2¼Ü²¢ÅÅ
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_8), 3, 1, 40);
	
	//3+2
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_9), 7, 1, 48);
	//Ð±·É
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_4), 0.6, 5, 63);
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_6), 0.6, 5, 63);
	//¾¯¸æ
	this->schedule(schedule_selector(EnemyLayer_2::warning), 0.4, 10, 67);
	//boss2
	this->schedule(schedule_selector(EnemyLayer_2::boss2), 0.4, 0, 70);
	this->schedule(schedule_selector(EnemyLayer_2::changeStyle_10), 0.4, 0, 74);

	this->addChild(myEnemyStlyle);
	return true;
}
void EnemyLayer_2::changeStyle_1(float t) {
	myEnemyStlyle->newEnemyStyle_1(2);
}
void EnemyLayer_2::changeStyle_2(float t) {
	myEnemyStlyle->newEnemyStyle_2(2);
}
void EnemyLayer_2::changeStyle_3(float t) {
	myEnemyStlyle->newEnemyStyle_3(2);
}
void EnemyLayer_2::changeStyle_4(float t) {
	myEnemyStlyle->newEnemyStyle_4(2);
}
void EnemyLayer_2::changeStyle_5(float t) {
	myEnemyStlyle->newEnemyStyle_5(2);
}
void EnemyLayer_2::changeStyle_6(float t) {
	myEnemyStlyle->newEnemyStyle_6(2);
}
void EnemyLayer_2::changeStyle_7(float t) {
	myEnemyStlyle->newEnemyStyle_7(2);
}
void EnemyLayer_2::changeStyle_8(float t) {
	myEnemyStlyle->newEnemyStyle_8(2);
}
void EnemyLayer_2::changeStyle_9(float t) {
	myEnemyStlyle->newEnemyStyle_9(2);
}
void EnemyLayer_2::changeStyle_10(float t) {
	myEnemyStlyle->newEnemyStyle_10(2);
}
void EnemyLayer_2::warning(float t) {
	myEnemyStlyle->warning();
}
void EnemyLayer_2::boss2(float t) {
	myEnemyStlyle->boss2();
}
