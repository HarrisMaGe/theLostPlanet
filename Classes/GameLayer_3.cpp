#include "GameLayer_3.h"
#include "SimpleAudioEngine.h"
#include "BackGround.h"
#include "FoodLayer.h"
#include "StartLayer.h"
#include "EnemyBulletLayer.h"
#include "PlayerBulletLayer.h"
#include "EnemyLayer.h"
#include "GameOver.h"
#include "LoadLayer.h"
#include "ChooseLoadLayer.h"
#include "EndLayer.h"

#define BULLET  18
USING_NS_CC;
using namespace CocosDenshion;




Scene* GameLayer_3::createScene()
{

	auto scene = Scene::create();


	auto layer = GameLayer_3::create();


	scene->addChild(layer);


	return scene;
}



bool GameLayer_3::init() {


	if (!Layer::init())
	{
		return false;
	}

	BackGround* myBackGround = new BackGround();
	this->addChild(myBackGround->createBackGround_3(), 1);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/bgmusic_stage3.wav",-1);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();




	auto reStartItem = MenuItemImage::create(
		"UI/return.png",
		"UI/return_pressed.png",
		CC_CALLBACK_1(GameLayer_3::menuCallback, this));

	reStartItem->setTag(1);


	auto menu = Menu::create(reStartItem, NULL);
	menu->setPosition(visibleSize.width - 110, 26);
	this->addChild(menu, 4);


	auto scoreBackGround = Sprite::create("UI/scoreLable.png");
	scoreBackGround->setPosition(visibleSize.width * 7 / 8, visibleSize.height - 14);
	this->addChild(scoreBackGround, 4);


	labScore = Label::create("score:0", "Marker Felt", 20);
	labScore->setPosition(Point(visibleSize.width * 7 / 8, visibleSize.height - 14));
	labScore->setColor(Color3B::WHITE);
	this->addChild(labScore, 4);
	labScore->setTag(120);

	//���
	myPlayerLayer = PlayerLayer::create();
	this->addChild(myPlayerLayer, 4);


	//Boss���ⴴ��
	this->schedule(schedule_selector(GameLayer_3::scheduleBossLaser1));
	//Boss������ײ���
	this->schedule(schedule_selector(GameLayer_3::scheduleBossLaserShoot1));

	//�ӵ�
	myPlayerBulletLayer = PlayerBulletLayer::create(myPlayerLayer->player);
	this->addChild(myPlayerBulletLayer, 4, BULLET);
	myPlayerBulletLayer->createBulletForPlayer(1, 0.2, 500);

	//������Ʒ
	myFoodlayer = FoodLayer::create();
	this->addChild(myFoodlayer, 4);


	//�л�
	myEnemyLayer = EnemyLayer_3::create(myPlayerLayer->player);
	this->addChild(myEnemyLayer, 1);
	//this->schedule(schedule_selector(GameLayer_3::enemySch),1);


	//�л��ӵ�
	myEnemyBulletLayer = EnemyBulletLayer::create(myPlayerLayer->player);
	this->addChild(myEnemyBulletLayer, 4);
	this->schedule(schedule_selector(GameLayer_3::enemyBulletManagerA), 1);
	this->schedule(schedule_selector(GameLayer_3::enemyBulletManagerB), 0.5);
	this->schedule(schedule_selector(GameLayer_3::enemyBulletManagerC), 2);
	this->schedule(schedule_selector(GameLayer_3::enemyBulletManagerD), 1.5);
	


	//�л�
	//this->schedule(schedule_selector(GameLayer_3::newEnemy), 0.5);
	//this->schedule(schedule_selector(GameLayer_3::moveEnemy), 0.01);

	//��ײ���
	this->scheduleUpdate();

	return true;



}
//�ص�����
void GameLayer_3::menuCallback(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	MenuItem * nowItem = (MenuItem *)pSender;

	switch (nowItem->getTag())
	{
	case 1://���¿�ʼ
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		Director::getInstance()->replaceScene(GameLayer_3::createScene());
		break;
	case 2://�˳�
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		Director::getInstance()->replaceScene(StartLayer::createScene());
		break;

	}




}

void GameLayer_3::menureStartCallBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameLayer_3::createScene());

}
void GameLayer_3::menuBack(Ref* pSender)
{

	Director::getInstance()->replaceScene(LoadLayer::createScene());
}


//����
void GameLayer_3::death() {




	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture *renderTexture = RenderTexture::create(winSize.width, winSize.height);

	//������ǰ��������ӽڵ���Ϣ������renderTexture�С�  
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����  
	Scene *se = GameOver::scene(renderTexture);
	GameOver *gp = (GameOver *)se->getChildByTag(123);
	gp->choose = 3;
	gp->setBG(this);
	Director::getInstance()->pushScene(se);







}



