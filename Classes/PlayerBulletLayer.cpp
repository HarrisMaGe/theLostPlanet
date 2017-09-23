#include "PlayerBulletLayer.h"  

PlayerBulletLayer* PlayerBulletLayer::create(Node* plane) {
	PlayerBulletLayer* pRet = new PlayerBulletLayer(plane);
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

bool PlayerBulletLayer::init() {
   //初始化加载图片
	bulletBatchNode_1 = SpriteBatchNode::create("bullet/Bullet1.1.png");
	this->addChild(bulletBatchNode_1);
	bulletBatchNode_2 = SpriteBatchNode::create("bullet/Bullet1.2.png");
	this->addChild(bulletBatchNode_2);
	bulletBatchNode_3 = SpriteBatchNode::create("bullet/Bullet1.png");
	this->addChild(bulletBatchNode_3);
	bulletBatchNode_4 = SpriteBatchNode::create("bullet/Bullet2.1.png");
	this->addChild(bulletBatchNode_4);
	bulletBatchNode_5 = SpriteBatchNode::create("bullet/bullet_level3.png");
	this->addChild(bulletBatchNode_5);
	bulletBatchNode_6 = SpriteBatchNode::create("bullet/laser1.png");
	this->addChild(bulletBatchNode_6);
	bulletBatchNode_7 = SpriteBatchNode::create("bullet/laser2.png");
	this->addChild(bulletBatchNode_7);
	




	return true;

}






PlayerBulletLayer::PlayerBulletLayer(Node* plane) {
	this->plane = plane;


}

PlayerBulletLayer::~PlayerBulletLayer() {
	removeAllObject();  
}


void PlayerBulletLayer::removeAllObject() {
	bulletBatchNode_1->removeAllChildren();
	bulletBatchNode_2->removeAllChildren();
	bulletBatchNode_3->removeAllChildren();
	bulletBatchNode_4->removeAllChildren();
	bulletBatchNode_5->removeAllChildren();
	bulletBatchNode_6->removeAllChildren();
	bulletBatchNode_7->removeAllChildren();

	
	
	
	
	vecBullet.clear();
	this->removeAllChildren();

}


//删除子弹

void PlayerBulletLayer::removeBullet_1(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_1->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
void PlayerBulletLayer::removeBullet_2(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_2->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
void PlayerBulletLayer::removeBullet_3(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_3->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
void PlayerBulletLayer::removeBullet_4(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_4->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
void PlayerBulletLayer::removeBullet_5(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_5->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

void PlayerBulletLayer::removeBullet_6(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_6->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

void PlayerBulletLayer::removeBullet_7(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;


	bulletBatchNode_7->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}







void PlayerBulletLayer::createBulletForPlayer( int flyStyle, float fre, float flyVelocity) {
	this->fre = fre;
	this->flyVelocity = flyVelocity;
	this->flyStyle = flyStyle;
	switch (flyStyle)
	{
	case 1:

		//每隔fre S调用一次发射子弹函数  
		schedule(schedule_selector(PlayerBulletLayer::shootBullet1_ForPlayer), 0.1);
		schedule(schedule_selector(PlayerBulletLayer::shootBullet2_ForPlayer), 0.3);
		break;
	case 2:
		schedule(schedule_selector(PlayerBulletLayer::shootBullet1_ForPlayer), 0.1);
		schedule(schedule_selector(PlayerBulletLayer::shootBullet3_ForPlayer), 0.3);
		break;
	case 3:
		schedule(schedule_selector(PlayerBulletLayer::shootBullet4_ForPlayer), 0.1);
		schedule(schedule_selector(PlayerBulletLayer::shootBullet5_ForPlayer), 0.3);
		break;
	case 4:
		schedule(schedule_selector(PlayerBulletLayer::shootBullet6_ForPlayer), 0.01);
		schedule(schedule_selector(PlayerBulletLayer::shootBullet7_ForPlayer), 0.03);
		break;
	default:
		break;
	}
	

}
void PlayerBulletLayer::stopBulletForPlayer() {
	
	switch (flyStyle)
	{
	case 1:

		
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet1_ForPlayer));
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet2_ForPlayer));

		break;
	case 2:
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet1_ForPlayer));
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet3_ForPlayer));
		break;
	case 3:
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet4_ForPlayer));
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet5_ForPlayer));
		break;
	case 4:
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet6_ForPlayer));
		unschedule(schedule_selector(PlayerBulletLayer::shootBullet7_ForPlayer));
		break;
	default:
		break;
	}

}




