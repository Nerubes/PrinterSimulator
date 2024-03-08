#include <string>

#include "Distortions/Distortions.hpp"

int main(int argc, char* argv[]) {
    std::string filename = argv[1];
    Mat image = imread(filename, IMREAD_GRAYSCALE);
    int rows = image.rows;
    int cols = image.cols;
    PrinterStack stack;
    // BlobPrinter first(0, 0, 70, true, 1, 300, 300, 10, 10);
    // SolidLinesPrinter second(0, 0, 60, false, 0.7, 50, 100, false);
    // SolidLinesPrinter third(0, 0, 30, true, 1, 200, 500, false);
    BlobPrinter first(0, 0, 10, false, 0.5, 300, 300, 100, 30);
    SolidLinesPrinter second(0, 0, 100, false, 0.7, 50, 100, false);
    SolidLinesPrinter subsecond(0, 0, 50, false, 0.9, 50, 100, false);
    SolidLinesPrinter third(0, 0, 100, false, 0.4, 200, 500, false);
    stack.AddLayer(first);
    stack.AddLayer(second);
    stack.AddLayer(subsecond);
    stack.AddLayer(third);
    stack.ProcessImage(image);
    imwrite("result.jpg", image);
}