/*
void  GameLayer_3::newEnemy(float t) {
Sprite * enemy = nullptr;
auto visibleSize = Director::getInstance()->getWinSize();
int num = rand() % 50;
if (num >= 3)
{
enemy = Sprite::create("plane/enmy1.png");
enemy->setTag(1000);
}
else
{
enemy = Sprite::create("plane/enmy2.png");
enemy->setTag(2000);
}
enemy->setPosition(Point(rand() % 300 + visibleSize.width/2, visibleSize.height-100));
this->addChild(enemy);
this->allEnemy.pushBack(enemy);
}
void  GameLayer_3::moveEnemy(float t) {

for (int i = 0;i<allEnemy.size();i++)
{
auto nowenemy = allEnemy.at(i);
nowenemy->setPositionY(nowenemy->getPositionY() - 3);
if (nowenemy->getPositionY()<0)
{
nowenemy->removeFromParent();
allEnemy.eraseObject(nowenemy);
i--;
}
}
}
*/




void GameLayer_3::update(float t) {
	auto player = myPlayerLayer->player;
	Rect rectPlayer(player->getPosition().x - 25, player->getPosition().y - 25, 50, 50);

	//�л��ӵ���player
	for (int i = 0; i < myEnemyBulletLayer->allEnemyBullet.size(); i++)
	{
		auto nowEnemyBullet = myEnemyBulletLayer->allEnemyBullet.at(i);
		Rect rectEnemyBullet(nowEnemyBullet->getPosition().x - 10, nowEnemyBullet->getPosition().y - 10, 20, 20);
		if (rectEnemyBullet.intersectsRect(rectPlayer))
		{
			//��Ч
			SimpleAudioEngine::getInstance()->playEffect("music/music4.wav");



			switch (nowEnemyBullet->getTag())
			{
			case 1:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet1(nowEnemyBullet);
				break;
			case 2:
				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}


				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet2(nowEnemyBullet);
				break;
			case 3:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet3(nowEnemyBullet);
				break;
			case 4:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet4(nowEnemyBullet);
				break;
			case 5:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet5(nowEnemyBullet);
				break;
			case 6:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet6(nowEnemyBullet);
				break;
			case 7:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet7(nowEnemyBullet);
				break;
			case 8:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet8(nowEnemyBullet);
				break;
			case 9:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet9(nowEnemyBullet);
				break;
			case 10:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet10(nowEnemyBullet);
				break;
			case 11:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet11(nowEnemyBullet);
				break;
			case 12:

				//��ҿ�Ѫ
				if (unlimited >= 1)
				{
					//�޵�Ŷ
				}
				else
				{
					//Ѫ��-1
					myPlayerLayer->blood = -1;
				}

				//�Ƴ��л��ӵ�
				myEnemyBulletLayer->removeEnemyBullet12(nowEnemyBullet);
				break;
			default:
				break;
			}



		}

	}
	//�������
	for (int i = 0; i < myFoodlayer->allFood.size(); i++)
	{
		auto nowFood = myFoodlayer->allFood.at(i);
		if (nowFood->getTag() == 4)
		{


			Rect rectFood(nowFood->getPosition().x - 200, nowFood->getPosition().y - 200, 400, 400);
			if (player->getPosition().x >= rectFood.getMinX() && player->getPosition().x <= rectFood.getMaxX())
			{
				if (player->getPosition().y >= rectFood.getMinY() && player->getPosition().y <= rectFood.getMaxY())
				{

					auto move = MoveTo::create(1, Vec2(player->getPosition().x, player->getPosition().y));
					nowFood->runAction(move);
				}

			}
		}
	}
	//�����player
	for (int i = 0; i < myFoodlayer->allFood.size(); i++)
	{
		auto nowFood = myFoodlayer->allFood.at(i);
		if (nowFood->getTag() == 4)
		{


			Rect rectFood(nowFood->getPosition().x - 75, nowFood->getPosition().y - 75, 150, 150);
			if (rectFood.intersectsRect(rectPlayer))
			{   //�ӷ�
				score += 10;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);
				//����ͼ��
				myFoodlayer->removeFood(nowFood);
				i--;

			}
		}
	}




	//������Ʒ��player
	for (int i = 0; i < myFoodlayer->allFood.size(); i++)
	{
		auto nowFood = myFoodlayer->allFood.at(i);
		Rect rectFood(nowFood->getPosition().x - 30, nowFood->getPosition().y - 30, 60, 60);
		if (rectFood.intersectsRect(rectPlayer))
		{

			//��Ч
			SimpleAudioEngine::getInstance()->playEffect("music/food_2.wav", false, 1, 0, 0.2);


			switch (nowFood->getTag())
			{
			case 1:
				//�ӵ�

				//10���رս���
				Food1 += 1;
				scheduleOnceFOODManager_1();
				break;
			case 2:
				//�ٶ�


				//10���رս���
				Food2 += 1;
				scheduleOnceFOODManager_2();

				break;
			case 3:
				//һ��ʱ���޵���Ϊ����

				//�޵��ж�
				unlimited = 1;
				//10���رս���
				Food3 = Food3 + 1;

				scheduleOnceFOODManager_3();
				break;

			case 5:
				//��Ѫ


				myPlayerLayer->blood = 1;

				break;
			default:
				break;
			}



			//����ͼ��
			myFoodlayer->removeFood(nowFood);
			i--;




		}
	}


	//�л����ҷ��ӵ�
	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{
		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
		myPlayerBulletLayer->vecBullet;
		Rect rectEnemy(nowenemy->getPosition().x - 50, nowenemy->getPosition().y - 50, 100, 100);
		for (int j = 0;j<myPlayerBulletLayer->vecBullet.size();j++)
		{
			auto nowbullet = myPlayerBulletLayer->vecBullet.at(j);

			Rect rectBullet(nowbullet->getPosition().x - 10, nowbullet->getPosition().y - 10, 20, 20);
			if (rectBullet.intersectsRect(rectEnemy))
			{





				//�ӵ���ʧ
				//�л���Ѫ



				switch (nowbullet->getTag())
				{
				case 131:
					//������Ե�ӵ�
					nowenemy->setTag(nowenemy->getTag() - 1);
					myPlayerBulletLayer->removeBullet_1(nowbullet);
					break;
				case 132:
					//���������ӵ�
					nowenemy->setTag(nowenemy->getTag() - 2);
					myPlayerBulletLayer->removeBullet_2(nowbullet);
					break;
				case 133:
					//һ�������ӵ�
					nowenemy->setTag(nowenemy->getTag() - 1);
					myPlayerBulletLayer->removeBullet_4(nowbullet);
					break;
				case 134:
					//������Ե�ӵ�
					nowenemy->setTag(nowenemy->getTag() - 2);
					myPlayerBulletLayer->removeBullet_3(nowbullet);
					break;
				case 135:
					//���������ӵ�
					nowenemy->setTag(nowenemy->getTag() - 3);
					myPlayerBulletLayer->removeBullet_5(nowbullet);
					break;
				case 136:
					nowenemy->setTag(nowenemy->getTag() - 1);
					myPlayerBulletLayer->removeBullet_7(nowbullet);
					break;
				case 137:
					nowenemy->setTag(nowenemy->getTag() - 1);
					myPlayerBulletLayer->removeBullet_6(nowbullet);
					break;
				default:
					break;
				}




				break;





			}
		}
	}

	//player�͵л�
	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{
		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);

		Rect rectEnemy(nowenemy->getPosition().x - 50, nowenemy->getPosition().y - 50, 100, 100);
		if (rectPlayer.intersectsRect(rectEnemy)) {

			//�л���Ѫ

			if (nowenemy->getTag() <= 1000)
			{
				nowenemy->setTag(nowenemy->getTag() - 10);
			}
			else if (nowenemy->getTag() <= 200 && nowenemy->getTag()>100)
			{
				nowenemy->setTag(nowenemy->getTag() - 1);
			}

			//��ҿ�Ѫ	
			if (unlimited >= 1)
			{
				//�޵�Ŷ
			}
			else
			{
				//Ѫ��-1
				myPlayerLayer->blood = -1;
			}





		}




	}

	//�л����������
	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{
		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);

		//���ݱ�ǩ�жϵл�����


		//�����л�
		if (nowenemy->getTag() <= 250)
		{//8��Ѫ��
			if (nowenemy->getTag() <= 242)
			{
				
				//��ը��Ч
				newBomb(nowenemy->getPosition().x, nowenemy->getPosition().y);


				//���ʵ�����Ʒ

				if (rand() % 1000>700)//�ӵ�
				{
					myFoodlayer->newFood(nowenemy, 1);
				}
				if (rand() % 1000>999)//�ٶ�
				{
					myFoodlayer->newFood(nowenemy, 2);
				}
				if (rand() % 1000>800)//�޵�
				{
					myFoodlayer->newFood(nowenemy, 3);
				}
				if (rand() % 1000>100)//����
				{
					for (int i = 0; i <3; i++)
					{
						myFoodlayer->newFood(nowenemy, 4);
					}
				}
				if (rand() % 1000>800)//����
				{

					myFoodlayer->newFood(nowenemy, 5);

				}





				//�����ۼ�1
				myPlayerLayer->energy = 1;



				//�ӷ�
				score += 50;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);


				//�л���ʧ
				nowenemy->removeFromParent();
				myEnemyLayer->myEnemyStlyle->allEnemy.eraseObject(nowenemy);
				i--;
			}
			else {
				//û��
			}
		}
		//��ɫ�л�
		else if (nowenemy->getTag() <= 500 && nowenemy->getTag()>250)
		{//14��Ѫ��
			if (nowenemy->getTag() <= 486)
			{

			
				//��ը��Ч
				newBomb(nowenemy->getPosition().x, nowenemy->getPosition().y);


				//ʮ��֮һ���ʵ�����Ʒ

				if (rand() % 1000>900)//�ӵ�
				{
					myFoodlayer->newFood(nowenemy, 1);
				}
				if (rand() % 1000>999)//�ٶ�
				{
					myFoodlayer->newFood(nowenemy, 2);
				}
				if (rand() % 1000>900)//�޵�
				{
					myFoodlayer->newFood(nowenemy, 3);
				}
				if (rand() % 1000>100)//����
				{
					for (int i = 0; i < 1; i++)
					{
						myFoodlayer->newFood(nowenemy, 4);
					}
				}
				if (rand() % 1000>900)//����
				{

					myFoodlayer->newFood(nowenemy, 5);

				}





				//�����ۼ�1
				myPlayerLayer->energy = 1;



				//�ӷ�
				score += 50;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);


				//�л���ʧ
				nowenemy->removeFromParent();
				myEnemyLayer->myEnemyStlyle->allEnemy.eraseObject(nowenemy);
				i--;


			}
			else {
			}
		}
		//�����л�
		else if (nowenemy->getTag() <= 1000 && nowenemy->getTag()>500)
		{//10��Ѫ��
			if (nowenemy->getTag() <= 990)
			{

				
				//��ը��Ч
				newBomb(nowenemy->getPosition().x, nowenemy->getPosition().y);


				//ʮ��֮һ���ʵ�����Ʒ

				if (rand() % 1000>700)//�ӵ�
				{
					myFoodlayer->newFood(nowenemy, 1);
				}
				if (rand() % 1000>999)//�ٶ�
				{
					myFoodlayer->newFood(nowenemy, 2);
				}
				if (rand() % 1000>800)//�޵�
				{
					myFoodlayer->newFood(nowenemy, 3);
				}
				if (rand() % 1000>100)//����
				{
					for (int i = 0; i <3; i++)
					{
						myFoodlayer->newFood(nowenemy, 4);
					}
				}
				if (rand() % 1000>800)//����
				{

					myFoodlayer->newFood(nowenemy, 5);

				}





				//�����ۼ�1
				myPlayerLayer->energy = 1;



				//�ӷ�
				score += 100;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);


				//�л���ʧ
				nowenemy->removeFromParent();
				myEnemyLayer->myEnemyStlyle->allEnemy.eraseObject(nowenemy);
				i--;
			}
		}
		//ţ�Ƶл�
		else if (nowenemy->getTag() <= 1500 && nowenemy->getTag()>1000)
		{//60��Ѫ��
			if (nowenemy->getTag() <= 1440)
			{

				
				//��ը��Ч
				newBomb(nowenemy->getPosition().x, nowenemy->getPosition().y);


				//ʮ��֮һ���ʵ�����Ʒ

				if (rand() % 1000 > 500)//�ӵ�
				{
					myFoodlayer->newFood(nowenemy, 1);
				}
				if (rand() % 1000 > 999)//�ٶ�
				{
					myFoodlayer->newFood(nowenemy, 2);
				}
				if (rand() % 1000 > 700)//�޵�
				{
					myFoodlayer->newFood(nowenemy, 3);
				}
				if (rand() % 1000 > 100)//����
				{
					for (int i = 0; i < 5; i++)
					{
						myFoodlayer->newFood(nowenemy, 4);
					}
				}
				if (rand() % 1000 > 500)//����
				{

					myFoodlayer->newFood(nowenemy, 5);

				}





				//�����ۼ�1
				myPlayerLayer->energy = 1;



				//�ӷ�
				score += 300;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);


				//�л���ʧ
				nowenemy->removeFromParent();
				myEnemyLayer->myEnemyStlyle->allEnemy.eraseObject(nowenemy);
				i--;
			}
		}
		//BoosŶ
		else if (nowenemy->getTag() <= 3000 && nowenemy->getTag()>1500)
		{//���ٵ�Ѫ��
			if (nowenemy->getTag() <= 2700)
			{

				//��ը��Ч
				newBossBomb(nowenemy->getPosition().x, nowenemy->getPosition().y);


				//ʮ��֮һ���ʵ�����Ʒ

				if (rand() % 1000 > 999)//�ӵ�
				{
					myFoodlayer->newFood(nowenemy, 1);
				}
				if (rand() % 1000 > 999)//�ٶ�
				{
					myFoodlayer->newFood(nowenemy, 2);
				}
				if (rand() % 1000 > 999)//�޵�
				{
					myFoodlayer->newFood(nowenemy, 3);
				}
				if (rand() % 1000 > 100)//����
				{
					for (int i = 0; i <40; i++)
					{
						myFoodlayer->newFood(nowenemy, 4);
					}
				}
				if (rand() % 1000 >999)//����
				{

					myFoodlayer->newFood(nowenemy, 5);

				}





				//�����ۼ�1
				myPlayerLayer->energy = 1;



				//�ӷ�
				score += 1000;
				labScore->setString(String::createWithFormat("score:%d", score)->_string);


				//�л���ʧ
				nowenemy->removeFromParent();
				myEnemyLayer->myEnemyStlyle->allEnemy.eraseObject(nowenemy);
				i--;

				if (this->getChildByTag(221) != NULL)
				{
					auto *laser = this->getChildByTag(221);
					laser->stopAllActions();
					laser->removeFromParent();
				}


				//ͨ�ؼ��
				this->scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceWin), 3);

			}
		}






	}










	//������������

	if (myPlayerLayer->life <= 0)
	{  
	//	SimpleAudioEngine::getInstance()->playEffect("music/hero_explor.wav.wav", false, 1, 0, 1);
	
		
		
		//�Ƴ��ɻ����ӵ�
		Sprite *player = (Sprite *)myPlayerLayer->player;
		player->setVisible(false);
		myPlayerBulletLayer->stopBulletForPlayer();

		//�������ر�
		unschedule(schedule_selector(GameLayer_3::update));


		//��Ч��ʧ
		if (this->getChildByTag(211) != NULL)
		{

			auto *shield = this->getChildByTag(211);
			//������ʧ
			shield->stopAllActions();
			//����������ʧ
			shield->removeFromParent();
		}

		//��������
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceDeath), 3);
	}


	//�˵�������
	if (myPlayerLayer->nuclear == 1)
	{   //�˱���Ч

		SimpleAudioEngine::getInstance()->playEffect("music/lighting.wav");

		Light(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2);

		//���˿�Ѫ
		for (int i = 0;i <myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
		{
			auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
			//Ч��
			nowenemy->setTag(nowenemy->getTag() - 30);
		}
		//�رպ˵�
		myPlayerLayer->nuclear = 0;
	}

	//��������
	if (this->getChildByTag(211) != NULL)
	{

		auto *shield = this->getChildByTag(211);
		shield->setPosition(player->getPosition().x, player->getPosition().y);

	}
	//��������
	if (this->getChildByTag(212) != NULL)
	{

		auto *fire = this->getChildByTag(212);
		fire->setPosition(player->getPosition().x, player->getPosition().y - 100);


	}
	//Boss�������
	if (this->getChildByTag(221) != NULL)
	{

		auto *laser = this->getChildByTag(221);

		for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
		{
			auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
			if (nowenemy->getTag()>1500)
			{
				laser->setPosition(nowenemy->getPosition().x, nowenemy->getPosition().y - 460);

			}

		}

	}








}