void PlayerBulletLayer::shootBullet1_ForPlayer(float dt) {

	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  
	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	


	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());

	
	
	
	spritebullet1->setTag(131);
	
	spritebullet2->setTag(131);
	
	
	bulletBatchNode_1->addChild(spritebullet1);
	
	bulletBatchNode_1->addChild(spritebullet2);
	

	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet1);
	
	vecBullet.pushBack(spritebullet2);



	spritebullet1->setPosition(Point(PlanePos.x-45,
		PlanePos.y + 10));
	
	spritebullet2->setPosition(Point(PlanePos.x+45,
		PlanePos.y + 10));
	

	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y-10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove1 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x - 45,
			winSize.height));
	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x + 45,
			winSize.height));
	



	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto* actionDone1 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_1, this));



	//子弹开始跑动  
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone1, NULL);
	spritebullet1->runAction(sequence1);
	
	Sequence* sequence2 = Sequence::create(actionMove2, actionDone1, NULL);
	spritebullet2->runAction(sequence2);

}
void PlayerBulletLayer::shootBullet2_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_2->getTexture());
	spritebullet2->setTag(132);

	bulletBatchNode_2->addChild(spritebullet2);

	vecBullet.pushBack(spritebullet2);

	spritebullet2->setPosition(Point(PlanePos.x,
		PlanePos.y + 20));

	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  
	
	
	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x, winSize.height));

	auto* actionDone2 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_2, this));

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone2, NULL);
	spritebullet2->runAction(sequence2);


}


void PlayerBulletLayer::shootBullet3_ForPlayer(float dt) {

	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  
	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_4->getTexture());



	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_4->getTexture());




	spritebullet1->setTag(133);

	spritebullet2->setTag(133);


	bulletBatchNode_4->addChild(spritebullet1);

	bulletBatchNode_4->addChild(spritebullet2);


	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet1);

	vecBullet.pushBack(spritebullet2);



	spritebullet1->setPosition(Point(PlanePos.x - 20,
		PlanePos.y + 10));

	spritebullet2->setPosition(Point(PlanePos.x + 20,
		PlanePos.y + 10));


	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove1 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x - 20,
			winSize.height));
	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x + 20,
			winSize.height));




	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto* actionDone1 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_4, this));



	//子弹开始跑动  
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone1, NULL);
	spritebullet1->runAction(sequence1);

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone1, NULL);
	spritebullet2->runAction(sequence2);

}








void PlayerBulletLayer::shootBullet4_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  
	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_3->getTexture());



	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_3->getTexture());




	spritebullet1->setTag(134);

	spritebullet2->setTag(134);


	bulletBatchNode_3->addChild(spritebullet1);

	bulletBatchNode_3->addChild(spritebullet2);


	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet1);

	vecBullet.pushBack(spritebullet2);



	spritebullet1->setPosition(Point(PlanePos.x - 45,
		PlanePos.y + 10));

	spritebullet2->setPosition(Point(PlanePos.x + 45,
		PlanePos.y + 10));


	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove1 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x - 45,
			winSize.height));
	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x + 45,
			winSize.height));




	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto* actionDone1 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_3, this));



	//子弹开始跑动  
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone1, NULL);
	spritebullet1->runAction(sequence1);

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone1, NULL);
	spritebullet2->runAction(sequence2);

}



void PlayerBulletLayer::shootBullet5_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_5->getTexture());
	spritebullet2->setTag(135);

	bulletBatchNode_5->addChild(spritebullet2);

	vecBullet.pushBack(spritebullet2);

	spritebullet2->setPosition(Point(PlanePos.x,
		PlanePos.y + 20));

	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  


	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x, winSize.height));

	auto* actionDone2 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_5, this));

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone2, NULL);
	spritebullet2->runAction(sequence2);


}


void PlayerBulletLayer::shootBullet6_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  
	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_7->getTexture());



	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_7->getTexture());




	spritebullet1->setTag(136);

	spritebullet2->setTag(136);


	bulletBatchNode_7->addChild(spritebullet1);

	bulletBatchNode_7->addChild(spritebullet2);


	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet1);

	vecBullet.pushBack(spritebullet2);



	spritebullet1->setPosition(Point(PlanePos.x - 45,
		PlanePos.y + 10));

	spritebullet2->setPosition(Point(PlanePos.x + 45,
		PlanePos.y + 10));


	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove1 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x - 45,
			winSize.height));
	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x + 45,
			winSize.height));




	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto* actionDone1 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_7, this));



	//子弹开始跑动  
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone1, NULL);
	spritebullet1->runAction(sequence1);

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone1, NULL);
	spritebullet2->runAction(sequence2);

}



