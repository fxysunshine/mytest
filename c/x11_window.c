/*
 * example from
 * https://stackoverflow.com/questions/31361859/simple-window-without-titlebar
 * simple X11 window without title bar
 */

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

int main(int argc, char **argv) {
  Display* d = XOpenDisplay(NULL);
  int s = DefaultScreen(d);
  Window w = XCreateSimpleWindow(d, RootWindow(d, s), 400, 400, 900, 600, 1,
                                 BlackPixel(d, s), WhitePixel(d, s));
  Atom window_type = XInternAtom(d, "_NET_WM_WINDOW_TYPE", False);
  long value = XInternAtom(d, "_NET_WM_WINDOW_TYPE_DOCK", False);
  XChangeProperty(d, w, window_type, XA_ATOM, 32, PropModeReplace, (unsigned char *) &value, 1);
  XEvent e;
  XMapWindow(d, w);
  while (1) {
    XNextEvent(d, &e);
    if (e.type == Expose) {
      XFillRectangle(d, w, DefaultGC(d, s), 0, 0, 0, 0);
    }
    if (e.type == KeyPress)
      break;
  }
  XCloseDisplay(d);
  return 0;
}
