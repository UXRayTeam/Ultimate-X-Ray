#ifndef __XR_INPUT__
#define __XR_INPUT__

enum
{
	UXR_GAMEPAD_A = SDL_SCANCODE_COUNT,
	UXR_GAMEPAD_B,
	UXR_GAMEPAD_X,
	UXR_GAMEPAD_Y,
	UXR_GAMEPAD_BACK,
	UXR_GAMEPAD_GUIDE,
	UXR_GAMEPAD_START,
	UXR_GAMEPAD_LS_CLICK,
	UXR_GAMEPAD_RS_CLICK,
	UXR_GAMEPAD_LB,
	UXR_GAMEPAD_RB,
	UXR_GAMEPAD_DPAD_UP,
	UXR_GAMEPAD_DPAD_DOWN,
	UXR_GAMEPAD_DPAD_LEFT,
	UXR_GAMEPAD_DPAD_RIGHT,
	UXR_GAMEPAD_MICROPHONE,
	UXR_GAMEPAD_RIGHT_PADDLE1,
	UXR_GAMEPAD_LEFT_PADDLE1,
	UXR_GAMEPAD_RIGHT_PADDLE2,
	UXR_GAMEPAD_LEFT_PADDLE2,
	UXR_GAMEPAD_TOUCHPAD,
	UXR_GAMEPAD_MISC2,
	UXR_GAMEPAD_MISC3,
	UXR_GAMEPAD_MISC4,
	UXR_GAMEPAD_MISC5,
	UXR_GAMEPAD_MISC6,

	UXR_GAMEPAD_LTRIGGER,
	UXR_GAMEPAD_RTRIGGER,

	UXR_GAMEPAD_LSTICK_UP,
	UXR_GAMEPAD_LSTICK_DOWN,
	UXR_GAMEPAD_LSTICK_LEFT,
	UXR_GAMEPAD_LSTICK_RIGHT,

	UXR_GAMEPAD_RSTICK_UP,
	UXR_GAMEPAD_RSTICK_DOWN,
	UXR_GAMEPAD_RSTICK_LEFT,
	UXR_GAMEPAD_RSTICK_RIGHT,

	UXR_BUTTONS_COUNT
};

class	ENGINE_API				IInputReceiver;

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//описание класса
const int mouse_device_key		= 1;
const int keyboard_device_key	= 2;
const int all_device_key		= mouse_device_key | keyboard_device_key;
const int default_key			= mouse_device_key | keyboard_device_key ;

/// @brief \~english add your device type here if you want to support by your game...
enum class eInputDeviceType : unsigned char
{
	keyboard,
	gamepad,
	mouse,
	totalcount,
	kUnknown = std::underlying_type_t<eInputDeviceType>(-1)
};

struct CInputDevice
{
	eInputDeviceType type;
	u32 handle=u32(-1);
};

struct CInputDeviceVendorInfo
{
	char name[32];
	// use this for interpret data that you accessed when you filled vendor info
	unsigned char data[16];
	unsigned char data2[32];
	unsigned char data3[64];
};

#define DEF_XR_INPUT_MAX_INPUT_CONNECTED_MOUSE_COUNT 1
#define DEF_XR_INPUT_MAX_INPUT_CONNECTED_KEYBOARD_COUNT 1
#define DEF_XR_INPUT_MAX_INPUT_CONNECTED_GAMEPAD_COUNT 1

#define DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT (DEF_XR_INPUT_MAX_INPUT_CONNECTED_MOUSE_COUNT + DEF_XR_INPUT_MAX_INPUT_CONNECTED_KEYBOARD_COUNT + DEF_XR_INPUT_MAX_INPUT_CONNECTED_GAMEPAD_COUNT)