void PlayerBulletLayer::shootBullet7_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_6->getTexture());
	spritebullet2->setTag(137);

	bulletBatchNode_6->addChild(spritebullet2);

	vecBullet.pushBack(spritebullet2);

	spritebullet2->setPosition(Point(PlanePos.x,
		PlanePos.y + 20));

	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y - 10;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  


	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(PlanePos.x, winSize.height));

	auto* actionDone2 = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_6, this));

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone2, NULL);
	spritebullet2->runAction(sequence2);


}

















































//方法一
void PlayerBulletLayer::shootBullet11_ForPlayer(float dt)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	bulletBatchNode_1->addChild(spritebullet);
		



	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet);
	spritebullet->setPosition(Point(PlanePos.x,
		PlanePos.y + 10));
	spritebullet->setScale(0.8f);

	//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = winSize.height - PlanePos.y;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(PlanePos.x, winSize.height));


    //子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto* actionDone = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_1, this));



	//子弹开始跑动  
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}

void PlayerBulletLayer::shootBullet12_ForPlayer(float dt) {

	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	//从缓存中创建子弹  

	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());


	//将创建好的子弹添加到BatchNode中进行批次渲染  
	bulletBatchNode_1->addChild(spritebullet1);
	bulletBatchNode_1->addChild(spritebullet2);
	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet1);
	vecBullet.pushBack(spritebullet2);

	Point bulletPos1 = (Point(PlanePos.x - plane->getContentSize().width / 4,
		PlanePos.y + 10));

	Point bulletPos2 = (Point(PlanePos.x + plane->getContentSize().width / 4,
		PlanePos.y + 10));

	spritebullet1->setPosition(bulletPos1);
	spritebullet1->setScale(0.8f);

	spritebullet2->setPosition(bulletPos2);
	spritebullet2->setScale(0.8f);


	float flyLen = winSize.height - PlanePos.y;
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  


												 //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove1 = MoveTo::create(realFlyDuration,
		Point(bulletPos1.x, winSize.height));

	auto actionMove2 = MoveTo::create(realFlyDuration,
		Point(bulletPos2.x, winSize.height));

	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_1, this));

	//子弹开始跑动  
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	spritebullet1->runAction(sequence1);

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
	spritebullet2->runAction(sequence2);

}






void PlayerBulletLayer::shootBullet10_ForPlayer(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = plane->getPosition();
	double angle = M_PI * 80 /180;//旋轉的角度 
	//从缓存中创建子弹  
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	spritebullet1->setRotation(-angle);
	auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode_1->getTexture());
	spritebullet2->setRotation(angle);
	//将创建好的子弹添加到BatchNode中进行批次渲染  
	bulletBatchNode_1->addChild(spritebullet);
	bulletBatchNode_1->addChild(spritebullet1);
	bulletBatchNode_1->addChild(spritebullet2);
	//将创建好的子弹添加到容器  
	vecBullet.pushBack(spritebullet);
	vecBullet.pushBack(spritebullet1);
	vecBullet.pushBack(spritebullet2);

	Point bulletPos = (Point(PlanePos.x,
		PlanePos.y + 20));


	Point bulletPos1 = (Point(PlanePos.x - 20,
		PlanePos.y + 10));

	Point bulletPos2 = (Point(PlanePos.x + 20,
		PlanePos.y + 10));

	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.8f);

	spritebullet1->setPosition(bulletPos1);
	spritebullet1->setScale(0.8f);

	spritebullet2->setPosition(bulletPos2);
	spritebullet2->setScale(0.8f);


	//运行速度，可以自己控制，每秒所走的像素  

	float flyLen = winSize.height - PlanePos.y;
	float flyLen1 = PlanePos.x / cos(angle);//按照度來算  
	float flyLen2 = (winSize.width - PlanePos.x) / cos(angle);

	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  
	float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
	float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  

												   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos.x, winSize.height));

	auto actionMove1 = MoveTo::create(realFlyDuration1,
		Point(0, PlanePos.x*tan(angle) + PlanePos.y));

	auto actionMove2 = MoveTo::create(realFlyDuration2,
		Point(winSize.width, (winSize.width - PlanePos.x)*tan(angle) + PlanePos.y));

	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(PlayerBulletLayer::removeBullet_1, this));

	//子弹开始跑动  
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);

	Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	spritebullet1->runAction(sequence1);

	Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
	spritebullet2->runAction(sequence2);
}





