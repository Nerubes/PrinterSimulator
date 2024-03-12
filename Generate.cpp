#include <string>
#include <memory>

#include "Distortions.hpp"

Mat first_img = imread("/home/gurovno/Project_CV/example/imgs/first.jpg", IMREAD_GRAYSCALE);
Mat second_img = imread("/home/gurovno/Project_CV/example/imgs/first.jpg", IMREAD_GRAYSCALE);
Mat third_img = imread("/home/gurovno/Project_CV/example/imgs/third.jpg", IMREAD_GRAYSCALE);

int main() {
    PrinterStack first, second, third;
    {
        auto black_lines = std::make_unique<LinesPrinter>(0, 200, 50, true, 0.7, 20, 70, false);
        first.AddLayer(std::move(black_lines));
        auto white_line = std::make_unique<LinesPrinter>(0, 0, 90, false, 0.3, first_img.cols - first_img.cols / 3, first_img.cols, false);
        first.AddLayer(std::move(white_line));
        first.ProcessImage(first_img);
        imwrite("first_m.jpg", first_img);
    }
    {
        auto sinus = std::make_unique<SinPrinter>(0, 0, 70, true, 1, -100, 0, 200, 1, false);
        auto first_line = std::make_unique<LinesPrinter>(200, 0, 60, false, 0.8, 0, 100, false);
        auto second_line = std::make_unique<LinesPrinter>(200, 0, 40, true, 0.8, 50, 80, true);
        auto third_line = std::make_unique<LinesPrinter>(400, 0, 60, true, 1, 234, 237, true);
        auto blob = std::make_unique<BlobPrinter>(200, 0, 25, true, 0.7, 130, 679, 20, 40, false);
        auto all_field = std::make_unique<LinesPrinter>(0, 0, 5, true, 1, 0, second_img.cols, false);
        second.AddLayer(std::move(sinus));
        second.AddLayer(std::move(first_line));
        second.AddLayer(std::move(second_line));
        second.AddLayer(std::move(third_line));
        second.AddLayer(std::move(blob));
        second.AddLayer(std::move(all_field));
        second.ProcessImage(second_img);
        imwrite("second_m.jpg", second_img);
    }
    {
        auto all_field = std::make_unique<LinesPrinter>(0, 0, 10, false, 0.5, 0, third_img.cols, false);
        auto first_blank = std::make_unique<LinesPrinter>(0, 0, 30, false, 0.4, 100, 550, false);
        auto second_blank = std::make_unique<LinesPrinter>(0, 0, 50, false, 0.4, 250, 350, false);
        auto third_blank = std::make_unique<LinesPrinter>(0, 0, 60, false, 0.6, 280, 300, false);
        third.AddLayer(std::move(all_field));
        third.AddLayer(std::move(first_blank));
        third.AddLayer(std::move(second_blank));
        third.AddLayer(std::move(third_blank));
        third.ProcessImage(third_img);
        imwrite("third_m.jpg", third_img);
    }
}