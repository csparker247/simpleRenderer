#include "simpleRender.h"

namespace simpleRenderer {

    void simpleRenderer::drawLine(cv::Vec3d A, cv::Vec3d B) {

      // Ignore the Z for now
      cv::Point a( cvRound(A(0)), cvRound(A(1)) );
      cv::Point b( cvRound(B(0)), cvRound(B(1)) );

      // Draw the line
      cv::line( _frame, a, b, SR_WHITE);
    };

    void simpleRenderer::drawLine( double Ax, double Ay, double Az,
                                   double Bx, double By, double Bz ) {
      drawLine( cv::Vec3d( Ax, Ay, Az), cv::Vec3d( Bx, By, Bz) );
    }

}