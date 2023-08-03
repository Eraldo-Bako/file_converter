#include "classes/image_converter.h"
#include "classes/video_converter.h"
#include "classes/audio_converter.h"

#include <iostream>
#include <cctype>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"  // Windows system command to clear console
#else
    #define CLEAR_COMMAND "clear"  // Unix-like system command to clear console
#endif

using namespace std;

void converter() {
    string filetype;
    cout << "What file are you going to convert (image, video, audio) : ";
    cin >> filetype;

    for (char& c : filetype) {
        c = tolower(c);
    }

    if (filetype == "image") {
        image();
    } else if (filetype == "video") {
        video();
    } else if (filetype == "audio") {
        audio();
    } else {
        cout << "We do not support this filetype yet!" << endl;
    }
}

int main() {
    converter();

    char response;
    cout << "Do you want to convert another file (Y/n): ";
    cin >> response;

    while (response == 'Y' || response == 'y') {
        system(CLEAR_COMMAND);  // Clear the console using the appropriate command
        converter();
        cout << "Do you want to convert another file (Y/n): ";
        cin >> response;
    }

    return 0;
}
