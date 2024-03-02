// based on UEFI spec 2.10 (https://uefi.org/sites/default/files/resources/UEFI_Spec_2_10_Aug29.pdf)
// and EFI specification 1.10 Update -001 (https://www.intel.com/content/www/us/en/architecture-and-technology/unified-extensible-firmware-interface/efi-specifications-general-technology.html)

#define IN
#define OUT
#define OPTIONAL
#define EFIAPI

typedef signed __int8  INT8;
typedef signed __int16 INT16;
typedef signed __int32 INT32;
typedef signed __int64 INT64;

typedef unsigned __int8  UINT8;
typedef unsigned __int16 UINT16;
typedef unsigned __int32 UINT32;
typedef unsigned __int64 UINT64;

typedef signed __int64 INTN;
typedef unsigned __int64 UINTN;

typedef UINT8 BOOLEAN;
#define TRUE 1
#define FALSE 0

typedef UINT8 CHAR8;
typedef UINT16 CHAR16;

typedef void* EFI_HANDLE;
typedef void* EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;
typedef void* EFI_EVENT;
typedef UINT64 EFI_VIRTUAL_ADDRESS;
typedef UINT64 EFI_PHYSICAL_ADDRESS;

typedef UINTN EFI_STATUS;

#define EFI_STATUS_CODE(CODE, MSG) CODE

#define EFI_SUCCESS EFI_STATUS_CODE(0, "The operation completed successfully.")

#define EFI_WARN_UNKNOWN_GLYPH    EFI_STATUS_CODE(1, "The string contained one or more characters that the device could not render and were skipped.")
#define EFI_WARN_DELETE_FAILURE   EFI_STATUS_CODE(2, "The handle was closed, but the file was not deleted.")
#define EFI_WARN_WRITE_FAILURE    EFI_STATUS_CODE(3, "The handle was closed, but the data to the file was not flushed properly.")
#define EFI_WARN_BUFFER_TOO_SMALL EFI_STATUS_CODE(4, "The resulting buffer was too small, and the data was truncated to the buffer size.")
#define EFI_WARN_STALE_DATA       EFI_STATUS_CODE(5, "The data has not been updated within the timeframe set by local policy for this type of data.")
#define EFI_WARN_FILE_SYSTEM      EFI_STATUS_CODE(6, "The resulting buffer contains UEFI-compliant file system.")
#define EFI_WARN_RESET_REQUIRED   EFI_STATUS_CODE(7, "The operation will be processed across a system reset.")

