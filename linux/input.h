/* dummy_linux_input.h - Mock header for linux/input.h for testing.
* No OS interaction; defines key structs/types for compilation/testing.
 * Include this instead of <linux/input.h> in your test code.
 * Provides dummy input_event struct and common constants.
 */

#ifndef _DUMMY_LINUX_INPUT_H
#define _DUMMY_LINUX_INPUT_H

#include <stdint.h>
#include <sys/time.h>  /* for struct timeval; use <time.h> on some systems */
//#include <sys/ioctl.h>  /* Must include for ioctl() */

/* Basic types matching kernel uapi */
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef int32_t __s32;

/* Event types */
#define EV_SYN      0x00
#define EV_KEY      0x01
#define EV_REL      0x02
#define EV_ABS      0x03
#define EV_MSC      0x04
#define EV_SW       0x05
#define EV_LED      0x11
#define EV_SND      0x12
#define EV_REP      0x14
#define EV_FF       0x15
#define EV_PWR      0x16
#define EV_FF_STATUS 0x17

/* SYN constants */
#define SYN_REPORT  0
#define SYN_CONFIG  1
#define SYN_MT_REPORT 2
#define SYN_DROPPED 3

/* Common key codes (subset for testing; extend as needed) */
#define KEY_A       30
#define KEY_B       48
/* Add more like KEY_ESC=1, BTN_LEFT=0x110, etc. */

/* Main event structure - matches kernel input_event */
struct input_event {
    struct timeval time;
    __u16 type;
    __u16 code;
    __s32 value;
};

/* Dummy absinfo for completeness */
struct input_absinfo {
    __s32 value;
    __s32 minimum;
    __s32 maximum;
    __s32 fuzz;
    __s32 flat;
    __s32 resolution;
};

/* Common ioctls (if your code uses them) */
#define EVIOCGVERSION      _IOR('E', 0x01, int)
#define EVIOCGID           _IOR('E', 0x02, struct input_id)
#define EVIOCGKEYCODE      _IOR('E', 0x04, unsigned int[2])
#define EVIOCGRAB _IOW('E', 0x90, int)  /* Grab/Release device */

struct input_id {
    __u16 bustype;
    __u16 vendor;
    __u16 product;
    __u16 version;
};

/* Dummy functions/macros for common usage (no-op for testing) */
#define input_event(dev, type, code, value) do { /* no-op */ } while(0)
#define input_sync(dev) do { /* no-op */ } while(0)

#endif /* _DUMMY_LINUX_INPUT_H */
