#pragma once

#include <memory>

#include <raylib.h>

#include "Graph/Graph.h"
#include "Point/Point.h"
#include "Line/Line.h"

class Point;
class Line;
class Graph;

class LinearRegression
{
    LinearRegression();

public:
    static LinearRegression &GetInstance();
    ~LinearRegression();

    void Update();
    void GenerateLine();

    std::shared_ptr<Line> GetLine() { return this->m_line; }

private:
    Graph *m_graph = nullptr;
    std::shared_ptr<Line> m_line;
};