#define EFI_LOAD_ERROR           EFI_STATUS_CODE((1ULL << 63) | 1, "The image failed to load.")
#define EFI_INVALID_PARAMETER    EFI_STATUS_CODE((1ULL << 63) | 2, "A parameter was incorrect.")
#define EFI_UNSUPPORTED          EFI_STATUS_CODE((1ULL << 63) | 3, "The operation is not supported.")
#define EFI_BAD_BUFFER_SIZE      EFI_STATUS_CODE((1ULL << 63) | 4, "The buffer was not the proper size for the request.")
#define EFI_BUFFER_TOO_SMALL     EFI_STATUS_CODE((1ULL << 63) | 5, "The buffer is not large enough to hold the requested data. The required buffer size is returned in the appropriate parameter when this error occurs.")
#define EFI_NOT_READY            EFI_STATUS_CODE((1ULL << 63) | 6, "There is no data pending upon return.")
#define EFI_DEVICE_ERROR         EFI_STATUS_CODE((1ULL << 63) | 7, "The physical device reported an error while attempting the operation.")
#define EFI_WRITE_PROTECTED      EFI_STATUS_CODE((1ULL << 63) | 8, "The device cannot be written to.")
#define EFI_OUT_OF_RESOURCES     EFI_STATUS_CODE((1ULL << 63) | 9, "A resource has run out.")
#define EFI_VOLUME_CORRUPTED     EFI_STATUS_CODE((1ULL << 63) | 10, "An inconstancy was detected on the file system causing the operating to fail.")
#define EFI_VOLUME_FULL          EFI_STATUS_CODE((1ULL << 63) | 11, "There is no more space on the file system.")
#define EFI_NO_MEDIA             EFI_STATUS_CODE((1ULL << 63) | 12, "The device does not contain any medium to perform the operation.")
#define EFI_MEDIA_CHANGED        EFI_STATUS_CODE((1ULL << 63) | 13, "The medium in the device has changed since the last access.")
#define EFI_NOT_FOUND            EFI_STATUS_CODE((1ULL << 63) | 14, "The item was not found.")
#define EFI_ACCESS_DENIED        EFI_STATUS_CODE((1ULL << 63) | 15, "Access was denied.")
#define EFI_NO_RESPONSE          EFI_STATUS_CODE((1ULL << 63) | 16, "The server was not found or did not respond to the request.")
#define EFI_NO_MAPPING           EFI_STATUS_CODE((1ULL << 63) | 17, "A mapping to a device does not exist.")
#define EFI_TIMEOUT              EFI_STATUS_CODE((1ULL << 63) | 18, "The timeout time expired.")
#define EFI_NOT_STARTED          EFI_STATUS_CODE((1ULL << 63) | 19, "The protocol has not been started.")
#define EFI_ALREADY_STARTED      EFI_STATUS_CODE((1ULL << 63) | 20, "The protocol has already been started.")
#define EFI_ABORTED              EFI_STATUS_CODE((1ULL << 63) | 21, "The operation was aborted.")
#define EFI_ICMP_ERROR           EFI_STATUS_CODE((1ULL << 63) | 22, "An ICMP error occurred during the network operation.")
#define EFI_TFTP_ERROR           EFI_STATUS_CODE((1ULL << 63) | 23, "A TFTP error occurred during the network operation.")
#define EFI_PROTOCOL_ERROR       EFI_STATUS_CODE((1ULL << 63) | 24, "A protocol error occurred during the network operation.")
#define EFI_INCOMPATIBLE_VERSION EFI_STATUS_CODE((1ULL << 63) | 25, "The function encountered an internal version that was incompatible with a version requested by the caller.")
#define EFI_SECURITY_VIOLATION   EFI_STATUS_CODE((1ULL << 63) | 26, "The function was not performed due to a security violation.")
#define EFI_CRC_ERROR            EFI_STATUS_CODE((1ULL << 63) | 27, "A CRC error was detected.")
#define EFI_END_OF_MEDIA         EFI_STATUS_CODE((1ULL << 63) | 28, "Beginning or end of media was reached")
#define EFI_END_OF_FILE          EFI_STATUS_CODE((1ULL << 63) | 31, "The end of the file was reached.")
#define EFI_INVALID_LANGUAGE     EFI_STATUS_CODE((1ULL << 63) | 32, "The language specified was invalid.")
#define EFI_COMPROMISED_DATA     EFI_STATUS_CODE((1ULL << 63) | 33, "The security status of the data is unknown or compromised and the data must be updated or replaced to restore a valid security status.")
#define EFI_IP_ADDRESS_CONFLICT  EFI_STATUS_CODE((1ULL << 63) | 34, "There is an address conflict address allocation.")
#define EFI_HTTP_ERROR           EFI_STATUS_CODE((1ULL << 63) | 35, "A HTTP error occurred during the network operation.")

typedef struct EFI_MAC_ADDRESS
{
	UINT8 octets[32];
} EFI_MAC_ADDRESS;

typedef struct EFI_IPV4_ADDRESS
{
	UINT8 octets[4];
} EFI_IPV4_ADDRESS;

typedef struct EFI_IPV6_ADDRESS
{
	UINT8 octets[16];
} EFI_IPV6_ADDRESS;

typedef struct EFI_TABLE_HEADER {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

// -----------------------------------------------------------------------------------------------------------------
//                                            Simple Text Input Protocol
// -----------------------------------------------------------------------------------------------------------------

// Clear input queues
// Error codes
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_INPUT_RESET) (IN struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This, IN BOOLEAN ExtendedVerification);

typedef struct EFI_INPUT_KEY {
	UINT16 ScanCode;
	CHAR16 UnicodeChar; // if != 0 input is printable and this is the character code, if == 0 input is a special key (e.g. left arrow)
} EFI_INPUT_KEY;
enum
{
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Null           = 0x00,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_UpArrow        = 0x01,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_DownArrow      = 0x02,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_RIghtArrow     = 0x03,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_LeftArrow      = 0x04,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Home           = 0x05,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_End            = 0x06,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Insert         = 0x07,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Delete         = 0x08,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_PageUp         = 0x09,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_PageDown       = 0x0a,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function1      = 0x0b,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function2      = 0x0c,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function3      = 0x0d,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function4      = 0x0e,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function5      = 0x0f,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function6      = 0x10,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function7      = 0x11,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function8      = 0x12,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function9      = 0x13,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function10     = 0x14,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Escape         = 0x17,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function11     = 0x15,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function12     = 0x16,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Pause          = 0x48,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function13     = 0x68,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function14     = 0x69,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function15     = 0x6A,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function16     = 0x6B,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function17     = 0x6C,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function18     = 0x6D,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function19     = 0x6E,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function20     = 0x6F,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function21     = 0x70,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function22     = 0x71,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function23     = 0x72,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Function24     = 0x73,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Mute           = 0x7F,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_VolumeUp       = 0x80,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_VolumeDown     = 0x81,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_BrightnessUp   = 0x100,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_BrightnessDown = 0x101,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Suspend        = 0x102,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Hibernate      = 0x103,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Toggle         = 0x104,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Recovery       = 0x105,
	EFI_SIMPLE_TEXT_INPUT_SCAN_CODE_Eject          = 0x106,
	// 0x8000-0xFFFF	OEM Reserved
};

