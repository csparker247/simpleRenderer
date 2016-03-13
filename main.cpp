#include <iostream>

#include <opencv2/opencv.hpp>

#include "Mesh.h"
#include "simpleRender.h"

int main( int argc, char* argv[] ) {

  int width = 800;
  int height = 600;

  simpleRenderer::Mesh mesh;

  // generate the 8 vertices
  mesh.addVertex(  10,  10, 10);
  mesh.addVertex(  10, 100, 10);
  mesh.addVertex( 100, 100, 10);
  mesh.addVertex( 100,  10, 10);

  mesh.addVertex(  10,  10, 100);
  mesh.addVertex(  10, 100, 100);
  mesh.addVertex( 100, 100, 100);
  mesh.addVertex( 100,  10, 100);

  // generate the 12 cells for faces

  mesh.addCell(0, 1, 2);
  mesh.addCell(0, 1, 5);
  mesh.addCell(0, 2, 3);
  mesh.addCell(0, 3, 4);
  mesh.addCell(0, 4, 5);
  mesh.addCell(1, 2, 6);
  mesh.addCell(1, 5, 6);
  mesh.addCell(2, 3, 7);
  mesh.addCell(2, 6, 7);
  mesh.addCell(3, 4, 7);
  mesh.addCell(4, 5, 7);
  mesh.addCell(5, 6, 7);

  simpleRenderer::simpleRenderer renderer( 800, 600 );
  cv::namedWindow( "Display window", CV_WINDOW_AUTOSIZE );

  while( true ) {
    renderer.clearFrame();

    mesh.translate( cv::Vec3d(10, 10, 10) );

    for ( size_t f = 0; f < mesh.getCells().size(); ++f ) {
      cv::Vec3d A = mesh.getCells()[f].v1->pos;
      cv::Vec3d B = mesh.getCells()[f].v2->pos;
      cv::Vec3d C = mesh.getCells()[f].v3->pos;
      renderer.drawLine( A, B );
      renderer.drawLine( B, C );
      renderer.drawLine( B, A );
    }

    cv::imshow( "Display window", renderer.currentFrame() );

    if ( cv::waitKey(500) != -1 ) break;
  }

}