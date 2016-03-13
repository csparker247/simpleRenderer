//
// Created by Seth Parker on 9/18/15.
//

#ifndef SIMPLE_MESH_H
#define SIMPLE_MESH_H

#include <memory>
#include <opencv2/opencv.hpp>

namespace simpleRenderer {

  class Vertex {
  public:
      Vertex(){};
      cv::Vec3d pos;
      cv::Vec3d norm;
      unsigned long face_count;
  };

  class Cell {
  public:
      Cell(){};
      Vertex *v1, *v2, *v3;
  };


  class Mesh {
  public:
    Mesh(){};

    std::vector<Vertex> getPoints() {return _points;}
    std::vector<Cell> getCells() {return _cells;}

    void addVertex( double x, double y, double z ) { _add_vertex(x,y,z); };
    void addCell( unsigned long a, unsigned long b, unsigned long c) { _add_cell( a, b, c); };

    void translate( cv::Vec3d translation );

  protected:
    std::vector<Vertex> _points;
    std::vector<Cell> _cells;

    void _add_vertex(double x, double y, double z);
    void _add_cell(unsigned long v1, unsigned long v2, unsigned long v3);
    void _update_normal(unsigned long vertex, double nx_in, double ny_in, double nz_in);

  }; // Mesh

} // simpleRenderer

#endif //SIMPLE_MESH_H
