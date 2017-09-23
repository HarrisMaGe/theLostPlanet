#include "FoodLayer.h"

FoodLayer::FoodLayer() {
	
}

FoodLayer* FoodLayer::create() {
	FoodLayer* pRet = new FoodLayer();
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

bool FoodLayer::init() {


	
	
	
	
	return true;

}


void FoodLayer::newFood(Node * oB, int type) {
	
	if (type == 1)
	{
		auto myFood = Sprite::create("Food/upgrade0.png");
		myFood->setScale(0.5);
		//单个TAG，用于碰撞判断
		myFood->setTag(type);
		myFood->setPosition(oB->getPosition().x, oB->getPosition().y);
		this->addChild(myFood);
		allFood.pushBack(myFood);


		auto move = MoveBy::create(6, Vec2(-rand() % 300, -rand() % 300));



		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(FoodLayer::removeFood, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myFood->runAction(sequence);

	}
	else if (type == 2)
	{
		auto myFood = Sprite::create("Food/upgrade0.png");
		myFood->setScale(0.5);
		//单个TAG，用于碰撞判断
		myFood->setTag(type);
		myFood->setPosition(oB->getPosition().x, oB->getPosition().y);
		this->addChild(myFood);
		allFood.pushBack(myFood);


		auto move = MoveBy::create(6, Vec2(-rand() % 300, -rand() % 300));



		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(FoodLayer::removeFood, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myFood->runAction(sequence);
	}
	else if (type == 3)
	{
		auto myFood = Sprite::create("Food/crystal.png");
		myFood->setScale(0.5);
		//单个TAG，用于碰撞判断
		myFood->setTag(type);
		myFood->setPosition(oB->getPosition().x, oB->getPosition().y);
		this->addChild(myFood);
		allFood.pushBack(myFood);


		auto move = MoveBy::create(6, Vec2(-rand() % 300, -rand() % 300));



		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(FoodLayer::removeFood, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myFood->runAction(sequence);
	}
	else if (type == 4)
	{
		auto myFood = Sprite::create("Food/star.png");
		
		//单个TAG，用于碰撞判断
		myFood->setTag(type);
		myFood->setPosition(oB->getPosition().x+rand()%30, oB->getPosition().y + rand() % 30);
		this->addChild(myFood);
		allFood.pushBack(myFood);


		auto move = MoveBy::create(6, Vec2(-rand() % 300, -rand() % 300));



		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(FoodLayer::removeFood, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myFood->runAction(sequence);
	}
	else if (type == 5)
	{
		auto myFood = Sprite::create("Food/blood.png");
		myFood->setScale(0.5);
		//单个TAG，用于碰撞判断
		myFood->setTag(type);
		myFood->setPosition(oB->getPosition().x, oB->getPosition().y);
		this->addChild(myFood);
		allFood.pushBack(myFood);


		auto move = MoveBy::create(6, Vec2(-rand() % 300, -rand() % 300));



		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(FoodLayer::removeFood, this));

		Sequence* sequence = Sequence::create(move, actionDone, NULL);
		myFood->runAction(sequence);
	}
	
	

	
	


}


void FoodLayer::removeFood(Node* myFood) {
	if (NULL == myFood) {
		return;
	}
	Sprite *food = (Sprite *)myFood;
	food->removeFromParent();
	allFood.eraseObject(food);
}


