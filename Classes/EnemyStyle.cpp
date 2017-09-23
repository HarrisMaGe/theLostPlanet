//
//  EnemyStyle.cpp
//  TheLostPlanet
//
//  Created by 付镇宇 on 16/8/27.
//
//

#include "EnemyStyle.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

EnemyStyle::EnemyStyle(int t) {
	if (t == 1) {
		enemyBatchNode_1 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_1);
		enemyBatchNode_2 = SpriteBatchNode::create("plane/enemy2.png");
		this->addChild(enemyBatchNode_2);
		enemyBatchNode_3 = SpriteBatchNode::create("plane/enemy3.png");
		this->addChild(enemyBatchNode_3);
		enemyBatchNode_4 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_4);
		enemyBatchNode_5 = SpriteBatchNode::create("plane/boss1_0.png");
		this->addChild(enemyBatchNode_5);
		enemyBatchNode_10 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_10);
	}
	else if (t == 2) {
		enemyBatchNode_1 = SpriteBatchNode::create("plane/enemy_2_1.png");
		this->addChild(enemyBatchNode_1);
		enemyBatchNode_2 = SpriteBatchNode::create("plane/enemy_2_2.png");
		this->addChild(enemyBatchNode_2);
		enemyBatchNode_3 = SpriteBatchNode::create("plane/enemy_2_3.png");
		this->addChild(enemyBatchNode_3);
		enemyBatchNode_4 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_4);
		enemyBatchNode_5 = SpriteBatchNode::create("plane/boss2_0.png");
		this->addChild(enemyBatchNode_5);
		enemyBatchNode_6 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_6);
		enemyBatchNode_7 = SpriteBatchNode::create("plane/enemy2.png");
		this->addChild(enemyBatchNode_7);
		enemyBatchNode_8 = SpriteBatchNode::create("plane/enemy3.png");
		this->addChild(enemyBatchNode_8);
		enemyBatchNode_10 = SpriteBatchNode::create("plane/enemy_2_2.png");
		this->addChild(enemyBatchNode_10);

	}
	else if (t == 3) {
		enemyBatchNode_1 = SpriteBatchNode::create("plane/enemy_3_1.png");
		this->addChild(enemyBatchNode_1);
		enemyBatchNode_2 = SpriteBatchNode::create("plane/enemy_3_2.png");
		this->addChild(enemyBatchNode_2);
		enemyBatchNode_3 = SpriteBatchNode::create("plane/enemy_3_3.png");
		this->addChild(enemyBatchNode_3);
		enemyBatchNode_4 = SpriteBatchNode::create("plane/enemy_3_4.png");
		this->addChild(enemyBatchNode_4);
		enemyBatchNode_5 = SpriteBatchNode::create("plane/boss3_0.png");
		this->addChild(enemyBatchNode_5);
		enemyBatchNode_6 = SpriteBatchNode::create("plane/enemy1.png");
		this->addChild(enemyBatchNode_6);
		enemyBatchNode_7 = SpriteBatchNode::create("plane/enemy2.png");
		this->addChild(enemyBatchNode_7);
		enemyBatchNode_8 = SpriteBatchNode::create("plane/enemy3.png");
		this->addChild(enemyBatchNode_8);
		enemyBatchNode_9 = SpriteBatchNode::create("plane/enemy_2_1.png");
		this->addChild(enemyBatchNode_9);
		enemyBatchNode_10 = SpriteBatchNode::create("plane/enemy_2_2.png");
		this->addChild(enemyBatchNode_10);
		enemyBatchNode_11 = SpriteBatchNode::create("plane/enemy_2_3.png");
		this->addChild(enemyBatchNode_11);
	}
}
void EnemyStyle::inPlane(Node *plane) {
	this->plane = plane;
}





//飞行方式一：右上角出发朝英雄飞机飞来
void EnemyStyle::newEnemyStyle_1(int t) {
	//设置飞机速度
	enemyFlySpeed = 600;
	if (t == 1) {
		//应用批次渲染
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane);

	}
	else if (t == 2) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_7->getTexture());
		enemyBatchNode_7->addChild(enemyPlane);

	}
	else if (t == 3) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_9->getTexture());
		enemyBatchNode_9->addChild(enemyPlane);

	}

	enemyPlane->setTag(250);

	//设置敌机的位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(winSize.width + planeWidth / 2, winSize.height + planeHeight / 2));
	//this->addChild(enemyPlane);
	this->allEnemy.pushBack(enemyPlane);

	//获取飞机横纵坐标
	float x = plane->getPositionX();
	float y = plane->getPositionY();

	//窗口大小减去飞机坐标
	float winSize_x = winSize.width - x;
	float winSize_y = winSize.height - y;

	//飞行的角度,敌机旋转角度
	float radians = atanf(winSize_x / winSize_y);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemyPlane->setRotation(180 + mDegree);

	//敌机最后的位置的坐标设定
	float endPositionX = winSize.width - (winSize_x / winSize_y)*winSize.height;
	float endPositionY = 0 - planeHeight;
	//飞行距离
	float flyLen = sqrt((winSize.width - endPositionX)*(winSize.width - endPositionX) + (winSize.height - endPositionY)*(winSize.height - endPositionY));
	float realFlyDuration = flyLen / enemyFlySpeed;

	//设置动作
	auto actionMove = MoveTo::create(realFlyDuration, Point(endPositionX, endPositionY));
	//auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane, this));
	Sequence * sequence = Sequence::create(actionMove, NULL);
	enemyPlane->runAction(sequence);
}