//��Ч


//ɾ�����꾫�飬�ͷ��ڴ�
void GameLayer_3::del(Node * pSender)
{
	pSender->removeFromParentAndCleanup(true);
}


//��ըЧ��
void GameLayer_3::newBomb(int x, int  y)
{

	//��ը��Ч
//	SimpleAudioEngine::getInstance()->playEffect("music/boom.wav");



	auto sprite = Sprite::create();
	sprite->setPosition(Point(x, y));
	sprite->setAnchorPoint(ccp(0.5, 0.5));
	this->addChild(sprite, 4);

	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/boom_1.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/boom_2.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/boom_3.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/boom_4.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf4);
	SpriteFrame * sf5 = SpriteFrame::create("effect/boom_5.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf5);
	SpriteFrame * sf6 = SpriteFrame::create("effect/boom_6.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf6);
	SpriteFrame * sf7 = SpriteFrame::create("effect/boom_7.png", Rect(0, 0, 64, 64));
	allframe.pushBack(sf7);


	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.06);

	Action * act = Sequence::create(
		Animate::create(ani),  //����
		CCCallFuncN::create(sprite, callfuncN_selector(GameLayer_3::del)), //ɾ������
		NULL);


	sprite->runAction(act);
	allframe.clear();

}






//Boss��ըЧ��
void GameLayer_3::newBossBomb(int x, int  y)
{

	///��ը��Ч
//	SimpleAudioEngine::getInstance()->playEffect("boos_explor.wav");
	auto sprite = Sprite::create();
	sprite->setPosition(Point(x, y));
	sprite->setAnchorPoint(ccp(0.5, 0.5));
	this->addChild(sprite, 4);

	Vector<SpriteFrame*> allframe;
	SpriteFrame * sf1 = SpriteFrame::create("effect/boss1_explor_1.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/boss1_explor_2.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/boss1_explor_3.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/boss1_explor_4.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf4);
	SpriteFrame * sf5 = SpriteFrame::create("effect/boss1_explor_5.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf5);
	SpriteFrame * sf6 = SpriteFrame::create("effect/boss1_explor_6.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf6);
	SpriteFrame * sf7 = SpriteFrame::create("effect/boss1_explor_7.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf7);
	SpriteFrame * sf8 = SpriteFrame::create("effect/boss1_explor_8.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf8);
	SpriteFrame * sf9 = SpriteFrame::create("effect/boss1_explor_9.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf9);


	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);

	Action * act = Sequence::create(
		Animate::create(ani),  //����
		CCCallFuncN::create(sprite, callfuncN_selector(GameLayer_3::del)), //ɾ������
		NULL);


	sprite->runAction(act);
	allframe.clear();

}








//ͨ�غ�ʤ������
void GameLayer_3::win() {

	Size winSize = Director::getInstance()->getWinSize();

	Vector<SpriteFrame *>allframe;
	SpriteFrame *win1 = SpriteFrame::create("effect/win1.png", Rect(0, 0, 300, 300));
	allframe.pushBack(win1);
	SpriteFrame *win2 = SpriteFrame::create("effect/win2.png", Rect(0, 0, 300, 300));
	allframe.pushBack(win2);
	SpriteFrame *win3 = SpriteFrame::create("effect/win3.png", Rect(0, 0, 300, 300));
	allframe.pushBack(win3);
	SpriteFrame *win4 = SpriteFrame::create("effect/win4.png", Rect(0, 0, 300, 300));
	allframe.pushBack(win4);
	SpriteFrame *win5 = SpriteFrame::create("effect/win5.png", Rect(0, 0, 300, 300));
	allframe.pushBack(win5);
	Animation *animation = Animation::createWithSpriteFrames(allframe, 0.2);
	auto sprite = Sprite::create();
	this->addChild(sprite, 4);

	Action * action = Sequence::create(Animate::create(animation), CCCallFuncN::create(sprite, callfuncN_selector(EnemyStyle::del)), NULL);
	sprite->setPosition(Vec2(winSize.width / 2, winSize.height * 2 / 3));

	sprite->runAction(action);
	allframe.clear();
}











//����Ч��
void GameLayer_3::Light(int x, int  y)
{
	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/jineng_1.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/jineng_2.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/jineng_3.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/jineng_4.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf4);
	SpriteFrame * sf5 = SpriteFrame::create("effect/jineng_5.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf5);
	SpriteFrame * sf6 = SpriteFrame::create("effect/jineng_6.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf6);

	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);
	auto sprite = Sprite::create();
	Action * act = Sequence::create(
		Animate::create(ani),  //����
		CCCallFuncN::create(sprite, callfuncN_selector(GameLayer_3::del)), //ɾ������
		NULL);

	sprite->setAnchorPoint(ccp(0.5, 0.5));
	sprite->setPosition(Point(x, y));
	this->addChild(sprite, 4);
	sprite->runAction(act);
	allframe.clear();
}


//Boos����
void GameLayer_3::Laser(Node *player)
{
	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/boss1_jineng_1.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/boss1_jineng_2.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/boss1_jineng_3.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/boss1_jineng_4.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf4);
	SpriteFrame * sf5 = SpriteFrame::create("effect/boss1_jineng_5.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf5);
	SpriteFrame * sf6 = SpriteFrame::create("effect/boss1_jineng_6.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf6);
	SpriteFrame * sf7 = SpriteFrame::create("effect/boss1_jineng_5.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf7);
	SpriteFrame * sf8 = SpriteFrame::create("effect/boss1_jineng_3.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf8);
	SpriteFrame * sf9 = SpriteFrame::create("effect/boss1_jineng_2.png", Rect(0, 0, 512, 768));
	allframe.pushBack(sf9);

//	SimpleAudioEngine::getInstance()->playEffect("music/click.wav", false, 1, 0, 0.3);

	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);
	auto repeat = RepeatForever::create(Animate::create(ani));
	Sprite *Laser = Sprite::create();
	Laser->setPosition(player->getPosition().x, player->getPosition().y - 390);
	this->addChild(Laser, 4);
	Laser->setTag(221);
	Laser->runAction(repeat);
}







//����
void GameLayer_3::shield_F(Node *player)
{
	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/shield_1.png", Rect(0, 0, 128, 128));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/shield_2.png", Rect(0, 0, 128, 128));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/shield_1.png", Rect(0, 0, 128, 128));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/shield_2.png", Rect(0, 0, 128, 128));
	allframe.pushBack(sf4);


	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);
	auto repeat = RepeatForever::create(Animate::create(ani));
	Sprite *shield = Sprite::create();
	shield->setPosition(player->getPosition().x, player->getPosition().y);
	this->addChild(shield, 4);
	shield->setTag(211);
	shield->runAction(repeat);
}


//��β����
void GameLayer_3::fire_F(Node *player)
{
	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/Fire01.png", Rect(0, 0, 40, 150));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/Fire02.png", Rect(0, 0, 40, 150));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/Fire02.png", Rect(0, 0, 40, 150));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/Fire01.png", Rect(0, 0, 40, 150));
	allframe.pushBack(sf4);



	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);
	auto repeat = RepeatForever::create(Animate::create(ani));
	Sprite *fire = Sprite::create();
	fire->setPosition(player->getPosition().x, player->getPosition().y - 100);
	this->addChild(fire, 4);
	fire->setTag(212);
	fire->runAction(repeat);
}

void GameLayer_3::nuclear(int x, int y) {

	auto sprite = Sprite::create();
	sprite->setPosition(Point(x, y));
	sprite->setAnchorPoint(ccp(0.5, 0.5));
	this->addChild(sprite, 4);


	Vector<SpriteFrame*> allframe;

	SpriteFrame * sf1 = SpriteFrame::create("effect/boss1_explor_1.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf1);
	SpriteFrame * sf2 = SpriteFrame::create("effect/boss1_explor_2.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf2);
	SpriteFrame * sf3 = SpriteFrame::create("effect/boss1_explor_3.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf3);
	SpriteFrame * sf4 = SpriteFrame::create("effect/boss1_explor_4.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf4);
	SpriteFrame * sf5 = SpriteFrame::create("effect/boss1_explor_5.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf5);
	SpriteFrame * sf6 = SpriteFrame::create("effect/boss1_explor_6.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf6);
	SpriteFrame * sf7 = SpriteFrame::create("effect/boss1_explor_7.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf7);
	SpriteFrame * sf8 = SpriteFrame::create("effect/boss1_explor_8.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf8);
	SpriteFrame * sf9 = SpriteFrame::create("effect/boss1_explor_9.png", Rect(0, 0, 222, 298));
	allframe.pushBack(sf9);


	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);

	Action * act = Sequence::create(
		Animate::create(ani),  //����
		CCCallFuncN::create(sprite, callfuncN_selector(GameLayer_3::del)), //ɾ������
		NULL);


	sprite->runAction(act);
	allframe.clear();

}



//��������������
void GameLayer_3::scheduleOnceFOODManager_1() {
	//�ӵ��仯
	if (Food1 == 1)
	{
		//�ı��ӵ���Ϊ����
		myPlayerBulletLayer->stopBulletForPlayer();
		myPlayerBulletLayer->createBulletForPlayer(2, 0.02, 500);
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD1), 5);

	}
	else if (Food1 == 0)
	{

	}
	else if (Food1 == 2)
	{
		unschedule(schedule_selector(GameLayer_3::scheduleOnceFOOD1));
		myPlayerBulletLayer->stopBulletForPlayer();
		myPlayerBulletLayer->createBulletForPlayer(3, 0.01, 500);
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD1), 5);
	}
	else
	{
		unschedule(schedule_selector(GameLayer_3::scheduleOnceFOOD1));
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD1), 5);
	}




}

void GameLayer_3::scheduleOnceFOODManager_2() {


	//�ٶȱ仯
	if (Food2 == 1)
	{
		//�����ٶ���Ϊ����
		myPlayerLayer->speed = 2;
		fire_F(myPlayerLayer->player);
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD2), 5);

	}
	else if (Food2 == 0)
	{

	}
	else
	{
		unschedule(schedule_selector(GameLayer_3::scheduleOnceFOOD2));
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD2), 5);
	}
}
void GameLayer_3::scheduleOnceFOODManager_3() {

	//�޵�
	if (Food3 == 1)
	{
		shield_F(myPlayerLayer->player);
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD3), 3);
		Food3++;
	}
	else if (Food3 == 0)
	{

	}
	else
	{
		unschedule(schedule_selector(GameLayer_3::scheduleOnceFOOD3));
		scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceFOOD3), 3);
	}

}


