#pragma once  
#ifndef __EnemyBulletLayer_H__  
#define __EnemyBulletLayer_H__  
#include "cocos2d.h"  
using namespace cocos2d;

class EnemyBulletLayer : public Layer
{
public:
	EnemyBulletLayer(Node * player);
	static EnemyBulletLayer* create(Node * player);

	virtual bool init();
	void removeEnemyBullet1(Node * myEnemyBullet);

	void removeEnemyBullet2(Node * myEnemyBullet);

	void removeEnemyBullet3(Node * myEnemyBullet);
	void removeEnemyBullet4(Node * myEnemyBullet);
	void removeEnemyBullet5(Node * myEnemyBullet);
	void removeEnemyBullet6(Node * myEnemyBullet);
	void removeEnemyBullet7(Node * myEnemyBullet);
	void removeEnemyBullet8(Node * myEnemyBullet);
	void removeEnemyBullet9(Node * myEnemyBullet);
	void removeEnemyBullet10(Node * myEnemyBullet);
	void removeEnemyBullet11(Node * myEnemyBullet);
	void removeEnemyBullet12(Node * myEnemyBullet);
	
	void newEnemyBullet(Node * oB,int type,float flyVelocity);

	void newEnemyBulletB(Node * oB, int type, float flyVelocity);
	
	void removeEnemyBullet(Node* myEnemyBullet);
	
	
	Node * oB;//���������
	Node * player;//�����������
	int type;//EnemyBullet������

	SpriteBatchNode* bulletBatchNode1; //�ӵ���Ⱦ�ڵ�
	SpriteBatchNode* bulletBatchNode2;
	SpriteBatchNode* bulletBatchNode3;
	SpriteBatchNode* bulletBatchNode4;
	SpriteBatchNode* bulletBatchNode5;
	SpriteBatchNode* bulletBatchNode6;
	SpriteBatchNode* bulletBatchNode7;
	SpriteBatchNode* bulletBatchNode8;
	SpriteBatchNode* bulletBatchNode9;
	SpriteBatchNode* bulletBatchNode10;
	SpriteBatchNode* bulletBatchNode11;
	SpriteBatchNode* bulletBatchNode12;

	Vector<Sprite *> allEnemyBullet;//���ڵ�����ʹ�õл��ӵ�
};
#endif
