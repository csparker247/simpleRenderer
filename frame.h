#ifndef SIMPLE_FRAME_H
#define SIMPLE_FRAME_H

#include <opencv2/opencv.hpp>

namespace simpleRenderer {

class frame {
public:
  frame();
private:
  cv::Mat _frame;

} // frameBuffer

}// namespace simpleRenderer

#endif // SIMPLE_FRAME_H