class ENGINE_API CInput
	:
	public pureFrame,
	public pureAppActivate,
	public pureAppDeactivate
{
public:
	enum {
		COUNT_MOUSE_BUTTONS			= 8,
		COUNT_MOUSE_AXIS			= 3,
		COUNT_KB_BUTTONS			= UXR_BUTTONS_COUNT // keyboard + gamepad
	};

	std::function<void(u32, bool)> receive_gamepad_addedorremoved;
	std::function<void(u32, bool)> receive_keyboard_addedorremoved;
	std::function<void(u32, bool)> receive_mouse_addedorremoved;

	std::function<void(int)> xrgame_sdk_input_pressed;
	std::function<void(int)> xrgame_sdk_input_released;

private:
	bool						mouseMoved = false;
	bool						mouseScrolled = false;
	char						mouseState[COUNT_MOUSE_BUTTONS] = {};
	char						KBState[COUNT_KB_BUTTONS] = {};
	int 						offs[COUNT_MOUSE_AXIS] = {};
	char						old_mouseState[COUNT_MOUSE_BUTTONS] = {};
	char						old_KBState[COUNT_KB_BUTTONS] = {};
	bool						controllerMode = false;
	bool						touchpadMode = false;
	shared_str GamepadTypeName = "xbox1";

	Fvector2 LeftAxis = { 0, 0 };
	Fvector2 RightAxis = { 0, 0 };

	Fvector2 AdaptiveTrigger = { 0, 0 };

	bool gyroscopeMoved = false;
	Fvector3 Gyroscope = {0, 0, 0};

	bool touchpadMoved = false;
	Fvector2 Touchpad = {0, 0};

	xr_vector<IInputReceiver*>	cbStack;

	void						NoInputUpdate				();
	void						MouseUpdate					();
	void						KeyboardUpdate				();
	void						GamepadUpdate				();
	void						GyroscopeUpdate				();
	void						TouchpadUpdate				();

public:
	u32							dwCurTime;
	
	void						MouseMotion					(float dx, float dy);
	void						MouseScroll					(float d);
	void						MousePressed				(int button);
	void						MouseReleased				(int button);
		
	void                        KeyboardButtonUpdate        (int scancode, bool IsPressed);
	
	void						LeftAxisUpdate				(bool IsX, float value);
	void						RightAxisUpdate				(bool IsX, float value);
	void						AdaptiveTriggerUpdate		(bool IsX, float value);
	void						GamepadGyroscopeUpdate		(Fvector3 value);
	void						TouchpadUpdate				(Fvector2 value);


	void						iCapture					( IInputReceiver *pc );
	void						iRelease					( IInputReceiver *pc );
	bool						iGetAsyncKeyState			( int dik );
	bool						iGetAsyncBtnState			( int btn );
	void						iGetLastMouseDelta			( Ivector2& p );

	CInput						( bool bExclusive = true, int deviceForInit = default_key);
	virtual ~CInput				( );

	virtual void	_BCL		OnFrame						(void);
	virtual void				OnAppActivate				(void);
	virtual void				OnAppDeactivate				(void);

	IInputReceiver*				CurrentIR					();

	/// @brief \~english returns total amount by supported devices types that defined in eInputDeviceType enum
	/// @param  
	/// @return 
	unsigned char GetConnectedInputDeviceCount(void) const noexcept;

	/// @brief \~english returns current amount of connected input device by type that defined in eInputDeviceType enum
	/// @param type 
	/// @return 
	unsigned char GetConnectedInputDeviceCount(eInputDeviceType type) const noexcept;

	void GetConnectedInputDevices(CInputDevice(&devices)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT]) noexcept;
	void GetInfoAboutConnectedInputDevices(const CInputDevice(&devices)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT], CInputDeviceVendorInfo(&infos)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT]) noexcept;
	bool GetVendorInfoAboutInputDevice(const CInputDevice* pDevice, CInputDeviceVendorInfo* pInfo) const noexcept;
	bool GetVendorInfoAboutInputDevice(const CInputDevice& device, CInputDeviceVendorInfo* pInfo) const noexcept;
	bool IsAcquire = false;

	void						unacquire();
	void						acquire();
	bool						get_dik_name(int dik, LPSTR dest, int dest_sz);

	void						feedback(u16 s1, u16 s2, float time);

	void						SetControllerMode(bool val);
	bool						GetControllerMode() { return controllerMode; }
	void SelectGamepadPrefix();
	const char* GamepadPrefix() const { return GamepadTypeName.c_str(); }

	IC void						SetTouchpadMode(bool val) { touchpadMode = val; }
	bool						GetTouchpadMode() { return touchpadMode; }

	bool LeftMouseButtonPressed();

private:
	bool FillVendorInfo(const CInputDevice& device, CInputDeviceVendorInfo& info) noexcept;
	bool GetConnectedInputKeyboards(CInputDevice(&pool)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT], unsigned char max_keyboards = DEF_XR_INPUT_MAX_INPUT_CONNECTED_KEYBOARD_COUNT) noexcept;
	bool GetConnectedInputMouses(CInputDevice(&pool)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT], unsigned char max_mouses = DEF_XR_INPUT_MAX_INPUT_CONNECTED_MOUSE_COUNT) noexcept;
	bool GetConnectedInputGamepads(CInputDevice(&pool)[DEF_XR_INPUT_MAX_INPUT_CONNECTED_DEVICES_COUNT], unsigned char max_gamepads = DEF_XR_INPUT_MAX_INPUT_CONNECTED_GAMEPAD_COUNT) noexcept;
};

extern ENGINE_API CInput *		pInput;

#endif //__XR_INPUT__
