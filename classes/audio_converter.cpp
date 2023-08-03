#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib> // For system function
#include <algorithm> // For std::transform
#include <cctype> // For std::tolower

namespace fs = std::filesystem;

void audio() {
    // Ask the user for the input audio filename (without path)
    std::string inputFilename;
    std::cout << "Enter the input audio filename (without path, with extension): ";
    std::cin >> inputFilename;

    // Ask the user for the audio format to convert to
    std::string format;
    std::cout << "Enter the audio format to convert to (MP3, WAV, AAC, FLAC, OGG, etc.): ";
    std::cin >> format;

    // Convert the format to lowercase
    std::transform(format.begin(), format.end(), format.begin(), ::tolower);

    // Check if the format is supported
    if (format != "mp3" && format != "wav" && format != "aac" && format != "flac" && format != "ogg") {
        std::cerr << "Error: Unsupported output format. Please choose from MP3, WAV, AAC, FLAC, or OGG." << std::endl;
    }

    // Construct the full input file path
    std::string inputFolderPath = "input_file/";
    std::string inputFilePath = inputFolderPath + inputFilename;

    // Check if the input audio file exists in the "input_audio" folder
    if (!fs::exists(inputFilePath)) {
        std::cerr << "Error: The input audio file does not exist in the 'input_audio' folder." << std::endl;
    }

    // Construct the full output file path
    std::string outputFolderPath = "output_file/";
    std::string outputFilePath = outputFolderPath + inputFilename.substr(0, inputFilename.find_last_of('.')) + "." + format;

    // Construct the FFmpeg command for audio conversion
    std::string cmd;

    if (format == "mp3") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:a libmp3lame " + outputFilePath;
    } else if (format == "wav") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:a pcm_s16le " + outputFilePath;
    } else if (format == "aac") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:a aac " + outputFilePath;
    } else if (format == "flac") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:a flac " + outputFilePath;
    } else if (format == "ogg") {
        cmd = "ffmpeg -i " + inputFilePath + " -c:a libvorbis " + outputFilePath;
    }

    // Run the FFmpeg command for audio conversion using system function
    int result = system(cmd.c_str());

    if (result != 0) {
        std::cerr << "Error: Failed to convert the audio." << std::endl;
    }

    std::cout << "Audio conversion to " << format << " completed. Saved as: " << outputFilePath << std::endl;
}
