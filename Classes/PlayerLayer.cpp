#include "PlayerLayer.h"


bool PlayerLayer::init() {


	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getWinSize();

	player = Sprite::create("plane/player.png");
	player->setPosition(visibleSize.width / 2, visibleSize.height / 6);
	player->setTag(1);
	player->setScale(0.8);
	this->addChild(player, 1);
	

	



	//血条/蓝条控制

	//蓝条background
	Sprite * energyBackGround = Sprite::create("UI/energyBackGround.png");
	energyBackGround->setPosition(Vec2(30, 27));
	this->addChild(energyBackGround);
	//蓝条滚动
	Sprite * energy = Sprite::create("UI/energy.png");
	ProgressTimer * progress = ProgressTimer::create(energy);
	progress->setPosition(Vec2(30, 27));
	this->addChild(progress);

	//设置进度条的模式
	progress->setType(kCCProgressTimerTypeBar);//kCCProgressTimerTypeBar表示条形模式
											   //设置进度条变化的方向
	progress->setBarChangeRate(Point(0, 1));//ccp(0,1)表示沿着y轴变化
											//设置进度条的起始位置
	progress->setMidpoint(Point(0, 0));//ccp(0,0)表示下面
									   //设置进度条的ID
	progress->setTag(101);
	//血条

	Sprite * bloodBackGround = Sprite::create("UI/bloodBackGround.png");
	bloodBackGround->setPosition(Vec2(visibleSize.width/2-55, visibleSize.height - 14));
	this->addChild(bloodBackGround);
	//血条滚动
	Sprite * blood = Sprite::create("UI/blood.png");
	ProgressTimer * progress2 = ProgressTimer::create(blood);
	progress2->setPosition(Vec2(visibleSize.width/2-40, visibleSize.height - 14));
	this->addChild(progress2);
	//设置血条的模式
	progress2->setType(kCCProgressTimerTypeBar);//kCCProgressTimerTypeBar表示条形模式
												//设置血条变化的方向	
	progress2->setBarChangeRate(Point(1, 0));//x轴
											 //设置进度条的起始位置
	progress2->setMidpoint(Point(0, 0));//
										//设置进度条的ID
	progress2->setTag(102);
	progress2->setPercentage(100);

	//创建一个定时器

	this->schedule(schedule_selector(PlayerLayer::scheduleenergy), 0.01);
	this->schedule(schedule_selector(PlayerLayer::scheduleblood), 1);
	
	
	
	
	
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyReleased = CC_CALLBACK_2(PlayerLayer::onKeyReleased, this);
	keyListener->onKeyPressed = CC_CALLBACK_2(PlayerLayer::onKeyPressed, this);
	// 添加监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	
	
	
	
	return true;

}



//核弹发射
void PlayerLayer::shootNuclear() {
	
	
	//蓝条初始化
	ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
	progress->setPercentage(0);
	//重开蓝条监听器
	this->schedule(schedule_selector(PlayerLayer::scheduleenergy), 0.01);
	

	auto nuclearWeapon = Sprite::create("bullet/boss1_bullet_9.png");
	nuclearWeapon->setPosition(Director::getInstance()->getWinSize().width / 2, 0);
	this->addChild(nuclearWeapon);



	float flyVelocity = 500;
	float flyLen = Director::getInstance()->getWinSize().height/2;//飞行距离
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  

												 //子弹运行的距离和时间，从飞机处开始运行到屏幕底端					
	auto move = MoveTo::create(realFlyDuration, Point(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2));






	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(PlayerLayer::removeNuclearWeapon, this));

	Sequence* sequence = Sequence::create(move, actionDone, NULL);
	nuclearWeapon->runAction(sequence);

};

void PlayerLayer::removeNuclearWeapon(Node* nuclearWeapon) {
	if (NULL == nuclearWeapon) {
		return;
	}
	//核弹判断器打开
	nuclear = 1;
	Sprite *myNuclearWeapon = (Sprite *)nuclearWeapon;
	myNuclearWeapon->removeFromParent();
	
	
}






//监听器
//按键盘的时候
void PlayerLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {


	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //上
	{

		this->schedule(schedule_selector(PlayerLayer::upArrow), 0.001);

		this->schedule(schedule_selector(PlayerLayer::upArrow), 0.001);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //下
	{
		this->schedule(schedule_selector(PlayerLayer::downArrow), 0.001);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //右
	{   

		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player_right.png");
		this->schedule(schedule_selector(PlayerLayer::rightArrow), 0.001);

	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //左
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player_left.png");
		this->schedule(schedule_selector(PlayerLayer::leftArrow), 0.001);

	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) //空格
	{
		ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
		if (progress->getPercentage() >= 100)
		{
			shootNuclear();
		}
	}


}
//松开键盘的时候

void PlayerLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //上
	{
		this->unschedule(schedule_selector(PlayerLayer::upArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //下
	{
		this->unschedule(schedule_selector(PlayerLayer::downArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //右
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player.png");
		this->unschedule(schedule_selector(PlayerLayer::rightArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //左
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player.png");
		this->unschedule(schedule_selector(PlayerLayer::leftArrow));
	}






}


//键盘移动调度器

void PlayerLayer::upArrow(float t)
{
	
	if (player->getPosition().y + 50 >= Director::getInstance()->getWinSize().height)
	{
	}
	else {
		player->setPosition(player->getPosition().x, player->getPosition().y + speed);
	}
}
void PlayerLayer::downArrow(float t)
{
	
	if (player->getPosition().y <= 50)
	{
	}
	else {
		player->setPosition(player->getPosition().x, player->getPosition().y - speed);
	}
}
void PlayerLayer::rightArrow(float t)
{

	if (player->getPosition().x >= Director::getInstance()->getWinSize().width)
	{
	}
	else {
		player->setPosition(player->getPosition().x + speed, player->getPosition().y);
	}
}
void PlayerLayer::leftArrow(float t)
{
	
	if (player->getPosition().x <= 0)
	{
	}
	else {
		player->setPosition(player->getPosition().x - speed, player->getPosition().y);
	}

}





//蓝条检验
void PlayerLayer::scheduleenergy(float t) {

	ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
	if (energy == 0) {
	}
	else if (energy == 1) {
		progress->setPercentage(progress->getPercentage() + 5);
		energy = 0;//初始化记录

	}
	else if (energy == 2) {
		progress->setPercentage(progress->getPercentage() + 2);
		energy = 0;//初始化记录
	}
	else
	{

	}

	if (progress->getPercentage() >= 100)
	{
		//终止定时器
		this->unschedule(schedule_selector(PlayerLayer::scheduleenergy));

	}

}

//血条检验
void PlayerLayer::scheduleblood(float t) {
	ProgressTimer * progress2 = (ProgressTimer *)getChildByTag(102);

	if (blood == 0) {
	}
	else if (blood == -1) {
		life -= 1;//真*血条减少
		progress2->setPercentage((life/20)*100);//血条减少
		
		blood = 0;//初始化记录
	}
	else if (blood == -4) {
		life -= 4;//真*血条减少
		progress2->setPercentage((life / 20) * 100);//血条减少

		blood = 0;//初始化记录
	}
	else if (blood == 1) {
		if (life<=16) {
			
			life += 4;//真*血条增加
		
		}
		else
		{
			life = 20;
		}
		progress2->setPercentage((life / 20) * 100);//血条增加

		blood = 0;//初始化记录
	}
	else
	{

	}

	if (progress2->getPercentage() <= 0)
	{
		//终止定时器
		this->unschedule(schedule_selector(PlayerLayer::scheduleblood));

	}

}

