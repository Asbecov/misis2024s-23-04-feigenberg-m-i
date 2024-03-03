#include <opencv2/opencv.hpp>
#include <cstddef>
#include <array>
#include <iostream>

int main(int argcount, char* args[]) {
    cv::Mat img = cv::imread(args[1], cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cout << "Could not read the image\n";
        return 1;
    }

    std::array<uchar, 256> table;
    for (int i{0}; i < table.size(); i++) {
        table[i] = (uchar)(50 * (i / 50));
    }

    std::ptrdiff_t nrow{img.rows};
    std::ptrdiff_t ncol{img.cols * img.channels()};

    if (img.isContinuous()) {
        ncol *= nrow;
        nrow = 1;
    }

    uchar* p;
    for (std::ptrdiff_t i{0}; i < nrow; ++i) {
        p = img.ptr<uchar>(i);
        for (std::ptrdiff_t j{0}; j < ncol; ++j) {
            (p[j]) = table[p[j]]; 
        }
    }

    cv::imshow("Display Window", img);
    cv::waitKey(0);
    return 0;
}