//敌机的第二种飞行方式：左上角出发朝英雄飞机飞来
void EnemyStyle::newEnemyStyle_2(int t) {
	//设置飞机速度
	enemyFlySpeed = 600;

	if (t == 1) {
		//应用批次渲染
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane);

	}
	else if (t == 2) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_7->getTexture());
		enemyBatchNode_7->addChild(enemyPlane);

	}
	else if (t == 3) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_9->getTexture());
		enemyBatchNode_9->addChild(enemyPlane);

	}

	enemyPlane->setTag(250);

	//设置敌机的位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(0 - planeWidth / 2, winSize.height + planeHeight / 2));
	this->allEnemy.pushBack(enemyPlane);

	//获取飞机横纵坐标
	float x = plane->getPositionX();
	float y = plane->getPositionY();

	//窗口大小减去飞机坐标
	float winSize_x = winSize.width - x;
	float winSize_y = winSize.height - y;

	//飞机的角度，敌机旋转角度
	float radians = atanf(x / winSize_y);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemyPlane->setRotation(180 - mDegree);

	//敌机设置飞机最后位置
	float endPositionX = winSize.height * x / winSize_y;
	float endPositionY = 0 - planeHeight;
	//飞行距离
	float flyLen = sqrt(endPositionX *endPositionX + (winSize.height - endPositionY)*(winSize.height - endPositionY));
	float realFlyDuration = flyLen / enemyFlySpeed;
	auto actionMove = MoveTo::create(realFlyDuration, Point(endPositionX, endPositionY));
	//auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane, this));
	Sequence * sequence = Sequence::create(actionMove, NULL);
	enemyPlane->runAction(sequence);
}





//飞行方式三：从顶端下来，再移向左边，再移向右边，最后移向中间
void EnemyStyle::newEnemyStyle_3(int t) {
	//设置飞机速度
	enemyFlySpeed = 350;

	//应用批次渲染
	auto enemyPlane = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
	enemyBatchNode_1->addChild(enemyPlane);
	enemyPlane->setTag(500);

	//设置敌机位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(winSize.width / 2, winSize.height + planeHeight / 2));
	//this->addChild(enemyPlane);
	this->allEnemy.pushBack(enemyPlane);

	//下来停靠的位置
	float stopPositionX = winSize.width / 2;
	float stopPositionY = winSize.height * 4 / 5;

	//飞行距离
	float flyLen = winSize.height * 1 / 5 + planeHeight / 2;
	float realFlyDuration = flyLen / enemyFlySpeed;

	//设置动作
	auto actionMove = MoveTo::create(realFlyDuration, Point(stopPositionX, stopPositionY));


	//boss左右动
	float stopPositionX_2 = planeWidth / 2;
	float stopPositionY_2 = winSize.height * 4 / 5;
	float flyLen_2 = winSize.width / 2;
	float realFlyDuration_2 = flyLen_2 / enemyFlySpeed;

	//设置动作
	auto actionMove_2 = MoveTo::create(realFlyDuration_2, Point(stopPositionX_2, stopPositionY_2));

	float stopPositionX_3 = winSize.width - planeWidth / 2;
	float stopPositionY_3 = winSize.height * 4 / 5;
	float flyLen_3 = winSize.width - planeWidth;
	float realFlyDuration_3 = flyLen_3 / enemyFlySpeed;
	//设置动作
	auto actionMove_3 = MoveTo::create(realFlyDuration_3, Point(stopPositionX_3, stopPositionY_3));
	//auto actionDone_2 = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane, this));

	float stopPositionX_4 = rand() % 512;
	float stopPositionY_4 = winSize.height * 4 / 5;
	float flyLen_4 = winSize.width / 2 - planeWidth / 2;
	float realFlyDuration_4 = flyLen_4 / enemyFlySpeed;
	auto actionMove_4 = MoveTo::create(realFlyDuration_4, Point(stopPositionX_4, stopPositionY_4));
	Sequence * sequence = Sequence::create(actionMove, actionMove_2, actionMove_3, actionMove_4, NULL);
	enemyPlane->runAction(sequence);
}


//左顶端快速斜飞
void EnemyStyle::newEnemyStyle_4(int t) {
	if (t == 1) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}
	else if (t == 2) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_7->getTexture());
		enemyBatchNode_7->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}
	else if (t == 3) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}
	enemyFlySpeed = 400;

	//设置敌机的位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(winSize.width + planeWidth / 2, winSize.height + planeHeight / 2));
	this->allEnemy.pushBack(enemyPlane);

	//飞机的角度，敌机旋转角度
	float radians = atanf(winSize.width / winSize.height / 2);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemyPlane->setRotation(180 + mDegree);

	//设置敌机最后位置
	float endPositionX = 0 - planeWidth / 2;
	float endPositionY = winSize.height / 2;

	//飞行距离
	float flyLen = sqrt(winSize.width*winSize.width + winSize.height / 2 * winSize.height / 2);
	float realFlyDuration = flyLen / enemyFlySpeed;


	//设置动作
	auto actionMove = MoveTo::create(realFlyDuration, Point(endPositionX, endPositionY));

	if (t == 1)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_2, this));
	}
	else if (t == 2)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_7, this));
	}
	else if (t == 3)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_6, this));
	}
	Sequence * sequence = Sequence::create(actionMove, actionDone, NULL);
	enemyPlane->runAction(sequence);

}



