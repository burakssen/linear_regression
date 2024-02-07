#include "Graph.h"

#include <iostream>

Graph::Graph()
{
    this->m_linearRegression = &LinearRegression::GetInstance();
}

Graph &Graph::GetInstance()
{
    static Graph instance;
    return instance;
}

Graph::~Graph()
{
}

void Graph::Update()
{
}

void Graph::Render()
{
    DrawRectangleRoundedLines({this->m_position.x, this->m_position.y, this->m_size.x, this->m_size.y}, 0.01, 0, 1, WHITE);

    // draw grid lines on x and y axis with 50 pixels apart from each other and origin should be in the middle of the graph and start from 0 with alpha 0.2
    for (int i = 0; i < this->m_size.x / 2; i += 50)
    {
        DrawLine(this->m_position.x + this->m_size.x / 2 + i, this->m_position.y, this->m_position.x + this->m_size.x / 2 + i, this->m_position.y + this->m_size.y, Fade(GREEN, 0.2));
        DrawLine(this->m_position.x + this->m_size.x / 2 - i, this->m_position.y, this->m_position.x + this->m_size.x / 2 - i, this->m_position.y + this->m_size.y, Fade(GREEN, 0.2));
    }

    for (int i = 0; i < this->m_size.y / 2; i += 50)
    {
        DrawLine(this->m_position.x, this->m_position.y + this->m_size.y / 2 + i, this->m_position.x + this->m_size.x, this->m_position.y + this->m_size.y / 2 + i, Fade(GREEN, 0.2));
        DrawLine(this->m_position.x, this->m_position.y + this->m_size.y / 2 - i, this->m_position.x + this->m_size.x, this->m_position.y + this->m_size.y / 2 - i, Fade(GREEN, 0.2));
    }
    // draw x and y axis
    DrawLine(this->m_position.x, this->m_position.y + this->m_size.y / 2, this->m_position.x + this->m_size.x, this->m_position.y + this->m_size.y / 2, GREEN);
    DrawLine(this->m_position.x + this->m_size.x / 2, this->m_position.y, this->m_position.x + this->m_size.x / 2, this->m_position.y + this->m_size.y, GREEN);

    // draw values on x and y axis origin should be in the middle of the graph and start from 0
    for (int i = 0; i < this->m_size.x / 2; i += 50)
    {
        DrawText(std::to_string(i).c_str(), this->m_position.x + this->m_size.x / 2 + i, this->m_position.y + this->m_size.y / 2, 10, GREEN);
        DrawText(std::to_string(-i).c_str(), this->m_position.x + this->m_size.x / 2 - i, this->m_position.y + this->m_size.y / 2, 10, GREEN);
    }

    for (int i = 0; i < this->m_size.y / 2; i += 50)
    {
        DrawText(std::to_string(i).c_str(), this->m_position.x + this->m_size.x / 2, this->m_position.y + this->m_size.y / 2 - i, 10, GREEN);
        DrawText(std::to_string(-i).c_str(), this->m_position.x + this->m_size.x / 2, this->m_position.y + this->m_size.y / 2 + i, 10, GREEN);
    }

    for (auto point : this->m_points)
    {
        point->Render();
    }

    if (this->m_line != nullptr)
    {
        this->m_line->Render();
    }

    DrawText("Press L to generate line", 15, 15, 10, GREEN);
    DrawText("Press R to reset", 15, 25, 10, GREEN);
    DrawText("Press Left Mouse Button to add point", 15, 35, 10, GREEN);
}

void Graph::HandleInput()
{

    for (auto point : this->m_points)
    {
        point->HandleInput();
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        for (auto point : this->m_points)
        {
            if (point->IsDragging())
            {
                return;
            }
        }
    }

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        for (auto point : this->m_points)
        {
            if (CheckCollisionRecs({point->GetPosition().x - point->GetRadius(), point->GetPosition().y - point->GetRadius(), point->GetRadius() * 2, point->GetRadius() * 2}, {GetMousePosition().x, GetMousePosition().y, 1, 1}))
            {
                this->m_points.erase(std::remove(this->m_points.begin(), this->m_points.end(), point), this->m_points.end());
                return;
            }
        }
    }

    if (IsKeyPressed(KEY_R))
    {
        this->m_points.clear();
    }

    if (IsKeyPressed(KEY_L))
    {
        this->m_linearRegression->GenerateLine();
        this->m_line = this->m_linearRegression->GetLine();
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePosition = GetMousePosition();

        for (auto point : this->m_points)
        {
            if (CheckCollisionRecs({point->GetPosition().x - point->GetRadius(), point->GetPosition().y - point->GetRadius(), point->GetRadius() * 2, point->GetRadius() * 2}, {mousePosition.x, mousePosition.y, 1, 1}))
            {
                return;
            }
        }

        auto point = std::make_shared<Point>(mousePosition);
        point->SetRadius(5);
        this->m_points.push_back(point);
    }
}

void Graph::SetPosition(Vector2 position)
{
    this->m_position = position;
}

void Graph::SetSize(Vector2 size)
{
    this->m_size = size;
}

Vector2 Graph::GetPosition()
{
    return this->m_position;
}

Vector2 Graph::GetSize()
{
    return this->m_size;
}