#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/uinput.h>

#define die(str, args...) do { \
    perror(str); \
    exit(EXIT_FAILURE); \
} while (0)

int main()
{
    int fd;
    struct uinput_user_dev uidev;

    fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (fd < 0) die("error: open");
    if (ioctl(fd, UI_SET_EVBIT, EV_KEY) == -1) {
        die("ioctl0");
    }

    if (ioctl(fd, UI_SET_KEYBIT, BTN_LEFT) == -1) {
        die("ioctl0.1");
    }

    if (ioctl(fd, UI_SET_EVBIT, EV_REL) == -1) {
        die("ioctl1");
    }

    if (ioctl(fd, UI_SET_RELBIT, REL_X) == -1) {
        die("ioctl2");
    }

    if (ioctl(fd, UI_SET_RELBIT, REL_Y) == -1) {
        die("ioctl3");
    }

    memset(&uidev, 0, sizeof(uidev));
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "virtual_mouse");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor = 0x1;
    uidev.id.product = 0x1;
    uidev.id.version = 1;

    if (write(fd, &uidev, sizeof(uidev)) < 0) die("error: write");
    if (ioctl(fd, UI_DEV_CREATE) < 0) die("error: ioctl");

    sleep(10000);
    // will generate a mouse and an input device in /dev/input
    // from /proc/bus/input/devices, can see the bus the installed virtual device

    if (ioctl(fd, UI_DEV_DESTROY) < 0) die("error: ioctl");
    close(fd);

    return 0;
}