void GameLayer_3::scheduleOnceFOOD1(float t) {
	myPlayerBulletLayer->stopBulletForPlayer();
	myPlayerBulletLayer->createBulletForPlayer(1, 0.2, 500);
	Food1 = 0;

}
void GameLayer_3::scheduleOnceFOOD2(float t) {

	//�ٶȻָ�
	myPlayerLayer->speed = 0.6;
	Food2 = 0;
	//��û���
	auto *fire = this->getChildByTag(212);
	//������ʧ
	fire->stopAllActions();
	//����������ʧ
	fire->removeFromParent();

}
void GameLayer_3::scheduleOnceFOOD3(float t) {

	auto *shield = this->getChildByTag(211);


	//�޵���ʧ
	unlimited = 0;
	Food3 = 0;
	//������ʧ
	shield->stopAllActions();
	//����������ʧ
	shield->removeFromParent();

}



//�л��ӵ�������
//ֱ�߷���
void GameLayer_3::enemyBulletManagerA(float t) {

	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{

		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
	


		if (nowenemy->getTag() <= 1000 && nowenemy->getTag()>500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 9, 400);
		}

		if (nowenemy->getTag() >1500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 9, 600);
		}
		if (nowenemy->getTag() >1500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 12, 400);
		}

	}


}
//�����ӵ�
void GameLayer_3::enemyBulletManagerB(float t) {

	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{


		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);


		if (nowenemy->getTag()>1000)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 10, 600);
		}

		if (nowenemy->getTag()>1000)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 11, 600);
		}
		if (nowenemy->getTag() >1500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 10, 600);
		}

		if (nowenemy->getTag() >1500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 11, 600);
		}

	
	}


}

