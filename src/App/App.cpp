#include "App.h"

App::App()
{
    InitWindow(this->m_width, this->m_height, this->m_title.c_str());
    SetTargetFPS(60);

    this->m_graph.SetPosition({10, 10});
    this->m_graph.SetSize({this->m_width - 20, this->m_height - 20});
}

App::~App()
{
    CloseWindow();
}

App &App::GetInstance()
{
    static App instance;
    return instance;
}

void App::Run()
{
    while (!WindowShouldClose())
    {
        this->HandleInput();
        this->Update();
        this->Render();
    }
}

void App::Update()
{
    this->m_graph.Update();
}

void App::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    this->m_graph.Render();
    EndDrawing();
}

void App::HandleInput()
{
    this->m_graph.HandleInput();
}
