#include "EnemyBulletLayer.h"
#include <math.h>

EnemyBulletLayer::EnemyBulletLayer(Node * player) {
	this->player = player;
}

EnemyBulletLayer* EnemyBulletLayer::create(Node * player) {
	EnemyBulletLayer* pRet = new EnemyBulletLayer(player);
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

bool EnemyBulletLayer::init() {

	bulletBatchNode1 = SpriteBatchNode::create("bullet/enemybullet_1.png");
	this->addChild(bulletBatchNode1);
	
	bulletBatchNode2 = SpriteBatchNode::create("bullet/enemybullet_3.png");
	this->addChild(bulletBatchNode2);
	
	bulletBatchNode3 = SpriteBatchNode::create("bullet/enemybullet_2.png");
	this->addChild(bulletBatchNode3);
	
	bulletBatchNode4 = SpriteBatchNode::create("bullet/enemybullet_2_1.png");
	this->addChild(bulletBatchNode4);

	bulletBatchNode5 = SpriteBatchNode::create("bullet/enemy2_2_bullet.png");
	this->addChild(bulletBatchNode5);

	bulletBatchNode6 = SpriteBatchNode::create("bullet/enemy_2_3_bullet.png");
	this->addChild(bulletBatchNode6);

	bulletBatchNode7 = SpriteBatchNode::create("bullet/enemy3_1_bullet.png");
	this->addChild(bulletBatchNode7);

	bulletBatchNode8 = SpriteBatchNode::create("bullet/enemy3_2_bullet(45x45).png");
	this->addChild(bulletBatchNode8);

	bulletBatchNode9 = SpriteBatchNode::create("bullet/enemy3_3_bullet(45x45).png");
	this->addChild(bulletBatchNode9);

	bulletBatchNode10 = SpriteBatchNode::create("bullet/enemy3_4_bullet(50x60).png");
	this->addChild(bulletBatchNode10);

	bulletBatchNode11 = SpriteBatchNode::create("bullet/enemybullet_1.png");
	this->addChild(bulletBatchNode11);

	bulletBatchNode12 = SpriteBatchNode::create("bullet/enemybullet_1.png");
	this->addChild(bulletBatchNode12);






	return true;

}


void EnemyBulletLayer::removeEnemyBullet1(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode1->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet2(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode2->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet3(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode3->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet4(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode4->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet5(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode5->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}

void EnemyBulletLayer::removeEnemyBullet6(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode6->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}

void EnemyBulletLayer::removeEnemyBullet7(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode7->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}

void EnemyBulletLayer::removeEnemyBullet8(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode8->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}

void EnemyBulletLayer::removeEnemyBullet9(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode9->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet10(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode10->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet11(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode11->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}
void EnemyBulletLayer::removeEnemyBullet12(Node* myEnemyBullet) {
	if (NULL == myEnemyBullet) {
		return;
	}
	Sprite *EnemyBullet = (Sprite *)myEnemyBullet;
	bulletBatchNode12->removeChild(myEnemyBullet, true);
	allEnemyBullet.eraseObject(EnemyBullet);
}








































void EnemyBulletLayer::newEnemyBullet(Node * oB, int type, float flyVelocity) {

	if (type == 1)
	{//双发子弹直线发射
		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode1->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode1->getTexture());

		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);

		//单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(type);
		myEnemyBullet2->setTag(type);
		
		myEnemyBullet1->setPosition(oB->getPosition().x+20, oB->getPosition().y);
		myEnemyBullet2->setPosition(oB->getPosition().x-20, oB->getPosition().y);


		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode1->addChild(myEnemyBullet1);
		bulletBatchNode1->addChild(myEnemyBullet2);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);





		float flyLen = oB->getPosition().y;//飞行距离
		float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  


													 //子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
		auto move1 = MoveTo::create(realFlyDuration, Point(myEnemyBullet1->getPosition().x, 0));

		//子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
		auto move2 = MoveTo::create(realFlyDuration, Point(myEnemyBullet2->getPosition().x, 0));






		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet1, this));

		Sequence* sequence1 = Sequence::create(move1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(move2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);



	}
	else if (type == 2)
	{//三发子弹三角度发射
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();
	
		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode2->getTexture());
	
		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode2->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode2->getTexture());


		
		double angle2 =30;//旋轉的角度 

		//单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(type);
	
		myEnemyBullet4->setTag(type);
		myEnemyBullet5->setTag(type);



		myEnemyBullet1->setScale(0.5);

		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);

		
		myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);
		
		
		
		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);
		
		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode2->addChild(myEnemyBullet1);
		
		bulletBatchNode2->addChild(myEnemyBullet4);
		bulletBatchNode2->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		
		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);

		


		float flyLen1 = PlanePosition.y;
		
		float flyLen4 = PlanePosition.x*2;
		float flyLen5 = (winSize.width - PlanePosition.x) *2;

		float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
	
		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  

		
													 
													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(PlanePosition.x,0));

		double y1 = PlanePosition.y - (PlanePosition.x*1.71);
		double y2 = PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71 );
		
		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(0, y1 ));
		
		auto actionMove5= MoveTo::create(realFlyDuration5,
			Vec2(winSize.width,y2 ));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet2, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

	

     	Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
		myEnemyBullet4->runAction(sequence4);

		Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
		myEnemyBullet5->runAction(sequence5);

	}
	
	else if (type == 3)
	{
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode3->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode3->getTexture());
		auto myEnemyBullet3 = Sprite::createWithTexture(bulletBatchNode3->getTexture());

		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode3->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode3->getTexture());



		double angle1 = 60;//旋轉的角度 
		double angle2 = 30;
						   //单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(type);
		myEnemyBullet2->setTag(type);
		myEnemyBullet3->setTag(type);
		myEnemyBullet4->setTag(type);
		myEnemyBullet5->setTag(type);



		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);
		myEnemyBullet3->setScale(0.5);
		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);


		myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet2->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet2->setRotation(angle1);

		myEnemyBullet3->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet3->setRotation(-angle1);


		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);

		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode3->addChild(myEnemyBullet1);
		bulletBatchNode3->addChild(myEnemyBullet2);
		bulletBatchNode3->addChild(myEnemyBullet3);
		bulletBatchNode3->addChild(myEnemyBullet4);
		bulletBatchNode3->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);
		allEnemyBullet.pushBack(myEnemyBullet3);
		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);




		float flyLen1 = PlanePosition.y;
		float flyLen2 = PlanePosition.x * 2 / 1.71;
		float flyLen3 = (winSize.width - PlanePosition.x) * 2 / 1.71;
		float flyLen4 = PlanePosition.x * 2 ;
		float flyLen5 = (winSize.width - PlanePosition.x) * 2 ;

		float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
		float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  
		float realFlyDuration3 = flyLen3 / flyVelocity;//实际飞行的时间  
		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(PlanePosition.x, 0));

		auto actionMove2 = MoveTo::create(realFlyDuration2,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71 / 3)));

		auto actionMove3 = MoveTo::create(realFlyDuration3,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71 / 3)));

		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71)));

		auto actionMove5 = MoveTo::create(realFlyDuration5,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71)));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet3, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);

		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
		myEnemyBullet3->runAction(sequence3);

	Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
	myEnemyBullet4->runAction(sequence4);
	
	Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
	myEnemyBullet5->runAction(sequence5);
	}
	else if (type == 4)
	{//第二关
		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode4->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode4->getTexture());

		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);

		//单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(type);
		myEnemyBullet2->setTag(type);

		myEnemyBullet1->setPosition(oB->getPosition().x + 20, oB->getPosition().y);
		myEnemyBullet2->setPosition(oB->getPosition().x - 20, oB->getPosition().y);


		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode4->addChild(myEnemyBullet1);
		bulletBatchNode4->addChild(myEnemyBullet2);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);





		float flyLen = oB->getPosition().y;//飞行距离
		float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  


													 //子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
		auto move1 = MoveTo::create(realFlyDuration, Point(myEnemyBullet1->getPosition().x, 0));

		//子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
		auto move2 = MoveTo::create(realFlyDuration, Point(myEnemyBullet2->getPosition().x, 0));






		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet4, this));

		Sequence* sequence1 = Sequence::create(move1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(move2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);

	}
	else if(type == 5)
	{
		auto myEnemyBullet = Sprite::createWithTexture(bulletBatchNode5->getTexture());

		myEnemyBullet->setScale(0.5);

		//单个TAG，用于碰撞判断
		myEnemyBullet->setTag(type);
		myEnemyBullet->setPosition(oB->getPosition().x, oB->getPosition().y);


		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode5->addChild(myEnemyBullet);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet);





		float flyLen = oB->getPosition().y;//飞行距离
		float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

													 //子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
		auto move = MoveTo::create(realFlyDuration, Point(myEnemyBullet->getPosition().x, 0));






		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet5, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myEnemyBullet->runAction(sequence);
	}
	else if (type == 6)
	{
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode4->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode4->getTexture());
		auto myEnemyBullet3 = Sprite::createWithTexture(bulletBatchNode4->getTexture());

		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode4->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode4->getTexture());



		double angle1 = 60;//旋轉的角度 
		double angle2 = 30;
		//单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(4);
		myEnemyBullet2->setTag(4);
		myEnemyBullet3->setTag(4);
		myEnemyBullet4->setTag(4);
		myEnemyBullet5->setTag(4);



		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);
		myEnemyBullet3->setScale(0.5);
		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);


		myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet2->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet2->setRotation(angle1);

		myEnemyBullet3->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet3->setRotation(-angle1);


		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);

		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode4->addChild(myEnemyBullet1);
		bulletBatchNode4->addChild(myEnemyBullet2);
		bulletBatchNode4->addChild(myEnemyBullet3);
		bulletBatchNode4->addChild(myEnemyBullet4);
		bulletBatchNode4->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);
		allEnemyBullet.pushBack(myEnemyBullet3);
		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);




		float flyLen1 = PlanePosition.y;
		float flyLen2 = PlanePosition.x * 2 / 1.71;
		float flyLen3 = (winSize.width - PlanePosition.x) * 2 / 1.71;
		float flyLen4 = PlanePosition.x * 2;
		float flyLen5 = (winSize.width - PlanePosition.x) * 2;

		float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
		float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  
		float realFlyDuration3 = flyLen3 / flyVelocity;//实际飞行的时间  
		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(PlanePosition.x, 0));

		auto actionMove2 = MoveTo::create(realFlyDuration2,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71 / 3)));

		auto actionMove3 = MoveTo::create(realFlyDuration3,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71 / 3)));

		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71)));

		auto actionMove5 = MoveTo::create(realFlyDuration5,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71)));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet4, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);

		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
		myEnemyBullet3->runAction(sequence3);

		Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
		myEnemyBullet4->runAction(sequence4);

		Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
		myEnemyBullet5->runAction(sequence5);
	}
	else if (type == 7)
	{
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode6->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode6->getTexture());
		auto myEnemyBullet3 = Sprite::createWithTexture(bulletBatchNode6->getTexture());

		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode6->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode6->getTexture());



		double angle1 = 60;//旋轉的角度 
		double angle2 = 30;
		//单个TAG，用于碰撞判断
		myEnemyBullet1->setTag(6);
		myEnemyBullet2->setTag(6);
		myEnemyBullet3->setTag(6);
		myEnemyBullet4->setTag(6);
		myEnemyBullet5->setTag(6);



		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);
		myEnemyBullet3->setScale(0.5);
		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);


		myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet2->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet2->setRotation(angle1);

		myEnemyBullet3->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet3->setRotation(-angle1);


		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);

		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode6->addChild(myEnemyBullet1);
		bulletBatchNode6->addChild(myEnemyBullet2);
		bulletBatchNode6->addChild(myEnemyBullet3);
		bulletBatchNode6->addChild(myEnemyBullet4);
		bulletBatchNode6->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);
		allEnemyBullet.pushBack(myEnemyBullet3);
		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);




		float flyLen1 = PlanePosition.y;
		float flyLen2 = PlanePosition.x * 2 / 1.71;
		float flyLen3 = (winSize.width - PlanePosition.x) * 2 / 1.71;
		float flyLen4 = PlanePosition.x * 2;
		float flyLen5 = (winSize.width - PlanePosition.x) * 2;

		float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
		float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  
		float realFlyDuration3 = flyLen3 / flyVelocity;//实际飞行的时间  
		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(PlanePosition.x, 0));

		auto actionMove2 = MoveTo::create(realFlyDuration2,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71 / 3)));

		auto actionMove3 = MoveTo::create(realFlyDuration3,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71 / 3)));

		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(0, PlanePosition.y - (PlanePosition.x*1.71)));

		auto actionMove5 = MoveTo::create(realFlyDuration5,
			Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71)));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet6, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);

		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
		myEnemyBullet3->runAction(sequence3);

		Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
		myEnemyBullet4->runAction(sequence4);

		Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
		myEnemyBullet5->runAction(sequence5);
	}
   else if (type==8)
    {//第三关
	   Size winSize = Director::getInstance()->getWinSize();
	   auto PlanePosition = oB->getPosition();

	   auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode7->getTexture());

	   auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode7->getTexture());
	   auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode7->getTexture());



	   double angle2 = 30;//旋轉的角度 

						  //单个TAG，用于碰撞判断
	   myEnemyBullet1->setTag(7);

	   myEnemyBullet4->setTag(7);
	   myEnemyBullet5->setTag(7);



	   myEnemyBullet1->setScale(0.5);

	   myEnemyBullet4->setScale(0.5);
	   myEnemyBullet5->setScale(0.5);


	   myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);



	   myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet4->setRotation(angle2);

	   myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet5->setRotation(-angle2);

	   //将创建好的子弹添加到BatchNode中进行批次渲染 
	   bulletBatchNode7->addChild(myEnemyBullet1);

	   bulletBatchNode7->addChild(myEnemyBullet4);
	   bulletBatchNode7->addChild(myEnemyBullet5);
	   //添加进入容器以便于迭代
	   allEnemyBullet.pushBack(myEnemyBullet1);

	   allEnemyBullet.pushBack(myEnemyBullet4);
	   allEnemyBullet.pushBack(myEnemyBullet5);




	   float flyLen1 = PlanePosition.y;

	   float flyLen4 = PlanePosition.x * 2;
	   float flyLen5 = (winSize.width - PlanePosition.x) * 2;

	   float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  

	   float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
	   float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													  //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

	   auto actionMove1 = MoveTo::create(realFlyDuration1,
		   Point(PlanePosition.x, 0));

	   double y1 = PlanePosition.y - (PlanePosition.x*1.71);
	   double y2 = PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71);

	   auto actionMove4 = MoveTo::create(realFlyDuration4,
		   Vec2(0, y1));

	   auto actionMove5 = MoveTo::create(realFlyDuration5,
		   Vec2(winSize.width, y2));

	   //子弹执行完动作后进行函数回调，调用移除子弹函数  
	   auto actionDone = CallFuncN::create(
		   CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet7, this));

	   Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	   myEnemyBullet1->runAction(sequence1);



	   Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
	   myEnemyBullet4->runAction(sequence4);

	   Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
	   myEnemyBullet5->runAction(sequence5);
    }
   else if (type==9) {
   
   
	   Size winSize = Director::getInstance()->getWinSize();
	   auto PlanePosition = oB->getPosition();

	   auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode8->getTexture());
	   auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode8->getTexture());
	   auto myEnemyBullet3 = Sprite::createWithTexture(bulletBatchNode8->getTexture());

	   auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode8->getTexture());
	   auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode8->getTexture());



	   double angle1 = 60;//旋轉的角度 
	   double angle2 = 30;
	   //单个TAG，用于碰撞判断
	   myEnemyBullet1->setTag(8);
	   myEnemyBullet2->setTag(8);
	   myEnemyBullet3->setTag(8);
	   myEnemyBullet4->setTag(8);
	   myEnemyBullet5->setTag(8);



	   myEnemyBullet1->setScale(0.5);
	   myEnemyBullet2->setScale(0.5);
	   myEnemyBullet3->setScale(0.5);
	   myEnemyBullet4->setScale(0.5);
	   myEnemyBullet5->setScale(0.5);


	   myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);

	   myEnemyBullet2->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet2->setRotation(angle1);

	   myEnemyBullet3->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet3->setRotation(-angle1);


	   myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet4->setRotation(angle2);

	   myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
	   myEnemyBullet5->setRotation(-angle2);

	   //将创建好的子弹添加到BatchNode中进行批次渲染 
	   bulletBatchNode8->addChild(myEnemyBullet1);
	   bulletBatchNode8->addChild(myEnemyBullet2);
	   bulletBatchNode8->addChild(myEnemyBullet3);
	   bulletBatchNode8->addChild(myEnemyBullet4);
	   bulletBatchNode8->addChild(myEnemyBullet5);
	   //添加进入容器以便于迭代
	   allEnemyBullet.pushBack(myEnemyBullet1);
	   allEnemyBullet.pushBack(myEnemyBullet2);
	   allEnemyBullet.pushBack(myEnemyBullet3);
	   allEnemyBullet.pushBack(myEnemyBullet4);
	   allEnemyBullet.pushBack(myEnemyBullet5);




	   float flyLen1 = PlanePosition.y;
	   float flyLen2 = PlanePosition.x * 2 / 1.71;
	   float flyLen3 = (winSize.width - PlanePosition.x) * 2 / 1.71;
	   float flyLen4 = PlanePosition.x * 2;
	   float flyLen5 = (winSize.width - PlanePosition.x) * 2;

	   float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
	   float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  
	   float realFlyDuration3 = flyLen3 / flyVelocity;//实际飞行的时间  
	   float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
	   float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													  //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

	   auto actionMove1 = MoveTo::create(realFlyDuration1,
		   Point(PlanePosition.x, 0));

	   auto actionMove2 = MoveTo::create(realFlyDuration2,
		   Vec2(0, PlanePosition.y - (PlanePosition.x*1.71 / 3)));

	   auto actionMove3 = MoveTo::create(realFlyDuration3,
		   Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71 / 3)));

	   auto actionMove4 = MoveTo::create(realFlyDuration4,
		   Vec2(0, PlanePosition.y - (PlanePosition.x*1.71)));

	   auto actionMove5 = MoveTo::create(realFlyDuration5,
		   Vec2(winSize.width, PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71)));

	   //子弹执行完动作后进行函数回调，调用移除子弹函数  
	   auto actionDone = CallFuncN::create(
		   CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet8, this));

	   Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	   myEnemyBullet1->runAction(sequence1);

	   Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
	   myEnemyBullet2->runAction(sequence2);

	   Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
	   myEnemyBullet3->runAction(sequence3);

	   Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
	   myEnemyBullet4->runAction(sequence4);

	   Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
	   myEnemyBullet5->runAction(sequence5);
   
   
   
   
   }
  
   
   
   else if (type==10)
   {
	   auto myEnemyBullet = Sprite::createWithTexture(bulletBatchNode9->getTexture());

	   myEnemyBullet->setScale(0.5);

	   //单个TAG，用于碰撞判断
	   myEnemyBullet->setTag(9);
	   myEnemyBullet->setPosition(oB->getPosition().x, oB->getPosition().y);


	   //将创建好的子弹添加到BatchNode中进行批次渲染 
	   bulletBatchNode9->addChild(myEnemyBullet);
	   //添加进入容器以便于迭代
	   allEnemyBullet.pushBack(myEnemyBullet);





	   float flyLen = oB->getPosition().y;//飞行距离
	   float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

													//子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
	   auto move = MoveTo::create(realFlyDuration, Point(myEnemyBullet->getPosition().x, 0));






	   auto actionDone = CallFuncN::create(
		   CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet9, this));

	   Sequence* sequence = Sequence::create(move, actionDone, NULL);
	   myEnemyBullet->runAction(sequence);
   }
   else if (type==11)
   {
	   auto myEnemyBullet = Sprite::createWithTexture(bulletBatchNode10->getTexture());

	   myEnemyBullet->setScale(0.5);

	   //单个TAG，用于碰撞判断
	   myEnemyBullet->setTag(10);
	   myEnemyBullet->setPosition(oB->getPosition().x, oB->getPosition().y);


	   //将创建好的子弹添加到BatchNode中进行批次渲染 
	   bulletBatchNode10->addChild(myEnemyBullet);
	   //添加进入容器以便于迭代
	   allEnemyBullet.pushBack(myEnemyBullet);





	   float flyLen = oB->getPosition().y;//飞行距离
	   float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

													//子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
	   auto move = MoveTo::create(realFlyDuration, Point(myEnemyBullet->getPosition().x, 0));






	   auto actionDone = CallFuncN::create(
		   CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet10, this));

	   Sequence* sequence = Sequence::create(move, actionDone, NULL);
	   myEnemyBullet->runAction(sequence);
	   
   }
	else if (type==12)
	{
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		

		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode11->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode11->getTexture());



		double angle2 = 30;//旋轉的角度 

						   //单个TAG，用于碰撞判断


		myEnemyBullet4->setTag(11);
		myEnemyBullet5->setTag(11);



	

		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);





		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);

		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 


		bulletBatchNode11->addChild(myEnemyBullet4);
		bulletBatchNode11->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		

		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);




		

		float flyLen4 = PlanePosition.x * 2;
		float flyLen5 = (winSize.width - PlanePosition.x) * 2;

		

		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  



													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		

		double y1 = PlanePosition.y - (PlanePosition.x*1.71);
		double y2 = PlanePosition.y - ((winSize.width - PlanePosition.x)*1.71);

		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(0, y1));

		auto actionMove5 = MoveTo::create(realFlyDuration5,
			Vec2(winSize.width, y2));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet11, this));




		Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
		myEnemyBullet4->runAction(sequence4);

		Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
		myEnemyBullet5->runAction(sequence5);
	}
	else if (type == 13)
	{

		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		auto myEnemyBullet1 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet2 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet3 = Sprite::createWithTexture(bulletBatchNode12->getTexture());

		auto myEnemyBullet4 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet5 = Sprite::createWithTexture(bulletBatchNode12->getTexture());




		double angle1 = 60;//旋轉的角度 
		double angle2 = 30;
		double angle3 = 120;
		double angle4 = 150;


		myEnemyBullet1->setTag(12);
		myEnemyBullet2->setTag(12);
		myEnemyBullet3->setTag(12);
		myEnemyBullet4->setTag(12);
		myEnemyBullet5->setTag(12);



		myEnemyBullet1->setScale(0.5);
		myEnemyBullet2->setScale(0.5);
		myEnemyBullet3->setScale(0.5);
		myEnemyBullet4->setScale(0.5);
		myEnemyBullet5->setScale(0.5);


		myEnemyBullet1->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet2->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet2->setRotation(angle1);

		myEnemyBullet3->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet3->setRotation(-angle1);


		myEnemyBullet4->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet4->setRotation(angle2);

		myEnemyBullet5->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet5->setRotation(-angle2);

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode12->addChild(myEnemyBullet1);
		bulletBatchNode12->addChild(myEnemyBullet2);
		bulletBatchNode12->addChild(myEnemyBullet3);
		bulletBatchNode12->addChild(myEnemyBullet4);
		bulletBatchNode12->addChild(myEnemyBullet5);
		//添加进入容器以便于迭代
		allEnemyBullet.pushBack(myEnemyBullet1);
		allEnemyBullet.pushBack(myEnemyBullet2);
		allEnemyBullet.pushBack(myEnemyBullet3);
		allEnemyBullet.pushBack(myEnemyBullet4);
		allEnemyBullet.pushBack(myEnemyBullet5);



		float r = 110;
		float s60r = r*1.71 / 2;
		float s30r = r / 2;
		float c60r = r / 2;
		float c30r = r*1.71 / 2;

		float flyLen1 = r;
		float flyLen2 = r;
		float flyLen3 = r;
		float flyLen4 = r;
		float flyLen5 = r;

		float realFlyDuration1 = flyLen1 / flyVelocity;//实际飞行的时间  
		float realFlyDuration2 = flyLen2 / flyVelocity;//实际飞行的时间  
		float realFlyDuration3 = flyLen3 / flyVelocity;//实际飞行的时间  
		float realFlyDuration4 = flyLen4 / flyVelocity;//实际飞行的时间  
		float realFlyDuration5 = flyLen5 / flyVelocity;//实际飞行的时间  

													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(PlanePosition.x, PlanePosition.y - r));

		auto actionMove2 = MoveTo::create(realFlyDuration2,
			Vec2(PlanePosition.x - c60r, PlanePosition.y - s60r));

		auto actionMove3 = MoveTo::create(realFlyDuration3,
			Vec2(PlanePosition.x + c60r, PlanePosition.y - s60r));

		auto actionMove4 = MoveTo::create(realFlyDuration4,
			Vec2(PlanePosition.x - c30r, PlanePosition.y - s30r));

		auto actionMove5 = MoveTo::create(realFlyDuration5,
			Vec2(PlanePosition.x + c30r, PlanePosition.y - s30r));

		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet12, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		myEnemyBullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		myEnemyBullet2->runAction(sequence2);

		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
		myEnemyBullet3->runAction(sequence3);

		Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);
		myEnemyBullet4->runAction(sequence4);

		Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);
		myEnemyBullet5->runAction(sequence5);
	}
	else if(type==14)
	{
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePosition = oB->getPosition();

		
		auto myEnemyBullet6 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet7 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet8 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet9 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet10 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet11 = Sprite::createWithTexture(bulletBatchNode12->getTexture());
		auto myEnemyBullet12 = Sprite::createWithTexture(bulletBatchNode12->getTexture());



		
		double angle3 = 120;
		double angle4 = 150;
		//单个TAG，用于碰撞判断
		
		
	
		myEnemyBullet6->setTag(12);
		myEnemyBullet7->setTag(12);
		myEnemyBullet8->setTag(12);
		myEnemyBullet9->setTag(12);
		myEnemyBullet10->setTag(12);
		myEnemyBullet11->setTag(12);
		myEnemyBullet12->setTag(12);



	
		myEnemyBullet6->setScale(0.5);
		myEnemyBullet7->setScale(0.5);
		myEnemyBullet8->setScale(0.5);
		myEnemyBullet9->setScale(0.5);
		myEnemyBullet10->setScale(0.5);
		myEnemyBullet11->setScale(0.5);
		myEnemyBullet12->setScale(0.5);


		myEnemyBullet6->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet7->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet7->setRotation(angle3);

		myEnemyBullet8->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet8->setRotation(-angle3);


		myEnemyBullet9->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet9->setRotation(angle4);

		myEnemyBullet10->setPosition(oB->getPosition().x, oB->getPosition().y);
		myEnemyBullet10->setRotation(-angle4);


		myEnemyBullet11->setPosition(oB->getPosition().x, oB->getPosition().y);

		myEnemyBullet12->setPosition(oB->getPosition().x, oB->getPosition().y);














		//将创建好的子弹添加到BatchNode中进行批次渲染 
	
		bulletBatchNode12->addChild(myEnemyBullet6);
		bulletBatchNode12->addChild(myEnemyBullet7);
		bulletBatchNode12->addChild(myEnemyBullet8);
		bulletBatchNode12->addChild(myEnemyBullet9);
		bulletBatchNode12->addChild(myEnemyBullet10);
		bulletBatchNode12->addChild(myEnemyBullet11);
		bulletBatchNode12->addChild(myEnemyBullet12);





		//添加进入容器以便于迭代
	
		allEnemyBullet.pushBack(myEnemyBullet6);
		allEnemyBullet.pushBack(myEnemyBullet7);
		allEnemyBullet.pushBack(myEnemyBullet8);
		allEnemyBullet.pushBack(myEnemyBullet9);
		allEnemyBullet.pushBack(myEnemyBullet10);
		allEnemyBullet.pushBack(myEnemyBullet11);
		allEnemyBullet.pushBack(myEnemyBullet12);


		float r=110;
		float s60r = r*1.71 / 2;
		float s30r = r / 2;
		float c60r= r / 2;
		float c30r = r*1.71 / 2;

		float flyLen6 = r;
		float flyLen7 = r;
		float flyLen8 = r;
		float flyLen9 = r;
		float flyLen10 = r ;
		float flyLen11 = r;
		float flyLen12 = r;

		
		
		
		
		
		
	
		float realFlyDuration6 = flyLen6 / flyVelocity;//实际飞行的时间  
		float realFlyDuration7 = flyLen7 / flyVelocity;//实际飞行的时间  
		float realFlyDuration8 = flyLen8 / flyVelocity;//实际飞行的时间  
		float realFlyDuration9 = flyLen9 / flyVelocity;//实际飞行的时间  
		float realFlyDuration10 = flyLen10 / flyVelocity;//实际飞行的时间  
		float realFlyDuration11 = flyLen11 / flyVelocity;//实际飞行的时间  
		float realFlyDuration12 = flyLen12 / flyVelocity;//实际飞行的时间  



													   //子弹运行的距离和时间，从飞机处开始运行到屏幕顶端  

	
		auto actionMove6 = MoveTo::create(realFlyDuration6,
			Point(PlanePosition.x, PlanePosition.y +r));

		auto actionMove7 = MoveTo::create(realFlyDuration7,
			Vec2(PlanePosition.x-c30r, PlanePosition.y+s30r));

		auto actionMove8 = MoveTo::create(realFlyDuration8,
			Vec2(PlanePosition.x+c30r, PlanePosition.y+s30r));

		auto actionMove9 = MoveTo::create(realFlyDuration9,
			Vec2(PlanePosition.x-c60r, PlanePosition.y+s60r));

		auto actionMove10 = MoveTo::create(realFlyDuration10,
			Vec2(PlanePosition.x+c60r, PlanePosition.y+s60r));

		auto actionMove11 = MoveTo::create(realFlyDuration9,
			Vec2(PlanePosition.x-r, PlanePosition.y ));

		auto actionMove12 = MoveTo::create(realFlyDuration10,
			Vec2(PlanePosition.x+r , PlanePosition.y ));


		//子弹执行完动作后进行函数回调，调用移除子弹函数  
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(EnemyBulletLayer::removeEnemyBullet12, this));

	
		Sequence* sequence6 = Sequence::create(actionMove6, actionDone, NULL);
		myEnemyBullet6->runAction(sequence6);

		Sequence* sequence7 = Sequence::create(actionMove7, actionDone, NULL);
		myEnemyBullet7->runAction(sequence7);

		Sequence* sequence8 = Sequence::create(actionMove8, actionDone, NULL);
		myEnemyBullet8->runAction(sequence8);

		Sequence* sequence9 = Sequence::create(actionMove9, actionDone, NULL);
		myEnemyBullet9->runAction(sequence9);

		Sequence* sequence10 = Sequence::create(actionMove10, actionDone, NULL);
		myEnemyBullet10->runAction(sequence10);

		Sequence* sequence11 = Sequence::create(actionMove11, actionDone, NULL);
		myEnemyBullet11->runAction(sequence11);

		Sequence* sequence12 = Sequence::create(actionMove12, actionDone, NULL);
		myEnemyBullet12->runAction(sequence12);




	}
	







}





void EnemyBulletLayer::newEnemyBulletB(Node * oB, int type, float flyVelocity) {





}