//飞行方式五：随机出现向下移动
void EnemyStyle::newEnemyStyle_5(int t) {
	//设置飞机速度
	enemyFlySpeed = 300;

	//应用批次渲染
	auto enemyPlane = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
	enemyPlane->setPosition(Point(rand() % 512, winSize.height - 100));
	enemyBatchNode_1->addChild(enemyPlane);
	this->allEnemy.pushBack(enemyPlane);
	enemyPlane->setTag(500);

	//获取敌机的大小
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;

	//设置敌机末位置
	float endPositionX = enemyPlane->getPositionX();
	float endPositionY = 0 - planeHeight / 2;

	//飞行距离
	float flyLen = enemyPlane->getPositionY() + planeHeight / 2;
	auto actionMove = MoveTo::create(flyLen / enemyFlySpeed, Point(endPositionX, endPositionY));
	Sequence * sequence = Sequence::create(actionMove, NULL);
	enemyPlane->runAction(sequence);
}


//右顶端快速斜飞
void EnemyStyle::newEnemyStyle_6(int t) {
	enemyFlySpeed = 400;
	if (t == 1) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}
	else if (t == 2) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_7->getTexture());
		enemyBatchNode_7->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}
	else if (t == 3) {
		enemyPlane = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane);
		enemyPlane->setTag(1000);
	}

	//设置敌机的位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(0 - planeWidth / 2, winSize.height + planeHeight / 2));
	this->allEnemy.pushBack(enemyPlane);

	//飞机的角度，敌机旋转角度
	float radians = atanf(winSize.width / winSize.height / 2);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemyPlane->setRotation(180 - mDegree);

	//敌机设置飞机最后位置
	float endPositionX = winSize.width + planeWidth / 2;
	float endPositionY = winSize.height / 2;

	//飞行距离
	float flyLen = sqrt(winSize.width*winSize.width + winSize.height / 2 * winSize.height / 2);
	float realFlyDuration = flyLen / enemyFlySpeed;

	//设置动作
	auto actionMove = MoveTo::create(realFlyDuration, Point(endPositionX, endPositionY));
	if (t == 1)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_2, this));
	}
	else if (t == 2)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_7, this));
	}
	else if (t == 3)
	{
		actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane_6, this));
	}

	Sequence * sequence = Sequence::create(actionMove, actionDone, NULL);
	enemyPlane->runAction(sequence);
}

