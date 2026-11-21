#pragma once
#include<SFML/Audio.hpp>
#include"menu.h"
class gameSound {
public:
	sf::SoundBuffer moveBuffer, mergeBuffer, clickBuffer;
	sf::Sound moveSound, mergeSound, clickSound;

	gameSound();
	void loadSounds();
	void playMoveSound();
	void playMergeSound();
	void playClickSound();
};


