#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(unsigned int index, unsigned int numFrames, unsigned int animSpeed)
	:
	index(index),
	numFrames(numFrames),
	animSpeed(animSpeed)
{
}