// 5＋2 飞阵型
void EnemyStyle::newEnemyStyle_7(int t) {
	enemyFlySpeed = 80;

	//判断关卡
	if (t == 1) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_1);
		enemyPlane_1->setTag(500);

		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_2);
		enemyPlane_2->setTag(500);

		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_3);
		enemyPlane_3->setTag(500);

		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_4);
		enemyPlane_4->setTag(500);

		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_5);
		enemyPlane_5->setTag(500);

		enemyPlane_6 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_6);
		enemyPlane_6->setTag(1500);

		enemyPlane_7 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_7);
		enemyPlane_7->setTag(1500);
	}
	else if (t == 2) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_1);
		enemyPlane_1->setTag(500);

		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_2);
		enemyPlane_2->setTag(500);

		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_3);
		enemyPlane_3->setTag(500);

		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_4);
		enemyPlane_4->setTag(500);

		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_5);
		enemyPlane_5->setTag(500);

		enemyPlane_6 = Sprite::createWithTexture(enemyBatchNode_8->getTexture());
		enemyBatchNode_8->addChild(enemyPlane_6);
		enemyPlane_6->setTag(1500);

		enemyPlane_7 = Sprite::createWithTexture(enemyBatchNode_8->getTexture());
		enemyBatchNode_8->addChild(enemyPlane_7);
		enemyPlane_7->setTag(1500);
	}
	else if (t == 3) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_1);
		enemyPlane_1->setTag(1000);

		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_2);
		enemyPlane_2->setTag(1000);

		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_3);
		enemyPlane_3->setTag(1000);

		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_4);
		enemyPlane_4->setTag(1000);

		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_6->getTexture());
		enemyBatchNode_6->addChild(enemyPlane_5);
		enemyPlane_5->setTag(1000);

		enemyPlane_6 = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane_6);
		enemyPlane_6->setTag(1500);

		enemyPlane_7 = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane_7);
		enemyPlane_7->setTag(1500);
	}

	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);
	this->allEnemy.pushBack(enemyPlane_3);
	this->allEnemy.pushBack(enemyPlane_4);
	this->allEnemy.pushBack(enemyPlane_5);
	this->allEnemy.pushBack(enemyPlane_6);
	this->allEnemy.pushBack(enemyPlane_7);

	//获取敌机图片大小
	float planeHeight = enemyPlane_1->getContentSize().height;
	float planeWidth = enemyPlane_1->getContentSize().width;
	float planeHeight_big = enemyPlane_6->getContentSize().height;
	float planeWidth_big = enemyPlane_6->getContentSize().width;

	//设置5+2个敌机位置
	enemyPlane_1->setPosition(Vec2((winSize.width / 2 - planeWidth * 2), winSize.height + planeHeight / 2));
	enemyPlane_2->setPosition(Vec2((winSize.width / 2 - planeWidth), winSize.height + planeHeight / 2));
	enemyPlane_3->setPosition(Vec2((winSize.width / 2), winSize.height + planeHeight / 2));
	enemyPlane_4->setPosition(Vec2((winSize.width / 2 + planeWidth), winSize.height + planeHeight / 2));
	enemyPlane_5->setPosition(Vec2((winSize.width / 2 + planeWidth * 2), winSize.height + planeHeight / 2));
	enemyPlane_6->setPosition(Vec2((winSize.width / 2 - planeWidth_big / 2), winSize.height + planeHeight + planeHeight_big / 2));
	enemyPlane_7->setPosition(Vec2((winSize.width / 2 + planeWidth_big / 2), winSize.height + planeHeight + planeHeight_big / 2));

	//设置5+2个敌机最后停靠位置
	float endPositionX_1 = enemyPlane_1->getPositionX();
	float endPositionY_1 = winSize.height * 3 / 5;
	float endPositionX_2 = enemyPlane_2->getPositionX();
	float endPositionY_2 = winSize.height * 3 / 5;
	float endPositionX_3 = enemyPlane_3->getPositionX();
	float endPositionY_3 = winSize.height * 3 / 5;
	float endPositionX_4 = enemyPlane_4->getPositionX();
	float endPositionY_4 = winSize.height * 3 / 5;
	float endPositionX_5 = enemyPlane_5->getPositionX();
	float endPositionY_5 = winSize.height * 3 / 5;
	float endPositionX_6 = enemyPlane_6->getPositionX();
	float endPositionY_6 = winSize.height * 4 / 5;
	float endPositionX_7 = enemyPlane_7->getPositionX();
	float endPositionY_7 = winSize.height * 4 / 5;

	//设置5+2个敌机动作
	auto actionMove_1 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_1, endPositionY_1));
	auto actionMove_2 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_2, endPositionY_2));
	auto actionMove_3 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_3, endPositionY_3));
	auto actionMove_4 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_4, endPositionY_4));
	auto actionMove_5 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_5, endPositionY_5));
	auto actionMove_6 = MoveTo::create((winSize.height * 1 / 5) / enemyFlySpeed, Point(endPositionX_6, endPositionY_6));
	auto actionMove_7 = MoveTo::create((winSize.height * 1 / 5) / enemyFlySpeed, Point(endPositionX_7, endPositionY_7));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);
	Sequence * sequence_3 = Sequence::create(actionMove_3, NULL);
	Sequence * sequence_4 = Sequence::create(actionMove_4, NULL);
	Sequence * sequence_5 = Sequence::create(actionMove_5, NULL);
	Sequence * sequence_6 = Sequence::create(actionMove_6, NULL);
	Sequence * sequence_7 = Sequence::create(actionMove_7, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);
	enemyPlane_3->runAction(sequence_3);
	enemyPlane_4->runAction(sequence_4);
	enemyPlane_5->runAction(sequence_5);
	enemyPlane_6->runAction(sequence_6);
	enemyPlane_7->runAction(sequence_7);

}

//  两架飞机并排出
void EnemyStyle::newEnemyStyle_8(int t) {
	enemyFlySpeed = 80;
	//两架飞机的创建
	auto enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
	enemyBatchNode_3->addChild(enemyPlane_1);
	enemyPlane_1->setTag(1500);
	auto enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
	enemyBatchNode_3->addChild(enemyPlane_2);
	enemyPlane_2->setTag(1500);
	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);

	//获取敌机图片大小
	float planeHeight = enemyPlane_2->getContentSize().height;
	float planeWidth = enemyPlane_2->getContentSize().width;

	//设置2个敌机位置
	enemyPlane_1->setPosition(Vec2((winSize.width / 2 - planeWidth / 2), winSize.height + planeHeight / 2));
	enemyPlane_2->setPosition(Vec2((winSize.width / 2 + planeWidth / 2), winSize.height + planeHeight / 2));

	//设置2个敌机最后停靠位置
	float endPositionX_1 = enemyPlane_1->getPositionX();
	float endPositionY_1 = winSize.height * 7 / 10;
	float endPositionX_2 = enemyPlane_2->getPositionX();
	float endPositionY_2 = winSize.height * 7 / 10;

	//设置2个敌机动作
	auto actionMove_1 = MoveTo::create((winSize.height * 3 / 10) / enemyFlySpeed, Point(endPositionX_1, endPositionY_1));
	auto actionMove_2 = MoveTo::create((winSize.height * 3 / 10) / enemyFlySpeed, Point(endPositionX_2, endPositionY_2));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);

}