//5��ɢ  Boos��Enemy3
void GameLayer_3::enemyBulletManagerC(float t) {

	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{


		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
		if (nowenemy->getTag() <= 500 && nowenemy->getTag()>250)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 8, 400);
		}
		if (nowenemy->getTag() <= 500 && nowenemy->getTag()>250)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 10, 400);
		}

		if (nowenemy->getTag() >1500)
		{
			myEnemyBulletLayer->newEnemyBullet(nowenemy, 9, 800);
		}


	}


}


void GameLayer_3::enemyBulletManagerD(float t) {

	for (int i = 0; i < myEnemyBulletLayer->allEnemyBullet.size(); i++)
	{

		auto nowEnemyBullet = myEnemyBulletLayer->allEnemyBullet.at(i);
		//�̻���
		if (nowEnemyBullet->getTag() == 11)
		{
			myEnemyBulletLayer->newEnemyBullet(nowEnemyBullet, 13, 200);
			myEnemyBulletLayer->newEnemyBullet(nowEnemyBullet, 14, 200);

		}

	}


}






void GameLayer_3::scheduleOnceDeath(float t) {

	//�����������
	death();

}





void GameLayer_3::scheduleBossLaser1(float t) {
	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{
		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
		if (nowenemy->getTag() > 1500)
		{  //�ر�Boss���ּ���������
			this->unschedule(schedule_selector(GameLayer_3::scheduleBossLaser1));
			//5�����������
			this->scheduleOnce(schedule_selector(GameLayer_3::scheduleBossLaser2), 5);
		}
	}


}
//��������������
void GameLayer_3::scheduleBossLaser2(float t) {

	for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
	{
		auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
		if (nowenemy->getTag() > 1500)
		{ //��������
			Laser(nowenemy);
			//5���رռ���
			this->scheduleOnce(schedule_selector(GameLayer_3::scheduleBossLaser3), 5);
		}
	}

}

