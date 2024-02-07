#pragma once

#include <string>
#include <iomanip>
#include <sstream>

#include <raylib.h>

#include "Graph/Graph.h"

class Graph;

class Point
{
public:
    Point(Vector2 position);
    ~Point();

    void Update();
    void Render();
    void HandleInput();

    void SetPosition(Vector2 position);
    void SetRadius(float radius);

    Vector2 GetPosition() { return this->m_position; }
    float GetRadius() { return this->m_radius; }
    Vector2 GetCoordinate();

    bool IsDragging() { return this->m_dragging; }

private:
    Vector2 m_position = {0, 0};
    float m_radius = 0;

    Graph *m_graph = nullptr;

    bool m_dragging = false;
};