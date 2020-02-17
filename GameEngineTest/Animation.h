#pragma once


class Animation
{
public:
	unsigned int index;
	unsigned int numFrames;
	unsigned int animSpeed;
	Animation();
	Animation(unsigned int index, unsigned int numFrames, unsigned int animSpeed);
};