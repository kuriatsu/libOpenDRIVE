#include <pybind11/pybind11.h>

#include "OpenDriveMap.h"
#include "LaneSection.h"
#include "Lane.h"
#include "Mesh.h"
#include "Road.h"

PYBIND11_MODULE(pyopendrive, m) {
    // pybind11::module m_road = m.def_submodule("Road");

    pybind11::class_<odr::OpenDriveMap>(m, "OpenDriveMap")
        .def(pybind11::init<std::string&, bool, bool, bool, bool, bool, bool>())
        .def("get_roads", &odr::OpenDriveMap::get_roads)
        .def("get_junctions", &odr::OpenDriveMap::get_junctions)
        .def("get_road_network_mesh", &odr::OpenDriveMap::get_road_network_mesh)
        .def("get_routing_graph", &odr::OpenDriveMap::get_routing_graph)
        .def_readwrite("proj4", &odr::OpenDriveMap::proj4)
        .def_readwrite("x_offs", &odr::OpenDriveMap::x_offs)
        .def_readwrite("y_offs", &odr::OpenDriveMap::y_offs)
        // .def_readwrite("xodr_file", &odr::OpenDriveMap::xodr_file)
        // .def_readwrite("xml_doc", &odr::OpenDriveMap::xml_doc)
        .def_readwrite("id_to_road", &odr::OpenDriveMap::id_to_road)
        .def_readwrite("id_to_junction", &odr::OpenDriveMap::id_to_junction)
        ;

    pybind11::class_<odr::LaneSection>(m, "LaneSection")
        .def(pybind11::init<std::string, double>())
        .def("get_lanes", &odr::LaneSection::get_lanes)
        .def("get_lane_id", &odr::LaneSection::get_lane_id)
        .def("get_lane", &odr::LaneSection::get_lane)
        .def_readwrite("road_id", &odr::LaneSection::road_id)
        .def_readwrite("s0", &odr::LaneSection::s0)
        .def_readwrite("id_to_lane", &odr::LaneSection::id_to_lane)
        ;

    pybind11::class_<odr::Lane>(m, "Lane")
        .def(pybind11::init<std::string, double, int, bool, std::string>())
        .def("get_roadmarks", &odr::Lane::get_roadmarks)
        .def_readwrite("key", &odr::Lane::key)
        .def_readwrite("id", &odr::Lane::id)
        .def_readwrite("level", &odr::Lane::level)
        .def_readwrite("predecessor", &odr::Lane::predecessor)
        .def_readwrite("successor", &odr::Lane::successor)
        .def_readwrite("type", &odr::Lane::type)
        .def_readwrite("lane_width", &odr::Lane::lane_width)
        .def_readwrite("outer_border", &odr::Lane::outer_border)
        .def_readwrite("inner_border", &odr::Lane::inner_border)
        .def_readwrite("s_to_hight_offset", &odr::Lane::s_to_height_offset)
        .def_readwrite("roadmark_groups", &odr::Lane::roadmark_groups)
        ;

    pybind11::class_<odr::Mesh3D>(m, "Mesh3D")
        .def(pybind11::init<>())
        .def("add_mesh", &odr::Mesh3D::add_mesh)
        .def("get_obj", &odr::Mesh3D::get_obj)
        .def_readwrite("vertices", &odr::Mesh3D::vertices)
        .def_readwrite("indices", &odr::Mesh3D::indices)
        .def_readwrite("normals", &odr::Mesh3D::normals)
        .def_readwrite("st_coordinates", &odr::Mesh3D::st_coordinates)
        ;

    pybind11::class_<odr::Road>(m, "Road")
        .def(pybind11::init<std::string, double, std::string, std::string>())
        .def("get_lanesections", &odr::Road::get_lanesections)
        .def("get_road_objects", &odr::Road::get_road_objects)
        .def("get_lanesection_s0", &odr::Road::get_lanesection_s0)
        .def("get_lanesection", &odr::Road::get_lanesection)
        // .def("get_lanesection_end", (double (*)(LaneSection)) &odr::Road::get_lanesection_end)
        // .def("get_lanesection_end", (double (*)(double)) &odr::Road::get_lanesection_end)
        // .def("get_lanesection_length", (double (*)(LaneSection)) &odr::Road::get_lanesection_length)
        // .def("get_lanesection_length", (double (*)(double)) &odr::Road::get_lanesection_length)
        .def("get_xyz", &odr::Road::get_xyz)
        .def("get_surface_pt", &odr::Road::get_surface_pt)
        // .def("get_lane_mesh", &odr::Road::get_lane_mesh)
        .def("get_roadmark_mesh", &odr::Road::get_roadmark_mesh)
        .def("get_road_object_mesh", &odr::Road::get_road_object_mesh)
        .def_readwrite("length", &odr::Road::length)
        .def_readwrite("id", &odr::Road::id)
        .def_readwrite("junction", &odr::Road::junction)
        .def_readwrite("name", &odr::Road::name)
        .def_readwrite("predecessor", &odr::Road::predecessor)
        .def_readwrite("successor", &odr::Road::successor)
        .def_readwrite("crossfall", &odr::Road::crossfall)
        // .def_readwrite("ref_line", &odr::Road::ref_line)
        .def_readwrite("s_to_lanesection", &odr::Road::s_to_lanesection)
        .def_readwrite("s_to_type", &odr::Road::s_to_type)
        .def_readwrite("s_to_speed", &odr::Road::s_to_speed)
        .def_readwrite("id_to_object", &odr::Road::id_to_object)
        ;
}

