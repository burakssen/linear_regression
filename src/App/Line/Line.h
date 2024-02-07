#pragma once

#include <raylib.h>

#include "Graph/Graph.h"

class Graph;

class Line
{
public:
    Line();
    ~Line();

    void Update();
    void Render();
    void HandleInput();

    void SetPosition(Vector2 position);
    void SetSlope(float slope);

    Vector2 GetPosition() { return this->m_position; }
    float GetSlope() { return this->m_slope; }

    Vector2 GetCoordinate();

private:
    Vector2 m_position = {0, 0};
    float m_slope = 0;

    Graph *m_graph = nullptr;
};