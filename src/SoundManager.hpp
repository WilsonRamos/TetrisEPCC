#pragma once

#include <SFML/Audio.hpp>

class SoundManager
{
public:
	// Método estático para obtener la instancia única
	static SoundManager& GetInstance();

	/////////////////////////////
	void PlayMusic();
	void PauseMusic();
	void PlayLine();
	void PlayGameOver();
	void PlayNewScore();
	void Cleanup(); // Método para limpiar recursos
	~SoundManager(); // Destructor

private:
	// Constructor privado para evitar la creación de instancias fuera de la clase
	SoundManager();

	// Eliminar el constructor de copia y el operador de asignación como privados para evitar copias
	SoundManager(SoundManager&&) = delete;
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;

private:
	sf::Music music;
	sf::Sound lineSound;
	sf::Sound newScoreSound;
	sf::Sound gameOverSound;
	sf::SoundBuffer lineSoundBuffer;
	sf::SoundBuffer newScoreSoundBuffer;
	sf::SoundBuffer gameOverSoundBuffer;
};
