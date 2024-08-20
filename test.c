#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char *argv[])
{
    Display *mydisplay;
    XSetWindowAttributes myat;
    Window mywindow;
    XSizeHints wmsize;
    XWMHints wmhints;
    XTextProperty windowName, iconName;
    XEvent myevent;
    
    char *window_name = "Basic";
    char *icon_name = "Ba";
    int screen_num, done;
    unsigned long valuemask;

    /* open connection to the server */
    mydisplay = XOpenDisplay("");

    /* create a top-level window */
    screen_num = DefaultScreen(mydisplay);
    myat.background_pixel = WhitePixel(mydisplay, screen_num);
    myat.border_pixel = BlackPixel(mydisplay, screen_num);
    myat.event_mask = ButtonPressMask;
    valuemask = CWBackPixel | CWBorderPixel | CWEventMask;
    mywindow = XCreateWindow(mydisplay, RootWindow(mydisplay, screen_num),
        200, 200, 350, 250, 2,
        DefaultDepth(mydisplay, screen_num),
        InputOutput,
        DefaultVisual(mydisplay, screen_num),
        valuemask, &myat);

    wmsize.flags = USPosition | USSize;
    XSetWMNormalHints(mydisplay, mywindow, &wmsize);
    wmhints.initial_state = NormalState;
    wmhints.flags = StateHint;
    XSetWMHints(mydisplay, mywindow, &wmhints);
    XStringListToTextProperty(&window_name, 1, &windowName);
    XStringListToTextProperty(&icon_name, 1, &iconName);

    /* establish window resources */
    /* create all the other windows needed */
    /* select events for each window */
    /* map the windows */

    XMapWindow(mydisplay, mywindow);

    /* enter the event loop */

    done = 0;

    while (done == 0) {
        XNextEvent(mydisplay, &myevent);
        
        switch(myevent.type) {
            case ButtonPress:
                break;
        }
    }

    /* clean up before exiting */

    XUnmapWindow(mydisplay, mywindow);
    XDestroyWindow(mydisplay, mywindow);
    XCloseDisplay(mydisplay);

    return 0;
}





