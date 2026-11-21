#include"sound.h"
gameSound::gameSound() :
	moveSound(moveBuffer),
	mergeSound(mergeBuffer),
	clickSound(clickBuffer) {
}
void gameSound::loadSounds()
{
	(void)moveBuffer.loadFromFile("move.wav");
	(void)mergeBuffer.loadFromFile("merge.wav");
	(void)clickBuffer.loadFromFile("click.wav");
}

void gameSound::playMoveSound()
{
	if(sound)
		moveSound.play();
}
void gameSound::playMergeSound()
{
	if (sound)
		mergeSound.play();
}
void gameSound::playClickSound()
{
	if (sound)
		clickSound.play();
}