// Error codes
// - EFI_NOT_READY: no keystroke data was available
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: device does not support reading keystrokes
typedef EFI_STATUS (EFIAPI* EFI_INPUT_READ_KEY) (IN struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This, OUT EFI_INPUT_KEY* Key);

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// -----------------------------------------------------------------------------------------------------------------
//                                            Simple Text Output Protocol
// -----------------------------------------------------------------------------------------------------------------

typedef struct SIMPLE_TEXT_OUTPUT_MODE {
	INT32 MaxMode;

	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorRow;
	BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

// Reset output device, set cursor to (0, 0) and clear screen with default background color
// Error codes
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_TEXT_RESET) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN BOOLEAN ExtendedVerification);

// Write string at cursor and advance cursor according to the following rules
// Null            0x0 ignore, do not move cursor
// Backspace       0x8 move cursor left if not at leftmost edge of screen
// Linefeed        0xA move cursor down one row if cursor is not at bottom of screen, else scroll display one row with cursor unchanged
// Carriage Return 0xD move the cursor to the beginning of the current row
// else                print char and move cursor one right, wrap to next line when going past screen edge, scroll if needed
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: the device's mode is currently not in a defined text mode
// - EFI_WARN_UNKNOWN_GLYPH: some characters were not rendered and instead skipped
typedef EFI_STATUS (EFIAPI *EFI_TEXT_STRING) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN CHAR16* String);

#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250c
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251c
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252c
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253c
#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255a
#define BOXDRAW_UP_LEFT_DOUBLE 0x255b
#define BOXDRAW_UP_DOUBLE_LEFT 0x255c
#define BOXDRAW_DOUBLE_UP_LEFT 0x255d
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c
#define BLOCKELEMENT_FULL_BLOCK 0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591
#define GEOMETRICSHAPE_UP_TRIANGLE 0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25c4
#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

// Verify all characters in a string can be rendered
// Error codes
// - EFI_UNSUPPORTED: some character cannot be rendered
typedef EFI_STATUS (EFIAPI* EFI_TEXT_TEST_STRING) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN CHAR16* String);

// Return information about a text mode
// - Columns, Rows: screen dimensions for the requested mode
// All devices support mode 0 (80x25), some support mode 1 (80x50), modes 2- are device depdendent
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: mode number is not valid
typedef EFI_STATUS (EFIAPI* EFI_TEXT_QUERY_MODE) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN UINTN ModeNumber, OUT UINTN* Columns, OUT UINTN* Rows);

// Attempts to set the device's text output mode to the specied mode, on success clear background color and set cursor to (0, 0)
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: invalid mode number
typedef EFI_STATUS (EFIAPI* EFI_TEXT_SET_MODE) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN UINTN ModeNumber);

// Set background and foreground color for OutputString and ClearScreen
// - Attribute: bits lowest nibble is foreground color, first 3 bits of highest nibble is background color
// Error codes
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_TEXT_SET_ATTRIBUTE) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN UINTN Attribute);
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70

// Clear the screen to the set background color and reset cursor position to (0, 0)
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: output device is not in a valid text mode
typedef EFI_STATUS (EFIAPI* EFI_TEXT_CLEAR_SCREEN) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This);

// Set cursor to specified position, upper left is (0, 0)
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: the output device is not in a vlid text mode, or the specified position is invalid
typedef EFI_STATUS (EFIAPI* EFI_TEXT_SET_CURSOR_POSITION) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN UINTN Column, IN UINTN Row);

// Set visibility of cursor
// Error codes
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: output device does not support setting visibility
typedef EFI_STATUS (EFIAPI* EFI_TEXT_ENABLE_CURSOR) (IN struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN BOOLEAN Visible);

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
	EFI_TEXT_TEST_STRING TestString;
	EFI_TEXT_QUERY_MODE QueryMode;
	EFI_TEXT_SET_MODE SetMode;
	EFI_TEXT_SET_ATTRIBUTE SetAttribute;
	EFI_TEXT_CLEAR_SCREEN ClearScreen;
	EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
	EFI_TEXT_ENABLE_CURSOR EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE* Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// -----------------------------------------------------------------------------------------------------------------
//                                               Time Services
// -----------------------------------------------------------------------------------------------------------------

