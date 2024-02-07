#include "Line.h"

Line::Line()
{
    this->m_graph = &Graph::GetInstance();
}

Line::~Line()
{
}

void Line::Update()
{
}

void Line::Render()
{
    // draw line using m_point and m_slope by drawing points on the line with 1 pixel apart from each other
    for (int i = 0; i < this->m_graph->GetSize().x; i++)
    {
        DrawCircleV({this->m_position.x + i, this->m_position.y - this->m_slope * i}, 1, RED);
        DrawCircleV({this->m_position.x - i, this->m_position.y + this->m_slope * i}, 1, RED);
    }

    // draw a circle on the line where the line intersects with the mouse cursor
    Vector2 mousePosition = GetMousePosition();
    DrawCircleV({mousePosition.x, this->m_position.y - this->m_slope * (mousePosition.x - this->m_position.x)}, 5, YELLOW);
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << "y = " << this->m_slope << "x + " << this->m_position.y - this->m_slope * this->m_position.x;
    std::string str = ss.str();
    DrawText(str.c_str(), mousePosition.x + 10, this->m_position.y - this->m_slope * (mousePosition.x - this->m_position.x) - 10, 20, YELLOW);
}

void Line::HandleInput()
{
}

void Line::SetPosition(Vector2 position)
{
    this->m_position = position;
}

void Line::SetSlope(float slope)
{
    this->m_slope = slope;
}

Vector2 Line::GetCoordinate()
{
    return {this->m_position.x - this->m_graph->GetPosition().x - this->m_graph->GetSize().x / 2, this->m_graph->GetPosition().y + this->m_graph->GetSize().y / 2 - this->m_position.y};
}