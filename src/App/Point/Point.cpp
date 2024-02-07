#include "Point.h"

Point::Point(Vector2 position)
{
    this->m_position = position;
    this->m_graph = &Graph::GetInstance();
}

Point::~Point()
{
}

void Point::Update()
{
}

void Point::Render()
{
    DrawCircleV(this->m_position, this->m_radius, RED);

    if (CheckCollisionRecs({this->m_position.x - this->m_radius, this->m_position.y - this->m_radius, this->m_radius * 2, this->m_radius * 2}, {GetMousePosition().x, GetMousePosition().y, 1, 1}))
    {
        // draw index of the point as (x, y)
        Vector2 coordinate = this->GetCoordinate();
        // use precision to limit the number of decimal places to 2 for the coordinate

        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << "(" << coordinate.x << ", " << coordinate.y << ")";
        std::string str = ss.str();
        DrawText(str.c_str(), this->m_position.x + 10, this->m_position.y - 10, 10, GREEN);
    }
}

void Point::HandleInput()
{
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        if (CheckCollisionRecs({this->m_position.x - this->m_radius, this->m_position.y - this->m_radius, this->m_radius * 2, this->m_radius * 2}, {GetMousePosition().x, GetMousePosition().y, 1, 1}))
        {
            this->m_dragging = true;
        }

        if (this->m_dragging)
        {
            this->m_position = GetMousePosition();
        }
    }
    else
    {
        this->m_dragging = false;
    }
}

void Point::SetPosition(Vector2 position)
{
    this->m_position = position;
}

void Point::SetRadius(float radius)
{
    this->m_radius = radius;
}

Vector2 Point::GetCoordinate()
{
    // convert position to coordinate system
    return {this->m_position.x - this->m_graph->GetPosition().x - this->m_graph->GetSize().x / 2, this->m_graph->GetPosition().y + this->m_graph->GetSize().y / 2 - this->m_position.y};
}