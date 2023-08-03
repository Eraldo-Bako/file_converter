#include "video_converter.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib> // For system function
#include <algorithm> // For std::transform
#include <cctype> // For std::tolower

namespace fs = std::filesystem;

void video() {
    // Ask the user for the input video filename (without path)
    std::string inputFilename;
    std::cout << "Enter the input video filename (without path, with extension): ";
    std::cin >> inputFilename;

    // Ask the user for the format to convert to
    std::string format;
    std::cout << "Enter the format to convert to (MP4, AVI, MOV, WebM, MKV, or MP3): ";
    std::cin >> format;

    // Convert the format to lowercase
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);

    // Check if the format is supported
    if (format != "mp4" && format != "avi" && format != "mov" && format != "webm" && format != "mkv" && format != "mp3") {
        std::cerr << "Error: Unsupported output format. Please choose from MP4, AVI, MOV, WebM, MKV, or MP3." << std::endl;
    }

    // Construct the full input file path
    std::string inputFolderPath = "input_file/";
    std::string inputFilePath = inputFolderPath + inputFilename;

    // Check if the input video file exists in the "input_files" folder
    if (!fs::exists(inputFilePath)) {
        std::cerr << "Error: The input video file does not exist in the 'input_file' folder." << std::endl;
    }

    // Construct the full output file path
    std::string outputFolderPath = "output_file/";
    std::string outputFilePath;

    if (format == "mp3") {
        // For MP3 format, change the output file extension to ".mp3"
        outputFilePath = outputFolderPath + inputFilename.substr(0, inputFilename.find_last_of('.')) + ".mp3";
    } else {
        // For other video formats, keep the original output file extension
        outputFilePath = outputFolderPath + inputFilename.substr(0, inputFilename.find_last_of('.')) + "." + format;
    }

    // Convert the video to the desired format using FFmpeg
    std::string cmd;

    if (format == "webm") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:v libvpx-vp9 -c:a libopus " + outputFilePath;
    } else if (format == "mp3") {
        cmd = "ffmpeg -i " + inputFilePath + " -vn -c:a libmp3lame -q:a 2 " + outputFilePath;
    } else {
        cmd = "ffmpeg -i " + inputFilePath + " -c:v copy -c:a copy " + outputFilePath;
    }

    int result = system(cmd.c_str());

    if (result != 0) {
        std::cerr << "Error: Failed to convert the video." << std::endl;
    }

    std::cout << "Conversion completed. Saved as: " << outputFilePath << std::endl;
}
