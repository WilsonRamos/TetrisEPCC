#include "SoundManager.hpp"

#include <mutex>
#include <memory>
#include <thread>
#include <iostream>

static std::mutex mtx;

SoundManager::SoundManager()
	: lineSound(), newScoreSound(), gameOverSound()
{
	music.openFromFile("res/sound/music.ogg");
	music.setLoop(true);
	music.setVolume(20);

	if (!lineSoundBuffer.loadFromFile("res/sound/line.ogg"))
	{
		std::cerr << "Error al cargar sonido" << std::endl;
	}
	if (!newScoreSoundBuffer.loadFromFile("res/sound/newScore.ogg"))
	{
		std::cerr << "Error al cargar sonido" << std::endl;
	}
	if (!gameOverSoundBuffer.loadFromFile("res/sound/gameOver.ogg"))
	{
		std::cerr << "Error al cargar sonido" << std::endl;
	}

	lineSound.setBuffer(lineSoundBuffer);
	newScoreSound.setBuffer(newScoreSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

// Implementación del método getInstance
SoundManager &SoundManager::GetInstance()
{
	static std::unique_ptr<SoundManager> instance(new SoundManager());
	return *instance;
}

void SoundManager::PlayMusic()
{
	std::thread([this]()
				{
        std::lock_guard<std::mutex> lock(mtx);
        music.play(); })
		.detach();
}

void SoundManager::PauseMusic()
{
	std::thread([this]()
				{
        std::lock_guard<std::mutex> lock(mtx);
        music.pause(); })
		.detach();
}

void SoundManager::PlayLine()
{
	std::thread([this]()
				{
        std::lock_guard<std::mutex> lock(mtx);
        lineSound.play(); })
		.detach();
}

void SoundManager::PlayNewScore()
{
	std::thread([this]()
				{
        std::lock_guard<std::mutex> lock(mtx);
        newScoreSound.play(); })
		.detach();
}

void SoundManager::PlayGameOver()
{
}

void SoundManager::Cleanup()
{
	music.stop();
	lineSound.stop();
	newScoreSound.stop();
	gameOverSound.stop();
	// Libera cualquier otro recurso si es necesario
}
std::thread([this]()
			{
        std::lock_guard<std::mutex> lock(mtx);
        gameOverSound.play(); })
	.detach();
SoundManager::~SoundManager()
{
	Cleanup(); // Asegúrate de limpiar recursos
}
