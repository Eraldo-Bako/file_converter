#include "image_converter.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void image() {
    // Ask the user for the input image filename (without path)
    std::string inputFilename;
    std::cout << "Enter the input image filename (without path, with extension): ";
    std::cin >> inputFilename;

    // Construct the full input file path
    std::string inputFolderPath = "input_file/";
    std::string inputFilePath = inputFolderPath + inputFilename;

    // Check if the input image file exists in the "input_files" folder
    if (!fs::exists(inputFilePath)) {
        std::cerr << "Error: The input image file does not exist in the 'input_files' folder." << std::endl;
    }

    // Read the input image
    cv::Mat image = cv::imread(inputFilePath, cv::IMREAD_UNCHANGED);

    if (image.empty()) {
        std::cerr << "Error: Unable to load the input image." << std::endl;
    }

    // Ask the user for the image format to convert to
    std::string format;
    std::cout << "Enter the image format to convert to (PNG, JPEG, or WebP): ";
    std::cin >> format;

    // Convert the format to uppercase for comparison
    for (auto& c : format) {
        c = toupper(c);
    }

    if (format != "PNG" && format != "JPEG" && format != "WEBP") {
        std::cerr << "Invalid format. Supported formats are PNG, JPEG, and WebP." << std::endl;
    }

    // Extract the original filename without extension
    size_t extensionIndex = inputFilename.find_last_of(".");
    std::string originalName = inputFilename.substr(0, extensionIndex);

    // Convert the image to the specified format
    std::string outputFormat;
    std::string outputExtension;
    if (format == "PNG") {
        outputFormat = "PNG";
        outputExtension = ".png";
    } else if (format == "JPEG") {
        outputFormat = "JPEG";
        outputExtension = ".jpg";
    } else if (format == "WEBP") {
        outputFormat = "WebP";
        outputExtension = ".webp";
    }

    std::string outputPath = "output_file/" + originalName + outputExtension;
    cv::imwrite(outputPath, image, { cv::IMWRITE_JPEG_QUALITY, 90 });

    std::cout << "Image conversion to " << outputFormat << " completed. Saved as: " << outputPath << std::endl;
}
