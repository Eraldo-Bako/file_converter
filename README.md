# File Converter
File Converter is a C++ command-line utility that allows users to convert files between different formats, including images, videos, and audio. The utility provides a user-friendly interface for converting files while utilizing the standard C++ filesystem library for platform-independent file path handling.


<h2>Features:</h2>

-Convert image files (PNG, JPEG, WebP) to different formats.<br>
-Convert video files (MP4, AVI, MOV, WebM, MKV, MP3) to desired formats using FFmpeg.<br>
-Convert audio files (MP3, WAV, AAC, FLAC, OGG) to desired formats using FFmpeg.<br>
-Support for relative file paths or providing file paths as command-line arguments.<br>
-Clear the console after each conversion for a cleaner user experience.<br>


<h2>Requirements:</h2>

C++17 compiler<br>
OpenCV library (for image conversion)<br>
FFmpeg library (for video and audio conversion)<br>


<h2>Installation:</h2>

Install a C++17 compliant compiler on your system (e.g., GCC, Clang).<br>
Install the OpenCV library to handle image conversion. Follow the instructions provided on the OpenCV website or use a package manager like apt-get or brew.<br>
Install the FFmpeg library to handle video and audio conversion. Follow the instructions provided on the FFmpeg website or use a package manager like apt-get,brew, or download it from the official website.


<h2>Usage:</h2>

Clone the repository or download the code files from GitHub.<br>
Compile the main.cpp and classes files using the C++17 compiler and link with OpenCV and FFmpeg libraries.<br>

<h4>bash</h4>
    
    g++ -o main main.cpp classes/image_converter.cpp classes/video_converter.cpp classes/audio_converter.cpp -I/path_to_opencv_include -L/path_to_opencv_lib -lopencv_world -lstdc++fs


Run the executable "main" on your terminal or command prompt.
<h4>bash</h4>

    ./main

Follow the on-screen instructions to choose the file type you want to convert (image, video, or audio) and provide the necessary input.


<h2>Contributing:</h2>

Contributions are welcome! If you find any issues, have suggestions, or want to add new features, feel free to open an issue or submit a pull request.


<h2>License:</h2>

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as per the terms of the license.


<h2>Disclaimer:</h2>

Please use this utility responsibly and comply with all relevant copyright laws and licensing agreements when converting files. The authors are not responsible for any misuse or illegal activities involving this software.
