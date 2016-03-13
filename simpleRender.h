#ifndef SIMPLE_RENDER_H
#define SIMPLE_RENDER_H

#include <opencv2/opencv.hpp>

#define SR_WHITE cv::Scalar(255,255,255)

namespace simpleRenderer {
  class simpleRenderer {
  public:

    simpleRenderer( int width, int height ) :
            _width(width),
            _height(height)
    {
        _frame = cv::Mat::zeros(_height, _width, CV_8UC3);
    };

    void clearFrame() { _frame = cv::Mat::zeros( _height, _width, CV_8UC3); };
    cv::Mat currentFrame() { return _frame; };

    // Drawing functions
    void drawLine(cv::Vec3d A, cv::Vec3d B);
    void drawLine( double Ax, double Ay, double Az, double Bx, double By, double Bz );

  private:
    cv::Mat _frame;
    int _width;
    int _height;

    cv::Mat _worldToCameraTransform;
  };
} // simpleRenderer

#endif // SIMPLE_RENDER_H
