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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_Red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sum_Green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sum_Blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sum_Red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sum_Red;
            }
            if (sum_Green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sum_Green;
            }
            if (sum_Blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sum_Blue;
            }
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