// 3+2
void EnemyStyle::newEnemyStyle_9(int t) {
	enemyFlySpeed = 80;

	//判断关卡
	if (t == 1) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_1);
		enemyPlane_1->setTag(500);
		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_2);
		enemyPlane_2->setTag(500);
		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_3);
		enemyPlane_3->setTag(500);
		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_4);
		enemyPlane_4->setTag(1500);
		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_5);
		enemyPlane_5->setTag(1500);
	}
	else if (t == 2) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_1);
		enemyPlane_1->setTag(500);
		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_2);
		enemyPlane_2->setTag(500);
		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_1->getTexture());
		enemyBatchNode_1->addChild(enemyPlane_3);
		enemyPlane_3->setTag(500);
		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_4);
		enemyPlane_4->setTag(1500);
		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_5);
		enemyPlane_5->setTag(1500);
	}
	else if (t == 3) {
		enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane_1);
		enemyPlane_1->setTag(1000);
		enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane_2);
		enemyPlane_2->setTag(1000);
		enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_2->getTexture());
		enemyBatchNode_2->addChild(enemyPlane_3);
		enemyPlane_3->setTag(1000);

		enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_4);
		enemyPlane_4->setTag(1500);
		enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
		enemyBatchNode_3->addChild(enemyPlane_5);
		enemyPlane_5->setTag(1500);
	}


	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);
	this->allEnemy.pushBack(enemyPlane_3);
	this->allEnemy.pushBack(enemyPlane_4);
	this->allEnemy.pushBack(enemyPlane_5);

	//获取敌机图片大小
	float planeHeight = enemyPlane_1->getContentSize().height;
	float planeWidth = enemyPlane_1->getContentSize().width;
	float planeHeight_big = enemyPlane_4->getContentSize().height;
	float planeWidth_big = enemyPlane_4->getContentSize().width;

	//设置5个敌机位置
	enemyPlane_1->setPosition(Vec2((winSize.width / 2 - planeWidth), winSize.height + planeHeight / 2));
	enemyPlane_2->setPosition(Vec2((winSize.width / 2), winSize.height + planeHeight / 2));
	enemyPlane_3->setPosition(Vec2((winSize.width / 2 + planeWidth), winSize.height + planeHeight / 2));
	enemyPlane_4->setPosition(Vec2((winSize.width / 2 - planeWidth_big / 2), winSize.height + planeHeight + planeWidth_big / 2));
	enemyPlane_5->setPosition(Vec2((winSize.width / 2 + planeWidth_big / 2), winSize.height + planeHeight / 2 + planeWidth_big / 2));

	//设置5个敌机最后停靠位置
	float endPositionX_1 = enemyPlane_1->getPositionX();
	float endPositionY_1 = winSize.height * 3 / 5;
	float endPositionX_2 = enemyPlane_2->getPositionX();
	float endPositionY_2 = winSize.height * 3 / 5;
	float endPositionX_3 = enemyPlane_3->getPositionX();
	float endPositionY_3 = winSize.height * 3 / 5;
	float endPositionX_4 = enemyPlane_4->getPositionX();
	float endPositionY_4 = winSize.height * 4 / 5;
	float endPositionX_5 = enemyPlane_5->getPositionX();
	float endPositionY_5 = winSize.height * 4 / 5;


	//设置5个敌机动作
	auto actionMove_1 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_1, endPositionY_1));
	auto actionMove_2 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_2, endPositionY_2));
	auto actionMove_3 = MoveTo::create((winSize.height * 2 / 5) / enemyFlySpeed, Point(endPositionX_3, endPositionY_3));
	auto actionMove_4 = MoveTo::create((winSize.height * 1 / 5 + planeHeight) / enemyFlySpeed, Point(endPositionX_4, endPositionY_4));
	auto actionMove_5 = MoveTo::create((winSize.height * 1 / 5 + planeHeight) / enemyFlySpeed, Point(endPositionX_5, endPositionY_5));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);
	Sequence * sequence_3 = Sequence::create(actionMove_3, NULL);
	Sequence * sequence_4 = Sequence::create(actionMove_4, NULL);
	Sequence * sequence_5 = Sequence::create(actionMove_5, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);
	enemyPlane_3->runAction(sequence_3);
	enemyPlane_4->runAction(sequence_4);
	enemyPlane_5->runAction(sequence_5);

}


//3架并排
void EnemyStyle::newEnemyStyle_10(int t) {
	enemyFlySpeed = 100;

	//应用批次渲染
	enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
	enemyBatchNode_3->addChild(enemyPlane_1);
	enemyPlane_1->setTag(1500);

	enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_10->getTexture());
	enemyBatchNode_10->addChild(enemyPlane_2);
	enemyPlane_2->setTag(1500);

	enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_3->getTexture());
	enemyBatchNode_3->addChild(enemyPlane_3);
	enemyPlane_3->setTag(1500);

	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);
	this->allEnemy.pushBack(enemyPlane_3);

	//获取敌机图片大小
	float planeHeight_2 = enemyPlane_2->getContentSize().height;
	float planeWidth_2 = enemyPlane_2->getContentSize().width;
	float planeHeight_3 = enemyPlane_1->getContentSize().height;
	float planeWidth_3 = enemyPlane_1->getContentSize().width;

	//设置敌机初始位置
	enemyPlane_1->setPosition(Vec2((winSize.width / 2 - planeWidth_2 / 2 - planeWidth_3 / 2), (winSize.height + planeHeight_3 / 2)));

	enemyPlane_2->setPosition(Vec2(winSize.width / 2, winSize.height + planeHeight_2 / 2));

	enemyPlane_3->setPosition(Vec2((winSize.width / 2 + planeWidth_2 / 2 + planeWidth_3 / 2), (winSize.height + planeHeight_3 / 2)));

	//设置敌机
	float endPositionX_1 = enemyPlane_1->getPositionX();
	float endPositionY_1 = winSize.height * 7 / 10;
	float endPositionX_2 = enemyPlane_2->getPositionX();
	float endPositionY_2 = winSize.height * 7 / 10;
	float endPositionX_3 = enemyPlane_3->getPositionX();
	float endPositionY_3 = winSize.height * 7 / 10;


	//飞行距离
	float flyLen = winSize.height * 3 / 10;
	float realFlyDuration = flyLen / enemyFlySpeed;

	//设置动作
	auto actionMove_1 = MoveTo::create(realFlyDuration, Point(endPositionX_1, endPositionY_1));

	auto actionMove_2 = MoveTo::create(realFlyDuration, Point(endPositionX_2, endPositionY_2));

	auto actionMove_3 = MoveTo::create(realFlyDuration, Point(endPositionX_3, endPositionY_3));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);
	Sequence * sequence_3 = Sequence::create(actionMove_3, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);
	enemyPlane_3->runAction(sequence_3);
}


