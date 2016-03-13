//
// Created by Seth Parker on 9/18/15.
//

#include "Mesh.h"

namespace simpleRenderer {

    ///// Transformations /////

    void Mesh::translate(cv::Vec3d translation) {
        for( auto v = _points.begin(); v != _points.end(); ++v ) {
          v->pos += translation;
        }
    }

    ///// Mesh Generation Helper Functions /////
    void Mesh::_add_vertex(double x, double y, double z) {
        Vertex v;
        v.pos(0) = x;
        v.pos(1) = y;
        v.pos(2) = z;
        v.norm(0) = 0;
        v.norm(1) = 0;
        v.norm(2) = 0;
        v.face_count = 0;
        _points.push_back(v);
    }

    void Mesh::_add_cell(unsigned long v1, unsigned long v2, unsigned long v3) {
        Cell f;
        f.v1 = &_points[v1];
        f.v2 = &_points[v2];
        f.v3 = &_points[v3];
        _cells.push_back(f);

        // calculate vertex normals (average of surface normals of each triangle)
        // get surface normal of this triangle
        double nx, ny, nz, vx, vy, vz, wx, wy, wz, magnitude;

        vx = f.v2->pos(0) - f.v1->pos(0);
        vy = f.v2->pos(1) - f.v1->pos(1);;
        vz = f.v2->pos(2) - f.v1->pos(2);;

        wx = f.v3->pos(0) - f.v1->pos(0);
        wy = f.v3->pos(1) - f.v1->pos(1);
        wz = f.v3->pos(2) - f.v1->pos(2);

        nx = (vy * wz) - (vz * wy);
        ny = (vz * wx) - (vx * wz);
        nz = (vx * wy) - (vy * wx);

        // normalize
        magnitude = sqrt(nx*nx + ny*ny + nz*nz);
        nx /= magnitude;
        ny /= magnitude;
        nz /= magnitude;

        // update the vertex normals
        _update_normal(v1, nx, ny, nz);
        _update_normal(v2, nx, ny, nz);
        _update_normal(v3, nx, ny, nz);
    }

    void Mesh::_update_normal(unsigned long vertex, double nx_in, double ny_in, double nz_in) {
      // recalculate average (unaverage, add new component, recalculate average)
      Vertex *v = &_points[vertex];
      v->norm(0) = (v->norm(0) * v->face_count + nx_in) / (v->face_count + 1);
      v->norm(1) = (v->norm(1) * v->face_count + ny_in) / (v->face_count + 1);
      v->norm(2) = (v->norm(2) * v->face_count + nz_in) / (v->face_count + 1);
      v->face_count++;
    }


} // namespace simpleRenderer