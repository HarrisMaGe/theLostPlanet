//
//  EnemyLayer_3.cpp
//  theLostPlane
//
//  Created by ¸¶ÕòÓî on 16/8/31.
//
//

#include "EnemyLayer_3.h"
EnemyLayer_3::EnemyLayer_3(Node* heroPlane) {
	this->heroPlane = heroPlane;

}

EnemyLayer_3 * EnemyLayer_3::create(Node* heroPlane) {
	EnemyLayer_3* pRet = new EnemyLayer_3(heroPlane);
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
bool EnemyLayer_3::init() {
	if (!Layer::init())
	{
		return false;
	}

	myEnemyStlyle = new EnemyStyle(3);
	myEnemyStlyle->autorelease();
	myEnemyStlyle->inPlane(heroPlane);

	//×óÓÒ¸÷Ð±·É10¼Ü
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_4), 0.6, 10, 0);
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_6), 0.6, 10, 0);

	//Ëæ»ú³öÏÖ
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_5), 1, 10, 7);

	//Èý¼ÜÆë·É
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_10), 7, 1, 18);
	//×ó±ß6¼Üµ¹Èý½Ç
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_11), 43, 1, 34);
	//ÓÒ±ß6¼Üµ¹Èý½Ç
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_12), 43, 1, 34);

	//³¯Íæ¼Ò·É
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_1), 1, 5, 42);
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_2), 1, 5, 47);

	//3+2
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_9), 6, 1, 52);

	//5+2
	this->schedule(schedule_selector(EnemyLayer_3::changeStyle_7), 6, 1, 64);


	//¾¯¸æ
	this->schedule(schedule_selector(EnemyLayer_3::warning), 0.4, 10, 83);
	//boss2
	this->schedule(schedule_selector(EnemyLayer_3::boss2), 0.4, 0, 86);
	this->addChild(myEnemyStlyle);
	return true;
}
void EnemyLayer_3::changeStyle_1(float t) {
	myEnemyStlyle->newEnemyStyle_1(3);
}
void EnemyLayer_3::changeStyle_2(float t) {
	myEnemyStlyle->newEnemyStyle_2(3);
}
void EnemyLayer_3::changeStyle_3(float t) {
	myEnemyStlyle->newEnemyStyle_3(3);
}
void EnemyLayer_3::changeStyle_4(float t) {
	myEnemyStlyle->newEnemyStyle_4(3);
}
void EnemyLayer_3::changeStyle_5(float t) {
	myEnemyStlyle->newEnemyStyle_5(3);
}
void EnemyLayer_3::changeStyle_6(float t) {
	myEnemyStlyle->newEnemyStyle_6(3);
}
void EnemyLayer_3::changeStyle_7(float t) {
	myEnemyStlyle->newEnemyStyle_7(3);
}
void EnemyLayer_3::changeStyle_8(float t) {
	myEnemyStlyle->newEnemyStyle_8(3);
}
void EnemyLayer_3::changeStyle_9(float t) {
	myEnemyStlyle->newEnemyStyle_9(3);
}
void EnemyLayer_3::changeStyle_10(float t) {
	myEnemyStlyle->newEnemyStyle_10(3);
}
void EnemyLayer_3::changeStyle_11(float t) {
	myEnemyStlyle->newEnemyStyle_11(3);
}
void EnemyLayer_3::changeStyle_12(float t) {
	myEnemyStlyle->newEnemyStyle_12(3);
}
void EnemyLayer_3::boss2(float t) {
	myEnemyStlyle->boss2();
}

void EnemyLayer_3::warning(float t) {
	myEnemyStlyle->warning();
}