// Rules for calling runtime services
// All services may be called with interupts enabled (interupts will be temporarily disabled if needed by the service)
// The same service, or certain other services, may not be called before a service is completed or while it is running on
// another processor. The table below shows which services are forbidden when another service is still not completed
// due to being interrupted or running on another processor.
// +--------------------------------+--------------------------------+
// | If previous call is busy in    | Forbidden to call              |
// +--------------------------------+--------------------------------+
// | Any                            | SetVirtualAddressMap()         |
// +--------------------------------+--------------------------------+
// | ConvertPointer()               | ConvertPointer()               |
// +--------------------------------+--------------------------------+
// | SetVariable()                  | ResetSystem()                  |
// | UpdateCapsule()                |                                |
// | SetTime()                      |                                |
// | SetWakeupTime()                |                                |
// | GetNextHighMonotonicCount()    |                                |
// +--------------------------------+--------------------------------+
// | GetVariable()                  | GetVariable()                  |
// | GetNextVariableName()          | GetNextVariableName()          |
// | SetVariable()                  | SetVariable()                  |
// | QueryVariableInfo()            | QueryVariableInfo()            |
// | UpdateCapsule()                | UpdateCapsule()                |
// | QueryCapsuleCapabilities()     | QueryCapsuleCapabilities()     |
// | GetNextHighMonotonicCount()    | GetNextHighMonotonicCount()    |
// +--------------------------------+--------------------------------+
// | GetTime()                      | GetTime()                      |
// | SetTime()                      | SetTime()                      |
// | GetWakeupTime()                | GetWakeupTime()                |
// | SetWakeupTime()                | SetWakeupTime()                |
// +--------------------------------+--------------------------------+

// Values for EFI_TIME.Daylight
#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02

// Values for EFI_TIME.Timezone
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

typedef struct EFI_TIME {
	UINT16 Year;       // 1998 – 20XX
	UINT8 Month;       // 1 – 12
	UINT8 Day;         // 1 – 31
	UINT8 Hour;        // 0 – 23
	UINT8 Minute;      // 0 – 59
	UINT8 Second;      // 0 – 59
	UINT8 Pad1;
	UINT32 Nanosecond; // 0 – 999,999,999
	INT16 TimeZone;    // time offset in minuts from GMT, -1440 to 1440 or EFI_UNSPECIFIED_TIMEZONE (uses local time)
	UINT8 Daylight;    // EFI_TIME_ADJUST_DAYLIGHT states time should be adjusted for daylight savings, EFI_TIME_IN_DAYLIGHT say it is adjusted
	UINT8 Pad2;
} EFI_TIME;

typedef struct EFI_TIME_CAPABILITIES {
	UINT32 Resolution;  // resolution of clock in counts per second
	UINT32 Accuracy;    // error in parts per million, an error of 50 parts per million gives an accuracy of 50_000_000
	BOOLEAN SetsToZero; // clear time below resolution (per second resolution clears nanoseconds, usually FALSE)
} EFI_TIME_CAPABILITIES;

// Get current time and time-keeping capabilities
// - Time: Daylight and TimeZone are not kept by the clock hardware and is set to the values they got from a previous call to SetTime
// At runtime access must be synchronized before calling GetTime
// Error codes
// - EFI_INVALID_PARAMETER: Time is NULL
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_GET_TIME) (OUT EFI_TIME* Time, OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL);

// Set the current time, time zone and daylight savings settings
// Access to SetTime must be synchronized during runtime
// Error codes
// - EFI_INVALID_PARAMETER: returned if any of the values in Time do not satisfy the constrainst listed in the struct definition
typedef EFI_STATUS (EFIAPI* EFI_SET_TIME) (IN EFI_TIME* Time);

// Return current wakeup alarm clock setting
// - Enabled: if alarm is enabled
// - Pending: indicates if an alarm signal is pending and requires acknowledgement
// Access must be synchronized during runtime
// Error codes
// - EFI_INVALID_PARAMETER: if any parameter is NULL
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: wakeup timers are not supported
typedef EFI_STATUS (EFIAPI* EFI_GET_WAKEUP_TIME) (OUT BOOLEAN* Enabled, OUT BOOLEAN* Pending, OUT EFI_TIME* Time);

// Set system wakeup alarm time
// - Time: ignored if Enable is false
// Causes system to wake/power up on set time. Alarm is latched until acknoledged by diabling the alarm with a call to SetWakeupTime.
// Access must be synchronized at runtime
// Error codes
// - EFI_INVALID_PARAMETER: Time is out of range
// - EFI_DEVICE_ERROR
// - EFI_UNSUPPORTED: wakup timers are not supported
typedef EFI_STATUS (EFIAPI* EFI_SET_WAKEUP_TIME) (IN BOOLEAN Enable, IN EFI_TIME* Time OPTIONAL);

// -----------------------------------------------------------------------------------------------------------------
//                                            Virtual Memory Services
// -----------------------------------------------------------------------------------------------------------------

// May only be called at runtime (i.e. after boot service exit)
// TODO TODO TODO
typedef EFI_STATUS (EFIAPI* EFI_SET_VIRTUAL_ADDRESS_MAP) (IN UINTN MemoryMapSize, IN UINTN DescriptorSize, IN UINT32 DescriptorVersion, IN struct EFI_MEMORY_DESCRIPTOR* VirtualMap);

