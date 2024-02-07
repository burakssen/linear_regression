#include "LinearRegression.h"

#include <iostream>

LinearRegression::LinearRegression()
{
}

LinearRegression::~LinearRegression()
{
}

LinearRegression &LinearRegression::GetInstance()
{
    static LinearRegression instance;
    return instance;
}

void LinearRegression::GenerateLine()
{
    std::vector<std::shared_ptr<Point>> points = Graph::GetInstance().GetPoints();
    float sumX = 0;
    float sumY = 0;
    float sumXY = 0;
    float sumX2 = 0;

    for (auto &point : points)
    {
        sumX += point->GetPosition().x;
        sumY += point->GetPosition().y;
        sumXY += point->GetPosition().x * point->GetPosition().y;
        sumX2 += point->GetPosition().x * point->GetPosition().x;
    }

    float n = points.size();

    float slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float yIntercept = (sumY - slope * sumX) / n;

    this->m_line = std::make_shared<Line>();
    this->m_line->SetPosition({0, yIntercept});
    this->m_line->SetSlope(-slope);
}