//左侧出来6架飞机倒三角
void EnemyStyle::newEnemyStyle_11(int t) {
	enemyFlySpeed = 80;

	//应用批次渲染
	enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_1);
	enemyPlane_1->setTag(1000);

	enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_2);
	enemyPlane_2->setTag(1000);

	enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_3);
	enemyPlane_3->setTag(1000);

	enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_4);
	enemyPlane_4->setTag(1000);

	enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_5);
	enemyPlane_5->setTag(1000);

	enemyPlane_6 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_6);
	enemyPlane_6->setTag(1000);

	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);
	this->allEnemy.pushBack(enemyPlane_3);
	this->allEnemy.pushBack(enemyPlane_4);
	this->allEnemy.pushBack(enemyPlane_5);
	this->allEnemy.pushBack(enemyPlane_6);

	//获取图片大小
	float planeHeight = enemyPlane_1->getContentSize().height;
	float planeWidth = enemyPlane_1->getContentSize().width;

	//设置敌机初始位置
	enemyPlane_1->setPosition(Vec2((0 - planeWidth / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_2->setPosition(Vec2((0 - planeWidth * 3 / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_3->setPosition(Vec2((0 - planeWidth * 5 / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_4->setPosition(Vec2((0 - planeWidth), winSize.height * 4 / 5));
	enemyPlane_5->setPosition(Vec2((0 - planeWidth * 2), winSize.height * 4 / 5));
	enemyPlane_6->setPosition(Vec2((0 - planeWidth * 3 / 2), (winSize.height * 4 / 5 - planeHeight)));

	//设置6个敌机最后停靠位置
	float endPositionX_1 = planeWidth * 5 / 2;
	float endPositionY_1 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_2 = planeWidth * 3 / 2;
	float endPositionY_2 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_3 = planeWidth / 2;
	float endPositionY_3 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_4 = planeWidth;
	float endPositionY_4 = winSize.height * 4 / 5;
	float endPositionX_5 = planeWidth * 2;
	float endPositionY_5 = winSize.height * 4 / 5;
	float endPositionX_6 = planeWidth * 3 / 2;
	float endPositionY_6 = winSize.height * 4 / 5 - planeHeight;

	//设置6个敌机动作
	auto actionMove_1 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_1, endPositionY_1));
	auto actionMove_2 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_2, endPositionY_2));
	auto actionMove_3 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_3, endPositionY_3));
	auto actionMove_4 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_4, endPositionY_4));
	auto actionMove_5 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_5, endPositionY_5));
	auto actionMove_6 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_6, endPositionY_6));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);
	Sequence * sequence_3 = Sequence::create(actionMove_3, NULL);
	Sequence * sequence_4 = Sequence::create(actionMove_4, NULL);
	Sequence * sequence_5 = Sequence::create(actionMove_5, NULL);
	Sequence * sequence_6 = Sequence::create(actionMove_6, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);
	enemyPlane_3->runAction(sequence_3);
	enemyPlane_4->runAction(sequence_4);
	enemyPlane_5->runAction(sequence_5);
	enemyPlane_6->runAction(sequence_6);
}


