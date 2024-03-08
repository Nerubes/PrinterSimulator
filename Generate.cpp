#include <string>

#include "Distortions/Distortions.hpp"

Mat first_img = imread("/home/gurovno/Project_CV/example/imgs/first.jpg", IMREAD_GRAYSCALE);
Mat second_img = imread("/home/gurovno/Project_CV/example/imgs/first.jpg", IMREAD_GRAYSCALE);
Mat third_img = imread("/home/gurovno/Project_CV/example/imgs/third.jpg", IMREAD_GRAYSCALE);

int main() {
    PrinterStack first, second, third;
    {
        SolidLinesPrinter black_lines(0, 200, 50, true, 0.7, 20, 70, false);
        first.AddLayer(black_lines);
        SolidLinesPrinter white_line(0, 0, 90, false, 0.3, first_img.cols - first_img.cols / 3, first_img.cols, false);
        first.AddLayer(white_line);
        first.ProcessImage(first_img);
        imwrite("first_m.jpg", first_img);
    }
    {
        SinPrinter sinus(0, 0, 70, true, 1, -100, 0, 200, 1);
        SolidLinesPrinter first_line(200, 0, 60, false, 0.8, 0, 100, false);
        SolidLinesPrinter second_line(200, 0, 40, true, 0.8, 50, 80, true);
        SolidLinesPrinter third_line(400, 0, 60, true, 1, 234, 237, true);
        BlobPrinter blob(200, 0, 25, true, 0.7, 130, 679, 20, 40, false);
        SolidLinesPrinter all_field(0, 0, 5, true, 1, 0, second_img.cols, false);
        second.AddLayer(sinus);
        second.AddLayer(first_line);
        second.AddLayer(second_line);
        second.AddLayer(third_line);
        second.AddLayer(blob);
        second.AddLayer(all_field);
        second.ProcessImage(second_img);
        imwrite("second_m.jpg", second_img);
    }
    {
        SolidLinesPrinter all_field(0, 0, 10, false, 0.5, 0, third_img.cols, false);
        SolidLinesPrinter first_blank(0, 0, 30, false, 0.4, 100, 550, false);
        SolidLinesPrinter second_blank(0, 0, 50, false, 0.4, 250, 350, false);
        SolidLinesPrinter third_blank(0, 0, 60, false, 0.6, 280, 300, false);
        third.AddLayer(all_field);
        third.AddLayer(first_blank);
        third.AddLayer(second_blank);
        third.AddLayer(third_blank);
        third.ProcessImage(third_img);
        imwrite("third_m.jpg", third_img);
    }
}