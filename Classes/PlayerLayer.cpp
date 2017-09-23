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
	

	



	//Ѫ��/��������

	//����background
	Sprite * energyBackGround = Sprite::create("UI/energyBackGround.png");
	energyBackGround->setPosition(Vec2(30, 27));
	this->addChild(energyBackGround);
	//��������
	Sprite * energy = Sprite::create("UI/energy.png");
	ProgressTimer * progress = ProgressTimer::create(energy);
	progress->setPosition(Vec2(30, 27));
	this->addChild(progress);

	//���ý�������ģʽ
	progress->setType(kCCProgressTimerTypeBar);//kCCProgressTimerTypeBar��ʾ����ģʽ
											   //���ý������仯�ķ���
	progress->setBarChangeRate(Point(0, 1));//ccp(0,1)��ʾ����y��仯
											//���ý���������ʼλ��
	progress->setMidpoint(Point(0, 0));//ccp(0,0)��ʾ����
									   //���ý�������ID
	progress->setTag(101);
	//Ѫ��

	Sprite * bloodBackGround = Sprite::create("UI/bloodBackGround.png");
	bloodBackGround->setPosition(Vec2(visibleSize.width/2-55, visibleSize.height - 14));
	this->addChild(bloodBackGround);
	//Ѫ������
	Sprite * blood = Sprite::create("UI/blood.png");
	ProgressTimer * progress2 = ProgressTimer::create(blood);
	progress2->setPosition(Vec2(visibleSize.width/2-40, visibleSize.height - 14));
	this->addChild(progress2);
	//����Ѫ����ģʽ
	progress2->setType(kCCProgressTimerTypeBar);//kCCProgressTimerTypeBar��ʾ����ģʽ
												//����Ѫ���仯�ķ���	
	progress2->setBarChangeRate(Point(1, 0));//x��
											 //���ý���������ʼλ��
	progress2->setMidpoint(Point(0, 0));//
										//���ý�������ID
	progress2->setTag(102);
	progress2->setPercentage(100);

	//����һ����ʱ��

	this->schedule(schedule_selector(PlayerLayer::scheduleenergy), 0.01);
	this->schedule(schedule_selector(PlayerLayer::scheduleblood), 1);
	
	
	
	
	
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyReleased = CC_CALLBACK_2(PlayerLayer::onKeyReleased, this);
	keyListener->onKeyPressed = CC_CALLBACK_2(PlayerLayer::onKeyPressed, this);
	// ��Ӽ�����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	
	
	
	
	return true;

}



//�˵�����
void PlayerLayer::shootNuclear() {
	
	
	//������ʼ��
	ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
	progress->setPercentage(0);
	//�ؿ�����������
	this->schedule(schedule_selector(PlayerLayer::scheduleenergy), 0.01);
	

	auto nuclearWeapon = Sprite::create("bullet/boss1_bullet_9.png");
	nuclearWeapon->setPosition(Director::getInstance()->getWinSize().width / 2, 0);
	this->addChild(nuclearWeapon);



	float flyVelocity = 500;
	float flyLen = Director::getInstance()->getWinSize().height/2;//���о���
	float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��  

												 //�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ�׶�					
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
	//�˵��ж�����
	nuclear = 1;
	Sprite *myNuclearWeapon = (Sprite *)nuclearWeapon;
	myNuclearWeapon->removeFromParent();
	
	
}






//������
//�����̵�ʱ��
void PlayerLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {


	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //��
	{

		this->schedule(schedule_selector(PlayerLayer::upArrow), 0.001);

		this->schedule(schedule_selector(PlayerLayer::upArrow), 0.001);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //��
	{
		this->schedule(schedule_selector(PlayerLayer::downArrow), 0.001);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //��
	{   

		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player_right.png");
		this->schedule(schedule_selector(PlayerLayer::rightArrow), 0.001);

	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //��
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player_left.png");
		this->schedule(schedule_selector(PlayerLayer::leftArrow), 0.001);

	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) //�ո�
	{
		ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
		if (progress->getPercentage() >= 100)
		{
			shootNuclear();
		}
	}


}
//�ɿ����̵�ʱ��

void PlayerLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)  //��
	{
		this->unschedule(schedule_selector(PlayerLayer::upArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)  //��
	{
		this->unschedule(schedule_selector(PlayerLayer::downArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)  //��
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player.png");
		this->unschedule(schedule_selector(PlayerLayer::rightArrow));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)  //��
	{
		Sprite * myPlayer = (Sprite *)player;
		myPlayer->setTexture("plane/player.png");
		this->unschedule(schedule_selector(PlayerLayer::leftArrow));
	}






}


//�����ƶ�������

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





//��������
void PlayerLayer::scheduleenergy(float t) {

	ProgressTimer * progress = (ProgressTimer *)getChildByTag(101);
	if (energy == 0) {
	}
	else if (energy == 1) {
		progress->setPercentage(progress->getPercentage() + 5);
		energy = 0;//��ʼ����¼

	}
	else if (energy == 2) {
		progress->setPercentage(progress->getPercentage() + 2);
		energy = 0;//��ʼ����¼
	}
	else
	{

	}

	if (progress->getPercentage() >= 100)
	{
		//��ֹ��ʱ��
		this->unschedule(schedule_selector(PlayerLayer::scheduleenergy));

	}

}

//Ѫ������
void PlayerLayer::scheduleblood(float t) {
	ProgressTimer * progress2 = (ProgressTimer *)getChildByTag(102);

	if (blood == 0) {
	}
	else if (blood == -1) {
		life -= 1;//��*Ѫ������
		progress2->setPercentage((life/20)*100);//Ѫ������
		
		blood = 0;//��ʼ����¼
	}
	else if (blood == -4) {
		life -= 4;//��*Ѫ������
		progress2->setPercentage((life / 20) * 100);//Ѫ������

		blood = 0;//��ʼ����¼
	}
	else if (blood == 1) {
		if (life<=16) {
			
			life += 4;//��*Ѫ������
		
		}
		else
		{
			life = 20;
		}
		progress2->setPercentage((life / 20) * 100);//Ѫ������

		blood = 0;//��ʼ����¼
	}
	else
	{

	}

	if (progress2->getPercentage() <= 0)
	{
		//��ֹ��ʱ��
		this->unschedule(schedule_selector(PlayerLayer::scheduleblood));

	}

}

