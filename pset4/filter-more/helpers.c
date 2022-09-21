#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int record[height][width];
    int sum_Red[height][width];
    int sum_Blue[height][width];
    int sum_Green[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
            record[i][j] = 0;
            sum_Red[i][j] = 0;
            sum_Blue[i][j] = 0;
            sum_Green[i][j] = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int column = j - 1; column <= j + 1; column++)
                {
                    if (row < 0 || row >= height || column < 0 || column >= width)
                    {
                        continue;
                    }
                    sum_Red[i][j] += temp[row][column].rgbtRed;
                    sum_Blue[i][j] += temp[row][column].rgbtBlue;
                    sum_Green[i][j] += temp[row][column].rgbtGreen;
                    record[i][j]++;
                }
            }
            image[i][j].rgbtRed = round(sum_Red[i][j] * 1.0 / record[i][j]);
            image[i][j].rgbtBlue = round(sum_Blue[i][j] * 1.0 / record[i][j]);
            image[i][j].rgbtGreen = round(sum_Green[i][j] * 1.0 / record[i][j]);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2},  {-1, 0, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int xR = 0, xB = 0, xG = 0, yR = 0, yB = 0, yG = 0;
            for (int row = -1; row <= 1; row++)
            {
                for (int column = -1; column <= 1; column++)
                {
                    if (i + row < 0 || i + row >= height || j + column < 0 || j + column >= width)
                    {
                        continue;
                    }
                    xR += Gx[row + 1][column + 1] * temp[i + row][j + column].rgbtRed;
                    xG += Gx[row + 1][column + 1] * temp[i + row][j + column].rgbtGreen;
                    xB += Gx[row + 1][column + 1] * temp[i + row][j + column].rgbtBlue;
                    yR += Gx[column + 1][row + 1] * temp[i + row][j + column].rgbtRed;
                    yG += Gx[column + 1][row + 1] * temp[i + row][j + column].rgbtGreen;
                    yB += Gx[column + 1][row + 1] * temp[i + row][j + column].rgbtBlue;
                }
            }
            if (round(sqrt(xR * xR + yR * yR)) > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sqrt(xR * xR + yR * yR));
            }
            if (round(sqrt(xB * xB + yB * yB)) > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sqrt(xB * xB + yB * yB));
            }
            if (round(sqrt(xG * xG + yG * yG)) > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sqrt(xG * xG + yG * yG));
            }
        }
    }
    return;
}
