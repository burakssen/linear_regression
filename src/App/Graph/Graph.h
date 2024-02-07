#pragma once

#include <vector>
#include <memory>
#include <string>

#include <raylib.h>

#include "LinearRegression/LinearRegression.h"

#include "Point/Point.h"
#include "Line/Line.h"

class Point;
class Line;
class LinearRegression;

class Graph
{
    Graph();

public:
    static Graph &GetInstance();
    ~Graph();

    void Update();
    void Render();
    void HandleInput();

    void SetPosition(Vector2 position);
    void SetSize(Vector2 size);

    Vector2 GetPosition();
    Vector2 GetSize();

    std::vector<std::shared_ptr<Point>> &GetPoints() { return this->m_points; }

private:
    Vector2 m_position = {0, 0};
    Vector2 m_size = {0, 0};

    LinearRegression *m_linearRegression = nullptr;
    std::vector<std::shared_ptr<Point>> m_points;
    std::shared_ptr<Line> m_line;
};