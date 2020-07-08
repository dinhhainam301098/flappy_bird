#include "SplashScene.h"
#include "Pipe.h"
#include "Definitions.h"
//#include "Define.h"
USING_NS_CC;
Pipe::Pipe()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe::spawnPipe(cocos2d::Layer *layer)
{
	CCLOG("SPAWN PIPE");
	auto topPipe = Sprite::create("iphone/pipe.png");
	auto bottomPipe = Sprite::create("iphone/pipe.png");

	auto topPippeBody = PhysicsBody::createBox(topPipe->getContentSize());
	auto bottomPippeBody = PhysicsBody::createBox(bottomPipe->getContentSize());
	
	auto random = CCRANDOM_0_1();
	if (random < LOWER_SCREEN_PIPE_THRESHOLD)
	{
		random = LOWER_SCREEN_PIPE_THRESHOLD;
	}
	else if (random>UPPER_SCREEN_PIPE_THRESHOLD)
	{
		random = UPPER_SCREEN_PIPE_THRESHOLD;
	}
	auto topPipePosition = (random *visibleSize.height) + (topPipe->getContentSize().height / 2); 
	topPippeBody->setDynamic(false);
	bottomPippeBody->setDynamic(false);

	topPippeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	bottomPippeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	topPippeBody->setContactTestBitmask(true);
	bottomPippeBody->setContactTestBitmask(true);
	
	topPipe->setPhysicsBody(topPippeBody);
	bottomPipe->setPhysicsBody(bottomPippeBody);
	topPipe->setPosition(Point(visibleSize.width + topPipe->getContentSize().width+origin.x ,topPipePosition));
	

	bottomPipe->setPosition(Point(topPipe->getPositionX(),topPipePosition - (Sprite::create("iphonehd/Ball.png")->getContentSize().height*PIPE_GAP)-topPipe->getContentSize().height));
	layer->addChild(topPipe);
	layer->addChild(bottomPipe);
	auto topPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto bottomPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	topPipe->runAction(topPipeAction);
	bottomPipe->runAction(bottomPipeAction);
}



  