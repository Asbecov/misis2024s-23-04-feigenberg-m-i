#include <opencv2/opencv.hpp>

int main(int argcount, char* arguments[]) {
    if (argcount <= 1) 
    {
        std::cout << "Incorrect usage of the programm: to use - " << arguments[0] << " [path to the file] \n";
        return -1;
    }

    cv::Mat m = cv::imread(arguments[1], cv::IMREAD_COLOR);

    uchar table[256];
    for(int i{0}; i < 256; i ++ ){
        table[i] = (uchar) (100 * (i / 100));
    }

    std::ptrdiff_t nrow = m.rows;
    std::ptrdiff_t ncol = m.cols;

    if (m.isContinuous()) {
        ncol *= ncol;
        nrow = 1;
    }

    for (std::ptrdiff_t i{0}; i < nrow; ++i) {
        uchar* ptr = m.ptr(i);
        for (int j{0}; j < ncol * m.channels(); ++j) {
            ptr[j] = table[ptr[j]];
        }
    }
    
    
    cv::imshow("DisplayName", m);
    cv::waitKey(0);
}   