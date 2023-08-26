#ifndef SOUNDSYSTEM_HPP
#define SOUNDSYSTEM_HPP

#include <string>
#include <SFML/Audio.hpp>
#include "SoundSystem.hpp"
#include "IniParser.hpp"

class SoundSystem
{
public:
	static SoundSystem& GetInstance();

	void PlayMusic(const std::string& music_name);
	void PlayMusic();
	void StopMusic();
	void PauseMusic();

	void PlaySound(const sf::SoundBuffer& soundbuffer);
	void PlaySound(const std::string& sound_name);

	void SetMusicVolume(int volume);
	inline int GetMusicVolume() const { return music_volume_; }


	void SetSoundVolume(int volume);
	inline int GetSoundVolume() const { return sound_volume_; }

	void EnableMusic(bool enabled);
	bool IsMusicEnabled() const;

	void EnableSound(bool enabled);
	bool IsSoundEnabled() const;

	void StopAll();

	void LoadFromConfig(IniParser& config);
	void SaveToConfig(IniParser& config);

private:
	SoundSystem();
	SoundSystem(const SoundSystem&);
	~SoundSystem();

	enum {MAX_SOUNDS = 20};

	sf::Sound sounds_[MAX_SOUNDS];
	int last_used_;
	sf::Music music_;
	std::string music_name_;
	int music_volume_;
	int sound_volume_;
	bool enable_music_;
	bool enable_sound_;
};

#endif // SOUNDSYSTEM_HPP