// TODO: EFI_CONVERT_POINTER
// TODO TODO TODO
typedef EFI_STATUS (EFIAPI* EFI_CONVERT_POINTER) (IN UINTN DebugDisposition, IN void** Address);

// -----------------------------------------------------------------------------------------------------------------
//                                            Variable Services
// -----------------------------------------------------------------------------------------------------------------

typedef struct {
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

#define EFI_VARIABLE_NON_VOLATILE       1ULL
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 2ULL
// NOTE: EFI_VARIABLE_BOOTSERVICE_ACCESS must be present when EFI_VARIABLE_RUNTIME_ACCESS is used
#define EFI_VARIABLE_RUNTIME_ACCESS     4ULL

// Get variable by name and usage attributes
// Error codes
// - EFI_NOT_FOUND
// - EFI_BUFFER_TOO_SMALL
// - EFI_INVALID_PARAMETER: any parameter except Attributes is NULL
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_GET_VARIABLE) (IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, OUT UINT32* Attributes OPTIONAL, IN OUT UINTN* DataSize, OUT void* Data);

// Enumerate current variable names
// - VariableNameSize, VariableName: the previous values set by the function, initialize VariableName to a zero length string to start search.
//                     EFI_NOT_FOUND is returned on search end.  On EFI_BUFFER_TOO_SMALL VariableNameSize is set to the
//                     buffer size needed. Passing a VariableName that is not a zero length null terminated string or a previous result
//                     may lead to UB, and calls to SetVariable between calls to GetNextVariableName may also lead to UB.
// Error codes
// - EFI_NOT_FOUND: next variable was not found, returned on search end
// - EFI_BUFFER_TOO_SMALL: variableName buffer was too small, VariableNameSize is updated to needed buffer size
// - EFI_INVALID_PARAMETER: any parameter is NULL
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_GET_NEXT_VARIABLE_NAME) (IN OUT UINTN* VariableNameSize, IN OUT CHAR16* VariableName, IN OUT EFI_GUID* VendorGuid);

// Set value of variable
// when setting the same variable multiple times the same attributes must be used, otherwise UB. Changing attributes is
// done by deleting the varaible and creating a new one. Deleting a variable can be done by setting DataSize and Attributes
// to 0 (the used space might be unavailable until power cycling).
// Error codes
// - EFI_INVALID_PARAMETER: invalid Attributes or DataSize is greater than maximum allowed
// - EFI_INVALID_PARAMETER: VariableName is an empty string
// - EFI_OUT_OF_RESOURCES
// - EFI_DEVICE_ERROR
typedef EFI_STATUS (EFIAPI* EFI_SET_VARIABLE) (IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN void* Data);

// -----------------------------------------------------------------------------------------------------------------
//                                               Misc Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: EFI_GET_NEXT_HIGH_MONO_COUNT
typedef void* EFI_GET_NEXT_HIGH_MONO_COUNT;
// TODO: EFI_RESET_SYSTEM
typedef void* EFI_RESET_SYSTEM;

// -----------------------------------------------------------------------------------------------------------------
//                                              Capsule Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: EFI_UPDATE_CAPSULE
typedef void* EFI_UPDATE_CAPSULE;
// TODO: EFI_QUERY_CAPSULE_CAPABILITIES
typedef void* EFI_QUERY_CAPSULE_CAPABILITIES;

