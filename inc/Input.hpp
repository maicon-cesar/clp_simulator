#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Window.hpp>


class IniParser;

class Input
{
public:
	enum Action
	{
		PAUSE,
		TAKE_SCREENSHOT,
		PANEL_UP,
		PANEL_DOWN,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		USE_LASER,
		USE_COOLER,
		USE_MISSILE,
		ENTER,
		EXIT_APP,

		COUNT 
	};

	enum Device
	{
		KEYBOARD = 1 << 1,
		JOYSTICK = 1 << 2,
		ALL      = KEYBOARD | JOYSTICK
	};

	static Input& GetInstance();

	void Init();

	Action EventToAction(const sf::Event& event);
	bool HasInput(Action action);
	void SetKeyboardBind(sf::Keyboard::Key key, Action action);
	sf::Keyboard::Key GetKeyboardBind(Action action);
	void SetJoystickBind(unsigned int joybutton, Action action);
	unsigned int GetJoystickBind(Action action);

	//static const std::wstring& ActionToString(Action action);
	
	//const std::wstring& ActionToString(Action action)
	const sf::String ActionToString(Action action);

	static const char* KeyToString(int key);
	void SetDevices(unsigned int flag);
	void AskUserInput(Device device, Action action);
	int GetSensitivity() const;
	void SetSensitivity(int sensitivity);
	void LoadFromConfig(IniParser& config);
	void SaveToConfig(IniParser& config) const;

private:
	Input() {};
	Input(const Input&);

	enum {MAX_JOY_BUTTON = 16};
	Action key_to_action_[sf::Keyboard::KeyCount];
	sf::Keyboard::Key action_to_key_[COUNT];

	Action joybutton_to_action_[MAX_JOY_BUTTON];
	unsigned int action_to_joybutton_[COUNT];

	int device_flag_;
	int sensitivity_;
};


std::istream& operator>>(std::istream& in, sf::Keyboard::Key& code);

#endif // INPUT_HPP

