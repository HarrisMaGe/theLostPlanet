//
//  EnemyLayer.cpp
//  theLostPlane
//
//  Created by ������ on 16/8/29.
//
//

#include "EnemyLayer.h"



EnemyLayer::EnemyLayer(Node* heroPlane) {
	this->heroPlane = heroPlane;

}

EnemyLayer * EnemyLayer::create(Node* heroPlane) {
	EnemyLayer* pRet = new EnemyLayer(heroPlane);
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
bool EnemyLayer::init() {
	if (!Layer::init())
	{
		return false;
	}
	

	myEnemyStlyle = new EnemyStyle(1);
	myEnemyStlyle->autorelease();
	myEnemyStlyle->inPlane(heroPlane);
	/*
	this->schedule(schedule_selector(EnemyLayer::changeStyle_5), 1,10,0);
	this->schedule(schedule_selector(EnemyLayer::changeStyle_1), 1,10,11);
	this->schedule(schedule_selector(EnemyLayer::changeStyle_3), 1,5,22);
	this->schedule(schedule_selector(EnemyLayer::changeStyle_7), 7,1,31);
	*/
	// �������10��
	this->schedule(schedule_selector(EnemyLayer::changeStyle_5), 1, 10, 0);
	//���Ͻǿ���б��
	this->schedule(schedule_selector(EnemyLayer::changeStyle_4), 0.3, 5, 11);
	//���Ͻǿ���б��
	this->schedule(schedule_selector(EnemyLayer::changeStyle_6), 0.3, 5, 13);
	//���Ͻǳ��ɻ�����
	this->schedule(schedule_selector(EnemyLayer::changeStyle_2), 0.5, 10, 17);
	//���Ͻǳ��ɻ�����
	this->schedule(schedule_selector(EnemyLayer::changeStyle_1), 0.5, 10, 17);
	// 5+2 �Ӷ�������
	this->schedule(schedule_selector(EnemyLayer::changeStyle_7), 7, 1, 24);

	this->schedule(schedule_selector(EnemyLayer::warning), 0.4, 10, 37);
	//boss����
	this->scheduleOnce(CC_SCHEDULE_SELECTOR(EnemyLayer::boss1), 40);
	this->scheduleOnce(CC_SCHEDULE_SELECTOR(EnemyLayer::changeStyle_10), 42);
	this->addChild(myEnemyStlyle);

	return true;
}
void EnemyLayer::changeStyle_1(float t) {
	myEnemyStlyle->newEnemyStyle_1(1);
}
void EnemyLayer::changeStyle_2(float t) {
	myEnemyStlyle->newEnemyStyle_2(1);
}
void EnemyLayer::changeStyle_3(float t) {
	myEnemyStlyle->newEnemyStyle_3(1);
}
void EnemyLayer::changeStyle_4(float t) {
	myEnemyStlyle->newEnemyStyle_4(1);
}
void EnemyLayer::changeStyle_5(float t) {
	myEnemyStlyle->newEnemyStyle_5(1);
}
void EnemyLayer::changeStyle_6(float t) {
	myEnemyStlyle->newEnemyStyle_6(1);
}
void EnemyLayer::changeStyle_7(float t) {
	myEnemyStlyle->newEnemyStyle_7(1);
}
void EnemyLayer::changeStyle_10(float t) {
	myEnemyStlyle->newEnemyStyle_10(1);
}
void EnemyLayer::closeSch(float t) {
	this->unscheduleAllCallbacks();
}
void EnemyLayer::warning(float t) {
	myEnemyStlyle->warning();
}
void EnemyLayer::boss1(float t) {
	myEnemyStlyle->boss1();
}

void EnemyLayer::judge(float t) {
	this->scheduleUpdate();

}

void EnemyLayer::del(Node * pSender) {
	pSender->removeFromParentAndCleanup(true);
}