// -----------------------------------------------------------------------------------------------------------------
//                                           Misc UEFI 2.0 Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: EFI_QUERY_VARIABLE_INFO
typedef void* EFI_QUERY_VARIABLE_INFO;

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION
typedef struct EFI_RUNTIME_SERVICES {
	EFI_TABLE_HEADER Hdr;

	// Time Services
	EFI_GET_TIME GetTime;
	EFI_SET_TIME SetTime;
	EFI_GET_WAKEUP_TIME GetWakeupTime;
	EFI_SET_WAKEUP_TIME SetWakeupTime;

	// Virtual Memory Services
	EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
	EFI_CONVERT_POINTER ConvertPointer;

	// Variable Services
	EFI_GET_VARIABLE GetVariable;
	EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
	EFI_SET_VARIABLE SetVariable;

	// Miscellaneous Services
	EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;

	// UEFI 2.0 Capsule Services
	EFI_UPDATE_CAPSULE UpdateCapsule;
	EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

	// Miscellaneous UEFI 2.0 Service
	EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

// -----------------------------------------------------------------------------------------------------------------
//                                            Task Priority Services
// -----------------------------------------------------------------------------------------------------------------

#define TPL_APPLICATION 4
#define TPL_CALLBACK    8
#define TPL_NOTIFY     16
#define TPL_HIGH_LEVEL 31
// Set new (greater or equal) task priority level
// - NewTpl: the new task priority level to use, must be greater than or equal to the last
// - Returns: previous task level
typedef EFI_TPL (EFIAPI* EFI_RAISE_TPL) (IN EFI_TPL NewTpl);

// Restores task priority level to previous level
typedef void (EFIAPI* EFI_RESTORE_TPL) (IN EFI_TPL OldTpl);

// -----------------------------------------------------------------------------------------------------------------
//                                              Memory Services
// -----------------------------------------------------------------------------------------------------------------

// NOTE: Memory usage before ExitBootServices
// +----------------------------+----------------------------------------------------------------------------------+
// | Mnemonic                   | Description                                                                      |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiReservedMemoryType      | Not used                                                                         |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiLoaderCode              | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiLoaderData              | Pages used for EFI loader data and default pool allocation                       |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiBootServicesCode        | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiBootServicesData        | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiRuntimeServicesCode     | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiRuntimeServicesData     | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiConventionalMemory      | Free unallocated memory                                                          |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiUnusableMemory          | Memory where errors have been detected and are therefore unusable                |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiACPIReclaimMemory       | Memory for ACPI tables                                                           |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiACPIMemoryNVS           | Address space reserved for firmware                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiMemoryMappedIO          | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiMemoryMappedIOPortSpace | Used to translate memory cycles to IO cycles                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiPalCode                 | Reserved for processor firmware                                                  |
// +----------------------------+----------------------------------------------------------------------------------+

// NOTE: Memory usage after ExitBootServices
// +----------------------------+----------------------------------------------------------------------------------+
// | Mnemonic                   | Description                                                                      |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiReservedMemoryType      | Not used.                                                                        |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiLoaderCode              | ---                                                                              |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiLoaderData              | Pages used for EFI loader data and default pool allocation                       |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiBootServicesCode        | Available for general use                                                        |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiBootServicesData        | Available for general use                                                        |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiRuntimeServicesCode     | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiRuntimeServicesData     | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiConventionalMemory      | Available for general use                                                        |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiUnusableMemory          | Memory where errors have been detected and are therefore unusable                |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiACPIReclaimMemory       | Do not touch until ACPI is enabled. Afterwards available for general use         |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiACPIMemoryNVS           | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiMemoryMappedIO          | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiMemoryMappedIOPortSpace | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+
// | EfiPalCode                 | Do not touch                                                                     |
// +----------------------------+----------------------------------------------------------------------------------+

typedef enum EFI_MEMORY_TYPE {
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef enum EFI_ALLOCATE_TYPE {
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
} EFI_ALLOCATE_TYPE;

// - Type: restrictions on page placement
// - Pages: number of contiguous 4k pages to allocate
// - Memory: placement hint and out parameter
// Error codes
// - EFI_OUT_OF_RESOURCES
// - EFI_INVALID_PARAMETER: Type is not a valid EFI_ALLOCATE_TYPE or MemoryType is not a valid EFI_MEMORY_TYPE
// - EFI_NOT_FOUND: requested pages could not be found
typedef EFI_STATUS (EFIAPI* EFI_ALLOCATE_PAGES) (IN EFI_ALLOCATE_TYPE Type, IN EFI_MEMORY_TYPE MemoryType, IN UINTN Pages, IN OUT EFI_PHYSICAL_ADDRESS* Memory);

// - Memory: 4k page aligned address
// - Pages: number of 4k pages to free
// Error codes
// - EFI_NOT_FOUND: target pages were not allocated with AllocatePages and cannot be freed by FreePages
// - EFI_INVALID_PARAMETER: Memory is not page aligned
typedef EFI_STATUS (EFIAPI* EFI_FREE_PAGES) (IN EFI_PHYSICAL_ADDRESS Memory, IN UINTN Pages);

// NOTE: EFI_MEMORY_DESCRIPTOR Attributes
// Supports being configured as not cachable
#define EFI_MEMORY_UC      0x0000000000000001

// Supports being configured as write combining
#define EFI_MEMORY_WC      0x0000000000000002

// Supports being configured as write through
#define EFI_MEMORY_WT      0x0000000000000004

// Supports being configured as write back
#define EFI_MEMORY_WB      0x0000000000000008

// Supports being configured as not cacheable, exported, and supports the fetch and add semaphore mechanism
#define EFI_MEMORY_UCE     0x0000000000000010

// Supports being configured as write protected
#define EFI_MEMORY_WP      0x0000000000001000

// Supports being configured as read protected
#define EFI_MEMORY_RP      0x0000000000002000

// Supports being configured as execute protected
#define EFI_MEMORY_XP      0x0000000000004000

// Memory region must be given a virtual mapping by the OS
#define EFI_MEMORY_RUNTIME 0x8000000000000000

#define EFI_MEMORY_DESCRIPTOR_VERSION 1
typedef struct EFI_MEMORY_DESCRIPTOR {
	UINT32 Type; // EFI_MEMORY_TYPE
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute; // defined immediately above
} EFI_MEMORY_DESCRIPTOR;

// Returns the entire memory map, not only what is allocated by AllocatePages and AllocatePool
// - MemoryMapSize: size of buffer on input, needed size of buffer on output
// - MapKey: changes every time the memory map is updated
// - DescriptorSize, DescriptorVersion: Windows API like version control information, just set to sizeof(EFI_MEMORY_DESCRIPTOR)
//                                      and appropriate version
// Error codes
// - EFI_BUFFER_TOO_SMALL: input MemoryMapSize is too small, set to needed size
// - EFI_INVALID_PARAMETER
typedef EFI_STATUS (EFIAPI* EFI_GET_MEMORY_MAP) (IN OUT UINTN* MemoryMapSize, IN OUT EFI_MEMORY_DESCRIPTOR* MemoryMap, OUT UINTN* MapKey, OUT UINTN* DescriptorSize, OUT UINT32* DescriptorVersion);

// - PoolType: type of pool as an EFI_MEMORY_TYPE
// - Size: size in bytes
// Pages from EfiConventionalMemory is allocated as needed to requested pool
// Error codes
// - EFI_OUT_OF_RESOURCES
// - EFI_INVALID_PARAMETER: PoolType is not a valid EFI_MEMORY_TYPE
typedef EFI_STATUS (EFIAPI* EFI_ALLOCATE_POOL) (IN EFI_MEMORY_TYPE PoolType, IN UINTN Size, OUT void** Buffer);

// Error codes
// - EFI_INVALID_PARAMETER
typedef EFI_STATUS (EFIAPI* EFI_FREE_POOL) (IN void* Buffer);

// -----------------------------------------------------------------------------------------------------------------
//                                          Event & Timer Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: CreateEvent
typedef void* EFI_CREATE_EVENT;
// TODO: SetTimer
typedef void* EFI_SET_TIMER;
// TODO: WaitForEvent
typedef void* EFI_WAIT_FOR_EVENT;
// TODO: SignalEvent
typedef void* EFI_SIGNAL_EVENT;
// TODO: CloseEvent
typedef void* EFI_CLOSE_EVENT;
// TODO: CheckEvent
typedef void* EFI_CHECK_EVENT;

// -----------------------------------------------------------------------------------------------------------------
//                                         Protocol Handler Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: InstallProtocolInterface
typedef void* EFI_INSTALL_PROTOCOL_INTERFACE;
// TODO: ReinstallProtocolInterface
typedef void* EFI_REINSTALL_PROTOCOL_INTERFACE;
// TODO: UninstallProtocolInterface
typedef void* EFI_UNINSTALL_PROTOCOL_INTERFACE;
// TODO: HandleProtocol
typedef void* EFI_HANDLE_PROTOCOL;
// TODO: RegisterProtocolNotify
typedef void* EFI_REGISTER_PROTOCOL_NOTIFY;
// TODO: LocateHandle
typedef void* EFI_LOCATE_HANDLE;
// TODO: LocateDevicePath
typedef void* EFI_LOCATE_DEVICE_PATH;
// TODO: InstallConfigurationTable
typedef void* EFI_INSTALL_CONFIGURATION_TABLE;

// -----------------------------------------------------------------------------------------------------------------
//                                            Image Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: LoadImage
typedef void* EFI_IMAGE_LOAD;
// TODO: StartImage
typedef void* EFI_IMAGE_START;
// TODO: Exit
typedef void* EFI_EXIT;
// TODO: UnloadImage
typedef void* EFI_IMAGE_UNLOAD;

// No calls to boot services (except the memory service) should be made after calling ExitBootServices, even on failure
// - MapKey: current memory map, passed to make sure the program has knowledge of the current memory map before exiting boot services
// Error codes
// - EFI_INVALID_PARAMETER: MapKey is incorrect
typedef EFI_STATUS (EFIAPI* EFI_EXIT_BOOT_SERVICES) (IN EFI_HANDLE ImageHandle, IN UINTN MapKey);

// -----------------------------------------------------------------------------------------------------------------
//                                            Misc Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: GetNextMonotonicCount
typedef void* EFI_GET_NEXT_MONOTONIC_COUNT;
// TODO: Stall
typedef void* EFI_STALL;
// TODO: SetWatchdogTimer
typedef void* EFI_SET_WATCHDOG_TIMER;

// -----------------------------------------------------------------------------------------------------------------
//                                            Driver Support Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: ConnectController
typedef void* EFI_CONNECT_CONTROLLER;
// TODO: DisconnectController
typedef void* EFI_DISCONNECT_CONTROLLER;

// -----------------------------------------------------------------------------------------------------------------
//                                            Open and Close Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: OpenProtocol
typedef void* EFI_OPEN_PROTOCOL;
// TODO: CloseProtocol
typedef void* EFI_CLOSE_PROTOCOL;
// TODO: OpenProtocolInformation
typedef void* EFI_OPEN_PROTOCOL_INFORMATION;

// -----------------------------------------------------------------------------------------------------------------
//                                               Library Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: ProtocolsPerHandle
typedef void* EFI_PROTOCOLS_PER_HANDLE;
// TODO: LocateHandleBuffer
typedef void* EFI_LOCATE_HANDLE_BUFFER;
// TODO: LocateProtocol
typedef void* EFI_LOCATE_PROTOCOL;
// TODO: InstallMultipleProtocolInterfaces
typedef void* EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES;
// TODO: UninstallMultipleProtocolInterfaces
typedef void* EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES;

// -----------------------------------------------------------------------------------------------------------------
//                                               32-bit CRC Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: CalculateCrc32
typedef void* EFI_CALCULATE_CRC32;

// -----------------------------------------------------------------------------------------------------------------
//                                            Misc Services
// -----------------------------------------------------------------------------------------------------------------

// TODO: CopyMem
typedef void* EFI_COPY_MEM;
// TODO: SetMem
typedef void* EFI_SET_MEM;
// TODO: CreateEventEx
typedef void* EFI_CREATE_EVENT_EX;

// NOTE: All explicitly allocated/ackquired resources must be freed/released before returning control to the firmware
#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION
typedef struct EFI_BOOT_SERVICES {
	EFI_TABLE_HEADER Hdr;

	// Task Priority Services
	EFI_RAISE_TPL RaiseTPL;
	EFI_RESTORE_TPL RestoreTPL;

	// Memory Services
	EFI_ALLOCATE_PAGES AllocatePages;
	EFI_FREE_PAGES FreePages;
	EFI_GET_MEMORY_MAP GetMemoryMap;
	EFI_ALLOCATE_POOL AllocatePool;
	EFI_FREE_POOL FreePool;

	// Event & Timer Services
	EFI_CREATE_EVENT CreateEvent;
	EFI_SET_TIMER SetTimer;
	EFI_WAIT_FOR_EVENT WaitForEvent;
	EFI_SIGNAL_EVENT SignalEvent;
	EFI_CLOSE_EVENT CloseEvent;
	EFI_CHECK_EVENT CheckEvent;

	// Protocol Handler Services
	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
	EFI_HANDLE_PROTOCOL HandleProtocol;
	void* Reserved;
	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
	EFI_LOCATE_HANDLE LocateHandle;
	EFI_LOCATE_DEVICE_PATH LocateDevicePath;
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;

	// Image Services
	EFI_IMAGE_LOAD LoadImage; // Suspected typo in spec
	EFI_IMAGE_START StartImage;
	EFI_EXIT Exit;
	EFI_IMAGE_UNLOAD UnloadImage;
	EFI_EXIT_BOOT_SERVICES ExitBootServices;

	// Miscellaneous Services
	EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
	EFI_STALL Stall;
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;

	// DriverSupport Services
	EFI_CONNECT_CONTROLLER ConnectController; // EFI 1.1
	EFI_DISCONNECT_CONTROLLER DisconnectController; // EFI 1.1+

	// Open and Close Protocol Services
	EFI_OPEN_PROTOCOL OpenProtocol; // EFI 1.1+
	EFI_CLOSE_PROTOCOL CloseProtocol; // EFI 1.1+
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation; // EFI 1.1+

	// Library Services
	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle; // EFI 1.1+
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer; // EFI 1.1+
	EFI_LOCATE_PROTOCOL LocateProtocol; // EFI 1.1+
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces; // EFI 1.1+
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces; // EFI 1.1+

	// 32-bit CRC Services
	EFI_CALCULATE_CRC32 CalculateCrc32; // EFI 1.1+

	// Miscellaneous Services
	EFI_COPY_MEM CopyMem; // EFI 1.1+
	EFI_SET_MEM SetMem; // EFI 1.1+
	EFI_CREATE_EVENT_EX CreateEventEx; // UEFI 2.0+
} EFI_BOOT_SERVICES;

typedef struct EFI_CONFIGURATION_TABLE {
	EFI_GUID VendorGuid;
	void* VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef struct EFI_SYSTEM_TABLE {
	EFI_TABLE_HEADER Hdr;
	CHAR16* FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;
	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;
	EFI_RUNTIME_SERVICES* RuntimeServices;
	EFI_BOOT_SERVICES* BootServices;
	UINTN NumberOfTableEntries;
	EFI_CONFIGURATION_TABLE* ConfigurationTable;
} EFI_SYSTEM_TABLE;
