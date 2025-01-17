#ifndef ZW_SUPPORT_TIMER_H
#define ZW_SUPPORT_TIMER_H

#define ZUNO_TIMER_SWITCH_MAX_VALUE				0x63//Maximum value when dimming
#define ZUNO_TIMER_SWITCH_MIN_VALUE				0x0//The minimum value when dimming
#define ZUNO_TIMER_SWITCH_DEFAULT_DURATION		0x0//The default dimming period is seconds.

#define ZUNO_TIMER_SWITCH_INC					0x1//Indicates what should be up
#define ZUNO_TIMER_SWITCH_DEC					0x2//Indicates what should be down
#define ZUNO_TIMER_SWITCH_SUPERVISION			0x40
#define ZUNO_TIMER_SWITCH_NO_BASIC				0x80

typedef struct					ZunoTimerBasic_s
{
	uint8_t						channel;//Tracked Channel Number + 1
	uint8_t						bMode;//Stores modes
	uint8_t						targetValue;
	uint8_t						currentValue;//Current Dimming Level
	uint32_t					ticksEnd;
	uint32_t					ticks;//The number of milliseconds since starting the current program divided by 10 - Saved while changing current level
	uint32_t					step;//How many milliseconds divided by 10 to wait until the next change in the current dimming level
}								ZunoTimerBasic_t;


typedef struct							ZunoTimer_s
{
	ZunoTimerBasic_t					s_basic[0x4];
}										ZunoTimer_t;

extern ZunoTimer_t g_zuno_timer;

void zuno_CCTimer(uint32_t ticks);
size_t zuno_CCTimerTicksTable7(size_t duration);
ZunoTimerBasic_t *zuno_CCTimerBasicFind(size_t channel);
uint8_t zuno_CCTimerTable8(size_t ticks);
size_t zuno_CCTimerBasicFindStop(size_t channel);

#endif// ZW_SUPPORT_TIMER_H