//右侧出来6架飞机倒三角
void EnemyStyle::newEnemyStyle_12(int t) {
	enemyFlySpeed = 80;

	//应用批次渲染
	enemyPlane_1 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_1);
	enemyPlane_1->setTag(1000);

	enemyPlane_2 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_2);
	enemyPlane_2->setTag(1000);

	enemyPlane_3 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_3);
	enemyPlane_3->setTag(1000);

	enemyPlane_4 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_4);
	enemyPlane_4->setTag(1000);

	enemyPlane_5 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_5);
	enemyPlane_5->setTag(1000);

	enemyPlane_6 = Sprite::createWithTexture(enemyBatchNode_4->getTexture());
	enemyBatchNode_4->addChild(enemyPlane_6);
	enemyPlane_6->setTag(1000);

	this->allEnemy.pushBack(enemyPlane_1);
	this->allEnemy.pushBack(enemyPlane_2);
	this->allEnemy.pushBack(enemyPlane_3);
	this->allEnemy.pushBack(enemyPlane_4);
	this->allEnemy.pushBack(enemyPlane_5);
	this->allEnemy.pushBack(enemyPlane_6);

	//获取图片大小
	float planeHeight = enemyPlane_1->getContentSize().height;
	float planeWidth = enemyPlane_1->getContentSize().width;

	//设置敌机初始位置
	enemyPlane_1->setPosition(Vec2((winSize.width + planeWidth / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_2->setPosition(Vec2((winSize.width + planeWidth * 3 / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_3->setPosition(Vec2((winSize.width + planeWidth * 5 / 2), (winSize.height * 4 / 5 + planeHeight)));
	enemyPlane_4->setPosition(Vec2((winSize.width + planeWidth), winSize.height * 4 / 5));
	enemyPlane_5->setPosition(Vec2((winSize.width + planeWidth * 2), winSize.height * 4 / 5));
	enemyPlane_6->setPosition(Vec2((winSize.width + planeWidth * 3 / 2), (winSize.height * 4 / 5 - planeHeight)));

	//设置6个敌机最后停靠位置
	float endPositionX_1 = winSize.width - (planeWidth * 5 / 2);
	float endPositionY_1 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_2 = winSize.width - planeWidth * 3 / 2;
	float endPositionY_2 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_3 = winSize.width - planeWidth / 2;
	float endPositionY_3 = winSize.height * 4 / 5 + planeHeight;
	float endPositionX_4 = winSize.width - planeWidth;
	float endPositionY_4 = winSize.height * 4 / 5;
	float endPositionX_5 = winSize.width - planeWidth * 2;
	float endPositionY_5 = winSize.height * 4 / 5;
	float endPositionX_6 = winSize.width - planeWidth * 3 / 2;
	float endPositionY_6 = winSize.height * 4 / 5 - planeHeight;

	//设置6个敌机动作
	auto actionMove_1 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_1, endPositionY_1));
	auto actionMove_2 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_2, endPositionY_2));
	auto actionMove_3 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_3, endPositionY_3));
	auto actionMove_4 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_4, endPositionY_4));
	auto actionMove_5 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_5, endPositionY_5));
	auto actionMove_6 = MoveTo::create((planeWidth * 3) / enemyFlySpeed, Point(endPositionX_6, endPositionY_6));

	Sequence * sequence_1 = Sequence::create(actionMove_1, NULL);
	Sequence * sequence_2 = Sequence::create(actionMove_2, NULL);
	Sequence * sequence_3 = Sequence::create(actionMove_3, NULL);
	Sequence * sequence_4 = Sequence::create(actionMove_4, NULL);
	Sequence * sequence_5 = Sequence::create(actionMove_5, NULL);
	Sequence * sequence_6 = Sequence::create(actionMove_6, NULL);

	enemyPlane_1->runAction(sequence_1);
	enemyPlane_2->runAction(sequence_2);
	enemyPlane_3->runAction(sequence_3);
	enemyPlane_4->runAction(sequence_4);
	enemyPlane_5->runAction(sequence_5);
	enemyPlane_6->runAction(sequence_6);
}




//boss出来警告
void EnemyStyle::warning() {

	SimpleAudioEngine::getInstance()->playEffect("music/boss_warning.wav");
	Vector<SpriteFrame *>allframe;
	SpriteFrame *war1 = SpriteFrame::create("effect/warning1.png", Rect(0, 0, 512, 270));
	allframe.pushBack(war1);
	SpriteFrame *war2 = SpriteFrame::create("effect/warning2.png", Rect(0, 0, 512, 270));
	allframe.pushBack(war2);
	SpriteFrame *war3 = SpriteFrame::create("effect/warning3.png", Rect(0, 0, 512, 270));
	allframe.pushBack(war3);
	SpriteFrame *war4 = SpriteFrame::create("effect/warning4.png", Rect(0, 0, 512, 270));
	allframe.pushBack(war4);
	Animation *animation = Animation::createWithSpriteFrames(allframe, 0.1);
	auto sprite = Sprite::create();
	this->addChild(sprite);

	Action * action = Sequence::create(Animate::create(animation), CCCallFuncN::create(sprite, callfuncN_selector(EnemyStyle::del)), NULL);
	sprite->setPosition(Vec2(winSize.width / 2, winSize.height * 2 / 3));

	sprite->runAction(action);
	allframe.clear();
}






//boss1 飞行方式
void EnemyStyle::boss1() {
	//设置飞机速度
	enemyFlySpeed = 80;

	//应用批次渲染
	auto enemyPlane = Sprite::createWithTexture(enemyBatchNode_5->getTexture());
	enemyBatchNode_5->addChild(enemyPlane);
	enemyPlane->setTag(3000);

	//设置敌机位置
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;
	enemyPlane->setPosition(Vec2(winSize.width / 2, winSize.height + planeHeight / 2));
	//this->addChild(enemyPlane);
	this->allEnemy.pushBack(enemyPlane);

	//下来停靠的位置
	float stopPositionX = winSize.width / 2;
	float stopPositionY = winSize.height * 3 / 4;

	//飞行距离
	float flyLen = winSize.height * 1 / 5 + planeHeight / 2;
	float realFlyDuration = flyLen / enemyFlySpeed;

	//设置动作
	auto actionMove = MoveTo::create(realFlyDuration, Point(stopPositionX, stopPositionY));


	//boss左右动
	float stopPositionX_2 = planeWidth / 2;
	float stopPositionY_2 = winSize.height * 3 / 4;
	float flyLen_2 = winSize.width / 2;
	float realFlyDuration_2 = flyLen_2 / enemyFlySpeed;

	//设置动作
	auto actionMove_2 = MoveTo::create(realFlyDuration_2, Point(stopPositionX_2, stopPositionY_2));

	float stopPositionX_3 = winSize.width - planeWidth / 2;
	float stopPositionY_3 = winSize.height * 3 / 4;
	float flyLen_3 = winSize.width - planeWidth;
	float realFlyDuration_3 = flyLen_3 / enemyFlySpeed;
	//设置动作
	auto actionMove_3 = MoveTo::create(realFlyDuration_3, Point(stopPositionX_3, stopPositionY_3));
	//auto actionDone_2 = CallFuncN::create(CC_CALLBACK_1(EnemyStyle::moveEnemyPlane, this));

	float stopPositionX_4 = winSize.width / 2;
	float stopPositionY_4 = winSize.height * 3 / 4;
	float flyLen_4 = winSize.width / 2 - planeWidth / 2;
	float realFlyDuration_4 = flyLen_4 / enemyFlySpeed;
	auto actionMove_4 = MoveTo::create(realFlyDuration_4, Point(stopPositionX_4, stopPositionY_4));
	Sequence * sequence = Sequence::create(actionMove, actionMove_2, actionMove_3, actionMove_4, NULL);
	enemyPlane->runAction(sequence);
	/*
	if(enemyPlane->getTag()<=450){
	enemyPlane->removeFromParent();
	}
	*/
}


