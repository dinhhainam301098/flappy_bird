
#include "Bird.h"
#include "Definitions.h"
//#include "Define.h"
USING_NS_CC;
Bird::Bird(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	flappyBird = Sprite::create("iphonehd/Ball.png");
	flappyBird->setPosition(Point(visibleSize.width/2  + origin.x, visibleSize.height/2+origin.y));

	auto flappyBody = PhysicsBody::createCircle(flappyBird->getContentSize().width/2);
	flappyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	flappyBody->setContactTestBitmask(true);
	flappyBird->setPhysicsBody(flappyBody);
	layer->addChild(flappyBird, 100);
}




  