void GameLayer_3::scheduleBossLaser3(float t) {
	//�رռ���
	if (this->getChildByTag(221) != NULL)
	{
		auto *laser = this->getChildByTag(221);
		laser->stopAllActions();
		laser->removeFromParent();
	}
	//����boss����������
	this->schedule(schedule_selector(GameLayer_3::scheduleBossLaser1));




}

//������ײ��������
void GameLayer_3::scheduleBossLaserShoot1(float t) {



	if (this->getChildByTag(221) != NULL)
	{
		auto player = myPlayerLayer->player;
		Rect rectPlayer(player->getPosition().x - 25, player->getPosition().y - 25, 50, 50);
		auto *laser = this->getChildByTag(221);

		for (int i = 0;i < myEnemyLayer->myEnemyStlyle->allEnemy.size();i++)
		{
			auto nowenemy = myEnemyLayer->myEnemyStlyle->allEnemy.at(i);
			if (nowenemy->getTag()>1500)
			{
				laser->setPosition(nowenemy->getPosition().x, nowenemy->getPosition().y - 460);
				Rect laserRect(nowenemy->getPosition().x - 17, nowenemy->getPosition().y - 300 - 460, 34, 600);
				if (laserRect.intersectsRect(rectPlayer))
				{
					this->unschedule(schedule_selector(GameLayer_3::scheduleBossLaserShoot1));

					//��ҿ�Ѫ	
					if (unlimited >= 1)
					{
						//�޵�Ŷ
					}
					else
					{
						//Ѫ��-4
						myPlayerLayer->blood = -4;
					}

					//0.5�����µ���
					this->scheduleOnce(schedule_selector(GameLayer_3::scheduleBossShoot2), 0.5);
				}

			}

		}

	}


}
//������ײ��Ѫ������
void GameLayer_3::scheduleBossShoot2(float t) {


	this->schedule(schedule_selector(GameLayer_3::scheduleBossLaserShoot1));



}


void  GameLayer_3::scheduleOnceWin(float t) {
	Size winSize = Director::getInstance()->getWinSize();
	auto plane = myPlayerLayer->player;
	//�رձ�������
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::getInstance()->playEffect("music/victory.wav");
	win();
	//�õ��ɻ��ĸ�
	float planeHeight = plane->getContentSize().height;

	//����Ӣ�۷ɻ����λ��
	float stopPositionX = plane->getPositionX();
	float stopPositionY = winSize.height + planeHeight / 2;

	ActionInterval *moveto = MoveTo::create(3, Vec2(stopPositionX, stopPositionY));
	auto action = EaseExponentialInOut::create(moveto);
	plane->runAction(action);
	this->scheduleOnce(CC_SCHEDULE_SELECTOR(GameLayer_3::scheduleOnceWin2), 3);
}

//��ת����
void  GameLayer_3::scheduleOnceWin2(float t) {
	
	
	auto transfer = TransitionFade::create(6, EndLayer::createScene());
	Director::getInstance()->replaceScene(transfer);


}

