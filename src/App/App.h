#pragma once

#include <string>

#include <raylib.h>

#include "Graph/Graph.h"

class App
{
    App();

public:
    ~App();
    static App &GetInstance();
    void Run();

private:
    void Update();
    void Render();
    void HandleInput();

private:
    float m_width = 1024;
    float m_height = 768;

    std::string m_title = "Linear Regression";

    Graph &m_graph = Graph::GetInstance();
};