//boss2
void EnemyStyle::boss2() {
	
	
	//设置飞机速度
	enemyFlySpeed = 80;

	//应用批次渲染
	auto enemyPlane = Sprite::createWithTexture(enemyBatchNode_5->getTexture());
	enemyBatchNode_5->addChild(enemyPlane);
	enemyPlane->setTag(3000);

	//获取图片大小
	float planeHeight = enemyPlane->getContentSize().height;
	float planeWidth = enemyPlane->getContentSize().width;

	//设置boss2位置
	enemyPlane->setPosition(Vec2(0 - planeWidth / 2, winSize.height / 2));
	this->allEnemy.pushBack(enemyPlane);

	//第一次停靠的位置
	float stopPositionX_1 = winSize.width / 2;
	float stopPositionY_1 = winSize.height - planeHeight / 2;

	//飞行距离
	float flyLen_1 = sqrt((winSize.width / 2 + planeWidth / 2)*(winSize.width / 2 + planeWidth / 2) + (winSize.height / 2 - planeHeight / 2)*(winSize.height / 2 - planeHeight / 2));
	float realFlyDuration_1 = flyLen_1 / enemyFlySpeed;
	auto actionMove_1 = MoveTo::create(realFlyDuration_1, Point(stopPositionX_1, stopPositionY_1));

	//第二次停靠的位置
	float stopPositionX_2 = winSize.width - planeWidth / 2;
	float stopPositionY_2 = winSize.height * 3/4;

	//飞行距离
	float flyLen_2 = sqrt((winSize.width / 2 - planeWidth / 2)*(winSize.width / 2 - planeWidth / 2) + (winSize.height / 2 - planeHeight / 2)*(winSize.height / 2 - planeHeight / 2));
	float realFlyDuration_2 = flyLen_2 / enemyFlySpeed;
	auto actionMove_2 = MoveTo::create(realFlyDuration_2, Point(stopPositionX_2, stopPositionY_2));

	//第三次停靠的位置
	float stopPositionX_3 = planeWidth / 2;
	float stopPositionY_3 = winSize.height * 3 / 4;

	//飞行距离
	float flyLen_3 = winSize.width - planeWidth;
	float realFlyDuration_3 = flyLen_3 / enemyFlySpeed;
	auto actionMove_3 = MoveTo::create(realFlyDuration_3, Point(stopPositionX_3, stopPositionY_3));

	//第四次停靠的位置
	float stopPositionX_4 = winSize.width / 2;
	float stopPositionY_4 = winSize.height * 3 / 4;

	//飞行距离
	float flyLen_4 = winSize.width / 2 - planeWidth / 2;
	float realFlyDuration_4 = flyLen_4 / enemyFlySpeed;
	auto actionMove_4 = MoveTo::create(realFlyDuration_4, Point(stopPositionX_4, stopPositionY_4));
	Sequence * sequence = Sequence::create(actionMove_1, actionMove_2, actionMove_3, actionMove_4, NULL);
	enemyPlane->runAction(sequence);
}


void EnemyStyle::del(Node * pSender) {
	pSender->removeFromParentAndCleanup(true);
}


void EnemyStyle::moveEnemyPlane_2(Node *pNode) {
	if (pNode == NULL) {
		return;
	}
	Sprite * enemyPlane = (Sprite *)pNode;
	enemyBatchNode_2->removeChild(enemyPlane, true);
	allEnemy.eraseObject(enemyPlane);

}

void EnemyStyle::moveEnemyPlane_7(Node *pNode) {
	if (pNode == NULL) {
		return;
	}
	Sprite * enemyPlane = (Sprite *)pNode;
	enemyBatchNode_7->removeChild(enemyPlane, true);
	allEnemy.eraseObject(enemyPlane);

}
void EnemyStyle::moveEnemyPlane_6(Node *pNode) {
	if (pNode == NULL) {
		return;
	}
	Sprite * enemyPlane = (Sprite *)pNode;
	enemyBatchNode_6->removeChild(enemyPlane, true);
	allEnemy.eraseObject(enemyPlane);

}