#ifndef _Player_Layer_H__
#define _Player_Layer_H__

#include "cocos2d.h"


using namespace cocos2d;

class PlayerLayer : public Layer
{
public:

	//��ʼ��
	CREATE_FUNC(PlayerLayer);
	virtual bool init();

	void shootNuclear();

	void removeNuclearWeapon(Node * myEnemyBullet);

public:
	//��ҷɻ�
	Node * player;

	//Ѫ����������
	void scheduleenergy(float t);
	void scheduleblood(float t);



	//���̼�����
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	//���̵�����
	void leftArrow(float t);
	void upArrow(float t);
	void downArrow(float t);
	void rightArrow(float t);



public:
	//���Ѫ��
	float life = 20;
	//�ٶ�
	double speed = 0.5;
	//Ѫ���ж�ֵ
	int blood;
	//�����ж�ֵ
	int energy;
	//�˵��ж�
	int nuclear = 0;


};

#endif // _Player_Layer_H__
