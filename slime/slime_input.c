
//  slime_input.c
//  slime
//  [05/11/2016]

#include "slime_input.h"

typedef struct inputContainer_ {
    int mouseX, mouseY;
    bool mouseButtonStatus[3];
    bool mouseButtonPreviousStatus[3];
}inputContainer;

inputContainer slimeInput;
// slimeInput is a singleton
// of type inputContainer

void slimeInputPoll(void) {
    SDL_Event ev;
    for (int i = 0; i != 3; i++) {
        slimeInput.mouseButtonPreviousStatus[i] = slimeInput.mouseButtonStatus[i];
        slimeInput.mouseButtonStatus[i] = false;
    }
    while (SDL_PollEvent(&ev)) {
        int et = ev.type;
        switch (et) {
            case SDL_QUIT: exit(0); break;
            case SDL_MOUSEMOTION: {
                SDL_GetMouseState(&slimeInput.mouseX, &slimeInput.mouseY);
                break; }
            case SDL_MOUSEBUTTONDOWN: {
                switch (ev.button.button) {
                    case SDL_BUTTON_LEFT:  {
                        slimeInput.mouseButtonStatus[0] = true;
                        break; }
                    case SDL_BUTTON_MIDDLE: {
                        slimeInput.mouseButtonStatus[1] = true;
                    break; }
                    case SDL_BUTTON_RIGHT: {
                        slimeInput.mouseButtonStatus[2] = true;
                        break; }
                    default: break;
                } break; }
            case SDL_MOUSEBUTTONUP: {
                switch (ev.button.button) {
                    case SDL_BUTTON_LEFT:  {
                        slimeInput.mouseButtonStatus[0] = false;
                        break; }
                    case SDL_BUTTON_MIDDLE: {
                        slimeInput.mouseButtonStatus[1] = false;
                        break; }
                    case SDL_BUTTON_RIGHT: {
                        slimeInput.mouseButtonStatus[2] = false;
                        break; }
                    default: break;
                } break; }
            default: break;
        }
    }
}

int slimeMouseX(void) {
    return slimeInput.mouseX;
}

int slimeMouseY(void) {
    return slimeInput.mouseY;
}

bool slimeCheckMouseButton(mouseButton button) {
    return slimeInput.mouseButtonStatus[button];
}

bool slimeCheckMouseButtonPressed(mouseButton button) {
    if (slimeInput.mouseButtonStatus[button] &&
        !slimeInput.mouseButtonPreviousStatus[button]) {
        return true;
    } return false;
}
bool slimeCheckMouseButtonReleased(mouseButton button) {
    if (!slimeInput.mouseButtonStatus[button] &&
        slimeInput.mouseButtonPreviousStatus[button]) {
        return true;
    } return false;
}
