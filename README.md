# file_converter
File Converter is a C++ command-line utility that allows users to convert files between different formats, including images, videos, and audio. The utility provides a user-friendly interface for converting files while utilizing the standard C++ filesystem library for platform-independent file path handling.
Features:

    Convert image files (PNG, JPEG, WebP) to different formats.
    Convert video files (MP4, AVI, MOV, WebM, MKV, MP3) to desired formats using FFmpeg.
    Convert audio files (MP3, WAV, AAC, FLAC, OGG) to desired formats using FFmpeg.
    Support for relative file paths or providing file paths as command-line arguments.
    Clear the console after each conversion for a cleaner user experience.

Requirements:

    C++17 compiler
    OpenCV library (for image conversion)
    FFmpeg library (for video and audio conversion)

Installation:

    Install a C++17 compliant compiler on your system (e.g., GCC, Clang).
    Install the OpenCV library to handle image conversion. Follow the instructions provided on the OpenCV website or use a package manager like apt-get or brew.
    Install the FFmpeg library to handle video and audio conversion. Follow the instructions provided on the FFmpeg website or use a package manager like apt-get, brew, or download it from the official website.

Usage:

    Clone the repository or download the code files from GitHub.
    Compile the main.cpp and classes files using the C++17 compiler and link with OpenCV and FFmpeg libraries.

    bash

g++ -o main main.cpp classes/image_converter.cpp classes/video_converter.cpp classes/audio_converter.cpp -I/path_to_opencv_include -L/path_to_opencv_lib -lopencv_world -lstdc++fs

Run the executable "main" on your terminal or command prompt.

bash

    ./main

    Follow the on-screen instructions to choose the file type you want to convert (image, video, or audio) and provide the necessary input.

Contributing:
Contributions are welcome! If you find any issues, have suggestions, or want to add new features, feel free to open an issue or submit a pull request.

License:
This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as per the terms of the license.

Disclaimer:
Please use this utility responsibly and comply with all relevant copyright laws and licensing agreements when converting files. The authors are not responsible for any misuse or illegal activities involving this software.
