/*
 * Copyright © 2008 Ben Smith
 * Copyright © 2010-2011 Linaro Limited
 *
 * This file is part of the glmark2 OpenGL (ES) 2.0 benchmark.
 *
 * glmark2 is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * glmark2 is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * glmark2.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *  Ben Smith (original glmark benchmark)
 *  Alexandros Frantzis (glmark2)
 */
#ifndef GLMARK2_MESH_H_
#define GLMARK2_MESH_H_

#include "canvas.h"
#include "vec.h"

#include <stdio.h>
#include <math.h>
#include <vector>

class Mesh
{
public:
    Mesh();
    ~Mesh();

    void set_vertex_format(const std::vector<int> &format);
    void set_attrib_locations(const std::vector<int> &locations);

    void set_attrib(int pos, const LibMatrix::vec2 &v);
    void set_attrib(int pos, const LibMatrix::vec3 &v);
    void set_attrib(int pos, const LibMatrix::vec4 &v);
    void next_vertex();

    void reset();
    void build_array();
    void build_vbo();
    void delete_array();
    void delete_vbo();

    void render_array();
    void render_vbo();

private:
    bool check_attrib(int pos, int size);
    std::vector<float> &ensure_vertex();

    std::vector<std::pair<int, int> > vertex_format_;
    std::vector<int> attrib_locations_;
    int vertex_size_;

    std::vector<std::vector<float> > vertices_;

    std::vector<float *> vertex_arrays_;
    std::vector<GLuint> vbos_;
};

#endif
